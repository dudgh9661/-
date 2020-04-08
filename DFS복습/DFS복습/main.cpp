#include <iostream>
#include <vector>

using namespace std;

bool check[5];

void DFS(int start, vector<int> test[], bool check[]){
    if( check[start] == true ) return;
    
    check[start] = true;
    printf("%d ", start);
    for(int i = 0; i < test[start].size(); i++){
        int next = test[start][i];
        DFS(next, test, check);
        }
}
    
int main(){
    vector<int> test[5];
    test[0].push_back(1);
    test[1].push_back(0);
    
    test[0].push_back(2);
    test[2].push_back(0);
    
    test[1].push_back(3);
    test[3].push_back(1);
    
    test[1].push_back(4);
    test[4].push_back(1);
    
    fill(check, check+5, false);
    
    DFS(0, test, check);
    
    
}
