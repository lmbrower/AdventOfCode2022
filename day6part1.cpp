#include <iostream>
#include <fstream>

using namespace std;

bool allUnique(char one, char two, char three, char four) {
    if(one == 'A' || two == 'A' || three == 'A' || four == 'A') return false;
    if((one != two && one != three && one != four) && (two != three && two != four) && three != four && four != ' ') {
        return true;
    }
    return false;
}

int main() {
    ifstream input;
    input.open("input6.txt");
    bool completed = false;
    int num = 0;
    char one, two, three, four, signal = 'A';
    input >> four >> three >> two >> one;
    num += 4;
    if(allUnique(one, two, three, four)) {
        completed = true;
    }
    while(input.peek() != EOF && !completed) {
        num++;
        input >> signal;
        four = three;
        three = two;
        two = one;
        one = signal;
        if(allUnique(one,two,three,four)) {
            cout << "Found one!" << endl;
            cout << one << " " << two << " " << three << " " << four << endl;
            completed = true;
        }
    }
    cout << "Number: " << num;
    input.close();
    return 0;
}