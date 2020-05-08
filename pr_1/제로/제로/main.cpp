#include <stdio.h>
#include <stack>
//#include <iostream>
using namespace std;
int main()
{
    
    freopen("input.txt", "r", stdin);
    stack<int> stack;
    int input = 0;
    int test = 0;
    int test_case = 0;
    scanf("%d", &test_case);
    for( int i = 0; i < test_case; i++)
    {
        
        
    
    scanf("%d", &test);
    
    for(int i = 0; i < test; i++){
        scanf("%d", &input);
//        printf(" input : %d ", input);
        if( input == 0) {
            stack.pop();
        }
        else stack.push(input);
//        printf("stack %d : %d\n", i, stack.top());
    }
    
    int itr = stack.size();
    /*
    for( int i = 0; i < itr; i++)
    {
        printf("stack size %d ; %d \n", i, stack.size());
        printf("stack %d : %d \n", i, stack.top());
        stack.pop();
    }
    */
    
    int sum = 0;
    
    for(int i = 0; i < itr; i++){
        sum = sum + stack.top();
//        printf("sum %d ; %d\n", i, sum);
        stack.pop();
    }
    
    printf("#%d %d\n",i+1, sum);
        
        
    }
     
    return 0;
}
