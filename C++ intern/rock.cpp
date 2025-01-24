#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Seed for random number generator

    int choice;
    int computerChoice;

    cout << "Welcome to Rock Paper Scissors!\n";
    cout << "Enter your choice:\n";
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissors\n";
    cout << "Your choice: ";
    cin >> choice;

    // Generate random number for computer's choice (1 for Rock, 2 for Paper, 3 for Scissors)
    computerChoice = rand() % 3 + 1;

    cout << "Computer chose: ";
    switch(computerChoice) {
        case 1:
            cout << "Rock\n";
            break;
        case 2:
            cout << "Paper\n";
            break;
        case 3:
            cout << "Scissors\n";
            break;
    }

    cout << "You chose: ";
    switch(choice) {
        case 1:
            cout << "Rock\n";
            break;
        case 2:
            cout << "Paper\n";
            break;
        case 3:
            cout << "Scissors\n";
            break;
    }

    // Determine winner
    if (choice == computerChoice) {
        cout << "It's a tie!\n";
    } else if ((choice == 1 && computerChoice == 3) ||
               (choice == 2 && computerChoice == 1) ||
               (choice == 3 && computerChoice == 2)) {
        cout << "You win!\n";
    } else {
        cout << "Computer wins!\n";
    }

    return 0;
}