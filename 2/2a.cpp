#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    
    ifstream infile;
    infile.open("input.txt");

    string dir;
    int q;
    vector<int> loc = {0,0};
    map<string, vector<int>> dirs = {
        {"forward", vector<int>{1,0}},
        {"down", vector<int>{0,1}},
        {"up", vector<int>{0,-1}}
    };

    while(infile >> dir >> q) {
        loc[0] += dirs.find(dir)->second[0]*q;
        loc[1] += dirs.find(dir)->second[1]*q;
    }
    cout << loc[0] * loc[1];
    return 0;
}