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
#include <unistd.h>

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
    string cyan = "\033[96m";
    string bold = "\033[1m";
    string grey = "\033[2m";
    string italics = "\033[3m";
    string underline = "\033[4m";
    string hightlight = "\033[7m";
    string darkGreen = "\033[92m";
    string yellow = "\033[93m";
    string blue = "\033[94m";
    string purple = "\033[95m";
    string redHighlight = "\033[101m";
    string greenHighlight = "\033[102m";
    string yellowHighlight = "\033[103m";
    string blueHighlight = "\033[104m";
    string purpleHighlight = "\033[105m";
    string cyanHighlight = "\033[106m";
    string whiteHighlight = "\033[107m";
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
        cout << txtc.red << "\nError: You do not have permission to access the make-shift command-line.\n\n" << txtc.reset;
    }
}

int main() {
    cout << txtc.green << "The Basic command line is ready.\n\n" << txtc.reset;

    // Choose username
    string username;
    cout << "Enter username: ";
    getline(cin, username);

    // Age - Will affect the program.
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

    //Gender select - will affect the program.
    bool genderSelect = false;

    // if statements.
    int gender;
    while (genderSelect == false) {
        cout << "Choose gender.\n(1. Male | 2. Female): ";
        cin >> gender;

        if (gender == 1) {
            gender = 1;
            genderSelect = true;
        }
        else if (gender == 2) {
            gender = 2;
            genderSelect = true;
        }
        else {
            cout << " [!] Select proper gender!\n";
            continue;
        }
    }


    // Introduction - Claire.
    cout << txtc.purple << "\nClaire: " << txtc.reset << "My my, seems like I have a visitor here...and...";
    if (gender == 1) {
        cout.flush();
        sleep(2);
        cout << "male.\n\n";
    }
    else if (gender == 2) {
        cout.flush();
        sleep(2);
        cout << "female.\n\n";
    }

    sleep(3);

    cout << txtc.purple << " \nClaire: " << txtc.reset << "I will not bore you with the details here, I rather make this quick. Perhaps you'd like to get started?\n\n";

    bool choiceOne = false;

    // Choice one.
    while (choiceOne == false) {
        int choiceOneA;
        cout << "1. Okay\n\n" << username << ": ";
        cin >> choiceOneA;

        if (choiceOneA == 1) {
            choiceOne = true;
            cout << txtc.purple << "\nClaire: " << txtc.reset << "I didn't think you'd answer, but yes, right to it then!\n\n";
        }
        else {
            cout << "Choose a valid answer choice!";
        }
    }

    sleep(3);

    cout << txtc.purple << "\nClaire: " << txtc.reset << "After I let you go, you will see your username in the command-line,  there you will have access to make-shift commands and a 'make-shift command-line' as so she would call it.\n";

    sleep(10);
    cout << txtc.purple << "\nClaire: " << txtc.reset << "There's a thing called 'Slash commands', you can use the forward slash key and type \"help\" to display all available commands.\n";

    sleep(7);
    cout << txtc.purple << "\nClaire: " << txtc.reset << "Alright, that's it! You're on your own now.\n\n";

    sleep(3);

    // End of introduction.

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
            basics = 0;
            cout << txtc.red << "\n- ! - The program has been shutdown! - ! -\n\n" << txtc.reset;
        }
        else if (cmdline == slash + "view_perms") {
            if (permission == true) {
                cout << "Permissions: " << permission << "\n";
                cout << "\nYou (\033[32m" << username << "\033[0m) have access to the make-shift command-line.\n\n";
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