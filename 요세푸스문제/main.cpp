#include <queue>
#include <stdio.h>

using namespace std;

queue<int> que;
vector<int> ans;
int main() {

    int N, M;
    scanf("%d %d", &N, &M);

    for( int i = 1; i <= N; i++) {
        que.push(i);
    }

    int cnt = 0;
    while( !que.empty() ) {
        int front = que.front();
        que.pop();
        cnt++;
        if( cnt < M  ) que.push(front);
        else if ( cnt == M ) {
            cnt = 0;
            ans.push_back(front);
        }

    }

    printf("<");
    for(int i = 0; i < ans.size() - 1; i++) {
        printf("%d, ", ans[i]);
    }
    printf("%d", ans[ans.size()-1]);
    printf(">");
    return 0;
}