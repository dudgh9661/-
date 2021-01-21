#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int map[9][9] = { 0 };
vector<pair<int,int>> zero;

int tcCnt = 0;
int flag = 0;

void answerPrint() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << map[i][j];
        }
        cout << "\n";
    }
}
void init() {
    string str;
    int a;

    for (int i = 0; i < 9; i++) {
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            a = str[j] - '0';
            map[i][j] = a;
            if (a == 0) zero.push_back({i, j});
        }
    }
}

bool check(int r, int c, int num) { //들어갈 행과 열, 숫자
    int row = r;
    int col = c;
    //행열 중복 검사
    for(int i = 0; i < 9; i++) {
        if( map[i][c] == num && i != r ) return false;
        if( map[r][i] == num && i != c) return false;
    }
    //3 by 3
    if( row == 0 ) row = 1;
    if( col == 0 ) col = 1;
    for(int i = (row/3)*3; i <= (row/3)*3+2; i++) {
        for(int j = (col/3)*3; j <= (col/3)*3+2; j++) {
            if( map[i][j] == num ) return false;
        }
    }

    return true;
}
void DFS(int row, int col, int start) {
    if( row == zero[zero.size()-1].first && col == zero[zero.size()-1].second ) {
        answerPrint();
        cout << endl;
        flag = 1;
        return;
    }

    for(int i = start; i < zero.size(); i++) {
        int inputRow = zero[i].first;
        int inputCol = zero[i].second;

        for(int input = 1; input <= 9; input++) {
            if( flag == 1 ) return;
            if( !check(inputRow, inputCol, input) ) continue;
//            printf("(%d,%d) 들어갈 수 : %d\n", inputRow, inputCol, input);
            map[inputRow][inputCol] = input;

            DFS(inputRow, inputCol,i+1);

            map[inputRow][inputCol] = 0;

        }
        return;
    }
}
int main() {
    init();
    DFS(0,0,0);
    return 0;
}
