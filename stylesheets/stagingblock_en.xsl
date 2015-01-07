<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="html" encoding="UTF-8"/>

<xsl:template match="/">

	<html>
		<head>
			<title>Rocrail StagingBlock report</title>
		</head>
		<body>
			<br /><br />
			<h2>List of all defined Stagingblocks</h2>
			Rocrail-Version: <xsl:value-of select="plan/@rocrailversion" />
			<table border="1" rules="all" cellpadding="4" cellspacing="0" width="100%">
				<THEAD>
					<TR>
						<TH bgcolor="lightgrey">Nr.</TH>
						<TH bgcolor="lightgrey">ID</TH>
						<TH bgcolor="lightgrey">Description</TH>
						<TH bgcolor="lightgrey">Section length</TH>
						<TH bgcolor="lightgrey">Train gap</TH>
						<TH bgcolor="lightgrey">Enter sensor</TH>
						<TH bgcolor="lightgrey">Enter signal</TH>
						<TH bgcolor="lightgrey">Exit signal</TH>
						<TH bgcolor="lightgrey">Random rate</TH>
					</TR>
					<TR>
						<TH bgcolor="lightgrey">&#160;</TH>
						<TH bgcolor="lightgrey">&#160;</TH>
						<TH bgcolor="lightgrey">Depart</TH>
						<TH bgcolor="lightgrey">Arrive</TH>
						<TH bgcolor="lightgrey">Wait type</TH>
						<TH bgcolor="lightgrey">&#160;</TH>
						<TH bgcolor="lightgrey">&#160;</TH>
						<TH bgcolor="lightgrey">&#160;</TH>
						<TH bgcolor="lightgrey">&#160;</TH>
					</TR>
				</THEAD> 
				<TBODY>
					<xsl:apply-templates/>
				</TBODY>
			</table>
			<br /><br />
		</body>
	</html>
   
</xsl:template>

<xsl:template match="sblist">  
	<xsl:apply-templates>
		<xsl:sort select="@id" order="ascending" data-type="text" />
	</xsl:apply-templates>
</xsl:template>

