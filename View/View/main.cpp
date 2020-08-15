#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// flag == 0 이면 좌, 우로 2칸씩 세대가 없다는 것을 의미한다. 그러므로 count를 늘려준다.

void Print( int arr[256][1001]) {
    for(int i = 0; i < 256; i++) {
        for(int j = 0; j < 8; j++){
            printf("%d", arr[i][j]);
            //                printf("dfkaldjfad;");
        }
        printf("\n");
    }
}

int arr[256][1001] = { 0 };

int test = 0;


int RDFS( int height, int ground, int flag, int cnt) {
    //1-1. 만약 세대가 있다면 다음 세대를 찾아간다.
    //1-2. 만약 세대가 없다면, 조망권을 획득한 세대로 기록한다.
    
    int right = ground + 1;
    //    int left = ground - 1;
    
    if( cnt == 2 ) {
        return flag;
    }
    
    
    if( arr[height][right] == 0 ) {
        cnt++;
        flag = RDFS(height, right, flag, cnt);
    } else if ( arr[height][right] == 1 ) {
        flag = 1;
        return flag;
    }
    
    return flag;
}

int LDFS( int height, int ground, int flag, int cnt) {
    //1-1. 만약 세대가 있다면 다음 세대를 찾아간다.
    //1-2. 만약 세대가 없다면, 조망권을 획득한 세대로 기록한다.
    
    int left = ground - 1;
    //    int left = ground - 1;
    
    if( cnt == 2 ) {
        return flag;
    }
    
    
    if( arr[height][left] == 0 ) {
        cnt++;
        flag = LDFS(height, left, flag, cnt);
    } else if ( arr[height][left] == 1 ) {
        flag = 1;
        return flag;
    }
    
    return flag;
}


int main() {
    
    freopen("input.txt", "r", stdin);
    int count = 0;
    //빌딩 정보를 저장할 공간
    // [1]부터 시작, 높이는 255~1까지 만약 255층이다 그러면 255,254, ... , 1
    
    for(int i = 0; i < 10; i++) {
        
        //초기화
        for(int init = 0; init < 256; init++) {
            for(int init2 = 0; init2 < 1001; init2++) {
                arr[init][init2] = 0;
            }
        }
        int size = 0;
        scanf("%d", &size);
        
        int input = 0;
        
        for(int ground = 1; ground <= size; ground++) {
            scanf("%d", &input);
            for ( int height = 255;  height > 255 - input; height--) {
                arr[height][ground] = 1;
            }
        }
        
        //    Print(arr);
        
        
        // 가장 왼쪽, 가장 오른쪽 2칸은 건물이 없다.
        //모든 배열을 돌며 세대인지 아닌지를 체크한다.
        
        for(int ground = 3; ground <= size - 2; ground++) {
            for(int height = 255; height > 0; height--) {
                if( arr[height][ground] == 1 ) {
                    if( RDFS(height, ground, 0, 0) == 0 && LDFS(height, ground, 0 ,0) == 0)
                        count++;
                }
            }
        }
        
        //    printf("\n test : %d\n", arr[255][3]);
        printf("%d\n", count );
        count = 0;
    }
    return 0;
}
