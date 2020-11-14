#include <stdio.h>
#include <string.h>

int arr[26] = { 0 };

int main() {
    char input[101];
    scanf("%s", input);

    for(int i = 0; i < strlen(input); i++) {
        int idx = input[i] - 97;
        arr[idx]++;
    }

    for(int i = 0; i < 26; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
