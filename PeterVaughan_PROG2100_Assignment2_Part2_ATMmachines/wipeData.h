//
// Created by vaugh on 2024-10-25.
//

#ifndef WIPEDATA_H
#define WIPEDATA_H

#endif //WIPEDATA_H

extern string accountNumber;
extern string firstName;
extern string lastName;
extern string password;
extern double bankBalance;

void wipeData() {
    cout << "\nWIPE DATA STARTED" << endl;
    accountNumber.clear();
    firstName.clear();
    lastName.clear();
    password.clear();
    bankBalance = 0;
    cout << "WIPE DATA ENDED" << endl;
    printIntroMenu();
}