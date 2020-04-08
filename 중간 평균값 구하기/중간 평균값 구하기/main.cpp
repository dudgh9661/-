#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>


//소수 첫째자리에서 반올림 해주는 함수 작성
int round(int num)
{
    int x = 10000;
    while( num > 10) {
        if ( (num / x) != 0 ){
            num = num % x;
        }
        x = x / 10;
    }
//    printf("최종 나머지 : %d", num);
    return num;
}
using namespace std;
int main()
{
    freopen("input.txt","r", stdin);
    int test = 0;
    scanf("%d", &test);
    
   for( int i = 0; i < test; i++)
   {
    int arr[10] = {0};
        int input = 0;

        for(int j = 0; j < 10; j++){
            scanf("%d", &input);
            arr[j] = input;
        }
        
        //for(int i = 0; i < 10; i++) printf("%d ", arr[i]);
    
    sort(arr, arr+10, less<int>()); //오름차순
    int sum = 0;
    float sum2 = 0;
    for(int i = 1; i < 9; i++){
        sum = sum + arr[i];
        sum2 = sum2 + arr[i];
//        printf("%d ", arr[i]);
    }
//    printf("\nsum = %d\n", sum);
    double tmp = sum2 / 8;
//    printf("/8한 수 : %lf \n", tmp);
    int tmp2 = tmp *10;//한 자리수를 높혀 tmp에 수를 저장
//    printf("*10한 수 : %d \n", tmp2);
    int center = round(tmp2); //첫째 자리수 판단
//    printf("center = %d\n", center);
    tmp2 = tmp2 / 10;
    if( center >= 5 )
    {
        tmp = tmp + 1;
        sum = tmp;
    }
    else sum = tmp2;
    
    printf("#%d %d\n",i+1, sum);
    
    
    
    
    }
    

    return 0;
}
