#include <iostream>
#include <vector>
#include <fstream> 

using namespace std;

int main() {
    
    ifstream infile;
    infile.open("input.txt");

    vector<int> vals, ma;
    int inc = 0, val;

    while(infile >> val) {
        vals.push_back(val);
    }

    for(int i = 0; i<vals.size()-2;i++){
        ma.push_back(vals[i]+vals[i+1]+vals[i+2]);
    }

    for(int i = 1; i<ma.size(); i++){
        if(ma[i] > ma[i-1]){
            inc++;
        }
    }
    cout << inc;
    return 0;
}