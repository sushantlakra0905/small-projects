#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate random number between 1 and 100
    int number = rand() % 100 + 1;
    
    // Store user's guess
    int guess;

    std::cout << "Guess the number (between 1 and 100):\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (guess < number) {
            std::cout << "Too low. Try again.\n";
        } else if (guess > number) {
            std::cout << "Too high. Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the number!\n";
        }
    } while (guess != number);

    return 0;
}
