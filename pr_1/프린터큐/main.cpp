#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;


void Print(queue< pair <int,int> > que) {
    while ( !que.empty() ) {
        printf("{ %d, %d } ", que.front().first, que.front().second);
        que.pop();
    }
    printf("\n");
}

int main() {
    int TC = 0;
    scanf("%d", &TC);

    for(int tc = 0; tc < TC; tc++) {
        int N = 0, M = 0;
        scanf("%d %d", &N, &M);

//    INPUT(N);
//    string input;
//    cin >> input;
        //공백처리...시발거

        int pos = M;
        int target = 0;

        vector<int> vec;
        queue<pair<int, int> > que;
        for (int i = 0; i < N; i++) {
            int input = 0;
            scanf("%d", &input);
//        printf("NUM : %d\n", input);
            que.push({i, input});
            if (i == pos) target = i;
            vec.push_back(input);
//        printf("input ( %d, %d )\n", i, input);

        }

        sort(vec.begin(), vec.end(), greater<int>()); // 9 1 1 1 1 1

        int cnt = 0;
        int vecIdx = 0;


        while (!que.empty()) {
            //0. 타겟번호인지 아닌지 검사


//        Print(que);

            int MAX = vec[vecIdx];

            int idx = que.front().first;
            int number = que.front().second;
//        printf("MAX : %d, { %d, %d } \n", MAX, idx, number);
            que.pop();

//        if( idx == target ) { //만약 타겟이면
//            break;
//        }
            //1. pop한 놈이 최댓값이 아니면,
            if (number != MAX) {
                //1-1. 다시 큐에 넣어라.
                que.push({idx, number});
            }
                //1-2. 만약 최댓값이면 팝해라.
            else if (number == MAX) {

                if (idx == target) { //만약 타겟이면
                    cnt++;
                    break;
                }

//            printf("pop : %d\n", number);
//            que.pop();
                vecIdx++;
                cnt++;
            }

        }

        printf("%d\n", cnt);
    }
    return 0;
}