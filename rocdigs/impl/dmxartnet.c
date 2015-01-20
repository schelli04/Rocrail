/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2015 Rob Versluis, Rocrail.net

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/




#include "rocdigs/impl/dmxartnet_impl.h"

#include "rocs/public/mem.h"
#include "rocs/public/system.h"

#include "rocrail/wrapper/public/DigInt.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/Color.h"
#include "rocrail/wrapper/public/DMX.h"

static int instCnt = 0;

/** ----- OBase ----- */
static void __del( void* inst ) {
  if( inst != NULL ) {
    iODMXArtNetData data = Data(inst);
    /* Cleanup data->xxx members...*/
    
    freeMem( data );
    freeMem( inst );
    instCnt--;
  }
  return;
}

static const char* __name( void ) {
  return name;
}

static unsigned char* __serialize( void* inst, long* size ) {
  return NULL;
}

static void __deserialize( void* inst,unsigned char* bytestream ) {
  return;
}

static char* __toString( void* inst ) {
  return NULL;
}

static int __count( void ) {
  return instCnt;
}

static struct OBase* __clone( void* inst ) {
  return NULL;
}

static Boolean __equals( void* inst1, void* inst2 ) {
  return False;
}

static void* __properties( void* inst ) {
  return NULL;
}

static const char* __id( void* inst ) {
  return NULL;
}

static void* __event( void* inst, const void* evt ) {
  return NULL;
}

/** ----- ODMXArtNet ----- */

#define ARTDMX_MSGSIZE 531
#define ARTPOL_MSGSIZE 7
#define ARTPOL_IP "255.255.255.255"

static int __ArtHeader(byte* msg) {
  int i = 0;
  msg[i++]='A';
  msg[i++]='r';
  msg[i++]='t';
  msg[i++]='-';
  msg[i++]='N';
  msg[i++]='e';
  msg[i++]='t';
  msg[i++]=0x00;
  return i;
}



/*
From 192.168.100.181(63167) To 255.255.255.255(6454)  ArtPoll, Enquiry to Art-Net device(s)
 Raw Data = { [41], [72], [74], [2D], [4E], [65], [74], [00], [00], [20], [50], [0E], [06], [00], [00], [00], [14], [DE], [37], [04], [14], [DE], [00], [00], [4B], [53], [41], [76], [72], [41], [72], [74], ... } //Data )
>> Error in source port number
From 192.168.100.120(6454) To 192.168.100.255(6454) ArtPoll, Enquiry to Art-Net device(s)
 Raw Data = { [41], [72], [74], [2D], [4E], [65], [74], [00], [00], [20], [00], [0E], [06], [00], [00], [00], [14], [DE], [37], [04], [14], [DE], [00], [00], [4B], [53], [41], [76], [72], [41], [72], [74], ... } //Data )

 */
static void __ArtPol(iODMXArtNet inst) {
  iODMXArtNetData data = Data(inst);

  byte msg[ARTPOL_MSGSIZE];
  int i = __ArtHeader(msg);

  msg[i++]=0; // OpArtPol 0x2000
  msg[i++]=0x20;

  msg[i++]=0x50; //version
  msg[i++]=0x0E;

  msg[i++]=0x06; // TalkToMe
  msg[i++]=0x00; // Priority

  iOSocket socket = SocketOp.inst( ARTPOL_IP, 6454, False, True, False );
  if( socket != NULL ) {
    char client[256] = {'\0'};
    int port = 0;
    byte in[ARTDMX_MSGSIZE];
    SocketOp.setBroadcast(socket, True);
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "ArtPol broadcast...");

    TraceOp.dump( NULL, TRCLEVEL_INFO, (char*)msg, i );
    SocketOp.sendto( socket, (char*)msg, i, ARTPOL_IP, 0 );
    int packetSize = SocketOp.recvfrom( socket, (char*)in, ARTDMX_MSGSIZE, client, &port );
    if( packetSize > 0 ) {
      TraceOp.dump( NULL, TRCLEVEL_INFO, (char*)in, packetSize );
    }
    SocketOp.base.del(socket);
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "ArtPol broadcast ended");
  }
}

