#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    ifstream infile;
    infile.open("input.txt");
    
    vector<int> fishes;
    int new_fishes;

    for (int i; infile >> i;) {
        fishes.push_back(i);
        if (infile.peek() == ',')
            infile.ignore();
        else
            break;
    }
    
    for(int days = 0; days < 80; days++){
        new_fishes = 0;
        for(int &fish:fishes){
            if(fish==0){
                fish=7;
                new_fishes++;
            }
            fish--;
        }
        for(int nf = 0; nf<new_fishes;nf++){
            fishes.push_back(8);
        }
    }
    
    cout << fishes.size();
}