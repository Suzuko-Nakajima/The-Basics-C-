#include <iostream>
#include <string>
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

    int permission = 5;

    // Access to make-shift command line while permission is above 0.
    while (permission > 0) {
        string cmdline;
        cout << username << " [Permission - " << permission << "]: ";
        getline(cin, cmdline);

        permission--;
    }

    // Message about command line priveleges revoked!
    if (permission <= 0) {
        cout << "Your permission level dropped to 0.\nYou no longer have access to the make-shift command line.";
    }
    return 0;
}