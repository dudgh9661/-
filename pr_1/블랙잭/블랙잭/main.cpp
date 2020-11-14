#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    freopen("input.txt", "r", stdin);
    
    int N = 0;//the number of card
    int M = 0;//the number of sum
    int sum = 0;
    int max = 0;
    cin >> N;
    cin >> M;

    int input = 0;
    vector<int> card(0, N);
    for(int cnt = 0; cnt < N; cnt++) {
        cin >> input;
        card.push_back(input);
    }
    
//    cout << card[1] << endl;
    
    for(int i = 0; i < N-2; i++) {
        for(int j = i+1; j < N-1; j++) {
            for(int k = j+1; k < N; k++) {
                sum = card[i]+card[j]+card[k];
                if( sum <= M ) {
                    if( max < sum ) max = sum;
                }
            }
        }
    }
    cout << max << endl;
    return 0;
}
