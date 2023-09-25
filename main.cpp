#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    srand(time(0));
    const int minNumber;
    const int maxNumber;
    cin>>minNumber;
    cin>>maxNumber;

    char playAgain;
    
    do {
        int secretNumber = rand() % (maxNumber - minNumber + 1) + minNumber;
        int attempts = 0;
        int guess;
        
        cout << "Welcome to the Number Guessing Game!" << endl;
        cout << "I'm thinking of a number between " << minNumber << " and " << maxNumber << "." << endl;
        
        while (true) {
            cout << "Enter your guess: ";
            if (!(cin >> guess)) {
                cout << "Invalid input. Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            
            attempts++;
            
            if (guess < secretNumber) {
                cout << "Too low! Try again." << endl;
            } else if (guess > secretNumber) {
                cout << "Too high! Try again." << endl;
            } else {
                cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
                break;
            }
        }
        
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');
    
    cout << "Thanks for playing! Goodbye." << endl;
    
    return 0;
}
