#include <iostream>
#include <cstdlib> // For rand() function

using namespace std;

// Function to generate a random number within a given range
int gRandomNum(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

// Function to play the guessing game
void playGame(int lower, int upper, int maxAttempts) {
    int target = gRandomNum(lower, upper);
    int guess, attempts = 0;

    cout << "\nGuess the number between " << lower << " and " << upper << ". You have " << maxAttempts << " attempts.\n";

    // Start the guessing loop
    while (attempts < maxAttempts) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess == target) {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
            return; // End the game if the correct guess is made
        } else if (guess < target) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Too high! Try again.\n";
        }
    }

    cout << "You've run out of attempts. The correct number was " << target << ".\n";
}

int main() {
    // Initialize random number generator
    rand();

    char playAgain;

    cout << "Welcome to the Number Guessing Game!\n";

    do {
        int lower = 1, upper = 100, maxAttempts = 7;
        playGame(lower, upper, maxAttempts); // Start the game
        
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y'); // Repeat if the player wants to

    cout << "Thanks for playing!\n";
    return 0;
}
