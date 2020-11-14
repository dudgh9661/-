#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    //1. vec가 k+1만큼의 요소를 가진다.
    int k = 0;
    int cIdx = 0;
    cin >> k;
    getchar();
    
    string boo;
    getline(cin, boo, '\n');
    
    vector<int> vec;
    vector<int> Mvec;
    vector<char> Boo;
    
    
    for(int i = 0; i < k; i++ ) {
        Boo.push_back(boo[cIdx]);
        cIdx += 2;
    }
    
//    cout << Boo[0] << Boo[1];
    //2. 각 요소는 0부터 시작해서 k+1만큼씩 push_back 한다.
    for(int i = 0; i < k + 1; i++) {
        vec.push_back(i);
    }
    
    for(int i = 9; i > 9 - k - 1; i--) {
        Mvec.push_back(i);
    }
        
    //3.
    
    //    int flag = 0;
    int cnt = 0;
    while(1) {
        //        if ( flag = 1 ) break;

        for( int i = 0; i < k; i++) {
            if( Boo[i] == '>' && vec[i] > vec[i+1] ) {
//                printf("%d > %d\n", vec[i], vec[i+1]);
                cnt ++;
            } else if ( Boo[i] == '<' && vec[i] < vec[i+1]) {
//                printf("%d < %d\n", vec[i], vec[i+1]);
                cnt++;
            } else {
                next_permutation(vec.begin(), vec.end());
                cnt = 0;
                break;
            }
        }

        if( cnt == k ) break;

    }

    for(int i = 0; i < vec.size(); i++) {
           cout << vec[i];
    }
    printf("\n");
    cnt = 0;
    
    while(1) {
        //        if ( flag = 1 ) break;

        for( int i = 0; i < k; i++) {
            if( Boo[i] == '>' && Mvec[i] > Mvec[i+1] ) {
//                printf("%d > %d\n", Mvec[i], Mvec[i+1]);
                cnt ++;
            } else if ( Boo[i] == '<' && Mvec[i] < Mvec[i+1]) {
//                printf("%d < %d\n", Mvec[i], Mvec[i+1]);
                cnt++;
            } else {
                prev_permutation(Mvec.begin(), Mvec.end());
                cnt = 0;
                break;
            }
        }
        
        if( cnt == k ) break;

    }
    for(int i = 0; i < Mvec.size(); i++) {
        cout << Mvec[i];
    }
    
    
    return 0;
}
