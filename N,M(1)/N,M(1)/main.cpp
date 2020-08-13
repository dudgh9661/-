#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> vec;
bool visit[9] = {false};

void DFS(int count) {
    if( count == M) {
        
        for(int i = 0; i < vec.size(); i++) {
//            printf("Hi?");
            printf("%d ", vec[i]);
        }
        printf("\n");
        return;
    }
    
    for(int i = 1; i <= N; i++) {
        if ( visit[i] == false ) {
            visit[i] = true;
            vec.push_back(i);
            count++;
//            printf("count : %d\n", count);
            DFS(count);
            count--;
            visit[i] = false;
            vec.pop_back();
        }
    }
}

int main() {
    cin >> N >> M;
    DFS(0);
    return 0;
}
