/**
 * Author: Veronica Lear
 * Date: 2026/11/10
 *
 * Eathquake data collection and editing
 * using structures
*/

#ifndef EARTHQUAKE_H
#define EARTHQUAKE_H

/**
 * Structure to hold various types of data
 * for a specefic earthquake
 */
typedef struct {
  char *id;
  char *locationName;
  double magnitude;
  int significance;
  long timestamp;
  double latitude;
  double longitude;
  double depth;
} EarthquakeData;

/**
 * Error code for the functions
 */
typedef enum {
  NO_ERROR,
  NULL_POINTER,
  INVALID_NUM
} ErrorCode;

/**
 * An initialization function to initialize an instance of
 * <code>EarthquakeData</code> with the given values.
 */
int initEarthquakeData(EarthquakeData *data,
  const char *id,
  const char *locationName,
  double magnitude,
  int significance,
  long timestamp,
  double latitude,
  double longitude,
  double depth);

/**
 * A factory function to create an instance of
 * <code>EarthquakeData</code> with the given values.
 */
EarthquakeData *createEarthquakeData(
  const char *id,
  const char *locationName,
  double magnitude,
  int significance,
  long timestamp,
  double latitude,
  double longitude,
  double depth);

/**
 * A function to construct a (human-readable) string representation
 * of the given <code>EarthquakeData</code> instance.
 */
char *earthquakeDataToString(const EarthquakeData *data);

/**
 * Prints a human-readable representation of the given
 * <code>EarthquakeData</code> instance to the standard output.
 */
void earthquakeDataPrint(const EarthquakeData *data);

/**
 * Prints human-readable representations (in table format) of the given
 * <code>EarthquakeData</code> instances to the standard output.
 */
void earthquakeDataPrintAll(const EarthquakeData *data, int n);

/**
 * Returns a (deep) copy of the given string.
 */
char *strCopy(const char *str);

/**
 * Runs all reports on the given earthquake data.
 */
void runReports(const EarthquakeData *data, int n);

/**
 * Computes the air distance between the two locations in
 * kilometers.
 */
double airDistance(double originLatitude,
         double originLongitude,
         double destinationLatitude,
         double destinationLongitude);

#endif /* EARTHQUAKE_H */
