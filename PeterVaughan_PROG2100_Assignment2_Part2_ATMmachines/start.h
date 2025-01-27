#ifndef START_H
#define START_H

#endif //START_H

//this program only goes to this function
void printIntroMenu();

//main calls this and this is only used upon start up before going to the main page
void start() {
    //I use std:: because I did not use iostream as a header in this header
    std::cout << "LOADING PROGRAM\n";
    printIntroMenu();
}
