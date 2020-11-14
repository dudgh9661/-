#include <stdio.h>
#include <vector>

using namespace std;

int N;
vector<int> vec;
bool visit[50];

void DFS(int count) {
    if( count == N ) {
        for(int i = 0;  i < vec.size(); i++) {
            printf("%d ", vec[i]);
        }
        printf("\n");
    }

    for(int i = 1; i <= N; i++) {
        if( visit[i] ) continue;

        else if ( !visit[i] ) {
            visit[i] = true;
            vec.push_back(i);
            DFS(count+1);
            visit[i] = false;
            vec.pop_back();
        }
    }
}

int main() {

    scanf("%d", &N);
    DFS(0);
    return 0;
}