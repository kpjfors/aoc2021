#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream infile;
    infile.open("input.txt");
    
    vector<int> pos, dist;
    vector<int> crabs;
    int count_r = 0, count_l = 0, max = 0, sum_r = 0, sum_l = 0, min_dist = INT_MAX;

    for (int i = 0; infile >> i;) { //read
        crabs.push_back(i);
        if (infile.peek() == ',')
            infile.ignore();
        else
            break;
    }

    for(int i:crabs){ //init vectors
        if(i > max){
            max = i;
        }
        pos.resize(max+1); dist.resize(max+1);
    }

    for(int i:crabs){ //count crabs per pos as well as sum dist_r
        pos[i]++;
        sum_r+=i;
        count_r++;
    }

    for(int i = 0; i<pos.size(); i++){ //main loop
        dist[i] = sum_r+sum_l;
        count_l += pos[i]; count_r -= pos[i];
        sum_l+=count_l;sum_r-=count_r;
    }

    for(int i:dist){ //find min
       if(i < min_dist){
           min_dist = i;
       }
    }
    cout << min_dist;    
}