#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    //D : 필름 두께, W : 가로 크기, K : 합격 기준
    int D = 0, W = 0, K = 0;
    scanf("%d %d %d", &D, &W, &K);
    getchar();
    
    int **map = new int*[D];
    int **need = new int*[D];
    for(int i = 0; i < D; i++){
        map[i] = new int[W];
        need[i] = new int[W];
        memset(map[i], 0, sizeof(int)*W);
        memset(need[i], -1, sizeof(int)*W);
    }
    //input data
    int input = 0;
    for(int i = 0; i < D; i++){
        for(int j = 0; j < W; j++){
            scanf("%d ", &input);
            if( input == 1 ){
                map[i][j] = input;
            }
        }
    }
    // need array에 필요한 약품 기록
    //한 row을 조사하여 부족한 약품을 찾는다.
    //1. row의 갯수만큼 for문을 돌린다.
    int cnt = K-1; //cnt는 성분 통과 기준.
    int test = 0;
    for(int row = 0; row < W; row++){
        int one = 0; //1의 개수
        int zero = 0; //0의 개수
        int *numbers = new int[K];
        memset(numbers, 0, sizeof(int)*K );

        for(int idx = 0; idx < D-K; idx++){
            
            for(int dn = 1; dn < K; dn++){
                //1-1. 만약 성분 테스트를 통과하는 row라면 다음 row로 이동한다.
                //1-2. K만큼 for문을 돌려서 성분 통과(K)를 할 수 있게 만드는 약품과 약품이 들어가야 할 위치를 찾아서 같은 위치의 need배열에 저장
                if( map[idx][row] == map[idx+dn][row] ){
                    cnt--;
                }
            } //여기까지가 밑으로 K만큼 숫자 비교하는 for문
            
                if( cnt == 0 ) { //성분 테스트를 통과하는 경우!
                    test = 1;
                    break; //row for문으로 탈출.
                }
        } //기준점 idx에 대한 for문.
        
        //다 돈 시점.
        if( test == 0 ) { //다 돌아봤더니 성분을 통과하지 못하는 조건이다.
            if( map[0][row] == 1 ) {
                numbers[0] = 1;
                one++;
            }
            
            else if ( map[0][row] == 0 ) {
                numbers[0] = 0;
                zero++;
                
            }
            
            for(int i = 1; i < K; i++){
                if( map[0][row] != map[i][row] ) {
                    if( map[i][row] == 1 ) {
                        numbers[i] = 1;
                        one++;
                    }
                    else if ( map[i][row] == 0 ) {
                        numbers[i] = 0;
                        zero++;
                    }
                }
            }//통과하지 못한 조건을 가진 row에서 가장 위에서 K만큼 비교 후 주입해야할 성분 찾기 for문 끝
            
            for(int i = 0; K; i++){
                if( one > zero ){ // 0 -> 1
                    for(int j = 0; j < K; j++){
                        if( numbers[j] == 0 ) need[j][row] =
                    }
                }
            }
            
                
            }
        }
    }
    
    
    //가장 높은 cnt를 가지는 놈을 각 row 별로 저장할 저장소
    int *max_arr = new int[D];
    memset(max_arr, 0, sizeof(int)*D);
    
    
    
    
    for(int i = 0; i < D; i++){
        for(int j = 0; j < W; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}
