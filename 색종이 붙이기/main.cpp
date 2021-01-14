#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int map[10][10] = { 0 };
int paper[6] = { 0 };
int MIN = 1e9;
int test = 0;

vector<pair<int,int>> onePos;


void Print() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

//색종이를 뗀다
void reset(int r, int c, int size) {
    for(int i = r; i < r + size; i++) {
        for(int j = c; j < c + size; j++) {
            map[i][j] = 1;
        }
    }
}

//색종이를 붙일 수 있는지 판단
bool isPossible(int r, int c, int size) {
    for(int i = r; i < r + size; i++) {
        for(int j = c; j < c + size; j++) {
            if( map[i][j] ==  0 ) return false;
        }
    }
    return true;
}

//색종이를 붙인다
void putPaper(int r, int c, int size) {
    for(int i = r; i < r + size; i++) {
        for(int j = c; j < c + size; j++) {
            map[i][j] = 0;
        }
    }
}

//모두 다 붙여졌는지 판단
bool isEnd() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if( map[i][j] == 1 ) return false;
        }
    }
    return true;
}
bool inRange(int r, int c) {
    if( r < 0 || r >= 10 || c < 0 || c >= 10) return false;
    return true;
}
void init() {
    int a;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> a;
            map[i][j] = a;
            if( a == 1 ) onePos.push_back({i,j});
        }
    }
    fill(paper, paper+6, 5);
}

void DFS(int paperCnt, int start) {
    if( isEnd() ) {
        if( MIN > paperCnt ) MIN = paperCnt;
//        cout << "check\n";
        return;
    }
    if( MIN < paperCnt ) return;

    for(int i = start; i < onePos.size(); i++) {
        int r = onePos[i].first;
        int c = onePos[i].second;
        if( map[r][c] == 0 ) continue;

        for (int paperSize = 5; paperSize > 0; paperSize--) {
            //범위를 벗어나거나 색종이가 부족하면, continue
            if (!inRange(r + paperSize-1, c + paperSize-1)) continue;
            if (paper[paperSize] <= 0) continue;

            // 해당 사이즈를 붙일 수 있으면, 붙인다.
            else if (isPossible(r, c, paperSize)) {
                paper[paperSize]--;
                putPaper(r, c, paperSize);

                DFS(paperCnt + 1, i+1);

                paper[paperSize]++;
                reset(r, c, paperSize);
            }
        }
//        break;
        return;
    }
}
int main() {
    init();
    DFS(0,0);
    if( MIN == 1e9 ) cout << -1;
    else cout << MIN;
    return 0;
}
