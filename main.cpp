#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include <utility>
#include <cstdlib>
#include <list>
#include <exception>

using namespace std;

bool basics = true;
bool permission = true;
bool legal;
string slash = "/";

// Text color class

class txtColor {
    public:
    string reset = "\033[0m";
    string red = "\033[91m";
    string green = "\033[32m";
};

txtColor txtc;

// End of text color class.

//Program version
const string ver = "\n\033[34mVersion: 2021.5.13.2\n" + txtc.reset;

void versionInfo() {
    cout << ver;
}



// Make-shift command-line.
void msCmdline() {
    if (permission == true) {
        while (permission == true) {
            string msCMDline;
            cout << "Root - [" << permission << "]: ";
            getline(cin, msCMDline);

            if (msCMDline == slash + "help") {
                cout << "\n- exit | Exits the make-shift command-line.\n- help | Displays this list (available for make-shift command-line only).\n- rap | Revokes administration permissions.\n\n";
            }
            else if (msCMDline == slash + "rap") {
                cout << txtc.red << "\nRevoking permissions...\n\n" << txtc.reset;
                permission = 0;
            }
            else if (msCMDline == slash + "exit") {
                cout << " \nExiting...\n\n";
                break;
            }
        }
    }
    //Declines access to make-shift command-line.
    else if (permission == false) {
        cout << txtc.red << "\nError: You do not have permission to access the make-shift command line.\n\n" << txtc.reset;
    }
}

int main() {
    cout << txtc.green << "The Basic command line is ready.\n\n" << txtc.reset;

    string username;
    cout << "Enter username: ";
    getline(cin, username);

    int age;
    cout << "Enter age: ";
    cin >> age;

    try {
        if (age >= 18) {
            cout << "\nUpdating program settings...\n";
            legal = true;
            cout << "Setting toggle: " << legal << "\n\n";
        }
        else {
            throw 601;
        }
    }
    catch (int num) {
        cout << "\nUpdating program settings...\n";
        legal = false;
        cout << "Setting toggle: " << legal << "\n\n";
    }

    // Access basic command line.
    while (basics == 1) {
        string cmdline;
        cout << username << ": ";
        getline(cin, cmdline);

        if (cmdline == slash + "terminal") {
            msCmdline();
        }
        else if (cmdline == slash + "version") {
            versionInfo();
        }
        //Shutdown - closes the program.
        else if (cmdline == slash + "shutdown") {
            cout << "Shutting down program.";
            basics = 0;
        }
        else if (cmdline == slash + "view_perms") {
            if (permission == true) {
                cout << "Permissions: " << permission << "\n";
                cout << "\nYou (\033[32m" << username << "\033[0m) have access to the make-shift command line.\n\n";
            }
            else if (permission == false) {
                cout << "Permissions: " << permission << "\n";
                cout << "\nYou (\033[32m" << username << "\033[0m) do not have access to the make-shift command-line.\n\n";
            }
        }
        else if (cmdline == slash + "help") {
            cout << " \n- help | Show list of commands (for basic command-line).\n- shutdown | Shuts down the program (for basic command-line access).\n- version | Dispalys version of this program (basic command-line access only).\n- view_perms | View permissions.\n\n";
        }
    }
}