#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    //1. 연결 정보를 vector에 저장한다.
    int corNum = 0;
    scanf("%d", &corNum);
    
    int listLen = 0;
    scanf("%d", &listLen);
    
    vector<int> list[listLen+1];
    bool *check = new bool[corNum+1];
    
    //제대로 값 들어갔는지 확인해야함.
    fill(check, check+corNum+1, false);
    
    for(int i = 0; i < listLen; i++){
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);

        list[a].push_back(b);
        list[b].push_back(a);

    }
    //2. 상근이의 친구를 count한다.
    check[1]= true;
    
    int count = 0;
    for(int i = 0; i < list[1].size(); i++) {
        int friends = list[1][i];
        if( check[friends] == false) count++;
            check[friends] = true;
//            count++;
//            printf("friends : %d\n", friends);
            for(int bridge = 0; bridge < list[friends].size(); bridge++) {
                int bridgeFr = list[friends][bridge];
                if( check[bridgeFr] == false ) {
                    check[bridgeFr] = true;
                    count++;
//                    printf("bridgeFr : %d\n", bridgeFr);
                }
            }

    }

    //3. 상근이와 친구의 한다리 건너 연결된 친구들을 count 한다. 이 때 count했던 친구들은 count하지 않는다.
    printf("%d\n", count);
    return 0;
}
