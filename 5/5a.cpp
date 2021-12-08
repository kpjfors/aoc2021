#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> make_vec(string v){
        const char* c = ",";
        int x, y;
        x = stoi(v.substr(0, v.find(c)));
        y = stoi(v.substr(v.find(c)+1, v.npos));
        vector<int> vec {x, y};
        return vec;
    }

int sign(int x){
    if(x>0){
        return 1;
    }
    else if(x<0){
        return -1;
    }
    return 0;
}

int main() {
    
    ifstream infile;
    infile.open("input.txt");
    
    map<vector<int>, int> seen;
    vector<int> from, to, between, dir {0,0};
    vector<vector<int>> row;
    int found = 0;
    string arrow, v1, v2;
    
    while(infile >> v1 >> arrow >> v2) {
        row.clear();
        from = make_vec(v1); to = make_vec(v2);
        dir[0] = sign(to[0]-from[0]); dir[1] = sign(to[1]-from[1]);
        if(dir[0]==0||dir[1]==0){ //no diag
            between = from;
            while(between != to){
                row.push_back(between);
                between[0]+=dir[0]; between[1]+=dir[1];
            }
            row.push_back(to);
        }
        for(vector<int> r:row){
            if(seen.count(r)==0){
                seen[r]= 1;
            }
            else if(seen[r] == 1){
                seen[r]++;
                found++;
                
            }
        }
    }
    cout << found;
}