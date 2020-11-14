#include <stdio.h>
#include <string.h>
#include <ctype.h>

char ch[5][16] = { 0 };

void Print() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < sizeof(ch[i]) / sizeof(char); j++) {
            printf("%c", ch[i][j]);
        }
        printf("\n");
    }
}

int max( int a, int b ) {
    if ( a > b ) return a;
    else if ( a < b ) return b;
    else if ( a = b ) return a;
}

int main() {
    int MAX = 0;

    for(int i = 0; i < 5; i++) {
       char input[16] = "\n";
       scanf("%s", input);

       for(int j = 0; j < strlen(input); j++) {
           MAX = max(MAX, strlen(input));
           ch[i][j] = input[j];
       }
    }

    for(int col = 0; col < MAX; col++) {
        for(int row = 0; row < 5; row++) {
            char output = ch[row][col];
            if( isalpha(output) == 0 && isdigit(output) == 0) {
                continue;
            }
            printf("%c", output);
        }
//        printf("\n");
    }
    return 0;
}
