#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input;
    int max, secondMax, thirdMax = 0;
    int sum = 0;
    int runningTotal = 0;
    string line;
    input.open("input1.txt");
    while(getline(input, line)) {
        if(line.length() == 1) {
            if(runningTotal > thirdMax) {
                if(runningTotal > secondMax) {
                    if(runningTotal > max) {
                        thirdMax = secondMax;
                        secondMax = max;
                        max = runningTotal;
                    }
                    else {
                        thirdMax = secondMax;
                        secondMax = runningTotal;
                    }
                }
                else {
                    thirdMax = runningTotal;
                }
            }
            runningTotal = 0;
        }
        else {
            runningTotal += stoi(line);
        }
    }
    sum = max + secondMax + thirdMax;
    cout << "Sum = " << sum << endl;
    input.close();
    return 0;
}