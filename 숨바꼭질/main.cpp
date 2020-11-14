#include <iostream>
#include <vector>
#include <queue>

#define MAX 100001
using namespace std;

bool visit[MAX] = { false };
int Subin, brother;
int answer = 0;

void BFS(int start, int Time) {
    queue< pair<int, int> > que;
    que.push( {start, Time} );
    visit[start] = true;

    while( !que.empty() ) {
        int current = que.front().first;
        int Time = que.front().second;

//        printf("c : %d t : %d\n", current, Time);

        if( current == brother ) {
            answer = Time;
            return;
        }
        que.pop();

        if( current + 1 < MAX && !visit[current + 1]) {
            visit[current + 1] = true;
            que.push( {current + 1, Time + 1});
        }
        if( current - 1 >= 0 && !visit[current - 1]) {
            visit[current - 1 ] = true;
            que.push({current - 1, Time + 1});
        }
        if( current * 2 < MAX && !visit[current * 2] ) {
            visit[current * 2] = true;
            que.push( {current * 2, Time + 1});
        }


    }

}
int main() {
    scanf("%d %d", &Subin, &brother);

    int start = Subin;
    //1. 앞으로 갈 경우 +1
    //2. 순간이동 쓸 경우 *2
    //3. 뒤로 갈 경우 -1
    BFS(start, 0);
    printf("%d\n", answer);
    return 0;
}
