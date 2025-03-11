#include<iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int generateRandomNumber() { 
    return rand() % 100 + 1;
}

int getPlayerGuess() {
    int guess;
    cout << "Enter your guess: "; 
    cin >> guess;
    return guess;
}

void printAnswer(int guess, int secretNumber) {
    if (guess < secretNumber)
        cout << "Too low!" << endl;
    else if (guess > secretNumber) 
        cout << "Too high!" << endl;
    else 
        cout << "Correct!" << endl;  
}

string getHostAnswer(string X, int guess) {
    string answer;
    cout << "Is " << guess << " your number? higher/lower/yes: ";
    cin >> answer;
    return answer;
}

int main() {
    cout << "you guess type 1" << endl;
    cout << "I guess type 2" << endl;

    int choice;
    cin >> choice;
    int secretNumber = 0; 

    switch (choice) {
        default:
        case 1:
            cout << "You will guess my number" << endl;
            srand(time(NULL));
            secretNumber = generateRandomNumber();
            int guess;
            do {
                guess = getPlayerGuess();
                printAnswer(guess, secretNumber);
            } while (guess != secretNumber);
            break;

        case 2:
            cout << "I will guess your number" << endl;
            int low = 1, high = 100;
            string answer;
            do {
                int guess = (low + high) / 2;
                answer = getHostAnswer(answer, guess);
                if (answer == "higher") {
                    low = guess + 1;
            
                }
                else if (answer == "lower"){
                    high = guess - 1;
                }
                else 
                    cout << "I guessed your number" << endl;
            } while (answer != "yes");
            break;
    }

    return 0;
}
