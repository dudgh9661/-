#include <iostream>
#include <vector>

using namespace std;

int row, col;

int arr[100][100] = { 0 };
vector< pair<int,int> > vec;

void init() {
    cin >> row >> col;

    string a;
    for(int i = 0; i < row; i++) {
        cin >> a;
        for(int j = 0; j < a.length(); j++) {
            if ( a[j] == 'c' ) {
                arr[i][j] = 100;
                vec.push_back({i,j});
            }
        }
    }
}

void sol() {
    for(int i = 0; i < col; i++) {
        for (int j = 0; j < vec.size(); j++) {
            int r = vec[j].first;
            int c = vec[j].second;
            if ( c + 1 >= col ) continue;

            if (arr[r][c+1] == 0) {
                arr[r][c+1] = i + 1;
                vec[j].second = c + 1;
            }
        }
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if (arr[i][j] == 100) arr[i][j] = 0;
            else if (arr[i][j] == 0 ) arr[i][j] = -1;
        }
    }
}

void Print() {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {
    init();
    sol();
    Print();
    return 0;
}
