#include <iostream>
using namespace std;

int main() {
    cout << "\n\n Imperial to Metric conversion!\n\n";

    int numTons,numStones,numPounds, numOunces;
    double totalOunces;
    int totalKilos, metricTons;

    cout << " Enter the number of tons: ";
    cin >> numTons;

    cout << "Enter the number of stones: ";
    cin >> numStones;

    cout << "Enter the number of pounds: ";
    cin >> numPounds;

    cout << "Enter the number of ounces: ";
    cin >> numOunces;

    totalOunces = 35840 * numTons + 224 * numStones + 16 * numPounds + numOunces;
    totalKilos = totalOunces / 35.274;
    metricTons = int(totalKilos/1000);

    while (totalKilos >= 1000) {
        totalKilos = totalKilos - 1000;
    }

    //double remainingGrams = (totalOunces - (metricTons * 1000) - (totalKilos * 35.274))*28.35;
    totalOunces = totalOunces - ((totalKilos*35.274) + (metricTons*1000*35.274));
    double grams = totalOunces*28.35;

    cout << "\n The Metric weight is " << metricTons << " metric tons, " << totalKilos << " kilos, and ";
    printf( "%.1f", grams);
    cout << " grams. \n\n";

    return 0;
}
