#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <utility>
#include <cstdlib>
#include <exception>

using namespace std;

bool core = true;

const string programVersion = " \nVersion: 2021.5.12.100\n";

const int nakaNum = 16;
int oddOne = 7;
int evenTwo = 16;
int sum = oddOne * evenTwo;
string username;
bool single = true;

// Permission to access the make-shift command line.
int permission = true;

void initiate() {
    string username;
    cout << "Enter your username: ";
    getline(cin, username);
    cout << "Nakajima is learning...C++! | " << sum << "\n";
    if (username == "I. Nakajima, Suzuko") {
        cout << "Name: \n" << username << "\n = = = = = | * | = = = = = ";
    }
    else if (username != "I. Nakajima, Suzuko") {
        cout << "\n" << username << "\n";
    }
}

void makeshift_cmdline() {
    // Access to make-shift command line while permission is above 0.
    while (permission == true) {
        string slash = "/";
        string cmdline;
        cout << username << " [Permission - " << permission << "]: ";
        getline(cin, cmdline);

        if (cmdline == slash) {
            cout << "\nThis is the slash prefix, it serves as the source to your access of commands in this make-shift command line.\n";
        }
        else if (cmdline == slash + "cfile") {
            string fileName;
            cout << "Enter file name: ";
            getline(cin, fileName);

            ofstream newFile(fileName + ".txt");
            newFile << "Learning C++!";
            newFile.close();
        }
        else if (cmdline == slash + "version") {
            string ver = programVersion;
            cout << programVersion;
        }
        else if (cmdline == slash + "shutdown") {
            cout << "Closing make-shift terminal.";
            break;
        }
        else if (cmdline == slash + "rap") {
            cout << "Permissions revoked!";
            int permission = false;
        }

    }
}

void basic() {
    while (core == true) {
        string slash = "/";
        string mainarea;
        cout << username << ": ";
        getline(cin, mainarea);

        if (mainarea == slash + "terminal") {
            makeshift_cmdline();
        }
    }
}


int main() {

    // Message about command line priveleges revoked!
    if (permission == false) {
        cout << "\nYour permissions have been revoked!\nYou no longer have access to the make-shift command line.\n";
    }

    initiate();
    basic();
    return 0;
}