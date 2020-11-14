//
//  main.cpp
//  알람 시계
//
//  Created by 김영호 on 2020/08/18.
//  Copyright © 2020 김영호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int H, M;
    scanf("%d %d", &H, &M);
    //1. 만약에 M이 45보다 작으면
    if( M < 45 ) {
        if( H == 0 ) {
            H = 23;
            M =  M + 60 - 45;
        }
        else {
            H--;
            M =  M + 60 - 45;
        }
    } else {
        M = M - 45;
    }
    
    printf("%d %d", H, M);
    //1-1. H - 1을 해준다. ( 0 일 경우는 23으로 해준다. )
    //1-2. M = M + 60 - 45가 된다.
    
    return 0;
}
