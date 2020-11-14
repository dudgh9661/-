#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

bool visit[1001] = { false };

void DFS(int start, vector<int> vec[]) {
    visit[start] = true;
//    printf("%d ", start);
    for(int i = 0; i < vec[start].size(); i++) {
        int next = vec[start][i];
        if( visit[next] ) continue;
        DFS(next, vec);
    }
}

int main() {
//    printf("hi\n");
    int N = 0; //정점의 개수
    int M = 0; //간선의 개수
    scanf("%d %d", &N, &M);

    vector<int> vec[N+2];
    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        vec[a].push_back(b);
        vec[b].push_back(a);

//        printf("brk1");
    }


    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < vec[i].size(); j++) {
            int next = vec[i][j];
            if( !visit[next] ) {
                DFS(next, vec);
                cnt++;
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        if( !visit[i] ) cnt++;
    }
    printf("%d\n", cnt);



    return 0;

}