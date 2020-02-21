#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>

using namespace std;

queue<int> queu;
bool check[7];

void BFS(int start, vector<int> list[]){
    check[start] = true;
    queu.push(start);
    
    while( !queu.empty() ){
        int ad_node = queu.front();
        printf("%d ", ad_node);
        queu.pop();
        
        for(int i = 0; i < list[ad_node].size(); i++){ //이 시점에서 1은 pop되면서 2,3을 방문하면서 큐에 push 되어야 한다.
            int next = list[ad_node][i]; //2번 먼저,
            if( check[next] == false){ //방문하지 않았으면,
                check[next] = true; //방문해라.
                queu.push(next); //방문"한" 노드를 추가.
            }
        }
    }
    
}

int main(){
    
    vector<int> list[7];
    
    list[0].push_back(1);
    list[1].push_back(0);
    
    list[0].push_back(2);
    list[2].push_back(0);
    
    list[1].push_back(3);
    list[3].push_back(1);
    
    list[1].push_back(4);
    list[4].push_back(1);
    
    list[2].push_back(5);
    list[5].push_back(2);
    
    list[2].push_back(6);
    list[6].push_back(2);
    
    fill(check, check+7, false);
    
    BFS(0, list);
    return 0;
}
