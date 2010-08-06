package GUI_telemetry;

public class dataStore {

    txtData txtDataLabel;
    GrafPlot graph;
    GrafPlot graph2;
    GrafPlot graph3;
    wheelAngle wheel0;
    speedAnalog Analog;
    speedAnalogSimple RPM;
    lambda lambda0;
    barData pedalPos;
    accPlot acc;

    // Data
    private String[] dataArray;
    int speedanalog = 0;
    int angle = 0;

    // Fir filter
    IIRFilter dataFilter1 = null;
    //IIRFilter dataFilter2 = null;
    //IIRFilter dataFilter3 = null;

    public dataStore(txtData txtDataLabel, GrafPlot graph, GrafPlot graph2, GrafPlot graph3, speedAnalog Analog, wheelAngle wheel0 , speedAnalogSimple speedSimple0, lambda lambda0, barData pedalPos, accPlot acc)
    {
        this.txtDataLabel = txtDataLabel;
        this.graph = graph;
        this.graph2 = graph2;
        this.graph3 = graph3;
        this.wheel0 = wheel0;
        this.Analog = Analog;
        this.RPM = speedSimple0;
        this.lambda0 = lambda0;
        this.pedalPos = pedalPos;
        this.acc = acc;

        // Data Filter 
        dataFilter1 = new IIRFilter(0.05);
        //dataFilter2 = new IIRFilter(0.5);
        //dataFilter3 = new IIRFilter(0.5);
    }

    public void setData(String dataString)
    {
        dataArray = dataString.split(",");

        // Opdatering af data tekst
        //txtDataLabel.setData(1, Integer.parseInt(dataArray[1])); // Speed
        //txtDataLabel.setData(2, Integer.parseInt(dataArray[1])); // Steering
        //txtDataLabel.setData(3, Integer.parseInt(dataArray[2])); // Break
        //txtDataLabel.setData(4, Integer.parseInt(dataArray[3])); // Clutch

        // Opdatering af analog hastighed
  //      Analog.setData(Integer.parseInt(dataArray[1]));

        // Opdatering af analog RPM
        RPM.setData(Integer.parseInt(dataArray[0]));

        // Lambda
        //lambda0.setLambda(Integer.parseInt(dataArray[7]));

        // Pedal postion
        pedalPos.setBarData(Integer.parseInt(dataArray[5]),0,0);

        // Test
//       graph.updateData(Integer.parseInt(dataArray[5])/3);
//       graph2.updateData(Integer.parseInt(dataArray[6]));
        graph3.updateData(Integer.parseInt(dataArray[2]));
//       wheel0.setAngle(Integer.parseInt(dataArray[1]));
//        acc.setAcc(Integer.parseInt(dataArray[2]), Integer.parseInt(dataArray[2]));


        /*
        if(datanr == 5)
        {
            this.speedanalog = data;
            angle = (int)((25 * Math.cos(8*speedanalog*3*(3.14/180))) +25);
            graph.updateData(angle);
            graph2.updateData(angle);
            graph3.updateData(angle);
            Analog.setData(speedanalog);
            //Analog1.setData(speedanalog);
            wheel0.setAngle(angle+30);
            wheel1.setAngle(angle+30);
            speedSimple0.setData(speedanalog);
        }

       switch(datanr)
        {
            case 1:  this.speed = data; txtDataLabel.setData(1, speed); break;
            case 2:  this.steering = data; txtDataLabel.setData(2, steering); break;
            case 3:  this.breake = data; txtDataLabel.setData(3, breake); break;
            case 4:  this.clutch = data; txtDataLabel.setData(4, clutch); break;
        }
         */

    }
}
