#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<char> v[9];
    //loading data
    v[0].push_back('F'); v[0].push_back('H'); v[0].push_back('B'); v[0].push_back('V'); v[0].push_back('R'); v[0].push_back('Q'); v[0].push_back('D'); v[0].push_back('P');
    v[1].push_back('L'); v[1].push_back('D'); v[1].push_back('Z'); v[1].push_back('Q'); v[1].push_back('W'); v[1].push_back('V');
    v[2].push_back('H'); v[2].push_back('L'); v[2].push_back('Z'); v[2].push_back('Q'); v[2].push_back('G'); v[2].push_back('R'); v[2].push_back('P'); v[2].push_back('C'); 
    v[3].push_back('R'); v[3].push_back('D'); v[3].push_back('H'); v[3].push_back('F'); v[3].push_back('J'); v[3].push_back('V'); v[3].push_back('B'); 
    v[4].push_back('Z'); v[4].push_back('W'); v[4].push_back('L'); v[4].push_back('C'); 
    v[5].push_back('J'); v[5].push_back('R'); v[5].push_back('P'); v[5].push_back('N'); v[5].push_back('T'); v[5].push_back('G'); v[5].push_back('V'); v[5].push_back('M'); 
    v[6].push_back('J'); v[6].push_back('R'); v[6].push_back('L'); v[6].push_back('V'); v[6].push_back('M'); v[6].push_back('B'); v[6].push_back('S'); 
    v[7].push_back('D'); v[7].push_back('P'); v[7].push_back('J'); 
    v[8].push_back('D'); v[8].push_back('C'); v[8].push_back('N'); v[8].push_back('W'); v[8].push_back('V');
    
    //beginning logic

    ifstream input;
    input.open("input5.txt");
    int amount, source, destination = 0;
    char box;
    char message[9] = "";
    string junk;
    while(input.peek() != EOF) {
        input >> junk;
        if(input.eof()) break;
        input >> amount >> junk >> source >> junk >> destination;
        for(int i = 0; i < amount; i++) {
            box = v[source-1].back();
            v[source-1].pop_back();
            v[destination-1].push_back(box);
        }
    }
    for(int j = 0; j < 9; j++) {
        message[j] = v[j].back();
    }
    //for some reason my code is accessing message[9], but simply cutting
    //it off gives me the right output
    cout << "Message is: " << message << endl;
    input.close();
    return 0;
}