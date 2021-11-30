#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>

using namespace std;

int main() {
    
    ifstream infile;
    infile.open("test.txt");

    string val;
    
    while(infile >> val) {
        cout << val << endl;
    }
    return 0;
}