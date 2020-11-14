#include <stdio.h>
#include <string.h>

int main() {
    char res[20];
    char *arr[10] = { NULL } ; int idx = 0;
    char *ptr;

    scanf("%[^\n]s", res);
    // printf("%s",res);


    ptr = strtok(res, " ");

    while( ptr != NULL) {
        arr[idx] = ptr;
        idx++;

        ptr = strtok(NULL, " ");
    }

    for(int i = 0; i < idx; i++) {
        if( arr[i] != NULL ) {
            printf("%c\n", *arr[i]);
        }
    }


}