<xsl:variable name="anzahl" select="count(//sb)" />
<xsl:template match="sblist/sb" name="sb">
	<TR bgcolor="white">	
		<TD align="center" rowspan="2">
			<xsl:number level="multiple" count="id" format="01." value="position() - $anzahl - 1" />
		</TD>

		<xsl:choose>
			<xsl:when test="@state = 'closed'">
				<TD align="left" rowspan="2" bgcolor="lightgrey"><xsl:value-of select="@id" /></TD>
			</xsl:when>
			<xsl:otherwise>
				<TD align="left" rowspan="2"><xsl:value-of select="@id" /></TD>
			</xsl:otherwise>
		</xsl:choose>
	   

		<TD align="center">
			<xsl:choose>
				<xsl:when test="@desc = ''">
					<xsl:text>-</xsl:text>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="@desc" />
				</xsl:otherwise>
			</xsl:choose>
		</TD>

		<TD align="center">
			<xsl:choose>
				<xsl:when test="@slen = '0'">
					<xsl:text>-</xsl:text>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="@slen" />
				</xsl:otherwise>
			</xsl:choose>
		</TD>
	   
		<TD align="center">
			<xsl:choose>
				<xsl:when test="@gap = '0'">
					<xsl:text>-</xsl:text>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="@gap" />
				</xsl:otherwise>
			</xsl:choose>
		</TD>

		<TD align="center">
			<xsl:choose>
				<xsl:when test="@fbenterid = ''">
					<xsl:text>-</xsl:text>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="@fbenterid" />
				</xsl:otherwise>
			</xsl:choose>
		</TD>
	   	   
		<TD align="center">
			<xsl:choose>
				<xsl:when test="@entersignal = ''">
					<xsl:text>-</xsl:text>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="@entersignal" />
				</xsl:otherwise>
			</xsl:choose>
		</TD>
	
		<TD align="center">
			<xsl:choose>
				<xsl:when test="@exitsignal = ''">
					<xsl:text>-</xsl:text>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="@exitsignal" />
				</xsl:otherwise>
			</xsl:choose>
		</TD>

		<TD align="center">
			<xsl:choose>
				<xsl:when test="@randomrate = ''">
					<xsl:text>-</xsl:text>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="@randomrate" />
				</xsl:otherwise>
			</xsl:choose>
		</TD>
	</TR>

	<TR bgcolor="white">	
		<TD align="center">
			<xsl:choose>
				<xsl:when test="@exitspeed = ''">
					<xsl:text>-</xsl:text>
				</xsl:when>
				<xsl:otherwise>
					<xsl:choose>
						<xsl:when test="@exitspeed = 'cruise'">
							<xsl:text>Reise</xsl:text>
						</xsl:when>
						<xsl:when test="@exitspeed = 'min'">
							<xsl:text>Min.</xsl:text>
						</xsl:when>
						<xsl:when test="@exitspeed = 'mid'">
							<xsl:text>Mid.</xsl:text>
						</xsl:when>
						<xsl:when test="@exitspeed = 'mix'">
							<xsl:text>Max.</xsl:text>
						</xsl:when>
						<xsl:otherwise>
							<xsl:value-of select="@exitspeed" />
						</xsl:otherwise>
					</xsl:choose>
				</xsl:otherwise>
			</xsl:choose>
		</TD>

		<TD align="center">
			<xsl:choose>
				<xsl:when test="@stopspeed = ''">
					<xsl:text>-</xsl:text>
				</xsl:when>
				<xsl:otherwise>
					<xsl:choose>
						<xsl:when test="@stopspeed = 'cruise'">
							<xsl:text>Reise</xsl:text>
						</xsl:when>
						<xsl:when test="@stopspeed = 'min'">
							<xsl:text>Min.</xsl:text>
						</xsl:when>
						<xsl:when test="@stopspeed = 'mid'">
							<xsl:text>Mid.</xsl:text>
						</xsl:when>
						<xsl:when test="@stopspeed = 'mix'">
							<xsl:text>Max.</xsl:text>
						</xsl:when>
						<xsl:otherwise>
							<xsl:value-of select="@stopspeed" />
						</xsl:otherwise>
					</xsl:choose>
				</xsl:otherwise>
			</xsl:choose>
		</TD>
	   
		<TD align="center">
			<xsl:choose>
				<xsl:when test="@waitmode = ''">
					<xsl:text>-</xsl:text>
				</xsl:when>
				<xsl:otherwise>
					<xsl:choose>
						<xsl:when test="@waitmode = 'random'">
							<xsl:text>Zufall</xsl:text>
						</xsl:when>
						<xsl:when test="@waitmode = 'fixed'">
							<xsl:text>Fest</xsl:text>
						</xsl:when>
						<xsl:when test="@waitmode = 'mid'">
							<xsl:text>Lokomotive</xsl:text>
						</xsl:when>
						<xsl:when test="@waitmode = 'none'">
							<xsl:text>keine</xsl:text>
						</xsl:when>
						<xsl:otherwise>
							<xsl:value-of select="@waitmode" />
						</xsl:otherwise>
					</xsl:choose>
				</xsl:otherwise>
			</xsl:choose>
		</TD>
		<TD align="center">&#160;</TD>
		<TD align="center">&#160;</TD>
		<TD align="center">&#160;</TD>
		<TD align="center">&#160;</TD>
	
	</TR>

    <TR>
	<td align="center" bgcolor="white">&#160;</td>
	<TD colspan="11">
    <table border="0" rules="all" cellpadding="4" cellspacing="0" width="100%">
      <THEAD>
	  <TR>
	     <TH height="30" bgcolor="lightgrey">Abschittskennung</TH>
	     <TH height="30" bgcolor="lightgrey">L&#228;nge</TH>
	     <TH height="30" bgcolor="lightgrey">R&#252;ckmelder</TH>
	     <TH height="30" bgcolor="lightgrey">Belegung</TH>
	     <TH height="30" bgcolor="lightgrey">Lok-ID</TH>
	     <TH height="30" bgcolor="lightgrey">Nr.</TH>
	  </TR>
      </THEAD> 
      <TBODY>
        <xsl:apply-templates mode="section"/>
      </TBODY>
      </table>
	</TD>
	</TR>

 	<TR>
		<th colspan="12">&#160;</th>
	</TR>
  
</xsl:template>


<xsl:template match="sblist/sb/section" mode="section">

      <TR>
 	   <TD align="center">
         <xsl:value-of select="@id" />
	   </TD>
 	   <TD align="center">
         <xsl:value-of select="@len" />
	   </TD>
 	   <TD align="center">
         <xsl:value-of select="@fbid" />
	   </TD>
 	   <TD align="center">
         <xsl:value-of select="@fbidocc" />
	   </TD>
 	   <TD align="center">
         <xsl:value-of select="@lcid" />
	   </TD>
 	   <TD align="center">
         <xsl:value-of select="@nr" />
	   </TD>
	</TR>
 
</xsl:template>

</xsl:stylesheet>

