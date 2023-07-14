#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

bool allUnique(char* string) {
    for(int i = 0; i < 14; i++) {
        for(int j = i+1; j < 14; j++) {
            if(string[i] == string[j]) return false;
        }
    }
    return true;
}

int main() {
    ifstream input;
    input.open("input6.txt");
    bool completed = false;
    char string[14];
    int oldest = 0;
    char signal;
    for(int i = 0; i < 14; i++) {
        input >> string[i];
    }
    int num = 14;
    if(allUnique(string)) {
        completed = true;
    }
    while(input.peek() != EOF && !completed) {
        input >> signal;
        string[oldest] = signal;
        oldest++;
        num++;
        if(allUnique(string)) {
            completed = true;
        }
        if(oldest == 14) oldest = 0;
    }
    cout << "Number: " << num;
    input.close();
    return 0;
}