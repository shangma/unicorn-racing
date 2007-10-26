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
      <Item Name="Dependencies" Type="Dependencies"/>
      <Item Name="Build Specifications" Type="Build"/>
   </Item>
   <Item Name="NI-Unicorn" Type="RT CompactRIO">
      <Property Name="alias.name" Type="Str">NI-Unicorn</Property>
      <Property Name="alias.value" Type="Str">10.0.0.2</Property>
      <Property Name="CCSymbols" Type="Str">OS,PharLap;CPU,x86;TARGET_TYPE,RT;</Property>
      <Property Name="crio.family" Type="Str">900x</Property>
      <Property Name="host.ResponsivenessCheckEnabled" Type="Bool">true</Property>
      <Property Name="host.ResponsivenessCheckPingDelay" Type="UInt">5000</Property>
      <Property Name="host.ResponsivenessCheckPingTimeout" Type="UInt">1000</Property>
      <Property Name="host.TargetCPUID" Type="UInt">3</Property>
      <Property Name="host.TargetOSID" Type="UInt">15</Property>
      <Property Name="target.cleanupVisa" Type="Bool">false</Property>
      <Property Name="target.FPProtocolGlobals_ControlTimeLimit" Type="Int">300</Property>
      <Property Name="target.getDefault-&gt;WebServer.Port" Type="Int">80</Property>
      <Property Name="target.getDefault-&gt;WebServer.Timeout" Type="Int">60</Property>
      <Property Name="target.IsRemotePanelSupported" Type="Bool">true</Property>
      <Property Name="target.RTTarget.ApplicationPath" Type="Path">/c/ni-rt/startup/startup.rtexe</Property>
      <Property Name="target.RTTarget.EnableFileSharing" Type="Bool">true</Property>
      <Property Name="target.RTTarget.IPAccess" Type="Str">+*</Property>
      <Property Name="target.RTTarget.LaunchAppAtBoot" Type="Bool">false</Property>
      <Property Name="target.RTTarget.VIPath" Type="Path">/c/ni-rt/startup</Property>
      <Property Name="target.server.app.propertiesEnabled" Type="Bool">true</Property>
      <Property Name="target.server.control.propertiesEnabled" Type="Bool">true</Property>
      <Property Name="target.server.tcp.access" Type="Str">+*</Property>
      <Property Name="target.server.tcp.enabled" Type="Bool">false</Property>
      <Property Name="target.server.tcp.paranoid" Type="Bool">true</Property>
      <Property Name="target.server.tcp.port" Type="Int">3363</Property>
      <Property Name="target.server.tcp.serviceName" Type="Str"></Property>
      <Property Name="target.server.tcp.serviceName.default" Type="Str">Main Application Instance/VI Server</Property>
      <Property Name="target.server.vi.access" Type="Str">+*</Property>
      <Property Name="target.server.vi.callsEnabled" Type="Bool">true</Property>
      <Property Name="target.server.vi.propertiesEnabled" Type="Bool">true</Property>
      <Property Name="target.WebServer.Enabled" Type="Bool">true</Property>
      <Property Name="target.WebServer.LogEnabled" Type="Bool">false</Property>
      <Property Name="target.WebServer.LogPath" Type="Path">/c/ni-rt/system/www/www.log</Property>
      <Property Name="target.WebServer.Port" Type="Int">80</Property>
      <Property Name="target.WebServer.RootPath" Type="Path">/c/ni-rt/system/www</Property>
      <Property Name="target.WebServer.TcpAccess" Type="Str">c+*</Property>
      <Property Name="target.WebServer.Timeout" Type="Int">60</Property>
      <Property Name="target.WebServer.ViAccess" Type="Str">+*</Property>
      <Item Name="FPGA Target" Type="FPGA Target">
         <Property Name="AutoRun" Type="Bool">true</Property>
         <Property Name="configString.guid" Type="Str">{0089E444-8567-4CC5-986C-D63689F34BB7}resource=/crio_Analog Input/AI6;0{0170B359-6D91-45A2-90B3-68A3A61C10E1}resource=/crio_Analog Input/AI29;0{0665BB1F-BB5C-4C39-B3DC-6A3BB6D7E6B9}resource=/crio_Analog Input/AI21;0{0FE4D2A7-C0DE-4E60-A90D-D90ED6F0DD20}resource=/crio_Analog Input/AI26;0{0FFFD7F8-C841-47D1-8F10-3AD0B988A75D}resource=/crio_Analog Input/AI8;0{1A27B268-740D-4F8A-9100-22B05AA5D386}resource=/crio_Analog Input/AI0;0{1D934D2D-BF1D-47DF-AE79-5DBC469715F6}resource=/crio_Analog Input/AI18;0{2832F320-BD29-428E-9344-23376A4A7054}###!!A!!!")!&amp;E!Q`````QV3:8.P&gt;8*D:3"/97VF!"R!-0````]36'^Q)&amp;.J:WZB&lt;#"$&lt;WZO:7.U!!!;1$$`````%5.M&lt;W.L)&amp;.J:WZB&lt;#"/97VF!"B!#B*.;7YA2H*F=86F&lt;G.Z)#B)?CE!!"B!#B*.98AA2H*F=86F&lt;G.Z)#B)?CE!!"B!)2*798*J97*M:3"'=G6R&gt;76O9XE!!"R!#B:/&lt;WVJ&lt;G&amp;M)%:S:8&amp;V:7ZD?3!I3(IJ!!!=1!I85'6B;S"1:8*J&lt;W1A3GFU&gt;'6S)#BQ=SE!(%!+&amp;UVJ&lt;C"%&gt;82Z)%.Z9WRF)#AF)%BJ:WAJ!"R!#B&gt;.98AA2(6U?3"$?7.M:3!I*3");7&gt;I+1!51!I/17.D&gt;8*B9XEA+("Q&lt;3E!!"*!)1R'=G6F)&amp;*V&lt;GZJ&lt;G=!!"2!)1^4=(*F971A5X"F9X2S&gt;7U!%E!Q`````QB$&lt;'^D;S"*2!!!/%"!!!(`````!!UK5G6M982F:#"$&lt;'^D;X-A&gt;WFU;#"O&lt;S"$2%-A9W^N=(-A&lt;G6D:8.T98*Z!!!31&amp;--2W6O:8*J9S"%982B!!!/1$$`````"5&amp;M;7&amp;T!']!]1!!!!!!!!!")'ZJ=H:J1G&amp;T:624382F&lt;5.P&lt;G:J:X6S982J&lt;WYO9X2M!%6!5!!1!!!!!1!#!!-!"!!&amp;!!9!"Q!)!!E!#A!,!!Q!$A!0!"!&lt;1X6S=G6O&gt;#"$&lt;'^D;S"$&lt;WZG;7&gt;V=G&amp;U;7^O!!%!%1!!!"1U-#".3(IA4WZC&lt;W&amp;S:#"$&lt;'^D;Q!!!!6$&lt;'MU-!!!!!6$&lt;'MU-%'$%N!!!!!!19-3U!!!!!!!19-3U!!!!!"!&lt;U!!!!!!!%"*!!!!!!!!1%E!!!!!!!"!71!!!!!!!!%!!!!!!!AAA!)!!!!"!!1!!!!"!!!!!!!!!!!!&amp;$1Q)%V)?C"0&lt;G*P98*E)%.M&lt;W.L!!!!!!{28F99611-7BF4-44A7-85FB-4EE8FC3DB326}resource=/crio_Analog Input/AI27;0{2AC7E091-3FCA-44A6-8CEE-B7A03873E931}resource=/crio_Analog Input/AI30;0{2CE879A1-A2A8-402F-85FC-159E2A699F86}resource=/crio_Analog Input/AI10;0{2D35E8FF-4702-415E-AB28-3A5B7FE9D2FC}resource=/crio_Analog Input/AI20;0{40A8C563-DFC9-4F0F-9BEB-751BAE38A111}resource=/Chassis Temperature;0{44AE0722-F21E-47F8-B3F1-9EDFB658AFE1}resource=/crio_Analog Input/AI4;0{514E31C0-5840-40F0-86F6-82C52887CE93}resource=/crio_Analog Input/AI2;0{5B43634A-8275-4452-918E-2791F755E902}resource=/crio_Analog Input/AI3;0{798CA07C-1650-4FB9-A7E6-51C564E42BD3}resource=/crio_Analog Input/AI22;0{98EF2994-0D1A-43AC-8356-AFA64B0A83A0}resource=/crio_Analog Input/AI5;0{9C6EBB5E-CB9D-4CC9-AD44-E87F6F95A19A}resource=/crio_Analog Input/AI25;0{A9C1A124-DF73-406B-B198-22713FA98D8C}resource=/crio_Analog Input/AI12;0{AED159E1-7C0D-4CFC-AE1D-4F928AFAEEDF}resource=/crio_Analog Input/AI13;0{B0CAD89F-AB17-41B3-B733-E51D51FA65A9}resource=/crio_Analog Input/DO0;0{BFDFD480-2E0E-482A-A531-209FBDE90C10}NI 9205,Slot 3,cRIOModule.AI0.TerminalMode=1,cRIOModule.AI0.VoltageRange=0,cRIOModule.AI1.TerminalMode=1,cRIOModule.AI1.VoltageRange=0,cRIOModule.AI10.TerminalMode=1,cRIOModule.AI10.VoltageRange=0,cRIOModule.AI11.TerminalMode=1,cRIOModule.AI11.VoltageRange=0,cRIOModule.AI12.TerminalMode=1,cRIOModule.AI12.VoltageRange=0,cRIOModule.AI13.TerminalMode=1,cRIOModule.AI13.VoltageRange=0,cRIOModule.AI14.TerminalMode=1,cRIOModule.AI14.VoltageRange=0,cRIOModule.AI15.TerminalMode=1,cRIOModule.AI15.VoltageRange=0,cRIOModule.AI16.TerminalMode=1,cRIOModule.AI16.VoltageRange=0,cRIOModule.AI17.TerminalMode=1,cRIOModule.AI17.VoltageRange=0,cRIOModule.AI18.TerminalMode=1,cRIOModule.AI18.VoltageRange=0,cRIOModule.AI19.TerminalMode=1,cRIOModule.AI19.VoltageRange=0,cRIOModule.AI2.TerminalMode=1,cRIOModule.AI2.VoltageRange=0,cRIOModule.AI20.TerminalMode=1,cRIOModule.AI20.VoltageRange=0,cRIOModule.AI21.TerminalMode=1,cRIOModule.AI21.VoltageRange=0,cRIOModule.AI22.TerminalMode=1,cRIOModule.AI22.VoltageRange=0,cRIOModule.AI23.TerminalMode=1,cRIOModule.AI23.VoltageRange=0,cRIOModule.AI24.TerminalMode=1,cRIOModule.AI24.VoltageRange=0,cRIOModule.AI25.TerminalMode=1,cRIOModule.AI25.VoltageRange=0,cRIOModule.AI26.TerminalMode=1,cRIOModule.AI26.VoltageRange=0,cRIOModule.AI27.TerminalMode=1,cRIOModule.AI27.VoltageRange=0,cRIOModule.AI28.TerminalMode=1,cRIOModule.AI28.VoltageRange=0,cRIOModule.AI29.TerminalMode=1,cRIOModule.AI29.VoltageRange=0,cRIOModule.AI3.TerminalMode=1,cRIOModule.AI3.VoltageRange=0,cRIOModule.AI30.TerminalMode=1,cRIOModule.AI30.VoltageRange=0,cRIOModule.AI31.TerminalMode=1,cRIOModule.AI31.VoltageRange=0,cRIOModule.AI4.TerminalMode=1,cRIOModule.AI4.VoltageRange=0,cRIOModule.AI5.TerminalMode=1,cRIOModule.AI5.VoltageRange=0,cRIOModule.AI6.TerminalMode=1,cRIOModule.AI6.VoltageRange=0,cRIOModule.AI7.TerminalMode=1,cRIOModule.AI7.VoltageRange=0,cRIOModule.AI8.TerminalMode=1,cRIOModule.AI8.VoltageRange=0,cRIOModule.AI9.TerminalMode=1,cRIOModule.AI9.VoltageRange=0,cRIOModule.EnableCalProperties=false,cRIOModule.MinConvTime=4,000000{C043EFE7-2F0D-4C92-AC89-35D429B4D99D}resource=/crio_Analog Input/AI24;0{C986363F-185A-4883-9E57-9A8EA76B49D7}resource=/crio_Analog Input/AI16;0{CE0A2E23-57F6-42F9-AA8F-D86383AEF6AD}resource=/crio_Analog Input/AI31;0{DC771EEF-E8EF-45C8-A461-564547EEEA1E}resource=/crio_Analog Input/AI9;0{E2C00401-FF59-468A-8418-AE509D43D7DC}resource=/crio_Analog Input/AI14;0{E5337E3A-78D7-442D-9E2E-6CA66F3FE23E}resource=/crio_Analog Input/AI7;0{F048F227-B850-4B40-BEB7-656D7A630965}resource=/crio_Analog Input/AI23;0{F21CBE26-D248-42BB-B3D5-D7922CA8F4E8}resource=/crio_Analog Input/AI11;0{F66BBA89-8867-4EAF-B8F3-C7AC961F06A1}resource=/crio_Analog Input/AI1;0{F6AFDFAD-036E-4AB9-BC20-A52D0B38E1A0}resource=/crio_Analog Input/AI19;0{F92E1DE6-35D5-4DAF-8A7E-13BEB4E0342D}resource=/crio_Analog Input/AI28;0{F99366DE-14F3-442C-8B01-157A7B961EC2}resource=/crio_Analog Input/AI15;0{FB72F47F-C145-4E98-90C4-71E9F5363541}resource=/crio_Analog Input/AI17;0cRIO-9101/Clk40/40 MHz Onboard ClocktrueTARGET_TYPEFPGA</Property>
         <Property Name="configString.name" Type="Str">40 MHz Onboard Clock###!!A!!!")!&amp;E!Q`````QV3:8.P&gt;8*D:3"/97VF!"R!-0````]36'^Q)&amp;.J:WZB&lt;#"$&lt;WZO:7.U!!!;1$$`````%5.M&lt;W.L)&amp;.J:WZB&lt;#"/97VF!"B!#B*.;7YA2H*F=86F&lt;G.Z)#B)?CE!!"B!#B*.98AA2H*F=86F&lt;G.Z)#B)?CE!!"B!)2*798*J97*M:3"'=G6R&gt;76O9XE!!"R!#B:/&lt;WVJ&lt;G&amp;M)%:S:8&amp;V:7ZD?3!I3(IJ!!!=1!I85'6B;S"1:8*J&lt;W1A3GFU&gt;'6S)#BQ=SE!(%!+&amp;UVJ&lt;C"%&gt;82Z)%.Z9WRF)#AF)%BJ:WAJ!"R!#B&gt;.98AA2(6U?3"$?7.M:3!I*3");7&gt;I+1!51!I/17.D&gt;8*B9XEA+("Q&lt;3E!!"*!)1R'=G6F)&amp;*V&lt;GZJ&lt;G=!!"2!)1^4=(*F971A5X"F9X2S&gt;7U!%E!Q`````QB$&lt;'^D;S"*2!!!/%"!!!(`````!!UK5G6M982F:#"$&lt;'^D;X-A&gt;WFU;#"O&lt;S"$2%-A9W^N=(-A&lt;G6D:8.T98*Z!!!31&amp;--2W6O:8*J9S"%982B!!!/1$$`````"5&amp;M;7&amp;T!']!]1!!!!!!!!!")'ZJ=H:J1G&amp;T:624382F&lt;5.P&lt;G:J:X6S982J&lt;WYO9X2M!%6!5!!1!!!!!1!#!!-!"!!&amp;!!9!"Q!)!!E!#A!,!!Q!$A!0!"!&lt;1X6S=G6O&gt;#"$&lt;'^D;S"$&lt;WZG;7&gt;V=G&amp;U;7^O!!%!%1!!!"1U-#".3(IA4WZC&lt;W&amp;S:#"$&lt;'^D;Q!!!!6$&lt;'MU-!!!!!6$&lt;'MU-%'$%N!!!!!!19-3U!!!!!!!19-3U!!!!!"!&lt;U!!!!!!!%"*!!!!!!!!1%E!!!!!!!"!71!!!!!!!!%!!!!!!!AAA!)!!!!"!!1!!!!"!!!!!!!!!!!!&amp;$1Q)%V)?C"0&lt;G*P98*E)%.M&lt;W.L!!!!!!AI0resource=/crio_Analog Input/AI0;0AI10resource=/crio_Analog Input/AI10;0AI11resource=/crio_Analog Input/AI11;0AI12resource=/crio_Analog Input/AI12;0AI13resource=/crio_Analog Input/AI13;0AI14resource=/crio_Analog Input/AI14;0AI15resource=/crio_Analog Input/AI15;0AI16resource=/crio_Analog Input/AI16;0AI17resource=/crio_Analog Input/AI17;0AI18resource=/crio_Analog Input/AI18;0AI19resource=/crio_Analog Input/AI19;0AI1resource=/crio_Analog Input/AI1;0AI20resource=/crio_Analog Input/AI20;0AI21resource=/crio_Analog Input/AI21;0AI22resource=/crio_Analog Input/AI22;0AI23resource=/crio_Analog Input/AI23;0AI24resource=/crio_Analog Input/AI24;0AI25resource=/crio_Analog Input/AI25;0AI26resource=/crio_Analog Input/AI26;0AI27resource=/crio_Analog Input/AI27;0AI28resource=/crio_Analog Input/AI28;0AI29resource=/crio_Analog Input/AI29;0AI2resource=/crio_Analog Input/AI2;0AI30resource=/crio_Analog Input/AI30;0AI31resource=/crio_Analog Input/AI31;0AI3resource=/crio_Analog Input/AI3;0AI4resource=/crio_Analog Input/AI4;0AI5resource=/crio_Analog Input/AI5;0AI6resource=/crio_Analog Input/AI6;0AI7resource=/crio_Analog Input/AI7;0AI8resource=/crio_Analog Input/AI8;0AI9resource=/crio_Analog Input/AI9;0Analog InputNI 9205,Slot 3,cRIOModule.AI0.TerminalMode=1,cRIOModule.AI0.VoltageRange=0,cRIOModule.AI1.TerminalMode=1,cRIOModule.AI1.VoltageRange=0,cRIOModule.AI10.TerminalMode=1,cRIOModule.AI10.VoltageRange=0,cRIOModule.AI11.TerminalMode=1,cRIOModule.AI11.VoltageRange=0,cRIOModule.AI12.TerminalMode=1,cRIOModule.AI12.VoltageRange=0,cRIOModule.AI13.TerminalMode=1,cRIOModule.AI13.VoltageRange=0,cRIOModule.AI14.TerminalMode=1,cRIOModule.AI14.VoltageRange=0,cRIOModule.AI15.TerminalMode=1,cRIOModule.AI15.VoltageRange=0,cRIOModule.AI16.TerminalMode=1,cRIOModule.AI16.VoltageRange=0,cRIOModule.AI17.TerminalMode=1,cRIOModule.AI17.VoltageRange=0,cRIOModule.AI18.TerminalMode=1,cRIOModule.AI18.VoltageRange=0,cRIOModule.AI19.TerminalMode=1,cRIOModule.AI19.VoltageRange=0,cRIOModule.AI2.TerminalMode=1,cRIOModule.AI2.VoltageRange=0,cRIOModule.AI20.TerminalMode=1,cRIOModule.AI20.VoltageRange=0,cRIOModule.AI21.TerminalMode=1,cRIOModule.AI21.VoltageRange=0,cRIOModule.AI22.TerminalMode=1,cRIOModule.AI22.VoltageRange=0,cRIOModule.AI23.TerminalMode=1,cRIOModule.AI23.VoltageRange=0,cRIOModule.AI24.TerminalMode=1,cRIOModule.AI24.VoltageRange=0,cRIOModule.AI25.TerminalMode=1,cRIOModule.AI25.VoltageRange=0,cRIOModule.AI26.TerminalMode=1,cRIOModule.AI26.VoltageRange=0,cRIOModule.AI27.TerminalMode=1,cRIOModule.AI27.VoltageRange=0,cRIOModule.AI28.TerminalMode=1,cRIOModule.AI28.VoltageRange=0,cRIOModule.AI29.TerminalMode=1,cRIOModule.AI29.VoltageRange=0,cRIOModule.AI3.TerminalMode=1,cRIOModule.AI3.VoltageRange=0,cRIOModule.AI30.TerminalMode=1,cRIOModule.AI30.VoltageRange=0,cRIOModule.AI31.TerminalMode=1,cRIOModule.AI31.VoltageRange=0,cRIOModule.AI4.TerminalMode=1,cRIOModule.AI4.VoltageRange=0,cRIOModule.AI5.TerminalMode=1,cRIOModule.AI5.VoltageRange=0,cRIOModule.AI6.TerminalMode=1,cRIOModule.AI6.VoltageRange=0,cRIOModule.AI7.TerminalMode=1,cRIOModule.AI7.VoltageRange=0,cRIOModule.AI8.TerminalMode=1,cRIOModule.AI8.VoltageRange=0,cRIOModule.AI9.TerminalMode=1,cRIOModule.AI9.VoltageRange=0,cRIOModule.EnableCalProperties=false,cRIOModule.MinConvTime=4,000000Chassis Temperatureresource=/Chassis Temperature;0cRIO-9101/Clk40/40 MHz Onboard ClocktrueTARGET_TYPEFPGADO0resource=/crio_Analog Input/DO0;0</Property>
         <Property Name="Mode" Type="Int">0</Property>
         <Property Name="NI.LV.FPGA.CompileConfigString" Type="Str">cRIO-9101/Clk40/40 MHz Onboard ClocktrueTARGET_TYPEFPGA</Property>
         <Property Name="NI.LV.FPGA.Version" Type="Int">3</Property>
         <Property Name="Resource Name" Type="Str">RIO0::INSTR</Property>
         <Property Name="Target Class" Type="Str">cRIO-9101</Property>
         <Property Name="Top-Level Timing Source" Type="Str">40 MHz Onboard Clock</Property>
         <Property Name="Top-Level Timing Source Is Default" Type="Bool">true</Property>
         <Item Name="Analog Input" Type="Folder">
            <Item Name="Analog Input" Type="Folder">
               <Item Name="AI0" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI0</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{1A27B268-740D-4F8A-9100-22B05AA5D386}</Property>
               </Item>
               <Item Name="AI1" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI1</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{F66BBA89-8867-4EAF-B8F3-C7AC961F06A1}</Property>
               </Item>
               <Item Name="AI2" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI2</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{514E31C0-5840-40F0-86F6-82C52887CE93}</Property>
               </Item>
               <Item Name="AI3" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI3</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{5B43634A-8275-4452-918E-2791F755E902}</Property>
               </Item>
               <Item Name="AI4" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI4</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{44AE0722-F21E-47F8-B3F1-9EDFB658AFE1}</Property>
               </Item>
               <Item Name="AI5" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI5</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{98EF2994-0D1A-43AC-8356-AFA64B0A83A0}</Property>
               </Item>
               <Item Name="AI6" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI6</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{0089E444-8567-4CC5-986C-D63689F34BB7}</Property>
               </Item>
               <Item Name="AI7" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI7</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{E5337E3A-78D7-442D-9E2E-6CA66F3FE23E}</Property>
               </Item>
               <Item Name="AI8" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI8</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{0FFFD7F8-C841-47D1-8F10-3AD0B988A75D}</Property>
               </Item>
               <Item Name="AI9" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI9</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{DC771EEF-E8EF-45C8-A461-564547EEEA1E}</Property>
               </Item>
               <Item Name="AI10" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI10</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{2CE879A1-A2A8-402F-85FC-159E2A699F86}</Property>
               </Item>
               <Item Name="AI11" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI11</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{F21CBE26-D248-42BB-B3D5-D7922CA8F4E8}</Property>
               </Item>
               <Item Name="AI12" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI12</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{A9C1A124-DF73-406B-B198-22713FA98D8C}</Property>
               </Item>
               <Item Name="AI13" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI13</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{AED159E1-7C0D-4CFC-AE1D-4F928AFAEEDF}</Property>
               </Item>
               <Item Name="AI14" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI14</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{E2C00401-FF59-468A-8418-AE509D43D7DC}</Property>
               </Item>
               <Item Name="AI15" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI15</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{F99366DE-14F3-442C-8B01-157A7B961EC2}</Property>
               </Item>
               <Item Name="AI16" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI16</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{C986363F-185A-4883-9E57-9A8EA76B49D7}</Property>
               </Item>
               <Item Name="AI17" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI17</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{FB72F47F-C145-4E98-90C4-71E9F5363541}</Property>
               </Item>
               <Item Name="AI18" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI18</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{1D934D2D-BF1D-47DF-AE79-5DBC469715F6}</Property>
               </Item>
               <Item Name="AI19" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI19</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{F6AFDFAD-036E-4AB9-BC20-A52D0B38E1A0}</Property>
               </Item>
               <Item Name="AI20" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI20</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{2D35E8FF-4702-415E-AB28-3A5B7FE9D2FC}</Property>
               </Item>
               <Item Name="AI21" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI21</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{0665BB1F-BB5C-4C39-B3DC-6A3BB6D7E6B9}</Property>
               </Item>
               <Item Name="AI22" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI22</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{798CA07C-1650-4FB9-A7E6-51C564E42BD3}</Property>
               </Item>
               <Item Name="AI23" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI23</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{F048F227-B850-4B40-BEB7-656D7A630965}</Property>
               </Item>
               <Item Name="AI24" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI24</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{C043EFE7-2F0D-4C92-AC89-35D429B4D99D}</Property>
               </Item>
               <Item Name="AI25" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI25</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{9C6EBB5E-CB9D-4CC9-AD44-E87F6F95A19A}</Property>
               </Item>
               <Item Name="AI26" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI26</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{0FE4D2A7-C0DE-4E60-A90D-D90ED6F0DD20}</Property>
               </Item>
               <Item Name="AI27" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI27</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{28F99611-7BF4-44A7-85FB-4EE8FC3DB326}</Property>
               </Item>
               <Item Name="AI28" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI28</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{F92E1DE6-35D5-4DAF-8A7E-13BEB4E0342D}</Property>
               </Item>
               <Item Name="AI29" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI29</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{0170B359-6D91-45A2-90B3-68A3A61C10E1}</Property>
               </Item>
               <Item Name="AI30" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI30</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{2AC7E091-3FCA-44A6-8CEE-B7A03873E931}</Property>
               </Item>
               <Item Name="AI31" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/AI31</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{CE0A2E23-57F6-42F9-AA8F-D86383AEF6AD}</Property>
               </Item>
            </Item>
         </Item>
         <Item Name="Digital Line Output" Type="Folder">
            <Item Name="Analog Input" Type="Folder">
               <Item Name="DO0" Type="Elemental IO">
                  <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/crio_Analog Input/DO0</Value>
   </Attribute>
