#include <iostream>
#include <string>
#include <queue>

using namespace std;

int arr[16][16] = { 0 };
bool visit[16][16] = { false };

int UD[4] = { -1, 0, 1, 0};
int LR[4] = { 0, 1, 0, -1};

int flag = 0;

void Print() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            printf("%d", visit[i][j]);
        }
        printf("\n");
    }
}

void init() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            visit[i][j] = false;
            arr[i][j] = 0;
        }
    }
}

void BFS( int row, int col ) {
    queue< pair<int, int> > que;
    visit[row][col] = true;
    que.push( {row, col} );

    while( !que.empty() ) {

        int currentRow = que.front().first;
        int currentCol = que.front().second;

        que.pop();

        for(int i = 0; i < 4; i++) {
//            printf("is here?\n");
            int nextRow = currentRow + UD[i];
            int nextCol = currentCol + LR[i];
//            printf("%d, %d arr : %d \n", nextRow, nextCol, arr[nextRow][nextCol]);
            if( nextRow < 0 || nextRow > 16 || nextCol < 0 || nextCol > 16) {
//                printf("is111111??");
                continue;
            }

            if( visit[nextRow][nextCol] || arr[nextRow][nextCol] == 1) {
                continue;
            }

            else if ( (!visit[nextRow][nextCol] && arr[nextRow][nextCol] == 0) || arr[nextRow][nextCol] == 3 )  {
                if( arr[nextRow][nextCol] == 3 ) {
//                    printf("find %d, %d\n", nextRow, nextCol);
                    flag = 1;
                    return;
                }
                visit[nextRow][nextCol] = true;
                que.push( {nextRow, nextCol} );
            }
        }
    }


}
int main() {
    string input;

    for(int tc = 0; tc < 10; tc++) {

        int TC = 0;
        scanf("%d", &TC);

        init();
        flag = 0;

        for (int i = 0; i < 16; i++) {
            cin >> input;
            for (int j = 0; j < input.length(); j++) {
                int num = input[j] - '0';
//            printf("num : %d\n", num);
                arr[i][j] = num;
            }
        }

        BFS(1, 1);
//        Print();
//        printf("\n\n flag : %d\n\n", flag);

        if (flag == 1) printf("#%d 1\n", TC);
        else printf("#%d 0\n", TC);
    }
    return 0;
}
