#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int cnt = 0;

void DFS(int start, vector<int> com[], bool check[]){
    if(check[start]==true) return;
    
    check[start] = true;
    cnt++;
   // printf("%d ", cnt);
    for(int i = 0; i < com[start].size(); i++){
        int next = com[start][i];
        if( check[next] == false){
            DFS(next, com, check);
        }
    
    }
    
}
int main()
{
    freopen("input.txt", "r", stdin);
    int num = 0;
    scanf("%d", &num);
    //printf("%d\n", num);
    vector<int> com[num];
    bool check[num];
    fill(check, check+num, false);
    
    //인접 리스트 생성 즉, 연결 정보가 com 벡터에 저장되어있다.
    int a = 0, b = 0;
    int i = 0;
    int itr = 0;
    scanf("%d", &itr);
    while(i < itr){
        
        scanf("%d %d", &a, &b);
        com[a-1].push_back(b-1);
        com[b-1].push_back(a-1);
        i++;
    }
    
        
        DFS(0, com, check);
    printf("%d", cnt-1);
    

    
    
    return 0;
}
