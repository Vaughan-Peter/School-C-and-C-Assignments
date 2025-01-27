#ifndef PRINTINTROMENU_H
#define PRINTINTROMENU_H
#endif //PRINTINTROMENU_H

#include <iostream>

using namespace std;

//links to functions
void createAccount();
void login();

void printIntroMenu(){

    cout << "\n\nWelcome!";
    //choices with error handling - loops until correct response in entered
    while(true) {

        char choice;
        cout << "\nSelect from the following options...\nl -> Login\nc -> Create New Account\nq -> Quit\n>>";
        cin >> choice;

        switch (choice) {

            //login section
            case 'l':
                login();
                break;

            // account creation section
            case 'c':
                createAccount();
                break;

            //quits the program through exit code
            case 'q':
                cout << "Exiting...." << endl;
                exit(0);

            //error handling
            default:
                cout << "Invalid Input. Try Again...\nUse lowercase or an acceptable letter..." << endl;
        }
    }
}
