using System;
using System.Collections.Generic;
using System.Drawing;
using System.Text;
using System.Globalization;

namespace Unicorn
{
    public struct geoCoord
    {
        public double latitude;
        public double longtitude;

        public geoCoord(double lat, double longt)
        {
            latitude = lat;
            longtitude = longt;
        }
    };

    public class MapProjection
    {

       

        private const double DEGREEStoRADIANS = Math.PI / 180;

        public double geoXfactor;
        public double geoYfactor;

        public geoCoord geoZero;
        
        public MapProjection()
        { 
        
        }

        public void setfactors(geoCoord geoUL, geoCoord geoLR, int bmpWidth, int bmpHeight)
        {
            geoZero = geoUL;
            geoXfactor = (geoLR.longtitude - geoUL.longtitude) / bmpWidth;
            geoYfactor = (geoLR.latitude - geoUL.latitude) / bmpHeight;
        }

        //public int topixels(double north, double east)

        public geoCoord toGeoCoords(Point xyPoint)
        {
            geoCoord result = new geoCoord();

            result.longtitude = (xyPoint.X * geoXfactor) + geoZero.longtitude;
            result.latitude = (xyPoint.Y * geoYfactor) + geoZero.latitude;

            return result;

        }

        public Point toPixels(geoCoord geoC)
        {
            Point result = new Point();

            result.X = Convert.ToInt16((geoC.longtitude - geoZero.longtitude) / geoXfactor, CultureInfo.InvariantCulture);
            result.Y = Convert.ToInt16((geoC.latitude - geoZero.latitude) / geoYfactor, CultureInfo.InvariantCulture);
            
            return result;

        }
    }
}
