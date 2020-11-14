#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;
int main()
{
    int N = 0, M = 0, time = 0;
    
    freopen("input.txt", "r", stdin);
    scanf("%d", &time);
    for(int k = 0; k < time; k++)
    {
        
    scanf("%d %d", &N, &M);
    //printf("%d", M);
    int tmp = 0;
    int max = 0;
    
    int rowc = 0, colc = 0;
    
    vector< vector<int> > arr(N, vector<int>(N) ); // arr[num][num]
    //printf("%d")
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int element = 0;
            scanf("%d", &element);
            arr[i][j] = element;
//            printf("%d %d", i,j);
        }// arr을 0으로 초기화
    }

/*    for( int i = 0; i < N; i++)
    {
        for( int j = 0; j < N; j++) printf("%d ", arr[i][j]);
        printf("\n");
    }
    */
 
    
    int f = 0, s = 0;
    
    for( int cycle = 0; cycle < (N-1)*(N-1); cycle++)
    {
        
        for(int row = f; row < M+f; row++)
        {
            if(row == N) break;
           // rowc = row;
            for(int col = s; col < M+s; col++)
            {
                if( col == N) break;
       //        printf("f : %d s : %d , arr[%d][%d]\n", f, s, row, col);
                tmp = tmp + arr[row][col];
                
            }
              
        }
//        printf("\n");
            
    
//    printf("tmp : %d ", tmp);

        if( max < tmp )
        {
//            printf("row : %d col : %d \n", rowc, colc);
            max = tmp;
        }

        tmp = 0;
        
        s++;
        if(s == N-1) // 한줄을 다 계산했다면,
        {
           // printf("\n come in\n ");
            //if( f < N)
                f++;
            s = 0;
        }
        //tmp = 0;
    }
    
    
    printf("#%d %d\n",k+1, max);
    arr.clear();
      
    
        
   }//end
    
    
    
    
}

