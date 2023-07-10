#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input;
    input.open("input2.txt");
    string line;
    char opp;
    char self;
    int score = 0;
    while(input >> opp) {
        input >> self;
        if(opp == 'A') { // opponent rock
            if(self == 'X') { // rock tie
                score += 4;
            }
            if(self == 'Y')  { // paper win
                score += 8;
            }
            if(self == 'Z') { // scissors loss
                score += 3;
            }
        }
        if(opp == 'B') { // opponent paper
           if(self == 'X') { // rock loss
                score += 1;
            }
            if(self == 'Y')  { // paper tie
                score += 5;
            }
            if(self == 'Z') { // scissors win
                score += 9;
            } 
        }
        if(opp == 'C') { // opponent scissors
            if(self == 'X') { // rock win
                score += 7;
            }
            if(self == 'Y')  { // paper loss
                score += 2;
            }
            if(self == 'Z') { // scissors tie
                score += 6;
            }
        }
    }
    cout << "Score = " << score << endl;
    return 0;
}