/**
 * Author: Veronica Lear
 * Date: 2026/11/10
 *
 * Handles eathquake data using structures,
 * a bunch of functions to use and intialize
 * those structures
*/

#include <stdlib.h>
#include <stdio.h>

#include <math.h>
#include <string.h>
#include <time.h>

#include "earthquake.h"

int initEarthquakeData(EarthquakeData *data,
  const char *id,
  const char *locationName,
  double magnitude,
  int significance,
  long timestamp,
  double latitude,
  double longitude,
  double depth) {
    if(data == NULL || id == NULL || locationName == NULL) {
        return NULL_POINTER;
    } else if(magnitude < -1 || magnitude > 10 || significance < 0 || significance > 1000
        || latitude < -90 || latitude > 90 || longitude < -180 || longitude > 180) {
        return INVALID_NUM;
    }

    data->id = (char *) malloc(sizeof(char) * strlen(id) + 1);
    strcpy(data->id, id);

    data->locationName = (char *) malloc(sizeof(char) * strlen(locationName) + 1);
    strcpy(data->locationName, locationName);

    data->magnitude = magnitude;
    data->significance = significance;
    data->timestamp = timestamp;
    data->latitude = latitude;
    data->longitude = longitude;
    data->depth = depth;
    return NO_ERROR;
}

EarthquakeData * createEarthquakeData(
  const char *id,
  const char *locationName,
  double magnitude,
  int significance,
  long timestamp,
  double latitude,
  double longitude,
  double depth) {
    if(id == NULL || locationName == NULL) {
        return NULL;
    } else if(magnitude < -1 || magnitude > 10 || significance < 0 || significance > 1000
        || latitude < -90 || latitude > 90 || longitude < -180 || longitude > 180) {
        return NULL;
    }
    EarthquakeData *newEarthquake = (EarthquakeData *) malloc(sizeof(EarthquakeData));
    initEarthquakeData(newEarthquake, id, locationName, magnitude, significance, timestamp, latitude, longitude, depth);
    return newEarthquake;
}

char *earthquakeDataToString(const EarthquakeData *data) {

    //this code converts the data's timestamp to a human-readable format
    time_t timestamp_s = data->timestamp / 1000; // Convert to seconds

    struct tm *timeinfo = gmtime(&timestamp_s); // For UTC
    char time_str[30];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S UTC", timeinfo);
    //time_str now contains a human-readable string of the
    //timestamp that you may use below

    char buffer[1000];
    sprintf(buffer, "%s\n%s\n%.2f\n%d\n%s\n%.2f\n%.2f\n%.2fkm", data->id, data->locationName,
            data->magnitude, data->significance, time_str, data->latitude, data->longitude, data->depth);

    char *newString = (char *) malloc(sizeof(char) * strlen(buffer) + 1);
    strcpy(newString, buffer);

    return newString;



}


void earthquakeDataPrint(const EarthquakeData *data) {
    char *str = earthquakeDataToString(data);
    printf("%s\n", str);
    free(str);
    return;
}

void earthquakeDataPrintAll(const EarthquakeData *data, int n) {
    printf("Earthquake Data (n = %d)\n", n);
    printf("%-15s %-39s %s %24s %20s %8s\n", "Id",
                                  "Location",
                                  "magnitude/(sig)",
                                  "time",
                                  "lat/lon", "depth");
    for(int i=0; i<n; i++) {
        earthquakeDataPrint(&data[i]);
    }
    printf("\n\n");
}


char *strCopy(const char *str) {
    char *copy = (char *) malloc(sizeof(char) * (strlen(str)+1));
    strcpy(copy, str);
    return copy;
}

void runReports(const EarthquakeData *data, int n) {

    //find the minimum magnitude earthquake and print it
    int minMagnitudeIndex = 0;
    for(int i=1; i<n; i++) {
        if(data[i].magnitude < data[minMagnitudeIndex].magnitude) {
            minMagnitudeIndex = i;
        }
    }
    printf("Weakest Magnitude Earthquake: \n");
    earthquakeDataPrint(&data[minMagnitudeIndex]);

    //find the maximum magnitude earthquake and print it
    //but use a pointer instead of an index
    const EarthquakeData *maxMagnitudeEarthquake = &data[0];
    for(int i=1; i<n; i++) {
        if(data[i].magnitude > maxMagnitudeEarthquake->magnitude) {
            maxMagnitudeEarthquake = &data[i];
        }
    }
    printf("Strongest Magnitude Earthquake: \n");
    earthquakeDataPrint(maxMagnitudeEarthquake);

    //find the closest earthquake to Lincoln, NE, 40.806862, -96.681679
    //TODO: implement
    double minDistance = -100;
    printf("Closest Earthquake to Lincoln (%f kms away): \n", minDistance);

    return;
}

double airDistance(double originLatitude,
         double originLongitude,
         double destinationLatitude,
         double destinationLongitude) {

  originLatitude = originLatitude * M_PI / 180;
  originLongitude = originLongitude * M_PI / 180;
  destinationLatitude = destinationLatitude * M_PI / 180;
  destinationLongitude = destinationLongitude * M_PI / 180;

  double distance = acos(sin(originLatitude) * sin(destinationLatitude) + cos(originLatitude) * cos(destinationLatitude) * cos(destinationLongitude-originLongitude)) * 6371.0;
  return distance;
}
