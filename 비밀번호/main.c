#include <stdio.h>

char str[101];
int stack[101] = { 0 };
int length = 0;

void input() {

    scanf("%d", &length);
    scanf("%s", str);
}

void recur() {
//    input();
    int end = 0;

    while(1) {

        int flag = 1;
        for (int i = 0; i <= length; i++) {

            if (str[i] == '\0') {
                end = i;
                break;
            }
        }

        for (int i = 0; i < end; i++) { //문자열의 끝까지 탐색한다.
            if (str[i] == str[i + 1]) { //같은게 있으면
                flag = 0;
                str[i] = 'x'; //바꿔주고
                str[i + 1] = 'x';

                for(int k = i; k <= end; k++) {
                    str[k] = str[k+2];
                    //뒤에 놈들을 앞으로 앞당긴다.
                }
            }
//            break;
        }
        if( flag == 1 ) break;
    }
}

int main() {
    for(int TC = 1; TC <= 10; TC++) {
        input();
        recur();
        printf("%s", str);
    }
    return 0;
}
