/*
   Given two arrays (both of size n), one containing arrival time of trains and
   other containing the corresponding trains departure time (in the form of an integer)
   respectively. Return the minimum number of platform required, such that no train waits.
   Arrival and departure time of a train can't be same.
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int platformsNeeded(int arrival[], int departure[], int n) {
	sort(arrival, arrival + n);
	sort(departure, departure + n);
	int no_of_train = 0;
	int max = 0;
	int arr = 0, dep = 0;

	while(arr < n && dep < n) {
		if(arrival[arr] < departure[dep]) {
			no_of_train++;
			arr++;
		}  else {
			no_of_train--;
			dep++;
		}
		if(max < no_of_train) {
			max = no_of_train;
		}
	}
	return max;
}

int main(){
	int arrival[] = {900, 940, 950, 1100, 1500, 1800};
	int departure[] = {910, 1200, 1120, 1130, 1900, 2000};
	int n = sizeof(arrival) / sizeof(arrival[0]);
	cout << platformsNeeded(arrival, departure, n);
}
