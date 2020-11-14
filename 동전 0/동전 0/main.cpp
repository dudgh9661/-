#include <iostream>
#include <vector>

using namespace std;


void Print (vector<int> vec) {
    for(int i = 0; i < 10; i++) {
        cout << vec[i] << endl;
    }
}

int main() {
    int N = 0, K =0;
    cin >> N >> K;
//    cout << K << endl;
    int input = 0;
    int idx = N;
    int cnt = 0;
    
    //동전 가치가 저장된 벡터
    vector<int> vec(N, 0);
    for(int i = 0; i < N; i++) {
        scanf("%d", &input);
        vec[i] = input;
        if( vec[i] > K ) {
            idx = i;
        }
    }
    
    idx = idx - 1;
    
    int remain = 0;
    
    while( K > 0 ) {
        
        if( K <= 0 ) break;
        
        remain = K / vec[idx];
        if( remain > 0 ) {
            cnt += remain;
            K = K % vec[idx];
            idx--;
            cout << "K : " << K << "idx : " << idx << endl;
            if( idx < 0 ) break;
        }
        
        else {
            idx--;
            if( idx < 0 ) break;
        }
    }
    
    cout << cnt << endl;
    return 0;
}
