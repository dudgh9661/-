#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[1000][1000] = { 0 };

struct Range{
    int r, c;
};

void Print(vector<vector<int>> board) {
    for(int r = 0; r < board.size(); r++) {
        for(int c = 0; c < board[r].size(); c++) {
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }
}
void init(vector<vector<int>> board) {
    for(int r = 0; r < board.size(); r++) {
        for(int c = 0; c < board[r].size(); c++) {
            arr[r][c] = board[r][c];
        }
    }
}

void doSkill(vector<int> skill) {
    int type = skill[0]; // 1 : attack, 2 : heal
    Range from = {skill[1], skill[2]};
    Range to = {skill[3], skill[4]};
    int degree = skill[5];

    //attack
    if ( type == 1) {
        for(int r = from.r; r <= to.r; r++) {
            for(int c = from.c; c <= to.c; c++) {
                arr[r][c] -= degree;
            }
        }
    } else if ( type == 2 ) {
        for(int r = from.r; r <= to.r; r++) {
            for(int c = from.c; c <= to.c; c++) {
                arr[r][c] += degree;
            }
        }
    }
}

int getNum(vector<vector<int>> board) {
    int cnt = 0;

    for(int r = 0; r < board.size(); r++) {
        for(int c = 0; c < board[r].size(); c++) {
            if (arr[r][c] >= 1) cnt++;
        }
    }

    return cnt;
}
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    init(board);

    for(auto v : skill) {
        doSkill(v);
    }
    Print(board);
    answer = getNum(board);
    return answer;
}

int main() {
    vector<vector<int>> vec = {{123},{123}};
    // {{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5}}, {{1,0,0,3,4,4},{1,2,0,2,3,2},{2,1,0,3,1,2},{1,0,1,3,3,1}}
    cout << solution({{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5}}, {{1,0,0,3,4,4},{1,2,0,2,3,2},{2,1,0,3,1,2},{1,0,1,3,3,1}});
    return 0;
}