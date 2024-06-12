#include <iostream>
#include <stdlib.h>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

int returnRandomValue(){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 rng(seed);
    uniform_int_distribution<int> dist(1, 7);
    int random = dist(rng);
    return random;
}

class Guessing{
    public: 
        bool start;
        int guess;
        Guessing(bool aStart){
            start = aStart;
            rollDice();
        }
        string rollDice(){
            int diceTotal, dnum;
            string str;
            int i = 0;
            if (start) {
                while (i <= 2){
                    i++;
                    int dice1 = returnRandomValue();
                    this_thread::sleep_for(chrono::milliseconds(3));
                    int dice2 = returnRandomValue();
                    diceTotal = dice1 + dice2;
                    cout << "\nEnter a number between 2 and 14! \nIf you guess right you win. You only get three chances.\nGuess: ";
                    cin >> guess; 
                    if(guess == diceTotal){
                        str = "You Win!";
                        break;
                    } 
                    else {
                        str = "You Lose!";
                            if (i < 3){
                            cout << "Try again, the correct number was " << diceTotal << "!\n ";    
                            }
                            else{
                                cout << "\nThe correct number was " << diceTotal << ", you are out of chances." << endl;
                            }                
                    }
                }
            }
            cout << str <<endl;
        return str;
    }
};

int main(){
    Guessing(true);
return 0;
}