#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int nakaNum = 16;
int even = 8;
int evenTwo = 2;
int sum = even * evenTwo;
string name = "I. Nakajima, Suzuko";
bool single = true;
string profession = "programmer";


int main() {
    string username;
    cout << "Enter your username: ";
    getline(cin, username);
    cout << name << " is a " << profession << "!\n";
    cout << "Nakajima is learning...C++! | " << sum << "\n";
    if (username == "I. Nakajima, Suzuko") {
        cout << "Name: \n" << username << "\n = = = = = | * | = = = = = ";
    }
    else if (username != "I. Nakajima, Suzuko") {
        cout << "\n" << username << "\n";
    }

    // Command line

    // Permission level for make-shift command line.
    int permission = 5;

    // Access to make-shift command line while permission is above 0.
    while (permission > 0) {
        string slash = "/";
        string cmdline;
        cout << username << " [Permission - " << permission << "]: ";
        getline(cin, cmdline);

        if (cmdline == slash + "cfile") {
            string fileName;
            cout << "Enter file name: ";
            getline(cin, fileName);

            ofstream newFile(fileName + ".txt");
            newFile << "Learning C++!";
            newFile.close();
        }

        permission--;
    }

    // Message about command line priveleges revoked!
    if (permission <= 0) {
        cout << "Your permission level dropped to 0.\nYou no longer have access to the make-shift command line.";
    }
    return 0;
}