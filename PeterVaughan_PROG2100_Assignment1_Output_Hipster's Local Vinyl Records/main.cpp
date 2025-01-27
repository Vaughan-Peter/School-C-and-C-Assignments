#include <iostream>
using namespace std;
#include<cstdio>

int main() {
    cout << "\n Hipster's Local Vinyle Records - Customer Order Details\n";

    char customerFirstName[200], customerLastName[200];
    double deliveryDistance, purchase, deliveryCost, purchaseAndTax, totalPurchase;

    //enter a name with a space in it
    cout << " Enter the customer's name: ";
    cin >> customerFirstName;
    cin >> customerLastName;


    cout << "Enter the distance in kilometers for delivery: ";
    cin >> deliveryDistance;

    cout << "Enter the cost of records purchased: ";
    cin >> purchase;

    deliveryCost = deliveryDistance * 15;
    purchaseAndTax = purchase * 1.14;
    totalPurchase = purchaseAndTax + deliveryCost;


    //use only to second decimal place
    cout << "\n Purchase summary for " << customerFirstName << " " << customerLastName;
    cout << "\n Delivery Cost: $";
    printf("%.2f", deliveryCost);
    cout << "\n Purchase Cost with tax: $";
    printf("%.2f", purchaseAndTax);
    cout << "\n Total Cost: $";
    printf("%.2f", totalPurchase);
    cout << "\n";
    return 0;
}
