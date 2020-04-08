#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

int col = 0, row = 0;
int maxs = 0;

void Print(int **map, int **visit){
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            printf("%d ",visit[i][j]);
        }
        printf("\n");
    }
}

int arr2[4] = {-1, 1, 0, 0};//상하
int arr[4] = {0, 0, -1, 1}; //좌우
int cnt  = 0;
void BFS(queue<pair<int, int>> que, int **visit, int **map){
    
    while(!que.empty()){
        int popx = que.front().first;
        int popy = que.front().second;
        que.pop();
        
        if( maxs < visit[popx][popy])
        {
            maxs = visit[popx][popy];
        }
        
        
        for(int i = 0; i < 4; i++){
            int elementx = popx+arr2[i];
            int elementy = popy+arr[i];
            if( (elementx >= 0 && elementx < col) && (elementy >= 0 && elementy < row) && map[elementx][elementy] == 0
               && visit[elementx][elementy] == -1 ){
                {
                    visit[elementx][elementy] = visit[popx][popy] + 1;
                    map[elementx][elementy] = 1;
                    que.push(make_pair(elementx, elementy));
                    cnt++;
                    
                }
            }
        }
        
    }
    
}

int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &row, &col);
    if( row < 2 || row > 1000 || col < 2 || col > 1000) return 0;
    //토마토 상자 초기화
    int **map = new int*[col];
    for(int i = 0; i < col; i++){
        map[i] = new int[row];
        memset(map[i], -1, sizeof(int)*row);
    }
    //거리 배열 초기화
    int **visit = new int*[col];
    for(int i = 0; i < col; i++){
        visit[i] = new int[row];
        memset(visit[i], -1, sizeof(int)*row);
    }
    
    vector<pair<int, int>> tom;
    queue<pair<int, int>> que;
    //    printf("\n");
    
    int ele = 0;
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            scanf("%d", &ele);
            map[i][j] = ele;
            if( ele != 0 ) cnt++;
            if( ele == 1 ) {
                que.push(make_pair(i,j));
                visit[i][j] = 0;
                
            }
            
            //fflush(stdin); ***********stdin대상으로 fflush는 사용하지 않아야 하더라... 대신, getchar();로 대체!!
        }
    }
    //    Print(map, visit);
    //    printf("\n");
    
    BFS(que, visit, map);
    tom.clear();
    
    //모두 익지 못할 경우
    if(cnt != col*row ) {
        printf("-1\n");
//        return 0;
    }
    
        Print(visit,map);
    //    printf("cnt : %d\n", cnt);
    
    printf("%d\n", maxs);
    //메모리 해체
    for(int i = 0; i < col; i++){
        delete [] map[i];
        delete [] visit[i];
    }
    
    delete [] map;
    delete [] visit;
    
    
    return 0;
}
