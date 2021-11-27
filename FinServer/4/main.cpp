#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * 1. 아래로 이동
 * 2. 왼쪽으로 이동
 */

int arr[100001][1000001] = {0};
int colMax[100001] = {0};
int rowMax[100001] = {0};
vector<vector<int>> ans;

void printDownRec(int r1, int c1, int r2, int c2, int MAX) {
    for (int r = MAX; r <= r2-r1; r++) {
        for (int c = c1; c <= c2; c++) arr[r][c] = 1;
    }
}

void printLeftRec(int r1, int c1, int r2, int c2, int MAX) {
    for (int r = r1; r <= r2; r++) {
        for (int c = MAX; c <= c2-c1; c++) arr[r][c] = 1;
    }
}

void printRec(int r1, int c1, int r2, int c2) {
    for (int r = r1; r <= r2; r++) {
        for (int c = c1; c <= c2; c++) arr[r][c] = 1;
    }
}

void deleteRec(int r1, int c1, int r2, int c2) {
    for (int r = r1; r <= r2; r++) {
        for (int c = c1; c <= c2; c++) arr[r][c] = 0;
    }
}

void init(vector<vector<int>> rectangles) {
    for(auto rec : rectangles) {
        int r1 = rec[1], c1 = rec[0];
        int r2 = rec[3], c2 = rec[2];
        printRec(r1,c1,r2,c2);
    }
}

void moveDown(vector<vector<int>> rectangles) {
    for(auto rec : rectangles) {
        int r1 = rec[1], c1 = rec[0];
        int r2 = rec[3], c2 = rec[2];
        int MAX = -1;

        for (int i = c1; i <= c2; i++) {
            MAX = min(rowMax[i], MAX);
        }

        for (int i = c1; i <= c2; i++) {
            rowMax[i] = MAX;
        }

        deleteRec(r1,c1,r2,c2);
        printDownRec(r1,c1,r2,c2,MAX);
    }
}

void moveLeft(vector<vector<int>> rectangles) {
    for(auto rec : rectangles) {
        int r1 = rec[1], c1 = rec[0];
        int r2 = rec[3], c2 = rec[2];
        int MAX = -1;

        for (int i = r1; i <= r2; i++) {
            MAX = min(colMax[i], MAX);
        }

        for (int i = r1; i <= r2; i++) {
            colMax[i] = MAX;
        }

        deleteRec(r1,c1,r2,c2);
        printLeftRec(r1,c1,r2,c2,MAX);
    }
}

void Print() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout <<arr[i][j];
        }
        cout << endl;
    }
}
vector<string> solution(vector<vector<int>> rectangles) {
    vector<string> answer;
    ans = rectangles;
    init(rectangles);
    Print();
    moveDown(rectangles);
    cout << endl;
    Print();
    return answer;
}

int main() {
//    {{0, 2, 1, 3}, {1, 2, 2, 5}, {3, 3, 4, 4}, {4, 1, 6, 3}, {1, 6, 5, 7}, {5, 5, 7, 6}, {5, 8, 6, 10}}
solution({{0, 2, 1, 3}, {1, 2, 2, 5}, {3, 3, 4, 4}, {4, 1, 6, 3}, {1, 6, 5, 7}, {5, 5, 7, 6}, {5, 8, 6, 10}});
    return 0;
}