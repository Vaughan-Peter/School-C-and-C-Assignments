#include <iostream>
#include "start.h"
#include "printIntroMenu.h"
#include "printMainMenu.h"
#include "createAccount.h"
#include "login.h"
#include "testing.h"
#include"wipeData.h"
#include <string>

using namespace std;

//global char and double variables
string accountNumber;
string firstName;
string lastName;
string password;
double bankBalance;

int main(){
    // TO WRITE A WELCOME MESSAGE HERE
    cout << "\n\nWelcome to ATM machines!\n" << endl;
    // call the function start
    start();
    return 0;
}

/*
 * Allow for multiple users
 * log in and out of the same account with the saved details
 * Write comments
*/

