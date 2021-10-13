#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[101][101] = { 0 };
void init(int r, int c) {
    int num = 1;
    for (int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            arr[i][j] = num++;
        }
    }
}

int rotation(int r, int c, int r2, int c2) {
    int tmp = arr[r][c];
    int MIN = arr[r][c];
    for (int i = r; i <= r2-1; i++) {
        arr[i][c] = arr[i+1][c];
        MIN = min(MIN, arr[i+1][c]);
    }
    for (int i = c; i <= c2-1; i++) {
        arr[r2][i] = arr[r2][i+1];
        MIN = min(MIN, arr[r2][i+1]);
    }
    for (int i = r2; i >= r+1; i--) {
        arr[i][c2] = arr[i-1][c2];
        MIN = min(MIN, arr[i-1][c2]);
    }
    for (int i = c2; i >= c+1; i--) {
        arr[r][i] = arr[r][i-1];
        MIN = min(MIN, arr[r][i-1]);
    }
    
    arr[r][c+1] = tmp;   
    
    return MIN;
}

void Print(int r, int c) {
    for(int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    init(rows, columns);
    for (int i = 0; i < queries.size(); i++) {
        
        answer.push_back(rotation(queries[i][0],queries[i][1],queries[i][2],queries[i][3]));
        
    }
    
    // Print(rows, columns);
    return answer;
}
