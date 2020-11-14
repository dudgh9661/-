#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(50);
    vec.push_back(100);
    vec.push_back(500);
    
    int price;
    cin >> price;
    
    int K = 1000 - price;
    int idx = 5;
    
    int cnt = 0;
    int tmp = 0;
    while ( K > 0 ) {
        tmp = K / vec[idx];
        if( tmp == 0 ) {
            idx--;
            continue;
        }
        cnt += tmp;
        
        K = K % vec[idx];
        idx--;
    }
    
    cout << cnt << endl;
    
}

