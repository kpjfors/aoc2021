#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <vector>

#define N 5

using namespace std;

int main() {
    
    ifstream infile;
    infile.open("input.txt");
    class Board{
        public:
            int row_hits[N]{0};
            int col_hits[N]{0};
            int sum_remaining = 0; //formula (N-n+1)*(N+n)/2, n = 0
            int data[N][N]{0};
            bool won = false;
            bool last_remaining = false;
    };

    vector<Board> boards;
    int draw;
    vector<int> draws; 
    int inp;
    int read = 0;
    
    for (int i; infile >> i;) {
        draws.push_back(i);
        if (infile.peek() == ',')
            infile.ignore();
        else
            break;
    }

    while (infile >> inp){
        if(read%25 == 0){
            Board b;
            boards.push_back(b);
        }
        int pos = read%25;
        int col = pos%5;
        int row = (int)pos/5.0;
        boards.back().data[row][col] = inp;
        boards.back().sum_remaining += inp;
        read++;
    }

    for(int draw:draws){
        for(Board& board:boards){
            for(int r = 0;r<N;r++){
                for(int c = 0;c<N;c++){
                    if(draw==board.data[r][c]){
                        board.sum_remaining -= draw;
                        board.row_hits[r]++;
                        if(board.row_hits[r] == 5 && board.last_remaining){
                            cout << board.sum_remaining << " " << draw << " " << board.sum_remaining*draw;
                            return 0;
                        }
                        if(board.row_hits[r] == 5){
                            board.won = true;
                        }
                        board.col_hits[c]++;
                        if(board.col_hits[c] == 5 && board.last_remaining){
                            cout << board.sum_remaining << " " << draw << " " << board.sum_remaining*draw;
                            return 0;
                        }
                        if(board.col_hits[c] == 5){
                            board.won = true;
                        }
                    }
                }
            }
        }
        vector<Board> boards_remaining;
        for(Board& board:boards){
            if(!board.won){
                boards_remaining.push_back(board);
            }
        }
        boards = boards_remaining;
        //cout << boards.size();
        if(boards.size() == 1){
            boards.back().last_remaining=true;
        }
    }
}