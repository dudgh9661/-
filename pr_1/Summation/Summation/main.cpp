#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
    freopen("input.txt","r", stdin);
    int test = 0;
    scanf("%d", &test);
    cin.ignore(256, '\n');
   
    for(int i = 0; i < test; i++){
        string input_tmp;
        getline(cin, input_tmp);

        char str[input_tmp.size()];
        //strtok사용하여 공백 단위로 스트링 분리.
        strcpy(str, input_tmp.c_str());

        
        int max = -5, min = 100000;
        string str_num;
        int sum = 0;
        char *tok = strtok(str," ");
        for(int i = 0; i < 10; i++){
            
            if(tok != NULL){
                str_num = string(tok);
                tok = strtok(NULL," ");
                
            }
            
            sum = 0;
            
            int change = 0;
            //    cout << str_num[0];
            for(int i = 0; i < str_num.length(); i++){
                change = (int)str_num[i] - 48;
                //                            printf("int ; %d\n", change);
                sum = sum + change;
            }
            if( max < sum ) max = sum;
            if( min > sum ) min = sum;
            
            
            
            
            
            
        }
        //cin.clear();
        printf("#%d %d %d\n",i+1, max,min);
        
    }
    
    
    return 0;
}
