#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int total = 0;
//prim을 이용하여 MST를 만든다.
//void prim(int start, vector< pair<int, int> > map[]){
void prim(int start, vector< pair<int, int> > map[], bool *visit){
    
    priority_queue< pair<int, int> , vector< pair<int, int> >, greater< pair<int, int> > > que;
    visit[start] = true;
//    printf("size 1 : %d", map[start].size());
    for( int i = 0; i < map[start].size(); i++){
        int next = map[start][i].first;
        int nextV = map[start][i].second;
        que.push({nextV, next});
    }
    
    
    while( !que.empty() ){
        //우선순위 큐이므로 top에는 제일 작은 value를 가진 노드가 위치한다.
        int ele = que.top().second;
        int value = que.top().first;
        que.pop();
        //제일 짧은 노드를 발견했는데 그 노드가 이미 연결이 되어있는 노드라면 뽑아서 버린다.
        if( visit[ele] == true) {
            continue;
        }
        if( visit[ele] == false ){
            visit[ele] = true;
            total += value;
            for(int i = 0; i < map[ele].size(); i++){
                int next_ele = map[ele][i].first;
                int next_value = map[ele][i].second;
                que.push({next_value, next_ele});
            }
        }
        
    }
    
    
    
}

int main(){
    freopen("input.txt", "r", stdin);
    int n = 0;
    scanf("%d", &n);
    if( n < 1 || n > 1000) return 0;
    
    int m = 0; scanf("%d", &m); if( m < 1 || m > 100000) return 0;
    
    //연결 정보 저장 백터
    //방문 백터
    bool *visit = new bool[n+1];
    fill(visit,visit+n+1, false);
    vector< pair<int, int> > map[n+1];
    
    int a = 0, b = 0, c = 0;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        //연결 데이터를 map에 입력해준다.
        map[a].push_back({b,c});
        map[b].push_back({a,c});
    }
    
    int start = n-1;
    //prim 함수에 대입.
    prim(start, map, visit);
    
    printf("%d", total);
    
    
    return 0;
}
