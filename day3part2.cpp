#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
    ifstream input;
    input.open("input3.txt");
    string line1, line2, line3;
    int sum = 0;
    int num = 0;
    bool found = false;
    char one, two, three;
    while(1) {
        if(input.peek() == EOF) break;
        getline(input, line1);
        getline(input, line2);
        getline(input, line3);
        found = false;
        for(int i = 0; i < line1.length(); i++) {
            if(found) {
                break;
            }
            for(int j = 0; j < line2.length(); j++) {
                if(found) {
                    break;
                }
                for(int k = 0; k < line3.length(); k++) {
                    one = line1.at(i);
                    two = line2.at(j);
                    three = line3.at(k);
                    if(one == two && two == three && isalpha(one)) { // found a match
                        if(isupper(one)) {
                            num = (int)one - 38;
                        }
                        else {
                            num = (int)one - 96;
                        }
                        //cout << "one = " << line.at(i) << " and gives num of " << num << endl;
                        sum += num;
                        found = true;
                        break;
                    }
                }
            }
        }
    }
    cout << "Sum = " << sum << endl;
    input.close();
    return 0;
}