#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input;
    int max = 0;
    int runningTotal = 0;
    string line;
    input.open("input1.txt");
    while(getline(input, line)) {
        if(line.length() == 1) {
            if(runningTotal > max) {
                max = runningTotal;
            }
            runningTotal = 0;
        }
        else {
            runningTotal += stoi(line);
        }
    }
    cout << "Max: " << max << endl;
    input.close();
}