/**
 * Author: Veronica Lear
 *
 * Date: 2026/10/01
 *
 * Declaring and documenting the functions
 */

/**
 * Converts degrees to radians using the
 * formula: (d * pi) / 180
 */
 double degreesToRadians(double degree);

 /**
  * Computes the air distance between two coordinates
  * using the formula: d=arccos(sin(φ1)sin(φ2)+cos(φ1)cos(φ2)cos(Δ))⋅R
  */
double getAirDistance(double originLatitude, double originLongitude, double destinationLatitude, double destinationLongitude);

/**
 * Lorentz equation: T=t/(1−(v^2/c^2))
 * Uses that formula to compute the dialated time where v^2/c^2
 * is represented as percent C
 */
double lorentzTimeDilation(double t, double percentC);
