#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>

int UD[4] = {-1, 1, 0, 0};
int LR[4] = {0, 0, -1, 1};

int size = 0;

using namespace std;

void Print(int **arr){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


//내 생각엔 모든 경로를 탐색해야 하는 것 같다.
void BFS(int **map, int**visit, int **dist){
    queue<pair<int,int> > que;
    int x = 0;
    int y = 0;
    dist[x][y] = 0;
    visit[x][y] = 0;
    que.push(make_pair(x,y));
    
    while( !que.empty()){
        x = que.front().first;
        y = que.front().second;
        que.pop();
        
        
        for(int i = 0; i < 4; i++){
            int Nx = x+UD[i];
            int Ny = y+LR[i];
            if(Nx >= 0 && Nx < size && Ny >= 0 && Ny < size){
                int dis = map[Nx][Ny] + dist[x][y];
                if( dis  < dist[Nx][Ny]){
                    dist[Nx][Ny] = dis;
                    que.push(make_pair(Nx,Ny));
                }
            }
        }
    }
}

int main(){
    
    freopen("input.txt", "r", stdin);
    //테스트 케이스 개수 입력
    int ts = 0;
    scanf("%d", &ts);
    getchar();
    //지도의 크기 입력
    for(int i = 0; i < ts; i++){
        
        
        scanf("%d", &size);
        //입력 받을 배열 생성 및 초기화
        int **map = new int*[size];
        int **dist = new int*[size];
        for(int i = 0; i < size; i++){
            map[i] = new int[size];
            dist[i] = new int[size];
            memset(map[i], -1, sizeof(int)*size);
            //        memset(dist[i], 100, sizeof(int)*size);
        }
        for(int i = 0;i<size;i++){
            for(int j = 0; j < size; j++){
                dist[i][j] = 1000;
            }
        }
        
        string input;
        for(int i = 0; i < size; i++){
            cin >> input;
            for(int j = 0; j < size; j++){
                map[i][j] = input[j]-48;
            }
        }
        
        //방문 여부 배열 생성 및 초기화
        int **visit = new int*[size];
        for(int i = 0; i < size; i++){
            visit[i] = new int[size];
            memset(visit[i], -1, sizeof(int)*size);
        }
        
        BFS(map,visit,dist);
        //Print(dist);
        
        printf("#%d %d\n",i+1,dist[size-1][size-1]);
        
        for(int i = 0; i < size; i++){
            delete []visit[i];
            delete []map[i];
        }
        
        delete []visit;
        delete []map;
        
    }
    return 0;
}

