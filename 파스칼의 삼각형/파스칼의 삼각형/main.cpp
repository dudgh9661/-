#include <stdio.h>

int main()
{
    int test_num = 0;
    scanf("%d", &test_num);
    for(int a = 0; a < test_num; a++)
    {
        
    int num = 0;
    scanf("%d", &num);
    printf("#%d\n", a+1);
    int arr[12][12] = { 0 };
    
    for( int i = 0; i < 12; i++) arr[i][0] = {1};
    
    for( int i = 1; i < num; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
        }
    }

    // 출력
    for (int row = 0; row < num; row++ ){
        for(int col = 0; col <= row; col++)
        {
            printf("%d ", arr[row][col]);
        }
            printf("\n");
        
    }
    
    }
    
    return 0;
}

