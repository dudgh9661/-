#include <stdio.h>

int map[101][101] = { 0 };
int visit[101] = { 0 };
int queue[1001] = { 0 };
void Print() {
    for(int i = 1; i < 101; i++) {
        for(int j = 1; j < 101; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void PrintVisit() {
    for(int i = 1; i < 101; i++) {
        printf("%d ", visit[i]);
    }
}

void BFS( int node ) {
    int front = 0;
    int rear = 0;
    queue[rear++] = node;
    visit[node] = 0;

    while( front != rear) {
        int next = queue[front++];
        for(int i = 1; i < 101; i++) {
            if( map[next][i] == 1 && visit[i] == 0 ) { //연결이 된 노드이고 방문하지 않았으면 큐에 넣는다.
                queue[rear++] = i;
                visit[i] = visit[next] + 1;
            }
        }
    }
}

int findMax() {
    int MAX = 0;
    int ans = 0;
    for(int i = 1; i < 101; i++) {
        int num = visit[i];
        if( num >= MAX ) {
            MAX = num;
            if( i > ans ) {
                ans = i;
            }
        }
    }

    return ans;
}
int main() {
    for(int TC = 1; TC <= 10; TC++) {
        int inputLength = 0, startNum = 0;
        scanf("%d %d", &inputLength, &startNum);

        for (int i = 0; i < inputLength / 2; i++) {
            int from = 0, to = 0;
            scanf("%d %d", &from, &to);
            map[from][to] = 1;
        }

        BFS(startNum);
//    PrintVisit();
        int ans = findMax();
        printf("#%d %d\n",TC, ans);
    }



    return 0;
}
