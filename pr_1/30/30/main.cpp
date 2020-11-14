#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;
vector<unsigned long long> vec;

int main() {
    string N;
    cin >> N;
    
    
    for(int i = 0; i < N.length(); i++ ) {
        vec.push_back(N[i]-48);
    }
    
    sort(vec.begin(),vec.end(), less<int>());
    
    string output = "";
    unsigned long long res = 0;
    unsigned long long max = 0;
    do{
        for(int i = 0; i < N.length(); i++ ) {
            char c = vec[i]+48;
            output += c;
        }
        res = stoull(output);
        
        cout << res << endl;
        
        if( res % 30 == 0 ) {
            if ( max < res ) {
                max = res;
                output = "";
                res = 0;
                continue;
            } else {
                output = "";
                continue;
            }
        }
        
        else {
            output = "";
            res = 0;
            continue;
        
            }
    }while(next_permutation(vec.begin(), vec.end()));
    
//    cout << max;
    if( max == 0 ) cout << -1;
    else cout << max;
    return 0;
    
}
