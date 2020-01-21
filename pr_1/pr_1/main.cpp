#include <stdio.h>
#include <string.h>

int main()
{
    int num = 0;
    scanf("%d", &num);

    for(int l = 0; l < num; l++)
    {
    char str[31] ="0";
    char buf[31] ="0";
    scanf("%s", str);
    /*
    1. 첫번째 문자와 같은 문자가 나오면, 그 전까지의 문자들과 그 후에 같은 길이만큼의 문자를 비교
    맞다면, 그것이 패턴
    아니라면,
    그 다음 같은 문자가 나올 때까지 문자열을 저장하고 똑같이 반복
    */
    int i = 0;
    int copy_num = 0;
    
    int sol=0;
    int same_cnt=0;
    while( i < strlen(str) )
    {
        buf[copy_num] = str[copy_num];
        if( buf[0] == str[copy_num+1])
        {
            for(int itr = 0; itr < copy_num+1; itr++)
            {
               // printf("copynum : %d\n ", copy_num);
               // printf("buf : %c ", buf[itr]);
               // printf("str : %c ", str[itr]);
                if( buf[itr] == str[copy_num+1+itr])
                {
                    //printf("itr : %d ", itr);
                    same_cnt++;
                    //printf("same_cnt : %d \n", same_cnt);
                    if( same_cnt == copy_num) //copy_num은 패턴수. 5
                    {
                        sol = same_cnt;
                        printf("#%d %d\n",l+1, sol+1);
                        
                        //printf("\n\n break \n\n");
                        break;
                        
                    }
                    
                    //printf("1\n");
                }
                
                //printf("2\n");
            }
           if( same_cnt == copy_num) //copy_num은 패턴수. 5
                              {
                                  sol = same_cnt;
                                  //printf("ssssssssolllllll : %d ", sol+1);
                                   
                                 // printf("\n\n break \n\n");
                                  break;
                                  
                              }
        

           // printf("3\n");
                
        }
        
        copy_num++;
        i++;
    }
    }
    
}

