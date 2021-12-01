#include <iostream>
#include <fstream>

using namespace std;

int main() {
    
    ifstream infile;
    infile.open("input.txt");

    int val = 0, val_old = INT_MAX , inc = 0;

    while(infile >> val) {
        if (val>val_old){
            inc++;
        }
        val_old = val;
    }
    cout << inc;
    return 0;
}