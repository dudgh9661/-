#include <iostream>
#include <vector>

using namespace std;

int N, M, H; //col, x, row
int flag = 0;

bool arr[31][11] = { false }; //[1][1]부터 시작

void init() {
    cin >> N >> M >> H;

    int r, c;

    for(int i = 0; i < M; i++) {
        cin >> r >> c;
        arr[r][c] = true;
    }
}

bool inRange(int r, int c) {
    if( r > H || r < 1 || c > N || c < 1 ) return false;
    return true;
}

bool doGame() {
    int row;

    for(int col = 1; col <= N; col++) {
        int output = col;
        row = 1;
        while( row <= H ) {
            if ( arr[row][output] ) {
                if( !inRange(row,output) ) {
                    row++;
                    continue;
                }
                output++;
                row++;
            } else {
                if ( !inRange(row, output-1) ) row++;
                else {
                    if ( arr[row][output-1] ) {
                        output--;
                        row++;
                    } else row++;
                }
            }
        }

//        cout << col << " -> " << output << endl;
        if( output != col ) {
//            cout << "no condition " << endl;
            return false;
        }
    }
//    cout << "find condition!!!!!!" << endl;
    return true;
}

void DFS(int cr, int cc, int cnt, int limit) {
    if ( flag == 1 ) return;
    if( cnt >= limit ) {
        //1. 사다리게임 시작
        if ( doGame() ) {
            flag = 1;
        }
        return;
    }
    for(int r = cr; r <= H; r++) {
        for(int c = 1; c <= N; c++) {
            if ( !inRange(r,c+1) ) continue;
            if( arr[r][c] || arr[r][c-1] || arr[r][c+1] ) continue;

            if ( flag == 1 ) return;
            arr[r][c] = true;
//            cout << " created row : " << r << "," << c << endl;
            DFS(r, c, cnt + 1, limit);
            arr[r][c] = false;
        }
    }

}
int main()
{
    init();
    for(int i = 0; i <= 3; i++) {
        DFS(1,1,0,i);
        if( flag == 1 ) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
