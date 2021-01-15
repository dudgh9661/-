#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <iostream>

using namespace std;

int N, M;
bool isPossible = true;
int inDegree[1001] = { 0 };

vector<int> result;
vector<int> vec[1001];
vector<int> tmp;

void init() {
    cin >> N >> M; //가수 번호, 보조피디의 수
    int singer;
    for(int i = 1; i <= M; i++) {
        cin >> singer;
        int input;

        for(int j = 0; j < singer; j++) {
            cin >> input;
            tmp.push_back(input);
        }
        for(int itr = 0; itr < tmp.size()-1; itr++) {
            int from = tmp[itr];
            int to = tmp[itr+1];
            vec[from].push_back(to);
        }
        tmp.clear();
        tmp.resize(0);
    }

    //inDegree 초기화
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < vec[i].size(); j++) {
            int to = vec[i][j];
            inDegree[to]++;
        }
    }
}
void topologicalSort() {
    queue<int> que;

    for(int i = 1; i <= N; i++) {
        if( inDegree[i] == 0 ) {
            que.push(i);
        }
    }

    for(int i = 1; i <= N; i++) {
        if( que.empty() ) {
            isPossible = false;
            return;
        }

        int front = que.front();
        result.push_back(front);
        que.pop();
        for(int itr = 0; itr < vec[front].size(); itr++) {
            int to = vec[front][itr];
            if( --inDegree[to] == 0 ) {
                que.push(to);
            }
        }
    }
}
int main() {
    init();
    topologicalSort();
    if( !isPossible ) printf("0");
    else {
        for(int i = 0; i < result.size(); i++) {
            printf("%d\n",result[i]);
        }
    }
    return 0;
}
