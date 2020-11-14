#include <iostream>
#include <stdio.h>
#include <queue>

using namespace  std;

int main() {
    // N이 주어졌을 때, 버린 카드들을 순서대로 출력하고, 마지막에 남게 되는 카드를 출력하는 프로그램을 작성하시오.
    int N = 0;
    scanf("%d", &N);

    queue<int> card;

    for(int i = 1; i <= N; i++) {
        card.push(i);
    }

    vector<int> drop;

    // N=4인 경우를 생각해 보자. 카드는 제일 위에서부터 1234 의 순서로 놓여있다.
    // 1을 버리면 234가 남는다. 여기서 2를 제일 아래로 옮기면 342가 된다.
    // 3을 버리면 42가 되고, 4를 밑으로 옮기면 24가 된다.
    // 마지막으로 2를 버리고 나면, 버린 카드들은 순서대로 1 3 2가 되고, 남는 카드는 4가 된다.

//    int numOfCard = N;
    int flag = 1;
    while( !card.empty() ) {
        // 1일 땐 버린다.
        if( card.size() == 1 ) {
            int front = card.front();
            drop.push_back(front);
            break;
        }


        if( flag == 1) {
            int front = card.front();
            card.pop();
            drop.push_back(front);
            flag = 0;
        } else if ( flag == 0 ) {
            int front = card.front();
            card.pop();
            card.push(front);
            flag = 1;
        }

    }

    for(int i = 0; i < drop.size(); i++) {
        printf("%d ", drop[i]);
    }
    return 0;
}
