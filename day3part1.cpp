#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
    ifstream input;
    input.open("input3.txt");
    string line;
    int sum = 0;
    int num = 0;
    while(getline(input, line)) {
        int half = line.length()/2;
        for(int i = 0; i < half; i++) {
            for(int j = half; j < line.length(); j++) {
                if(line[i] = line[j] && isalpha(line[i])) { // found a match
                    if(isupper(line[i])) {
                        num = line[i];
                    }
                    else {
                        num = line[i];
                    }
                    cout << "Line[i] = " << line[i] << " || Line[j] = " << line[j] << endl;
                    sum += num;
                }
            }
        }
    }
    cout << "Sum = " << sum << endl;
    return 0;
}