static void __ArtDmx(iODMXArtNet inst) {
  iODMXArtNetData data = Data(inst);

  byte msg[ARTDMX_MSGSIZE];
  int i = __ArtHeader(msg);

  msg[i++]=0; // OpOutput 0x5000
  msg[i++]=0x50;

  msg[i++]=0x50; //version
  msg[i++]=0x0E;

  msg[i++]=0x00; //sequence =0

  msg[i++]=0x00; //physical

  msg[i++]=0x00;
  msg[i++]=0x00; //subuni net

  msg[i++]=0x02;
  msg[i]=0x00;

  if( MutexOp.wait( data->mux ) ) {
    // add DMX-values
    int j = 0;
    for(j = 1; j <= 512; j++) {
      msg[i+j]=(byte)data->dmxchannel[j];
    }
    MutexOp.post(data->mux);
  }

  iOSocket socket = SocketOp.inst( wDigInt.gethost(data->ini), 6454, False, True, False );
  if( socket != NULL ) {
    TraceOp.dump( NULL, TRCLEVEL_BYTE, (char*)msg, ARTDMX_MSGSIZE );
    SocketOp.sendto( socket, (char*)msg, ARTDMX_MSGSIZE, NULL, 0 );
    SocketOp.base.del(socket);
  }

}

static void __setChannel(iODMXArtNet inst, int addr, int red, int green, int blue, int brightness, Boolean active, int redChannel, int greenChannel, int blueChannel, int briChannel) {
  iODMXArtNetData data = Data(inst);
  if( MutexOp.wait( data->mux ) ) {
    TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999,
        "device=%d active=%d bri=%d RGB=%d,%d,%d", addr, active, brightness, red, green, blue );
    if( briChannel > 0 )
      data->dmxchannel[addr+briChannel-1] = brightness;
    if( redChannel > 0 )
      data->dmxchannel[addr+redChannel-1] = red;
    if( greenChannel > 0 )
      data->dmxchannel[addr+greenChannel-1] = green;
    if( blueChannel > 0 )
      data->dmxchannel[addr+blueChannel-1] = blue;
    MutexOp.post(data->mux);
  }
}


static iONode __translate( iODMXArtNet inst, iONode node ) {
  iODMXArtNetData data = Data(inst);
  iONode rsp   = NULL;

  /* System command. */
  if( StrOp.equals( NodeOp.getName( node ), wSysCmd.name() ) ) {
    const char* cmd = wSysCmd.getcmd( node );

    if( StrOp.equals( cmd, wSysCmd.stop ) ) {
    }
  }

  /* Output command. */
  else if( StrOp.equals( NodeOp.getName( node ), wOutput.name() ) ) {
    int addr = wOutput.getaddr( node );
    int port = wOutput.getport( node );
    int val  = wOutput.getvalue( node );
    iONode  color = wOutput.getcolor(node);
    Boolean blink = wOutput.isblink( node );
    Boolean colortype = wOutput.iscolortype( node );
    Boolean active = False;

    int redChannel   = wOutput.getredChannel(node);
    int greenChannel = wOutput.getgreenChannel(node);
    int blueChannel  = wOutput.getblueChannel(node);
    int briChannel   = wOutput.getbrightnessChannel(node);
    int r = 0;
    int g = 0;
    int b = 0;

    if( StrOp.equals( wOutput.getcmd( node ), wOutput.on ) || StrOp.equals( wOutput.getcmd( node ), wOutput.value ) )
      active = True;

    if( color != NULL ) {
      r = wColor.getred(color);
      g = wColor.getgreen(color);
      b = wColor.getblue(color);
    }
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "output device=%d active=%d cmd=%s bri=%d briChannel(%d) RGB=%d,%d,%d RGBChannels(%d,%d,%d)",
        addr, active, wOutput.getcmd( node ), val, briChannel, r, g, b, redChannel, greenChannel, blueChannel );

    __setChannel(inst, addr, r, g, b, val, active, redChannel, greenChannel, blueChannel, briChannel);
    data->refresh = True;
  }



  return rsp;
}


/**  */
static iONode _cmd( obj inst ,const iONode cmd ) {
  iODMXArtNetData data = Data(inst);
  iONode rsp = __translate( (iODMXArtNet)inst, cmd );
  /* Cleanup Node1 */
  cmd->base.del(cmd);
  return rsp;
}


/**  */
static byte* _cmdRaw( obj inst ,const byte* cmd ) {
  return 0;
}


/**  */
static void _halt( obj inst ,Boolean poweroff ,Boolean shutdown ) {
  iODMXArtNetData data = Data(inst);
  data->run = False;
  if( poweroff ) {
  }
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Shutting down <%s>...", data->iid );
  ThreadOp.sleep(200);
}


