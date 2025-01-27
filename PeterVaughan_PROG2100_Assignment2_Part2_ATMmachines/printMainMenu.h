#ifndef PRINTMAINMENU_H
#define PRINTMAINMENU_H
#endif //PRINTMAINMENU_H

#include <iostream>
#include <string>

//calls the external global variables that we need here
extern double bankBalance;
double bankChange;

//initializes these functions
void depositMoney();
void widthdrawl();
void bankBalances();

using namespace std;

void printMainMenu(){

    //variable for switch choices
    char menuInput;

    //choices with error handling
    while(true) {
        cout << "\nSelect from the following options...\nd -> Deposit Money\nw -> Withdraw Money\nr -> Request Balance\nq -> Quit\n>>";
        cin >> menuInput;

        //options have a function along with the error handling default
        switch (menuInput) {
            //how much are we depositing?
            case 'd':
                cout << "Deposit Money" << endl;
                depositMoney();
                break;

            //how much are we withdrawing?
            case 'w':
                cout << "Withdraw Money" << endl;
                widthdrawl();
                break;

            //requesting the current balance
            case 'r':
                cout << "Request Balance" << endl;
                bankBalances();
                break;

            //quits this sections of the code to go to the main option menu
            case 'q':
                printIntroMenu();
                break;

            //error handling
            default:
                cout << "Invalid Input. Try Again..." << endl;
        }
    }
}

//function for depositing money
void depositMoney(){
    cout << "Enter Deposit Value:\n";
    cin >> bankChange;
    bankBalance += bankChange;
    cout << "Bank Balance Value: ";
    printf("%.2f", bankBalance);
    cout << "\n";
}

//function for withdrawing money
void widthdrawl(){
    cout << "Enter Widthdrawl Value:\n";
    cin >> bankChange;
    bankBalance -= bankChange;
    cout << "Bank Balance Value: ";
    printf("%.2f", bankBalance);
    cout << "\n";
}

//check to see balance
void bankBalances() {
    cout << "Bank Balance Value: ";
    printf("%.2f", bankBalance);
    cout << "\n";
}