</AttributeSet>
</Property>
                  <Property Name="FPGA.PersistentID" Type="Str">{B0CAD89F-AB17-41B3-B733-E51D51FA65A9}</Property>
               </Item>
            </Item>
         </Item>
         <Item Name="Chassis Temperature" Type="Elemental IO">
            <Property Name="eioAttrBag" Type="Xml"><AttributeSet name="FPGA Target">
   <Attribute name="resource">
   <Value>/Chassis Temperature</Value>
   </Attribute>
</AttributeSet>
</Property>
            <Property Name="FPGA.PersistentID" Type="Str">{40A8C563-DFC9-4F0F-9BEB-751BAE38A111}</Property>
         </Item>
         <Item Name="40 MHz Onboard Clock" Type="FPGA Base Clock">
            <Property Name="FPGA.PersistentID" Type="Str">{2832F320-BD29-428E-9344-23376A4A7054}</Property>
            <Property Name="NI.LV.FPGA.BaseTSConfig" Type="Bin">###!!A!!!")!&amp;E!Q`````QV3:8.P&gt;8*D:3"/97VF!"R!-0````]36'^Q)&amp;.J:WZB&lt;#"$&lt;WZO:7.U!!!;1$$`````%5.M&lt;W.L)&amp;.J:WZB&lt;#"/97VF!"B!#B*.;7YA2H*F=86F&lt;G.Z)#B)?CE!!"B!#B*.98AA2H*F=86F&lt;G.Z)#B)?CE!!"B!)2*798*J97*M:3"'=G6R&gt;76O9XE!!"R!#B:/&lt;WVJ&lt;G&amp;M)%:S:8&amp;V:7ZD?3!I3(IJ!!!=1!I85'6B;S"1:8*J&lt;W1A3GFU&gt;'6S)#BQ=SE!(%!+&amp;UVJ&lt;C"%&gt;82Z)%.Z9WRF)#AF)%BJ:WAJ!"R!#B&gt;.98AA2(6U?3"$?7.M:3!I*3");7&gt;I+1!51!I/17.D&gt;8*B9XEA+("Q&lt;3E!!"*!)1R'=G6F)&amp;*V&lt;GZJ&lt;G=!!"2!)1^4=(*F971A5X"F9X2S&gt;7U!%E!Q`````QB$&lt;'^D;S"*2!!!/%"!!!(`````!!UK5G6M982F:#"$&lt;'^D;X-A&gt;WFU;#"O&lt;S"$2%-A9W^N=(-A&lt;G6D:8.T98*Z!!!31&amp;--2W6O:8*J9S"%982B!!!/1$$`````"5&amp;M;7&amp;T!']!]1!!!!!!!!!")'ZJ=H:J1G&amp;T:624382F&lt;5.P&lt;G:J:X6S982J&lt;WYO9X2M!%6!5!!1!!!!!1!#!!-!"!!&amp;!!9!"Q!)!!E!#A!,!!Q!$A!0!"!&lt;1X6S=G6O&gt;#"$&lt;'^D;S"$&lt;WZG;7&gt;V=G&amp;U;7^O!!%!%1!!!"1U-#".3(IA4WZC&lt;W&amp;S:#"$&lt;'^D;Q!!!!6$&lt;'MU-!!!!!6$&lt;'MU-%'$%N!!!!!!19-3U!!!!!!!19-3U!!!!!"!&lt;U!!!!!!!%"*!!!!!!!!1%E!!!!!!!"!71!!!!!!!!%!!!!!!!AAA!)!!!!"!!1!!!!"!!!!!!!!!!!!&amp;$1Q)%V)?C"0&lt;G*P98*E)%.M&lt;W.L!!!!!!</Property>
            <Property Name="NI.LV.FPGA.Valid" Type="Bool">true</Property>
            <Property Name="NI.LV.FPGA.Version" Type="Int">2</Property>
         </Item>
         <Item Name="Analog Input" Type="RIO C Series Module">
            <Property Name="crio.Location" Type="Str">Slot 3</Property>
            <Property Name="crio.RequiresValidation" Type="Bool">false</Property>
            <Property Name="crio.SupportsDynamicRes" Type="Bool">false</Property>
            <Property Name="crio.Type" Type="Str">NI 9205</Property>
            <Property Name="cRIOModule.AI0.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI0.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI1.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI1.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI10.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI10.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI11.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI11.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI12.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI12.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI13.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI13.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI14.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI14.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI15.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI15.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI16.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI16.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI17.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI17.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI18.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI18.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI19.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI19.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI2.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI2.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI20.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI20.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI21.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI21.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI22.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI22.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI23.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI23.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI24.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI24.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI25.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI25.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI26.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI26.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI27.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI27.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI28.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI28.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI29.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI29.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI3.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI3.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI30.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI30.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI31.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI31.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI4.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI4.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI5.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI5.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI6.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI6.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI7.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI7.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI8.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI8.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.AI9.TerminalMode" Type="Str">1</Property>
            <Property Name="cRIOModule.AI9.VoltageRange" Type="Str">0</Property>
            <Property Name="cRIOModule.EnableCalProperties" Type="Str">false</Property>
            <Property Name="cRIOModule.MinConvTime" Type="Str">4,000000</Property>
            <Property Name="FPGA.PersistentID" Type="Str">{BFDFD480-2E0E-482A-A531-209FBDE90C10}</Property>
         </Item>
         <Item Name="fpga_noFifo.vi" Type="VI" URL="fpga_noFifo.vi">
            <Property Name="configString.guid" Type="Str">{0089E444-8567-4CC5-986C-D63689F34BB7}resource=/crio_Analog Input/AI6;0{0170B359-6D91-45A2-90B3-68A3A61C10E1}resource=/crio_Analog Input/AI29;0{0665BB1F-BB5C-4C39-B3DC-6A3BB6D7E6B9}resource=/crio_Analog Input/AI21;0{0FE4D2A7-C0DE-4E60-A90D-D90ED6F0DD20}resource=/crio_Analog Input/AI26;0{0FFFD7F8-C841-47D1-8F10-3AD0B988A75D}resource=/crio_Analog Input/AI8;0{1A27B268-740D-4F8A-9100-22B05AA5D386}resource=/crio_Analog Input/AI0;0{1D934D2D-BF1D-47DF-AE79-5DBC469715F6}resource=/crio_Analog Input/AI18;0{2832F320-BD29-428E-9344-23376A4A7054}###!!A!!!")!&amp;E!Q`````QV3:8.P&gt;8*D:3"/97VF!"R!-0````]36'^Q)&amp;.J:WZB&lt;#"$&lt;WZO:7.U!!!;1$$`````%5.M&lt;W.L)&amp;.J:WZB&lt;#"/97VF!"B!#B*.;7YA2H*F=86F&lt;G.Z)#B)?CE!!"B!#B*.98AA2H*F=86F&lt;G.Z)#B)?CE!!"B!)2*798*J97*M:3"'=G6R&gt;76O9XE!!"R!#B:/&lt;WVJ&lt;G&amp;M)%:S:8&amp;V:7ZD?3!I3(IJ!!!=1!I85'6B;S"1:8*J&lt;W1A3GFU&gt;'6S)#BQ=SE!(%!+&amp;UVJ&lt;C"%&gt;82Z)%.Z9WRF)#AF)%BJ:WAJ!"R!#B&gt;.98AA2(6U?3"$?7.M:3!I*3");7&gt;I+1!51!I/17.D&gt;8*B9XEA+("Q&lt;3E!!"*!)1R'=G6F)&amp;*V&lt;GZJ&lt;G=!!"2!)1^4=(*F971A5X"F9X2S&gt;7U!%E!Q`````QB$&lt;'^D;S"*2!!!/%"!!!(`````!!UK5G6M982F:#"$&lt;'^D;X-A&gt;WFU;#"O&lt;S"$2%-A9W^N=(-A&lt;G6D:8.T98*Z!!!31&amp;--2W6O:8*J9S"%982B!!!/1$$`````"5&amp;M;7&amp;T!']!]1!!!!!!!!!")'ZJ=H:J1G&amp;T:624382F&lt;5.P&lt;G:J:X6S982J&lt;WYO9X2M!%6!5!!1!!!!!1!#!!-!"!!&amp;!!9!"Q!)!!E!#A!,!!Q!$A!0!"!&lt;1X6S=G6O&gt;#"$&lt;'^D;S"$&lt;WZG;7&gt;V=G&amp;U;7^O!!%!%1!!!"1U-#".3(IA4WZC&lt;W&amp;S:#"$&lt;'^D;Q!!!!6$&lt;'MU-!!!!!6$&lt;'MU-%'$%N!!!!!!19-3U!!!!!!!19-3U!!!!!"!&lt;U!!!!!!!%"*!!!!!!!!1%E!!!!!!!"!71!!!!!!!!%!!!!!!!AAA!)!!!!"!!1!!!!"!!!!!!!!!!!!&amp;$1Q)%V)?C"0&lt;G*P98*E)%.M&lt;W.L!!!!!!{28F99611-7BF4-44A7-85FB-4EE8FC3DB326}resource=/crio_Analog Input/AI27;0{2AC7E091-3FCA-44A6-8CEE-B7A03873E931}resource=/crio_Analog Input/AI30;0{2CE879A1-A2A8-402F-85FC-159E2A699F86}resource=/crio_Analog Input/AI10;0{2D35E8FF-4702-415E-AB28-3A5B7FE9D2FC}resource=/crio_Analog Input/AI20;0{40A8C563-DFC9-4F0F-9BEB-751BAE38A111}resource=/Chassis Temperature;0{44AE0722-F21E-47F8-B3F1-9EDFB658AFE1}resource=/crio_Analog Input/AI4;0{514E31C0-5840-40F0-86F6-82C52887CE93}resource=/crio_Analog Input/AI2;0{5B43634A-8275-4452-918E-2791F755E902}resource=/crio_Analog Input/AI3;0{798CA07C-1650-4FB9-A7E6-51C564E42BD3}resource=/crio_Analog Input/AI22;0{98EF2994-0D1A-43AC-8356-AFA64B0A83A0}resource=/crio_Analog Input/AI5;0{9C6EBB5E-CB9D-4CC9-AD44-E87F6F95A19A}resource=/crio_Analog Input/AI25;0{A9C1A124-DF73-406B-B198-22713FA98D8C}resource=/crio_Analog Input/AI12;0{AED159E1-7C0D-4CFC-AE1D-4F928AFAEEDF}resource=/crio_Analog Input/AI13;0{B0CAD89F-AB17-41B3-B733-E51D51FA65A9}resource=/crio_Analog Input/DO0;0{BFDFD480-2E0E-482A-A531-209FBDE90C10}NI 9205,Slot 3,cRIOModule.AI0.TerminalMode=1,cRIOModule.AI0.VoltageRange=0,cRIOModule.AI1.TerminalMode=1,cRIOModule.AI1.VoltageRange=0,cRIOModule.AI10.TerminalMode=1,cRIOModule.AI10.VoltageRange=0,cRIOModule.AI11.TerminalMode=1,cRIOModule.AI11.VoltageRange=0,cRIOModule.AI12.TerminalMode=1,cRIOModule.AI12.VoltageRange=0,cRIOModule.AI13.TerminalMode=1,cRIOModule.AI13.VoltageRange=0,cRIOModule.AI14.TerminalMode=1,cRIOModule.AI14.VoltageRange=0,cRIOModule.AI15.TerminalMode=1,cRIOModule.AI15.VoltageRange=0,cRIOModule.AI16.TerminalMode=1,cRIOModule.AI16.VoltageRange=0,cRIOModule.AI17.TerminalMode=1,cRIOModule.AI17.VoltageRange=0,cRIOModule.AI18.TerminalMode=1,cRIOModule.AI18.VoltageRange=0,cRIOModule.AI19.TerminalMode=1,cRIOModule.AI19.VoltageRange=0,cRIOModule.AI2.TerminalMode=1,cRIOModule.AI2.VoltageRange=0,cRIOModule.AI20.TerminalMode=1,cRIOModule.AI20.VoltageRange=0,cRIOModule.AI21.TerminalMode=1,cRIOModule.AI21.VoltageRange=0,cRIOModule.AI22.TerminalMode=1,cRIOModule.AI22.VoltageRange=0,cRIOModule.AI23.TerminalMode=1,cRIOModule.AI23.VoltageRange=0,cRIOModule.AI24.TerminalMode=1,cRIOModule.AI24.VoltageRange=0,cRIOModule.AI25.TerminalMode=1,cRIOModule.AI25.VoltageRange=0,cRIOModule.AI26.TerminalMode=1,cRIOModule.AI26.VoltageRange=0,cRIOModule.AI27.TerminalMode=1,cRIOModule.AI27.VoltageRange=0,cRIOModule.AI28.TerminalMode=1,cRIOModule.AI28.VoltageRange=0,cRIOModule.AI29.TerminalMode=1,cRIOModule.AI29.VoltageRange=0,cRIOModule.AI3.TerminalMode=1,cRIOModule.AI3.VoltageRange=0,cRIOModule.AI30.TerminalMode=1,cRIOModule.AI30.VoltageRange=0,cRIOModule.AI31.TerminalMode=1,cRIOModule.AI31.VoltageRange=0,cRIOModule.AI4.TerminalMode=1,cRIOModule.AI4.VoltageRange=0,cRIOModule.AI5.TerminalMode=1,cRIOModule.AI5.VoltageRange=0,cRIOModule.AI6.TerminalMode=1,cRIOModule.AI6.VoltageRange=0,cRIOModule.AI7.TerminalMode=1,cRIOModule.AI7.VoltageRange=0,cRIOModule.AI8.TerminalMode=1,cRIOModule.AI8.VoltageRange=0,cRIOModule.AI9.TerminalMode=1,cRIOModule.AI9.VoltageRange=0,cRIOModule.EnableCalProperties=false,cRIOModule.MinConvTime=4,000000{C043EFE7-2F0D-4C92-AC89-35D429B4D99D}resource=/crio_Analog Input/AI24;0{C986363F-185A-4883-9E57-9A8EA76B49D7}resource=/crio_Analog Input/AI16;0{CE0A2E23-57F6-42F9-AA8F-D86383AEF6AD}resource=/crio_Analog Input/AI31;0{DC771EEF-E8EF-45C8-A461-564547EEEA1E}resource=/crio_Analog Input/AI9;0{E2C00401-FF59-468A-8418-AE509D43D7DC}resource=/crio_Analog Input/AI14;0{E5337E3A-78D7-442D-9E2E-6CA66F3FE23E}resource=/crio_Analog Input/AI7;0{F048F227-B850-4B40-BEB7-656D7A630965}resource=/crio_Analog Input/AI23;0{F21CBE26-D248-42BB-B3D5-D7922CA8F4E8}resource=/crio_Analog Input/AI11;0{F66BBA89-8867-4EAF-B8F3-C7AC961F06A1}resource=/crio_Analog Input/AI1;0{F6AFDFAD-036E-4AB9-BC20-A52D0B38E1A0}resource=/crio_Analog Input/AI19;0{F92E1DE6-35D5-4DAF-8A7E-13BEB4E0342D}resource=/crio_Analog Input/AI28;0{F99366DE-14F3-442C-8B01-157A7B961EC2}resource=/crio_Analog Input/AI15;0{FB72F47F-C145-4E98-90C4-71E9F5363541}resource=/crio_Analog Input/AI17;0cRIO-9101/Clk40/40 MHz Onboard ClocktrueTARGET_TYPEFPGA</Property>
            <Property Name="configString.name" Type="Str">40 MHz Onboard Clock###!!A!!!")!&amp;E!Q`````QV3:8.P&gt;8*D:3"/97VF!"R!-0````]36'^Q)&amp;.J:WZB&lt;#"$&lt;WZO:7.U!!!;1$$`````%5.M&lt;W.L)&amp;.J:WZB&lt;#"/97VF!"B!#B*.;7YA2H*F=86F&lt;G.Z)#B)?CE!!"B!#B*.98AA2H*F=86F&lt;G.Z)#B)?CE!!"B!)2*798*J97*M:3"'=G6R&gt;76O9XE!!"R!#B:/&lt;WVJ&lt;G&amp;M)%:S:8&amp;V:7ZD?3!I3(IJ!!!=1!I85'6B;S"1:8*J&lt;W1A3GFU&gt;'6S)#BQ=SE!(%!+&amp;UVJ&lt;C"%&gt;82Z)%.Z9WRF)#AF)%BJ:WAJ!"R!#B&gt;.98AA2(6U?3"$?7.M:3!I*3");7&gt;I+1!51!I/17.D&gt;8*B9XEA+("Q&lt;3E!!"*!)1R'=G6F)&amp;*V&lt;GZJ&lt;G=!!"2!)1^4=(*F971A5X"F9X2S&gt;7U!%E!Q`````QB$&lt;'^D;S"*2!!!/%"!!!(`````!!UK5G6M982F:#"$&lt;'^D;X-A&gt;WFU;#"O&lt;S"$2%-A9W^N=(-A&lt;G6D:8.T98*Z!!!31&amp;--2W6O:8*J9S"%982B!!!/1$$`````"5&amp;M;7&amp;T!']!]1!!!!!!!!!")'ZJ=H:J1G&amp;T:624382F&lt;5.P&lt;G:J:X6S982J&lt;WYO9X2M!%6!5!!1!!!!!1!#!!-!"!!&amp;!!9!"Q!)!!E!#A!,!!Q!$A!0!"!&lt;1X6S=G6O&gt;#"$&lt;'^D;S"$&lt;WZG;7&gt;V=G&amp;U;7^O!!%!%1!!!"1U-#".3(IA4WZC&lt;W&amp;S:#"$&lt;'^D;Q!!!!6$&lt;'MU-!!!!!6$&lt;'MU-%'$%N!!!!!!19-3U!!!!!!!19-3U!!!!!"!&lt;U!!!!!!!%"*!!!!!!!!1%E!!!!!!!"!71!!!!!!!!%!!!!!!!AAA!)!!!!"!!1!!!!"!!!!!!!!!!!!&amp;$1Q)%V)?C"0&lt;G*P98*E)%.M&lt;W.L!!!!!!AI0resource=/crio_Analog Input/AI0;0AI10resource=/crio_Analog Input/AI10;0AI11resource=/crio_Analog Input/AI11;0AI12resource=/crio_Analog Input/AI12;0AI13resource=/crio_Analog Input/AI13;0AI14resource=/crio_Analog Input/AI14;0AI15resource=/crio_Analog Input/AI15;0AI16resource=/crio_Analog Input/AI16;0AI17resource=/crio_Analog Input/AI17;0AI18resource=/crio_Analog Input/AI18;0AI19resource=/crio_Analog Input/AI19;0AI1resource=/crio_Analog Input/AI1;0AI20resource=/crio_Analog Input/AI20;0AI21resource=/crio_Analog Input/AI21;0AI22resource=/crio_Analog Input/AI22;0AI23resource=/crio_Analog Input/AI23;0AI24resource=/crio_Analog Input/AI24;0AI25resource=/crio_Analog Input/AI25;0AI26resource=/crio_Analog Input/AI26;0AI27resource=/crio_Analog Input/AI27;0AI28resource=/crio_Analog Input/AI28;0AI29resource=/crio_Analog Input/AI29;0AI2resource=/crio_Analog Input/AI2;0AI30resource=/crio_Analog Input/AI30;0AI31resource=/crio_Analog Input/AI31;0AI3resource=/crio_Analog Input/AI3;0AI4resource=/crio_Analog Input/AI4;0AI5resource=/crio_Analog Input/AI5;0AI6resource=/crio_Analog Input/AI6;0AI7resource=/crio_Analog Input/AI7;0AI8resource=/crio_Analog Input/AI8;0AI9resource=/crio_Analog Input/AI9;0Analog InputNI 9205,Slot 3,cRIOModule.AI0.TerminalMode=1,cRIOModule.AI0.VoltageRange=0,cRIOModule.AI1.TerminalMode=1,cRIOModule.AI1.VoltageRange=0,cRIOModule.AI10.TerminalMode=1,cRIOModule.AI10.VoltageRange=0,cRIOModule.AI11.TerminalMode=1,cRIOModule.AI11.VoltageRange=0,cRIOModule.AI12.TerminalMode=1,cRIOModule.AI12.VoltageRange=0,cRIOModule.AI13.TerminalMode=1,cRIOModule.AI13.VoltageRange=0,cRIOModule.AI14.TerminalMode=1,cRIOModule.AI14.VoltageRange=0,cRIOModule.AI15.TerminalMode=1,cRIOModule.AI15.VoltageRange=0,cRIOModule.AI16.TerminalMode=1,cRIOModule.AI16.VoltageRange=0,cRIOModule.AI17.TerminalMode=1,cRIOModule.AI17.VoltageRange=0,cRIOModule.AI18.TerminalMode=1,cRIOModule.AI18.VoltageRange=0,cRIOModule.AI19.TerminalMode=1,cRIOModule.AI19.VoltageRange=0,cRIOModule.AI2.TerminalMode=1,cRIOModule.AI2.VoltageRange=0,cRIOModule.AI20.TerminalMode=1,cRIOModule.AI20.VoltageRange=0,cRIOModule.AI21.TerminalMode=1,cRIOModule.AI21.VoltageRange=0,cRIOModule.AI22.TerminalMode=1,cRIOModule.AI22.VoltageRange=0,cRIOModule.AI23.TerminalMode=1,cRIOModule.AI23.VoltageRange=0,cRIOModule.AI24.TerminalMode=1,cRIOModule.AI24.VoltageRange=0,cRIOModule.AI25.TerminalMode=1,cRIOModule.AI25.VoltageRange=0,cRIOModule.AI26.TerminalMode=1,cRIOModule.AI26.VoltageRange=0,cRIOModule.AI27.TerminalMode=1,cRIOModule.AI27.VoltageRange=0,cRIOModule.AI28.TerminalMode=1,cRIOModule.AI28.VoltageRange=0,cRIOModule.AI29.TerminalMode=1,cRIOModule.AI29.VoltageRange=0,cRIOModule.AI3.TerminalMode=1,cRIOModule.AI3.VoltageRange=0,cRIOModule.AI30.TerminalMode=1,cRIOModule.AI30.VoltageRange=0,cRIOModule.AI31.TerminalMode=1,cRIOModule.AI31.VoltageRange=0,cRIOModule.AI4.TerminalMode=1,cRIOModule.AI4.VoltageRange=0,cRIOModule.AI5.TerminalMode=1,cRIOModule.AI5.VoltageRange=0,cRIOModule.AI6.TerminalMode=1,cRIOModule.AI6.VoltageRange=0,cRIOModule.AI7.TerminalMode=1,cRIOModule.AI7.VoltageRange=0,cRIOModule.AI8.TerminalMode=1,cRIOModule.AI8.VoltageRange=0,cRIOModule.AI9.TerminalMode=1,cRIOModule.AI9.VoltageRange=0,cRIOModule.EnableCalProperties=false,cRIOModule.MinConvTime=4,000000Chassis Temperatureresource=/Chassis Temperature;0cRIO-9101/Clk40/40 MHz Onboard ClocktrueTARGET_TYPEFPGADO0resource=/crio_Analog Input/DO0;0</Property>
            <Property Name="NI.LV.FPGA.InterfaceBitfile" Type="Str">C:\Documents and Settings\kevin\Dokumenter\unicorn\v0.1\FPGA Bitfiles\test.lvproj_FPGA Target_fpga_noFifo.vi.lvbit</Property>
         </Item>
         <Item Name="Dependencies" Type="Dependencies"/>
         <Item Name="Build Specifications" Type="Build">
            <Item Name="My Source Distribution" Type="Source Distribution">
               <Property Name="Absolute[0]" Type="Bool">false</Property>
               <Property Name="Absolute[1]" Type="Bool">false</Property>
               <Property Name="BuildName" Type="Str">My Source Distribution</Property>
               <Property Name="DependencyApplyDestination" Type="Bool">true</Property>
               <Property Name="DependencyApplyInclusion" Type="Bool">true</Property>
               <Property Name="DependencyApplyPassword" Type="Bool">true</Property>
               <Property Name="DependencyApplyProperties" Type="Bool">true</Property>
               <Property Name="DependencyFolderDestination" Type="Int">0</Property>
               <Property Name="DependencyFolderInclusion" Type="Str">As Needed</Property>
               <Property Name="DependencyFolderMask" Type="Str">Default</Property>
               <Property Name="DependencyFolderPasswordSetting" Type="Str">No Password Change</Property>
               <Property Name="DependencyFolderPasswordToApply" Type="Str"></Property>
               <Property Name="DependencyFolderPropertiesItemCount" Type="Int">0</Property>
               <Property Name="DependencyFolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="DestinationID[0]" Type="Str">{B28F1F8D-44DF-4723-995E-AEA6B41E67BE}</Property>
               <Property Name="DestinationID[1]" Type="Str">{1B148A56-2906-4662-AD08-72CB93C49E74}</Property>
               <Property Name="DestinationItemCount" Type="Int">2</Property>
               <Property Name="DestinationName[0]" Type="Str">Destination Directory</Property>
               <Property Name="DestinationName[1]" Type="Str">Support Directory</Property>
               <Property Name="DestinationOption" Type="Str">Single Destination</Property>
               <Property Name="Disconnect" Type="Bool">false</Property>
               <Property Name="ExcludeInstrLib" Type="Bool">true</Property>
               <Property Name="ExcludeUserLib" Type="Bool">true</Property>
               <Property Name="ExcludeVILIB" Type="Bool">true</Property>
               <Property Name="Path[0]" Type="Path">../../builds/test/My Source Distribution</Property>
               <Property Name="Path[1]" Type="Path">../../builds/test/My Source Distribution/data</Property>
               <Property Name="SourceInfoItemCount" Type="Int">41</Property>
               <Property Name="SourceItem[0].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[0].IsFolder" Type="Bool">true</Property>
               <Property Name="SourceItem[0].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']</Property>
               <Property Name="SourceItem[0].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[1].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[1].IsFolder" Type="Bool">true</Property>
               <Property Name="SourceItem[1].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input</Property>
               <Property Name="SourceItem[1].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[10].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[10].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI8</Property>
               <Property Name="SourceItem[10].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[11].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[11].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI9</Property>
               <Property Name="SourceItem[11].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[12].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[12].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI10</Property>
               <Property Name="SourceItem[12].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[13].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[13].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI11</Property>
               <Property Name="SourceItem[13].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[14].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[14].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI12</Property>
               <Property Name="SourceItem[14].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[15].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[15].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI13</Property>
               <Property Name="SourceItem[15].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[16].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[16].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI14</Property>
               <Property Name="SourceItem[16].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[17].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[17].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI15</Property>
               <Property Name="SourceItem[17].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[18].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[18].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI16</Property>
               <Property Name="SourceItem[18].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[19].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[19].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI17</Property>
               <Property Name="SourceItem[19].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[2].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[2].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI0</Property>
               <Property Name="SourceItem[2].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[20].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[20].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI18</Property>
               <Property Name="SourceItem[20].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[21].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[21].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI19</Property>
               <Property Name="SourceItem[21].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[22].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[22].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI20</Property>
               <Property Name="SourceItem[22].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[23].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[23].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI21</Property>
               <Property Name="SourceItem[23].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[24].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[24].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI22</Property>
               <Property Name="SourceItem[24].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[25].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[25].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI23</Property>
               <Property Name="SourceItem[25].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[26].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[26].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI24</Property>
               <Property Name="SourceItem[26].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[27].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[27].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI25</Property>
               <Property Name="SourceItem[27].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[28].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[28].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI26</Property>
               <Property Name="SourceItem[28].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[29].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[29].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI27</Property>
               <Property Name="SourceItem[29].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[3].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[3].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI1</Property>
               <Property Name="SourceItem[3].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[30].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[30].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI28</Property>
               <Property Name="SourceItem[30].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[31].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[31].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI29</Property>
               <Property Name="SourceItem[31].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[32].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[32].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI30</Property>
               <Property Name="SourceItem[32].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[33].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[33].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI31</Property>
               <Property Name="SourceItem[33].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[34].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[34].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Chassis Temperature</Property>
               <Property Name="SourceItem[34].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[35].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[35].IsFolder" Type="Bool">true</Property>
               <Property Name="SourceItem[35].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Digital Line Output</Property>
               <Property Name="SourceItem[35].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[36].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[36].IsFolder" Type="Bool">true</Property>
               <Property Name="SourceItem[36].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Digital Line Output/Analog Input</Property>
               <Property Name="SourceItem[36].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[37].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[37].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Digital Line Output/Analog Input/DO0</Property>
               <Property Name="SourceItem[37].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[38].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[38].IsFolder" Type="Bool">true</Property>
               <Property Name="SourceItem[38].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/40 MHz Onboard Clock</Property>
               <Property Name="SourceItem[38].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[39].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[39].IsFolder" Type="Bool">true</Property>
               <Property Name="SourceItem[39].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='RIO C Series Module']</Property>
               <Property Name="SourceItem[39].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[4].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[4].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI2</Property>
               <Property Name="SourceItem[4].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[40].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[40].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/fpga_noFifo.vi</Property>
               <Property Name="SourceItem[40].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[40].VIPropertiesItemCount" Type="Int">2</Property>
               <Property Name="SourceItem[40].VIPropertiesSettingOption[0]" Type="Str">Remove panel</Property>
               <Property Name="SourceItem[40].VIPropertiesSettingOption[1]" Type="Str">Remove diagram</Property>
               <Property Name="SourceItem[40].VIPropertiesVISetting[0]" Type="Bool">false</Property>
               <Property Name="SourceItem[40].VIPropertiesVISetting[1]" Type="Bool">false</Property>
               <Property Name="SourceItem[5].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[5].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI3</Property>
               <Property Name="SourceItem[5].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[6].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[6].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI4</Property>
               <Property Name="SourceItem[6].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[7].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[7].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI5</Property>
               <Property Name="SourceItem[7].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[8].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[8].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI6</Property>
               <Property Name="SourceItem[8].TopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[9].FolderTopLevelVI" Type="Str">Never</Property>
               <Property Name="SourceItem[9].ItemID" Type="Ref">/NI-Unicorn/FPGA Target/Item[@Label='Analog Input' and @Type='Folder']/Analog Input/AI7</Property>
               <Property Name="SourceItem[9].TopLevelVI" Type="Str">Never</Property>
               <Property Name="StripLib" Type="Bool">false</Property>
            </Item>
         </Item>
      </Item>
      <Item Name="host_noFifo.vi" Type="VI" URL="host_noFifo.vi"/>
      <Item Name="Dependencies" Type="Dependencies"/>
      <Item Name="Build Specifications" Type="Build">
         <Item Name="My Real-Time Application" Type="{69A947D5-514E-4E75-818E-69657C0547D8}">
            <Property Name="Absolute[0]" Type="Bool">true</Property>
            <Property Name="Absolute[1]" Type="Bool">true</Property>
            <Property Name="Absolute[2]" Type="Bool">true</Property>
            <Property Name="AliasName" Type="Str">Project.aliases</Property>
            <Property Name="ApplicationID" Type="Str">{0CCA9E21-7FDF-4EFA-A694-1FDCA39120A1}</Property>
            <Property Name="ApplicationName" Type="Str">startup.rtexe</Property>
            <Property Name="BuildName" Type="Str">My Real-Time Application</Property>
            <Property Name="CommandLineArguments" Type="Bool">false</Property>
            <Property Name="CopyErrors" Type="Bool">false</Property>
            <Property Name="DebuggingEXE" Type="Bool">false</Property>
            <Property Name="DependencyApplyDestination" Type="Bool">true</Property>
            <Property Name="DependencyApplyInclusion" Type="Bool">true</Property>
            <Property Name="DependencyApplyProperties" Type="Bool">true</Property>
            <Property Name="DependencyFolderDestination" Type="Int">0</Property>
            <Property Name="DependencyFolderInclusion" Type="Str">As needed</Property>
            <Property Name="DependencyFolderPropertiesItemCount" Type="Int">0</Property>
            <Property Name="DestinationID[0]" Type="Str">{FAAD36FA-0A9E-4024-A52A-C01C23693741}</Property>
            <Property Name="DestinationID[1]" Type="Str">{FAAD36FA-0A9E-4024-A52A-C01C23693741}</Property>
            <Property Name="DestinationID[2]" Type="Str">{D60EF052-4920-43DD-A59A-21C9AA041CA6}</Property>
            <Property Name="DestinationItemCount" Type="Int">3</Property>
            <Property Name="DestinationName[0]" Type="Str">startup.rtexe</Property>
            <Property Name="DestinationName[1]" Type="Str">Destination Directory</Property>
            <Property Name="DestinationName[2]" Type="Str">Support Directory</Property>
            <Property Name="Disconnect" Type="Bool">true</Property>
            <Property Name="IncludeHWConfig" Type="Bool">false</Property>
            <Property Name="LocalDestAbsolute" Type="Bool">false</Property>
            <Property Name="LocalDestination" Type="Path">../../builds/test/My Real-Time Application</Property>
            <Property Name="Path[0]" Type="Path">/c/ni-rt/startup/internal.llb</Property>
            <Property Name="Path[1]" Type="Path">/c/ni-rt/startup</Property>
            <Property Name="Path[2]" Type="Path">/c/ni-rt/startup/data</Property>
            <Property Name="ShowHWConfig" Type="Bool">false</Property>
            <Property Name="SourceInfoItemCount" Type="Int">1</Property>
            <Property Name="SourceItem[0].Inclusion" Type="Str">Startup VI</Property>
            <Property Name="SourceItem[0].ItemID" Type="Ref">/NI-Unicorn/host_noFifo.vi</Property>
            <Property Name="SourceItem[0].VIPropertiesItemCount" Type="Int">1</Property>
            <Property Name="SourceItem[0].VIPropertiesSettingOption[0]" Type="Str">Remove panel</Property>
            <Property Name="SourceItem[0].VIPropertiesVISetting[0]" Type="Bool">false</Property>
            <Property Name="StripLib" Type="Bool">true</Property>
         </Item>
      </Item>
   </Item>
</Project>
