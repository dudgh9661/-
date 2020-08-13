#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;


void filter(int num, bool *visit) {
    int end = 2 * num;
    int k = 0;
    for(int i = 2; i <= sqrt(end); i++) {
        for(int j = 2; j <= end; j++) {
            k = i * j;
            if( k > end ) break;
            visit[k] = true;
            //            printf("%d ", k);
        }
    }
}
int main() {
    int n;
    
    while( 1) {
        
        cin >> n;
        if( n == 0 ) break;
        
        bool *visit = new bool[n*2+1];
        
        for(int i = 0; i <= n*2+1; i++) {
            visit[i] = false;
        }
        
        visit[0] = true;
        visit[1] = true;
        
        filter(n, visit);
        
        int cnt = 0;
        
        //    printf("\n\n");
        for(int i = n+1; i <= n*2; i++) {
            if( visit[i] == false ){
                //           printf("%d ", i);
                cnt++;
            }
        }
        
        printf("%d\n", cnt);
    }
    
    return 0;
}
