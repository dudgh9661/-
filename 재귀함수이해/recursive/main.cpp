#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> vec;

void f( int n ){
    if(n==0) return;
    f(n-1);
    printf("%d",n);
    printf("밑에도 실행이 된다!!\n");
}
//void DFS(int count) {
//    if( count == 2) return;
//    cout << count << endl;
//    for(int i = 0; i < 4; i++)
//        DFS(++count);
//
//}
int main() {
    f(5);
    return 0;
}
