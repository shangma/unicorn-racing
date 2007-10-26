<?xml version='1.0'?>
<Project Type="Project" LVVersion="8208000">
   <Item Name="My Computer" Type="My Computer">
      <Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
      <Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
      <Property Name="server.tcp.enabled" Type="Bool">false</Property>
      <Property Name="server.tcp.port" Type="Int">0</Property>
      <Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
      <Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
      <Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
      <Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
      <Property Name="specify.custom.address" Type="Bool">false</Property>
      <Item Name="dashboard.vi" Type="VI" URL="dashboard.vi"/>
      <Item Name="load_data.vi" Type="VI" URL="load_data.vi"/>
      <Item Name="frontend.vi" Type="VI" URL="frontend.vi"/>
      <Item Name="unicorn.ico" Type="Document" URL="unicorn.ico"/>
      <Item Name="Dependencies" Type="Dependencies"/>
      <Item Name="Build Specifications" Type="Build">
         <Item Name="Unicorn datalogger" Type="EXE">
            <Property Name="Absolute[0]" Type="Bool">false</Property>
            <Property Name="Absolute[1]" Type="Bool">false</Property>
            <Property Name="Absolute[2]" Type="Bool">false</Property>
            <Property Name="ActiveXInfoEnumCLSIDsItemCount" Type="Int">0</Property>
            <Property Name="ActiveXInfoMajorVersion" Type="Int">0</Property>
            <Property Name="ActiveXInfoMinorVersion" Type="Int">0</Property>
            <Property Name="ActiveXInfoObjCLSIDsItemCount" Type="Int">0</Property>
            <Property Name="ActiveXInfoProgIDPrefix" Type="Str"></Property>
            <Property Name="ActiveXServerName" Type="Str"></Property>
            <Property Name="AliasID" Type="Str">{AD989554-B19B-4168-9609-892CC11B5FC6}</Property>
            <Property Name="AliasName" Type="Str">Project.aliases</Property>
            <Property Name="ApplicationID" Type="Str">{FEAF5798-8A28-49C9-AE98-A697DADA3985}</Property>
            <Property Name="ApplicationName" Type="Str">unicorn_datalogger.exe</Property>
            <Property Name="AutoIncrement" Type="Bool">false</Property>
            <Property Name="BuildName" Type="Str">Unicorn datalogger</Property>
            <Property Name="CommandLineArguments" Type="Bool">false</Property>
            <Property Name="CopyErrors" Type="Bool">false</Property>
            <Property Name="CustomIcon" Type="Ref">/My Computer/unicorn.ico</Property>
            <Property Name="DebuggingEXE" Type="Bool">false</Property>
            <Property Name="DebugServerWaitOnLaunch" Type="Bool">false</Property>
            <Property Name="DefaultLanguage" Type="Str">English</Property>
            <Property Name="DependencyApplyDestination" Type="Bool">true</Property>
            <Property Name="DependencyApplyInclusion" Type="Bool">true</Property>
            <Property Name="DependencyApplyProperties" Type="Bool">true</Property>
            <Property Name="DependencyFolderDestination" Type="Int">0</Property>
            <Property Name="DependencyFolderInclusion" Type="Str">As needed</Property>
            <Property Name="DependencyFolderPropertiesItemCount" Type="Int">0</Property>
            <Property Name="DestinationID[0]" Type="Str">{E6048085-66F3-45A6-9D77-6035A2FF5B1D}</Property>
            <Property Name="DestinationID[1]" Type="Str">{E6048085-66F3-45A6-9D77-6035A2FF5B1D}</Property>
            <Property Name="DestinationID[2]" Type="Str">{E9F15A32-7E51-4D3F-890C-CED9352D2998}</Property>
            <Property Name="DestinationItemCount" Type="Int">3</Property>
            <Property Name="DestinationName[0]" Type="Str">unicorn_datalogger.exe</Property>
            <Property Name="DestinationName[1]" Type="Str">Destination Directory</Property>
            <Property Name="DestinationName[2]" Type="Str">Support Directory</Property>
            <Property Name="Disconnect" Type="Bool">true</Property>
            <Property Name="IncludeHWConfig" Type="Bool">false</Property>
            <Property Name="IncludeSCC" Type="Bool">true</Property>
            <Property Name="INIID" Type="Str">{E6D82FA4-2CDC-4357-9043-8D0A5157643B}</Property>
            <Property Name="ININame" Type="Str">LabVIEW.ini</Property>
            <Property Name="LOGID" Type="Str">{4EE961AB-B09E-46E2-9C8D-7F938053233A}</Property>
            <Property Name="MathScript" Type="Bool">false</Property>
            <Property Name="Path[0]" Type="Path">../../builds/show_data/Unicorn datalogger/internal.llb</Property>
            <Property Name="Path[1]" Type="Path">../../builds/show_data/Unicorn datalogger</Property>
            <Property Name="Path[2]" Type="Path">../../builds/show_data/Unicorn datalogger/data</Property>
            <Property Name="ShowHWConfig" Type="Bool">false</Property>
            <Property Name="SourceInfoItemCount" Type="Int">2</Property>
            <Property Name="SourceItem[0].ItemID" Type="Ref">/My Computer/dashboard.vi</Property>
            <Property Name="SourceItem[0].VIPropertiesItemCount" Type="Int">1</Property>
            <Property Name="SourceItem[0].VIPropertiesSettingOption[0]" Type="Str">Remove panel</Property>
            <Property Name="SourceItem[0].VIPropertiesVISetting[0]" Type="Bool">true</Property>
            <Property Name="SourceItem[1].Inclusion" Type="Str">Startup VI</Property>
            <Property Name="SourceItem[1].ItemID" Type="Ref">/My Computer/frontend.vi</Property>
            <Property Name="StripLib" Type="Bool">true</Property>
            <Property Name="SupportedLanguageCount" Type="Int">0</Property>
            <Property Name="TLBID" Type="Str">{BD1CA4CC-EE0C-4BA1-ACEC-CC8D66ADD9F9}</Property>
            <Property Name="UseFFRTE" Type="Bool">false</Property>
            <Property Name="VersionInfoCompanyName" Type="Str">Fuckamokka, Inc</Property>
            <Property Name="VersionInfoFileDescription" Type="Str"></Property>
            <Property Name="VersionInfoFileType" Type="Int">1</Property>
            <Property Name="VersionInfoFileVersionBuild" Type="Int">0</Property>
            <Property Name="VersionInfoFileVersionMajor" Type="Int">1</Property>
            <Property Name="VersionInfoFileVersionMinor" Type="Int">0</Property>
            <Property Name="VersionInfoFileVersionPatch" Type="Int">0</Property>
            <Property Name="VersionInfoInternalName" Type="Str">frontend</Property>
            <Property Name="VersionInfoLegalCopyright" Type="Str">Copyright © 2007 Fuckamokka, Inc</Property>
            <Property Name="VersionInfoProductName" Type="Str">UNICORN D.A.T.A. S.W.A.P.P.E.R.</Property>
         </Item>
      </Item>
   </Item>
</Project>
