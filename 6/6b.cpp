#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    ifstream infile;
    infile.open("input.txt");
    
    map<int64_t,int64_t> fishdays;
    int64_t total_fishes = 0;

    for (int i; infile >> i;) {
        if(fishdays.count(i)==0){
            fishdays[i] = 1;
        }
        else{
            fishdays[i]++;
        }
        if (infile.peek() == ',')
            infile.ignore();
        else
            break;
    }
    
    for(int days = 0; days < 256; days++){
        map<int64_t,int64_t> fd_temp;
        for(auto it = fishdays.begin(); it!=fishdays.end(); it++){
            if(it->first==0){
                fd_temp[8] = it->second;
                fd_temp[6] += it->second;
            }
            else{
                fd_temp[it->first-1] += it->second;
                }
        }
        fishdays = fd_temp;
        total_fishes = 0;
        for(auto it = fishdays.begin(); it!=fishdays.end(); it++){
            total_fishes += it->second;
        }
        
    }
    cout << total_fishes << endl;
}