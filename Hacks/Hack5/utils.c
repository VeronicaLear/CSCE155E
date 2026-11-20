/**
 * Author: Veronica Lear
 *
 * Date: 2026/10/01
 *
 * Defining the functions declared in utils.h
 * for air resitance and time elapsed
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>

 #include "utils.h"

 double degreesToRadians(double degree) {
    return degree / 180.0 * M_PI;
 }


double getAirDistance(double originLatitude, double originLongitude, double destinationLatitude, double destinationLongitude) {
    const double radiusOfEarth = 6371;
    double originLatitudeRad = degreesToRadians(originLatitude);
    double originLongitudeRad = degreesToRadians(originLongitude);
    double destinationLatitudeRad = degreesToRadians(destinationLatitude);
    double destinationLongitudeRad = degreesToRadians(destinationLongitude);

    double changeLongitude = destinationLongitudeRad - originLongitudeRad;

    double distance = acos(sin(originLatitudeRad) * sin(destinationLatitudeRad) + cos(originLatitudeRad) *
        cos(destinationLatitudeRad) * cos(changeLongitude)) * radiusOfEarth;
    return distance;
}


double lorentzTimeDilation(double t, double percentC){
    return t / (sqrt(1 - percentC * percentC));
}
