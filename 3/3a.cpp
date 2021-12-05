#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;

int main() {
    
    ifstream infile;
    infile.open("input.txt");
    bitset<12> gamma, delta;
    string inp;
    vector<double> count;
    count.insert(count.end(), 12, 0);

    while(infile >> inp) {
        for(int i=0; i<count.size() ; i++){
            count[i] += ((int) inp[i] - '0');
        }
    }

    for(int i=0; i<count.size(); i++){
        if((int)(count[i]/1000 + 0.5)){
            gamma.set(count.size() - i - 1);
        } 
    }

    delta = gamma;
    delta.flip();
    cout << delta.to_ulong() << " " << gamma.to_ulong() << " " << delta.to_ulong()*gamma.to_ulong();
    return 0;
}