#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <vector>
#include <cmath> 

using namespace std;

int value_to_keep(vector<string> data, int idx, bool isO2){
    int found = 0;
    double min_req = data.size()/2.0;
    for (string line:data){
        if (line[idx] == '1'){
            found++;
        }
        if (found>=min_req){
            if(isO2==true){
                return 1;
            }
            else{
                return 0;
            }
            
        }
    }
    if(isO2==true){
        return 0;
    }
    else{
        return 1;
    }
}

vector<string> modify_data(vector<string> data, char real, int idx){
    vector<string> new_data;
    for (string line:data){
        if (line[idx] == real+'0'){
            new_data.push_back(line);
        }
    }
    return new_data;
}

int main() {
    ifstream infile;
    infile.open("input.txt");
    vector<string> o2list, co2list;
    int bitsize = 12;
    bitset<12> o2, co2;
    string inp;

    while(infile >> inp) {
        o2list.push_back(inp);
    }
    co2list = o2list;
    int o2_keep;
    int co2_keep;

    for(int i = 0; i<bitsize; i++){
        o2_keep = value_to_keep(o2list, i, true);
        

        o2list = modify_data(o2list, o2_keep, i);
        if(o2list.size() == 1){
            break;
        }
    }
    for(int i = 0; i<bitsize; i++){
        co2_keep = value_to_keep(co2list, i, false);
        co2list = modify_data(co2list, co2_keep, i);
        if(co2list.size() == 1){
            break;
        }
    }
    for(int i = 0; i<bitsize; i++){
        if (co2list[0][i] == '1'){
            co2.set(bitsize - i - 1);
        }
        if (o2list[0][i] == '1'){
            o2.set(bitsize - i - 1);
        }
    }
    cout << o2list.size() << " " << o2list[0] << "\n";
    cout << co2list.size() << " " << co2list[0] << "\n";
    cout << o2.to_ulong() << " " << co2.to_ulong() << " " << o2.to_ulong()*co2.to_ulong();
    return 0;
}
