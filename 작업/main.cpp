/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> order;
vector<int> node[10001]; //연결 정보
int value[10001]; // 해당 노드가 작업하는데 걸리는 시간
int inputArrow[10001] = { 0 };
vector<int> ans(10001,0);

int N;

void init() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int val, jobNum, preJobNode;
        cin >> val >> jobNum;
        value[i] = val;
        
        
        // to do:  이곳에 작업이 하나도 없는 노드에 대한 인풋 예외처리 필요

        for(int j = 0; j < jobNum; j++) {
            cin >> preJobNode; 
            node[preJobNode].push_back(i); // i번째를 위해 선행되어야할 노드
            //inputArrow init
            inputArrow[i]++;
        }
    }
}

void sol() {
    queue<int> que;
    
    // inputArrow == 0 인 node를 que에 push
    for(int i = 1; i <= N; i++) {
        if( inputArrow[i] == 0 ) {
            que.push(i);
            ans[i] = value[i];
        }
    }
        
     // pop한 노드와 연결된 간선 제거
    for(int i = 1; i <= N; i++) {
        int front = que.front();
        que.pop();
        
        order.push_back(front);
        
        for(int j = 0; j < node[front].size(); j++) {
            int arrow = node[front][j];
            if( --inputArrow[arrow] == 0 ) { // 모든 간선이 제거되면, 선행작업들이 완료됐다는 의미
                que.push(arrow);
            }
            ans[arrow] = max(ans[arrow], ans[front] + value[arrow]);
        }
        
    }
}

int main()
{
    init();
    sol();
    
    // for(int i = 1; i <= N; i++) cout << ans[i] <<" ";
    cout << *max_element(ans.begin(), ans.end());
    return 0;
}

