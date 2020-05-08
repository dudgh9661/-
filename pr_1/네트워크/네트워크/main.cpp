#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

void DFS(int start, vector<int> arr[], bool visit[]){
    if( visit[start] == true ) return;
    
    visit[start] = true;
    printf("%d ", start);
    
    for(int i = 0; i < arr[start].size(); i++){
        int next = arr[start][i];
        if( visit[next] == false) //visit[i]가 아니고. visit[1], visit[2]가 되어야 하기 때문에 i가 아닌 visit[next]가 되어야 한다...
            DFS(next, arr, visit);
    }
    
}

void BFS(int start, vector<int> arr[], bool visit[]){
    queue<int> que;
    
    que.push(start);
    visit[start] = true;
    //    printf("%d ", start);
    
    while( !que.empty() ){
        int node = que.front();
        printf("%d ", node);
        que.pop();
        
        for(int i = 0; i < arr[node].size(); i++){
            int next = arr[node][i];
            if( visit[next] == false){
                que.push(next);
                visit[next] = true;
            }
        }
    }
    
}
int main()
{
    bool *visit = new bool[5];
//    bool visit[6];
    fill(visit, visit+6, false);

    vector<int> arr[6];
    arr[0].push_back(1);
    arr[0].push_back(2);

    arr[1].push_back(0);
    arr[2].push_back(0);

    arr[1].push_back(3);
    arr[1].push_back(4);

    arr[3].push_back(1);
    arr[4].push_back(1);

    arr[3].push_back(5);
    arr[5].push_back(3);

    DFS(0, arr , visit);
    fill(visit, visit+6, false);
    printf("\n");
    BFS(0, arr, visit);
    return 0;
}
