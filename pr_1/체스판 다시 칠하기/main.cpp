#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M ;
    int MIN = 100;
    scanf("%d %d", &N, &M);

    vector<string> vec;
    string input;

    for(int i = 0; i < N; i++) {
        cin >> input;
        vec.push_back(input);
    }

    for(int rowItr = 0; rowItr <= N - 8; rowItr++) { //행 이동범위

        //행 이동
            for(int colItr = 0; colItr <= M - 8; colItr++) { //열 이동 범위
                char ch = 'W';
                char ch2 = 'B';

                for (int twice = 0; twice < 2; twice++) {

                    int count = 0;

                    for (int row = rowItr; row < 8 + rowItr; row++) {
//                        printf("\nrow : %d\n", row);
                        int num = row % 2 + colItr;
                        int num2 = (row + 1) % 2 + colItr;

                        for (int col = colItr; col < 4 + colItr; col++) { //열 이동
//                            printf("( col %d, %d , %d )\n", col, num, num2);
                            if (vec[row][num] != ch) {
//                                printf("num : vec[%d][%d] = %c, ch : %c\n", row, num, vec[row][num], ch);
                                count++;
                            }
                            if (vec[row][num2] != ch2) {
//                                printf("num22 : vec[%d][%d] = %c, ch : %c\n", row, num, vec[row][num2], ch2);
                                count++;
                            }
                            num += 2;
                            num2 += 2;
                            if (num >= M || num2 >= M) break;
                        }
                    }

                    MIN = min(count, MIN);
//                    printf("minimum : %d\n", MIN);
                    ch = 'B';
                    ch2 = 'W';
                }

//                printf("\n\nend twice!!\n");
            }
    }

    printf("%d", MIN);

    return 0;
}
