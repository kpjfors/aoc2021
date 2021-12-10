#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int cumsum(int max){
    int s = 0;
    for(int i = 0; i<max; i++){
        s+=i;
    }
    return s;
}

int main() {
    ifstream infile;
    infile.open("input.txt");
    
    vector<int> pos, dist_r, dist_l;
    vector<int> crabs;
    int slope_r = 0, slope_l = 0, integral_r=0, integral_l= 0,max = 0, count_r = 0, count_l = 0, min_dist = INT_MAX;

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
        pos.resize(max+1); dist_r.resize(max+1), dist_l.resize(max+1);
    }

    for(int i:crabs){ //populate crabs per pos
        pos[i]++;
    }

    for(int i = pos.size()-1; i>-1; i--){ //main loop backwards
        dist_r[i] = integral_r;
        count_r += pos[i]; 
        slope_r += count_r; 
        integral_r += slope_r; 
    }

    for(int i = 0; i<pos.size(); i++){ //main loop forwards
        dist_l[i] = integral_l;
        count_l += pos[i]; 
        slope_l += count_l; 
        integral_l += slope_l; 
    }

    for(int i = 0; i<pos.size(); i++){ //find min
        if(dist_l[i] + dist_r[i] < min_dist){
            min_dist = dist_l[i] + dist_r[i];
        }
    }
    cout << min_dist;    
}