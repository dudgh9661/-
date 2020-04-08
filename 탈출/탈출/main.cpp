#include <stdio.h>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int col = 0, row = 0;
int s_short = 0;

int Id = 0;

queue<int> list;
queue<pair<int, int>> que;

int LR[4] = {-1, 1, 0, 0};
int UD[4] = {0, 0, -1, 1};
int tmp = 0;

void Print(int **arr){
    for(int i = 0; i < col; i++){
        for( int j = 0; j < row; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

//물 전용 BFS
void BFS(int **visit, int **map){
    //    queue<pair<int, int>> que;
    //물의초기 위치를 que push.
    
    /*
     for(vector<pair<int,int>>::iterator i = water.begin(); i != water.end(); i++){
     int x = i->first;
     int y = i->second;
     visit[x][y] = -5;
     que.push(make_pair(x, y));
     }
     */
    
    
    //    while( !que.empty() ){
    int nx = que.front().first;
    int ny = que.front().second;
    que.pop();
    
    
    //주변 노드들 방문 후 que에 push
    for(int i = 0; i < 4; i++){
        int nx2 = nx+UD[i];
        int ny2 = ny+LR[i];
        if( nx2 >= 0 && nx2 < col && ny2 >= 0 && ny2 < row ){
            //if(visit[nx2][ny2] == -1 && map[nx2][ny2] != 100 && map[nx2][ny2] != -1000 ){
            //물의 조건
            if(visit[nx2][ny2] != -5 && map[nx2][ny2] != 100 && map[nx2][ny2] != -1000 ){
                //tmp = visit[nx2][ny2];
                visit[nx2][ny2] = -5;
                que.push(make_pair(nx2, ny2));
                list.push(0);
                
                
                
            }
        }
        
    }
    //    }
}

//고슴도치용 BFS
void BFS2(int **visit, int **map){
    /*
     queue<pair<int, int>> que;
     visit[x][y] = 0;
     que.push(make_pair(x, y));
     */
    
    //    while( !que.empty() && s_short == 0 ){
    int nx = que.front().first; // y축...
    int ny = que.front().second; //x축...
    que.pop();
    
    if(visit[nx][ny] != -5){
    //주변 노드들 방문 후 que에 push
    for(int i = 0; i < 4; i++){
        int nx2 = nx+UD[i];
        int ny2 = ny+LR[i]; //printf("BFS2!!!\n");
        //            printf("%d, %d\n", nx2, ny2);
        //            printf("col : %d row : %d\n", col, row);
        
        if( (nx2 >= 0 && nx2 < col) && ny2 >= 0 && ny2 < row ){
            //왜 map[nx2][ny2] == 100 || visit~~ && map 과 다른 결과가 나오나???
            if( ( visit[nx2][ny2] != -5 && visit[nx2][ny2] == -1 && map[nx2][ny2] >= -1) ) {
                visit[nx2][ny2] = visit[nx][ny] + 1;
//                int a = visit[nx2][ny2];
//                printf("px : (%d, %d), nx : (%d, %d), %d\n ",nx,ny,nx2,ny2, a);
                que.push(make_pair(nx2, ny2));
                list.push(1);
                
            }
        }
        
    }
    }
    
    //    }
}



int main(){
    
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &col, &row);
    string element;
    
    int Dx = 0, Dy = 0;
    int Sx = 0, Sy = 0;
    
    
    //물 위치 저장 백터
    vector<pair<int, int>> water;
    
    //지도 배열 map 생성
    int **map = new int*[col];
    for(int i = 0; i < col; i++){
        map[i] = new int[row];
        memset(map[i], -1, sizeof(int)*row);
    }
    
    //방문 여부 배열 생성
    int **visit = new int*[col];
    for(int i = 0; i < col; i++){
        visit[i] = new int[row];
        memset(visit[i], -1, sizeof(int)*row);
    }
    //    Print(map);
    //    Print(visit);
    //    printf("\n");
    for( int i = 0; i < col; i++){
        cin >> element;
        for(int j = 0; j < element.length(); j++){
            if( element[j] == 'D' ) {
                map[i][j] = 100;
                //                visit[i][j] = 100;
                Dx = i;
                Dy = j;
            }
            else if( element[j] == '*') {
                map[i][j] = -100;
                water.push_back(make_pair(i,j));
            }
            else if( element[j] == 'S') {
                map[i][j] = 50;
                Sx = i;
                Sy = j;
            }
            else if( element[j] == 'X'){
                map[i][j] = -1000;
                visit[i][j] = -1000;
            }
        }
    }
    
    
    visit[Sx][Sy] = 0;
    que.push(make_pair(Sx, Sy));
    list.push(1);
    
    //물의 초기 위치를 큐에 삽입
    for(vector<pair<int,int>>::iterator i = water.begin(); i != water.end(); i++){
        int x = i->first;
        int y = i->second;
        visit[x][y] = -5;
        que.push(make_pair(x, y));
        list.push(0);
    }
    water.clear();
    
    //고슴도치 초기 위치를 큐에 삽입
    
    
    
    while( !que.empty() ){
        Id = list.front();
        //        printf("ID : %d\n", Id);
        list.pop();
        if( Id == 0 ) BFS(visit, map); //그 노드가 물이면,
        else if( Id == 1 ) BFS2(visit, map); //그 노드가 고슴도치이면,
    }
    
   
    
    //BFS2를 돌리고 난 후 가장 큰 값이 고슴도치가 target에 도착하는데 걸리는 최단 시간 (x)
    //    printf("고슴도치\n");
    //    BFS2(Sx, Sy, visit, map);
    // printf("s : %d y : %d", Sx, Sy);
    //    printf("\n");
    //    Print(map);
    //    printf("\n");
    //    Print(visit);
    
    /*
     for(int i = 0; i < col; i++){
     for(int j = 0; j < row; j++){
     if( s_short < visit[i][j])
     s_short = visit[i][j];
     }
     }
     //sort 알고리즘이 이상한데...
     */
    //    printf("ddddddd");
    
    //BFS를 돌리고 난 후 target의 상하좌우의 값이 x와 같다면, 고슴도치는 탈출 불가
    //                                    x보다 크다면, 고슴도치는 탈출 가능
    
    /*
     for(int i = 0; i < col; i++){
     for(int j = 0; j < row; j++){
     if( visit[i][j] != -100 ){
     visit[i][j] = -1;
     }
     }
     }
     */
    
    //    BFS(water, Sx, Sy, visit, map); //물이 확장
//    Print(map);
//    printf("\n");
//    Print(visit);
    //    printf("\nshort : %d\n", s_short);
    
    //    printf("\n %d %d\n", Dx, Dy);
    /*
     int ans = s_short - 1;
     for(int i = 0; i < 4; i++){
     int RDx = Dx+LR[i];
     int RDy = Dy+UD[i];
     if( RDx >= 0 && RDx < row && RDy >=0 && RDy < col){
     if( visit[RDx][RDy] > ans || visit[RDx][RDy] == -1) {
     printf("%d\n", s_short);
     for(int i = 0; i < col; i++){
     delete []map[i];
     delete []visit[i];
     }
     
     delete[] map;
     delete[] visit;
     
     return 0;
     }
     */
    
    /*
     if( visit[RDx][RDy] == s_short-1){
     printf("KAKTUS\n");
     for(int i = 0; i < col; i++){
     delete []map[i];
     delete []visit[i];
     }
     
     delete[] map;
     delete[] visit;
     
     return 0;
     }
     */
    if( visit[Dx][Dy] > 0 ){
        printf("%d", visit[Dx][Dy]);
    }
    else  printf("KAKTUS\n");
    
    
//    printf("%d\n",s_short);
   
    //메모리 해체
    for(int i = 0; i < col; i++){
        delete []map[i];
        delete []visit[i];
    }
    
    delete[] map;
    delete[] visit;
    
    return 0;
    
}
