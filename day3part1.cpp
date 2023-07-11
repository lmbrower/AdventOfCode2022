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
    bool found = false;
    char one, two;
    while(getline(input, line)) {
        int half = line.length()/2;
        found = false;
        for(int i = 0; i < half; i++) {
            if(found) {
                break;
            }
            for(int j = half; j < line.length(); j++) {
                one = line.at(i);
                two = line.at(j);
                if(one == two && isalpha(one)) { // found a match
                    if(isupper(one)) {
                        num = (int)one - 38;
                    }
                    else {
                        num = (int)one - 96;
                    }
                    cout << "one = " << line.at(i) << " and gives num of " << num << endl;
                    sum += num;
                    found = true;
                    break;
                }
            }
        }
    }
    cout << "Sum = " << sum << endl;
    return 0;
}