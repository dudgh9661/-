#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main() {
    
    int N = 0, X = 0;
    scanf("%d %d", &N, &X);
    
    vector<int> vec;
    
    for(int i = 0; i < N; i++) {
        int input = 0;
        scanf("%d", &input);
        
        if( input < X ) {
            vec.push_back(input);
        }
    }
    
    for(int i = 0; i < vec.size(); i++) {
        printf("%d ", vec[i]);
    }
    
    
    return 0;
}
