/*
   Given two arrays (both of size n), one containing arrival time of trains and
   other containing the corresponding trains departureTimes time (in the form of an integer)
   respectively. Return the minimum number of platform required, such that no train waits.
   Arrival and departure time of a train can't be same.
 */

#include <iostream>
using namespace std;

int findMinPlatformsNeeded(int arrivalTimes[], int departureTimes[], int numTrains) {
    sort(arrivalTimes, arrivalTimes + numTrains);
    sort(departureTimes, departureTimes + numTrains);

    int currentPlatforms = 0;
    int maxPlatforms = 0;
    int iArrival = 0, iDeparture = 0; // i prefixed for index in 2 pointer approach.

    while (iArrival < numTrains && iDeparture < numTrains) {
        if (arrivalTimes[iArrival] < departureTimes[iDeparture]) {
            currentPlatforms++;
            iArrival++;
        } else {
            currentPlatforms--;
            iDeparture++;
        }

        if (maxPlatforms < currentPlatforms) {
            maxPlatforms = currentPlatforms;
        }
    }
    return maxPlatforms;
}

int main() {
    int arrivalTimes[] = {900, 940, 950, 1100, 1500, 1800};
    int departureTimes[] = {910, 1200, 1120, 1130, 1900, 2000};
    int numTrains = sizeof(arrivalTimes) / sizeof(arrivalTimes[0]);
    cout << "Minimum number of platforms needed: " << findMinPlatformsNeeded(arrivalTimes, departureTimes, numTrains) << endl;
}

/**
 * Minimum number of platforms needed: 3
 */

/**
 * Time complexity:
 * Sorting - 2 * O (n log n)
 *
 */