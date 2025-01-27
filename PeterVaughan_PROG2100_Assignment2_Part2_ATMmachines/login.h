#ifndef LOGIN_H
#define LOGIN_H

#endif //LOGIN_H

#include <iostream>
#include <array>
#include <algorithm>
#include <string>

//Global variables - just the ones we need
extern string accountNumber;
extern string firstName;
extern string lastName;
extern string password;

using namespace std;

void login() {

    if(accountNumber == "" || firstName == "" || lastName == "" || password == "") {
        cout<<"\nAccount info is empty - create account before logging in";
        printIntroMenu();
    }

    //local variables to be compared to global
    string accountID;
    string nameLocal;
    string pass;

    //should compare local info (info given) to global variables - q to quit as any time
    //I did each info entry separately
    cout<<"\n\nUse q to exit to go to login at any time throughout this process...\n";

    while(true) {
        //USER ID
        cout << "Enter Account ID: \n";
        cin.ignore();
        cin >> accountID;

        //quit, compare or invalid options
        if(accountID[0] == 'q' && accountID[1] == NULL)
            printIntroMenu();

        if(accountID == accountNumber)
            break;

        cout << "Invalid Account Name\n";
        }

        //should compare info given to global variables
        while(true) {
            //USER NAME
            cout << "Enter First Name: \n";
            cin.ignore(-1);
            cin >> nameLocal;

            if(nameLocal[0] == 'q' && nameLocal[1] == NULL)
                printIntroMenu();

            if(nameLocal == firstName)
                break;

            cout << "Invalid Account Name\n";
        }

        //should compare info given to global variables
        while(true) {
            //USER PASSWORD
            cout << "Enter Account Password: \n";
            cin.ignore(-1);
            cin >> pass;

            if(pass[0] =='q' && pass[1] == NULL)
                printIntroMenu();

            if(pass == password)
                break;

            cout << "Invalid Account Password\n";
        }

        //Add the user's name in this string
        cout << "\nWelcome to ATM machines, " << nameLocal << "!!!" << endl;

        //going to the money-option main menu function of the ATM
        printMainMenu();
    }
