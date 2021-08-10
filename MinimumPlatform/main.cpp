#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int minimumPlatform(int arrival[], int departure[], int countOfTrains) {
    sort(arrival, arrival + countOfTrains);
    sort(departure, departure + countOfTrains);

    int platform = 1; int res = 1;
    int arrivalIndex = 1;
    int departureIndex = 0;
    while ( arrivalIndex < countOfTrains && departureIndex < countOfTrains ) {
      if (arrival[arrivalIndex] <= departure[departureIndex]) {
          platform++;
          arrivalIndex++;
      } else if(arrival[arrivalIndex] > departure[departureIndex]) {
         platform--;
         departureIndex++;
      }

      res = max(platform, res);
    }

    return res;

}


int main()
{
    int numberOfTrains = 6;
    int arrivalTimeSeries[] = {900, 940, 950, 1100, 1500, 1800};
    int departureTimeSeries[] = {910, 1200, 1120, 1130, 1900, 2000};
    cout << minimumPlatform(arrivalTimeSeries, departureTimeSeries, numberOfTrains) << endl;
    return 0;
}
