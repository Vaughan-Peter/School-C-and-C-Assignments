#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H
#endif //CREATEACCOUNT_H

#include <iostream>
#include  <bits/stdc++.h>
#include <string>

//global variables
extern string accountNumber;
extern string firstName;
extern string lastName;
extern string password;
extern double bankBalance;

using namespace std;

void accountCreationChoice();

//just for testing - diagnostic tool
void testing();
void wipeData();

void createAccount(){

    cout<<"\n\nUse q to exit to go to login at any time throughout this process...\n";
    //USER ID creation and exit logic
    cout << "Create Account ID (number and letters allowed): \n";
    cin.ignore();
    cin >> accountNumber;

    //Ability to quit on q as first value
    if(accountNumber[0] == 'q' && accountNumber[1] == NULL)
        wipeData();

    //user info creation
    cout << "Input Your First Name: \n";
    cin.ignore(-1);
    cin >> firstName;

    //Ability to quit on q as first value
    if(firstName == "q")
        wipeData();

    //user info creation
    cout << "Input Your Last Name: \n";
    cin.ignore(-1);
    cin >> lastName;

    //Ability to quit on q as first value
    if(lastName == "q")
        wipeData();

    //USER PASSWORD creation
    cout << "Create Account Password (number and letters allowed): \n";
    cin.ignore(-1);
    cin >> password;

    //Ability to quit on q as first value
    if(password == "q")
        wipeData();

    //initial balance creation
    cout << "Initial Bank Balance: \n";
    cin >> bankBalance;
    //error-handling for numbers and does not deal with quiting
    while(true) {
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input! Please try again!\n";
            cout << "Initial Bank Balance: \n";
            cin >> bankBalance;
        }
        if(!cin.fail())
            break;
    }

    cout << "Money deposited: ";
    printf("%.2f", bankBalance);
    cout << endl;

    //allowing for account creation here
    accountCreationChoice();
}


void accountCreationChoice() {

    //local variables
    char choice[2];

    //choice to not create account or to create account until proper choice is selected
    cout << "Do you want to create account? [y/n] \n";
    cin.ignore();
    cin.getline(choice, 2);

    while(true) {
        switch(choice[0]) {

            case 'y':
                //once the account is created, we want to go to the main menu and select login
                printIntroMenu();

            case 'n':
                //let's wipe info before continuing
                wipeData();

            //error handling
            default:
                cout << "Invalid Choice\nTry Again...\n";
        }
    }
}