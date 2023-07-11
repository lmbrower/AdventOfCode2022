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
            if(self == 'X') { // lose (scissors)
                score += 3;
            }
            if(self == 'Y')  { // tie (rock)
                score += 4;
            }
            if(self == 'Z') { // win (paper)
                score += 8;
            }
        }
        if(opp == 'B') { // opponent paper
           if(self == 'X') { // lose (rock)
                score += 1;
            }
            if(self == 'Y')  { // tie (paper)
                score += 5;
            }
            if(self == 'Z') { // win (scissors)
                score += 9;
            } 
        }
        if(opp == 'C') { // opponent scissors
            if(self == 'X') { // lose (paper)
                score += 2;
            }
            if(self == 'Y')  { // tie (scissors)
                score += 6;
            }
            if(self == 'Z') { // win (rock)
                score += 7;
            }
        }
    }
    cout << "Score = " << score << endl;
    input.close()
    return 0;
}