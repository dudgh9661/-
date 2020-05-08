#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<pair <int, int> > arr[10001];
bool visit[10001] = { false };

void prim(int start){
    
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int,int> > > que;
    
    visit[start] = true;
    for(int i = 0; i < arr[start].size(); i++ ){
        int next = arr[start][i].first;
        int value = arr[start][i].second;
        que.push({value, next});
    }
    
    int total = 0;
    
    while( !que.empty() ){
        //현재 노드(top->pop)와 연결된 node들(방문하지 않은 경우만)을 que.push
        int next = que.top().second;
        int value = que.top().first;
        que.pop();
        
        if( visit[next] == true) continue;
        
        visit[next] = true;
        total = total + value;
        
        for( int i = 0; i < arr[next].size(); i++){
            int ele = arr[next][i].first;
            int val = arr[next][i].second;
            
            que.push({val,ele});
        }

        //들어간 node들 중 min value값을 top->pop
        //다시 pop한 노드와 연결된 놈들을 Push
        
    }
    printf("\n%d", total);
}
int main(){
    //V,E 입력
    int V=0, E=0;
    scanf("%d %d", &V, &E);
    //map 입력
    int from=0,to=0,val=0;
    for(int i = 0; i < E; i++){
        scanf("%d %d %d", &from, &to, &val);
        arr[from].push_back({to, val});
        arr[to].push_back({from, val});
    }
    
    prim(1);
    return 0;
}
