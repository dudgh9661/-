#include <sys/types.h>
#include <regex.h>
#include <libgen.h>
#include <stdio.h>
#include <string.h>

int main()
{
    regex_t regex;
    regmatch_t matches[20];
    
    int cnt = 0;
    int length = 0;
    const char* pattern = "3+|6+|9+";
    char data[10]="\0";
    
    int num = 0;
    scanf("%d", &num);
    
    for( int k = 1; k <= num; k++)
    {
        char buf[256]="\0";
        sprintf(buf, "%d", k);
        //printf("buf : %s", buf);
        int result;
        result = regcomp( &regex, pattern, REG_EXTENDED);// 정규식을 정의
 //   printf("%d\n", result);
        if ( regexec ( &regex, buf, 20, matches, 0) == 0 ) //입력된 값이 정규식에 포함되었지를 확인
        {
        //중요한 건, 이 패턴 안에 3,6,9가 몇번이 반복되느냐를 찾는 것이 문제이다.
            strcpy(data, buf);
       // printf("fffff%c\n", data[1]);
            for(int i = 0; i < strlen(data); i++)
            {
                if( data[i] == '3' || data[i] == '6' || data[i] == '9') cnt++;
            }
        //printf("%d\n", cnt);
        
            for( int i = 0; i < cnt; i++)
            {
                //printf("buf : %s ", buf);
                printf("-");
            }
            printf(" ");
        //printf("%s", data);
        }
        else
            printf("%d ", k);
        
        cnt = 0;
    
    //printf("not if cnt : %d\n", cnt);
        regfree(&regex);
    }
    return 0;
}
