#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int wt;
    vector<int> vec(N,0);
    
    for(int i = 0; i < N; i++ ) {
        cin >> wt;
        vec[i] = wt;
    }
    
    int max = 0;
    int size = 0;
    int output = 0;
    sort(vec.begin(), vec.end(), less<int>() );
    
    int total = 0;
    for(int i = 0; i < N; i++) {
        size =  vec.size() - i;
        output = size * vec[i];
        if( max < output ) max = output;
    }
    cout << max << endl;
    return 0;
}
