#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

void Print(vector<int> vec[], int size) {
    for(int i = 1; i < size; i++) {
        for(int j = 0; j < vec[i].size(); j++)
            printf("(%d,%d) : %d ", i,j,vec[i][j]);
        printf("\n");
    }
    
}

void BFS ( vector<int> vec[], int start, bool *visit) {
    queue<int> que;
    
    visit[start] = true;
    que.push(start);
    
    printf("%d ", start);
    
    while(!que.empty()) {
        int here = que.front();
        que.pop();
        
        for(int i = 0; i < vec[here].size(); i++) {
            int next = vec[here][i];
            if( visit[next] == false ) {
                visit[next] = true;
                printf("%d ", next);
                que.push(next);
            }
        }
    }
    
}

void DFS ( vector<int> vec[], int start, bool *visit) {
    visit[start] = true;
    printf("%d ", start);
    for(int i = 0; i < vec[start].size(); i++){
        int next = vec[start][i];
        if( visit[next] == true ) {
//            printf("true case >> (%d,%d) : %d\n", start,i, next);
            continue;
        }
        else if( visit[next] == false ) {
            
//            visit[next] = true;
            DFS(vec, next, visit);
        }
    }
}

int main() {
    int N, M, V;
    cin >> N;
    cin >> M;
    cin >> V;
    vector<int> vec[N+1];
    bool *visit = new bool[N+1];
    memset(visit, false, N+1);
    
    for(int i = 0; i < M; i++) {
        int input, input2;
        scanf("%d %d", &input, &input2);
        vec[input].push_back(input2);
        vec[input2].push_back(input);
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < vec[i].size(); j++) {
            sort(vec[i].begin(), vec[i].end(), less<int>());
        }
    }
//    Print(vec, N+1);
    DFS(vec, V, visit);
    memset(visit, false, N+1);
    
    printf("\n");
    
    BFS(vec, V, visit);
    
    return 0;
}
