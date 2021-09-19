#include <iostream>
#include <vector>

using namespace std;
vector<pair<int,int>> vec;
int arr[9][9] = { 0 };
int flag = 0;

bool line(int r, int c, int num) {
    for (int i = 0; i < 9; i++) {
        if (arr[i][c] == num) return false;
    }
    for(int j = 0; j < 9; j++) {
        if (arr[r][j] == num) return false;
    }
    return true;
}
bool squareCol(int r, int c, int num) {
    if ( c < 3 ) {
        for (int j = 0; j < 3; j++) {
            if (arr[r][j] == num) return false;
        }
    } else if ( 2 < c && c < 6) {
        for (int j = 3; j < 6; j++) {
            if (arr[r][j] == num) return false;
        }
    } else if ( 5 < c && c < 9 ) {
        for (int j = 6; j < 9; j++) {
            if (arr[r][j] == num) return false;
        }
    }
    return true;
}
bool square(int r, int c, int num) {
    if ( r < 3 ) {
        for (int i = 0; i < 3; i++) {
            if (!squareCol(i,c,num)) return false;
        }
    } else if ( 2 < r && r < 6 ) {
        for (int i = 3; i < 6; i++) {
            if (!squareCol(i,c,num)) return false;
        }
    } else if ( 5 < r && r < 9 ) {
        for (int i = 6; i < 9; i++) {
            if (!squareCol(i,c,num)) return false;
        }
    }
    return true;
}
void DFS(int next) {
    if (flag == 1) return;
    if ( next == vec.size() ) {
        flag = 1;
        // Print answer
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    }

    int r = vec[next].first;
    int c = vec[next].second;
    for(int i = 1; i <= 9; i++) {
        if ( line(r,c,i) && square(r,c,i) ) {
            arr[r][c] = i;
            DFS(next + 1);
            arr[r][c] = 0;
        }
    }
}
void init() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) vec.push_back({i,j});
        }
    }
}
int main() {
    freopen("input.txt","r",stdin);
    init();
    DFS(0);
    return 0;
}
