#include <stdio.h>
#include <iostream>
#include <cstring>

int UD[3] = {0, 0, 1};
int LR[3] = {-1, 1, 0};

void DFS(int y, int x, bool visit[][100], int map[][100], int *ans){
    visit[y][x] = true;
    for(int i = 0; i < 3; i++){ //왼쪽이나 오른쪽에 경로가 존재하면 그 방향으로 진행해야한다.
        int Ny = y + UD[i];
        int Nx = x + LR[i];
        //        printf("%d, %d\n", Ny, Nx);
        if( visit[Ny][Nx] == true )
        {
            //            printf("In if %d, %d\n", Ny, Nx);
            continue; //왜 리턴은 안되냐?
            //return이 안되는 이유는 Ny,Nx(ex]오른쪽)가 true일 때 return을 해버리면 왼쪽, 아래도 탐색을 해야하는데 return을 해서
            //나머지 for문도 실행되지 않고 함수가 종료되어버림. 따라서 왼쪽과 아래는 탐색을 하지 않고 탐색이 종료되어버린다.
            
        }
        else if(Ny >= 0 && Ny < 100 && Nx >= 0 && Nx < 100 ) {
            if( map[Ny][Nx] == 2) {
                *ans = 100;
                visit[Ny][Nx] = true;
                return;
            }
            //범위 안이라면
            if( map[Ny][Nx] == 1 ){
                
                //                printf("%d, %d\n", Ny, Nx);
                DFS(Ny, Nx, visit, map, ans);
                break;
                //                    continue;
            }
        }
    }
    
}

int main(){
    
    freopen("input.txt", "r", stdin);
    int ans = 0;
    //테이스 케이스 입력
    int ts = 0;
    
    for(int i = 0; i < 10; i++){
        scanf("%d", &ts);
        //사다리 map입력
        int map[100][100] = {0};
        bool visit[100][100] = {false};
        
        int input = 0;
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                scanf("%d", &input);
                getchar();//fflush(stdin)을 사용하면 오류가 날 수 있음.
                //0으로 초기화 했기 때문에 1인 놈들만 걸러서 input
                if( input >= 1) {
                    map[i][j] = input;
                }
            }
        }
        for(int i = 0; i < 100; i++){
            if(map[0][i]== 1){
                DFS(0, i, visit, map, &ans);
            }
            if( ans == 100 ) {
                ans = i;
                break;
            }
            for(int j = 0; j < 100; j++){
                for(int k = 0; k < 100; k++){
                    visit[j][k] = false;
                }
            }
        }
        
        //    for(int i = 0; i < 10; i++){
        //        for(int j = 0; j < 10; j++){
        //            printf("%d ",visit[i][j] );
        //        }
        //        printf("\n");
        //    }
        
        
        
        printf("#%d %d\n",i+1, ans);
        ans = 0;
        
        //DFS돌리기 col : 0의 row 중 1인 값들만.
        //하나가 DFS 들어가고 끝까지 탐색 후 visit배열을 초기화 후 재탐색.
    }
    return 0;
}
