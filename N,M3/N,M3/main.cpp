#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> vec;
void DFS(int count) {
    if( count == M ) {
        for(int i = 0; i < vec.size(); i++) {
            printf("%d ", vec[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1; i <= N; i++) {
        vec.push_back(i);
        count++;
        DFS(count);
        count--;
        vec.pop_back();
    }
    
}
int main() {
    
    cin >> N >> M;
    DFS(0);
    return 0;
}
