#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

int main() {
    int total = 0;
    ifstream input;
    input.open("input4.txt");
    string line;
    char waste;
    int firstPair[2];
    int secondPair[2];
    while(getline(input, line)) {
        stringstream ss(line);
        ss >> firstPair[0] >> firstPair[1] >> waste >> secondPair[0] >> secondPair[1];
        firstPair[1] = abs(firstPair[1]);
        secondPair[1] = abs(secondPair[1]);
        //cout << "FirstPair = " << firstPair[0] << ", " << firstPair[1];
        //cout << " || SecondPair = " << secondPair[0] << ", " <<secondPair[1] << endl;
        if(firstPair[0] > secondPair[0]) {
            if(firstPair[1] <= secondPair[1]) {
                total++;
            }
        }
        else if(secondPair[0] > firstPair[0]) {
            if(secondPair[1] <= firstPair[1]) {
                total++;
            }
        }
        else total++;
    }
    cout << "Total = " << total << endl;
    input.close();
    return 0;
}