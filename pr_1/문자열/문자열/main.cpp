#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string A, B;
    
    cin >> A >> B;
    
    int Alen = A.length();
    int idx = 0;
    int cnt = 0;
    int minimum = 1000;
    string sub;
    
    while(1) {
        if( idx + Alen> B.length() ) break;
        
        sub = B.substr(idx, Alen);
//        cout << "sub : " << sub << endl;
        idx++;
        
//        cout << "idx : " << idx << endl;
        
        
        for( int i = 0; i < Alen; i++ ) {
            if( sub[i] != A[i] ) cnt++;
        }
        
        minimum = min(cnt, minimum);
        
        cnt = 0;
    }
    
    cout << minimum << endl;
    
    return 0;
}
