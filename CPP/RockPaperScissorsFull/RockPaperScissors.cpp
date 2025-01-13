#include <iostream>
#include <string>
#include <stdexcept>
#include <random>
#include <chrono>
using namespace std;

void checkRange(int userInput);
int rngMechanic();
bool userWinner(const int a, const int b);
bool userLoser(const int a, const int b);
bool playAgain();

bool user_win = false;
bool user_lose = false;

int main() {
    cout << "Rock, Paper or Scissors? " << endl;
    cout << "Press 1 for Rock" << endl;
    cout << "Press 2 for Paper" << endl;
    cout << "Press 3 for Scissors" << endl;
    cout << "What do you call?" << endl;
    int userChoice;
    cin >> userChoice;
    int computerChoice = rngMechanic();
    try {
        checkRange(userChoice);
    } 
    catch (const std::range_error& e) {
        // Handle the exception
        std::cerr << "Error: " << e.what() << endl;
    }
    if(computerChoice == 1) {
        cout << computerChoice << endl;
        cout << "Your opponent has chosen Rock" << endl;
    } else if (computerChoice == 2) {
        cout << computerChoice << endl;
        cout << "Your opponent has chosen Paper" << endl;
    } else {
        cout << computerChoice << endl;
        cout <<"Your opponent has chosen Scissors" << endl;
    }
    
    userWinner(userChoice, computerChoice);
    userLoser(computerChoice, userChoice);

    return 0;
}

int rngMechanic() {
    random_device r;
    mt19937 engine(r());
    uniform_int_distribution<int> dist (1, 3);
    return dist(engine);
}

void checkRange(int userInput) {
    if ( userInput < 1 || userInput > 3) {
        throw std::range_error("That is not within the range");
    }
}

bool userWinner(const int a, const int b) { //a is user input, b is computer input
    if (a == 1 && b == 3) {
        cout << "Rock beats scissors, you win!" << endl;
        return true;
    } else if (a == 3 && b == 2) {
        cout << "Scissor beats paper, you win!" << endl;
        return true;
    } else if (a == 2 && b == 1) {
        cout << "Paper beats Rock, you win!" << endl;
        return true;
    }
    return false;
}

bool userLoser(const int a, const int b) {
    if (a == 1 && b == 3) {
        cout << "Rock beats scissors, you lose!" << endl;
        return true;
    } else if (a == 3 && b == 2) {
        cout << "Scissor beats paper, you lose!" << endl;
        return true;
    } else if (a == 2 && b == 1) {
        cout << "Paper beats Rock, you lose!" << endl;
        return true;
    }
    return false;
}