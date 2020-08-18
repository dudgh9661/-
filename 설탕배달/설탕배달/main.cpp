#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int weight = 0;
    scanf("%d", &weight);
    
    int answer = 0;
    
    //1. 완전히 나누어 떨어질 때
    if( weight % 5 == 0 ) {
        answer = weight / 5;
//        printf("in 5 : %d\n", answer);
        
    } else if ( weight % 3 == 0 ) {
        answer = weight / 3;
//        printf("in 3 : %d\n", answer);
        
    }
    if( answer == 0 ) answer = 100000;
    //2. 완전히 나누어 떨어지지 않을 때
    int five = 0;
    int i = 1;
    int MAX = answer;
    while ( five < weight) {
        five = five + 5;
//        printf("five : %d\n", five); //15
        int mok = weight - five; // -3 = 12 - 15
        if( mok < 0 ) {
            if( answer == 100000 ) { //위에서도 답이 안나온 경우
                printf("-1");
                return 0;
            } else { //위에서 답이 나온 경우
                printf("%d\n", answer);
                return 0;
            }
           
        }
//        printf("mok : %d\n", mok);
        if( mok % 3 == 0 ) {
            answer = mok / 3 + five / 5;
//            printf("답 계산 결과는 %d\n", answer);
            answer = min(MAX, answer);
//            printf("max answer : %d\n", answer);
        }
    }
    
    printf("%d", answer);
    return 0;
}
