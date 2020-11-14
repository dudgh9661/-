#include <stdio.h>
#include <math.h>

int main() {
    int num;
    scanf("%d", &num);
    

    for(int i = 0; i < num; i++) {
        int input = 0;
        int input2 = 0;
        scanf("%d %d", &input, &input2);
        // int sum = input;
        int sum = 1;
        for(int itr = 0; itr < input2; itr++) {
            sum = sum * input;
            sum = sum % 10;
            // printf("sum : %d\n", sum);
        }
        if( sum == 0 ) sum = 10;
        printf("%d\n", sum);
    }

}