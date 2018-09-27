#include <iostream>
#include <sys/time.h>       // for gettimeofday
#include <unistd.h>     //for sleep
using namespace std;

long getTimeinMicroSeconds() {
	struct timeval start;
	gettimeofday(&start, NULL);
	return start.tv_sec * 1000000 + start.tv_usec;
}

int main(){
	long startTime, endTime;

	startTime = getTimeinMicroSeconds();
	sleep(2);
	endTime = getTimeinMicroSeconds();

	cout << "Time(ms) " << endTime - startTime;
}

/*
   1 micro seconds = 10 ^ -6 second
 */
