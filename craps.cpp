#include <iostream>
#include <stdlib.h>
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
            int num;
            string str;
            int i = 0;
            if (start) {
                while (i <= 2){
                    i++;
                    num = rand() % 6 + 1 ;
                    cout <<"The correct number is: " << num << endl;
                    cout << "Enter a number 1-6;" << endl;
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