/**  */
static Boolean _setListener( obj inst ,obj listenerObj ,const digint_listener listenerFun ) {
  iODMXArtNetData data = Data(inst);
  data->listenerObj = listenerObj;
  data->listenerFun = listenerFun;
  return True;
}


/**  */
static Boolean _setRawListener( obj inst ,obj listenerObj ,const digint_rawlistener listenerRawFun ) {
  return 0;
}


/** external shortcut event */
static void _shortcut( obj inst ) {
  return;
}


/** bit0=power, bit1=programming, bit2=connection */
static int _state( obj inst ) {
  return 0;
}


/**  */
static Boolean _supportPT( obj inst ) {
  return 0;
}


/** vmajor*1000 + vminor*100 + patch */
static int vmajor = 2;
static int vminor = 0;
static int patch  = 99;
static int _version( obj inst ) {
  iODMXArtNetData data = Data(inst);
  return vmajor*10000 + vminor*100 + patch;
}


static void __writer( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iODMXArtNet inst = (iODMXArtNet)ThreadOp.getParm( th );
  iODMXArtNetData data = Data(inst);

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "writer started." );
  ThreadOp.sleep(1000);

  int framepause = 0;
  while( data->run ) {
    ThreadOp.sleep(10);
    framepause += 10;
    if( framepause >= data->framerate || data->refresh) {
      data->refresh = False;
      framepause = 0;
      __ArtDmx(inst);
    }
  }

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "writer ended." );
}


static void __reader( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iODMXArtNet inst = (iODMXArtNet)ThreadOp.getParm( th );
  iODMXArtNetData data = Data(inst);

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "reader started." );
  ThreadOp.sleep(500);

  iOSocket socket = SocketOp.inst( ARTPOL_IP, 6454, False, True, False );
  if( socket != NULL ) {
    char client[256] = {'\0'};
    int port = 0;
    byte in[ARTDMX_MSGSIZE];
    __ArtPol(inst);
    while( data->run ) {
      int packetSize = SocketOp.recvfrom( socket, (char*)in, ARTDMX_MSGSIZE, client, &port );

      if( packetSize > 0 ) {
        TraceOp.dump( NULL, TRCLEVEL_INFO, (char*)in, packetSize );
      }
      ThreadOp.sleep(100);
    }
    SocketOp.base.del(socket);
  }

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "reader ended." );
}


/**  */
static struct ODMXArtNet* _inst( const iONode ini ,const iOTrace trc ) {
  iODMXArtNet __DMXArtNet = allocMem( sizeof( struct ODMXArtNet ) );
  iODMXArtNetData data = allocMem( sizeof( struct ODMXArtNetData ) );
  MemOp.basecpy( __DMXArtNet, &DMXArtNetOp, 0, sizeof( struct ODMXArtNet ), data );

  /* Initialize data->xxx members... */
  TraceOp.set( trc );
  SystemOp.inst();

  data->ini    = ini;
  data->dmxini = wDigInt.getdmx(ini);
  data->iid    = StrOp.dup( wDigInt.getiid( ini ) );
  data->mux    = MutexOp.inst( NULL, True );
  data->run    = True;

  if( data->dmxini == NULL ) {
    data->dmxini = NodeOp.inst(wDMX.name(), data->ini, ELEMENT_NODE);
    NodeOp.addChild(data->ini, data->dmxini);
  }

  data->framerate = wDMX.getframerate(data->dmxini);
  if( data->framerate < 100 )
    data->framerate = 500;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "DMX-ArtNet %d.%d.%d", vmajor, vminor, patch );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "  IID       : %s", data->iid );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "  IP        : %s", wDigInt.gethost(data->ini) );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "  Frame rate: %d", data->framerate );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );

  data->reader = ThreadOp.inst( "dmxreader", &__reader, __DMXArtNet );
  ThreadOp.start( data->reader );

  data->writer = ThreadOp.inst( "dmxwriter", &__writer, __DMXArtNet );
  ThreadOp.start( data->writer );

  instCnt++;
  return __DMXArtNet;
}


iIDigInt rocGetDigInt( const iONode ini ,const iOTrace trc )
{
  return (iIDigInt)_inst(ini,trc);
}


/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocdigs/impl/dmxartnet.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
