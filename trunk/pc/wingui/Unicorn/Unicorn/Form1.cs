using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
using System.Globalization;

namespace Unicorn
{
    public partial class Form1 : Form
    {
        float SweepAngle = 0;

        geoCoord curGPSpos = new geoCoord(1,1);
        
        TcpClient client = new TcpClient();
        NetworkStream clientStream;

        Bitmap bitmap;
 
        private MapProjection projector = new MapProjection();

        bool maploaded = false;
        
        public Form1()
        {
            InitializeComponent();
            /*SetStyle(ControlStyles.DoubleBuffer, true);
            SetStyle(ControlStyles.UserPaint, true);
            SetStyle(ControlStyles.AllPaintingInWmPaint, true);*/
        }

        public void loadmap()
        {

            geoCoord geoUL = new geoCoord(57.0160664000034, 9.98245239257813);
            geoCoord geoLR = new geoCoord(57.0123292193698, 9.98931650072336); 

            bitmap = new Bitmap("test.jpg");

            projector.setfactors(geoUL, geoLR, img.Size.Width, img.Size.Height);

            maploaded = true;
            img.Invalidate();

        }

        private void loadbtn_Click(object sender, EventArgs e)
        {
            loadmap();
        }

        private void img_Paint(object sender, PaintEventArgs e)
        {
 
            if (maploaded)
            {
                Brush brush = new SolidBrush(Color.Red);

                e.Graphics.DrawImage(bitmap, 0, 0, img.Size.Width, img.Size.Height);
                if (curGPSpos.latitude > 1) e.Graphics.FillEllipse(brush, projector.toPixels(curGPSpos).X, projector.toPixels(curGPSpos).Y, 20, 20);
            }
        }

        private void img_MouseMove(object sender, MouseEventArgs e)
        {
            labelMouse.Text = "Mouse X:" + e.X.ToString() + " Y:" + e.Y.ToString();

            geoCoord geoMouse = new geoCoord();

            geoMouse = projector.toGeoCoords(e.Location);

            labelLongLat.Text = "Lat:" + geoMouse.latitude.ToString() + " Long:" + geoMouse.longtitude.ToString();
        }

        private void connbtn_Click(object sender, EventArgs e)
        {
            IPEndPoint serverEndPoint = new IPEndPoint(IPAddress.Parse("192.168.1.1"), 2947);

            client.Connect(serverEndPoint);

            clientStream = client.GetStream();

            timer1.Enabled = true;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            int bytesRead = 0;
            string gpsdata;
            ASCIIEncoding encoder = new ASCIIEncoding();

            byte[] readbuf = new byte[4096];
            byte[] buffer = encoder.GetBytes("P\n");

            clientStream.Write(buffer, 0, buffer.Length);
            clientStream.Flush();

            bytesRead = clientStream.Read(readbuf, 0, 4096);

            gpsdata = encoder.GetString(readbuf, 0, bytesRead);

            geoCoord GPSCoord = new geoCoord();
            GPSCoord = parseGPSdata(gpsdata);
            curGPSpos = GPSCoord;
            toolStripStatusLabel1.Text = "long:" + GPSCoord.longtitude.ToString() + " lat:" + GPSCoord.latitude.ToString();
            img.Invalidate();
        }

        private geoCoord parseGPSdata(string rawdata)
        {
            geoCoord result = new geoCoord(0,0);

            if (rawdata.IndexOf("?") == -1)
            {

                int start = rawdata.IndexOf("=", 0);
                rawdata = rawdata.Substring(start + 1);

                result.longtitude = Convert.ToDouble(rawdata.Split(' ')[1], CultureInfo.InvariantCulture);
                result.latitude = Convert.ToDouble(rawdata.Split(' ')[0], CultureInfo.InvariantCulture);
            }

            return result;
        }

        private void speedoBox_Paint(object sender, PaintEventArgs e)
        {
            SweepAngle += 1F;
            
            Pen pen = new Pen(Color.Red, 20);

            Rectangle rect = new Rectangle(50,50,500,500);

            e.Graphics.DrawArc(pen, rect, 180F, SweepAngle);
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            speedoBox.Invalidate();
        }

    }
}
