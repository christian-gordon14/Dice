#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <random>
#include <chrono>

using namespace std;

class Guessing{
    public: 
        bool start;
        int guess;
        Guessing(bool aStart){
            start = aStart;
            rollDice();
        }
        string rollDice(){
            int num, dnum;
            string str;
            int i = 0;
            if (start) {
                while (i <= 2){
                    i++;
                    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
                    mt19937 rng(seed);
                    uniform_int_distribution<int> dist(1, 7);
                    num = dist(rng);
                    cout <<"The correct number is: " << num << endl;
                    cout << "Enter a number between 1 and 7! " << endl;
                    cin >> guess; 
                    if(guess == num){
                        str = "You Win!";
                        break;
                    } 
                    else {
                        str = "You Lose!";
                            if (i <= 2){
                            cout << "Try again" << endl;     
                            }
                            else{
                                cout << "Youre out of chances" << endl;
                            }                
                    }
                }
            }
            cout << str <<endl;
        return str;
    }
};

int main(){
    Guessing playing(true);
return 0;
}