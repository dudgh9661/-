#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N = 0, M = 0, I = 0;
    cin >> N >> M >> I;
   
    
    int sum = N+M - I;
    int cnt = 0;
    while( N > 1 && M > 0 )  {
        N -= 2;
        M -= 1;
        sum -= 3;
        cnt++;
    }
    
    cout << cnt;
}

