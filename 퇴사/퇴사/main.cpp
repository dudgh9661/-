#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    
    vector< pair<int, int> > vec;
    int N = 0;
    cin >> N;
    
    int T, P;
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &T, &P);
        vec.push_back( {T,P});
    }
    
    //    cout << vec.size() << endl;
    int MAX = 0;
    int price = 0;
    int idx = 0;
    //1. 1일에 잡혀있는 상담을 진행했을 경우의 결과와
    //2. 2일에 잡혀있는 상담을 진행했을 경우의 결과를 비교 후 최대값 찾기
    
    
    for(int j = 0; j < N; j++) {
        printf("제일 바깥 For문 idx : %d price : %d\n", idx, price);
        for(int i = j; i < N; i++) {
            idx = vec[i].first + idx - 1;
            price = vec[i].second;
            for(int k = i+1; k < N;){
                if( k + vec[k].first - 1 >= N ) {
                    printf(" wft %d\n", k + vec[k].first );
                    //                    price -= vec[j].second;
                    break;
                }
                if( vec[k].first == 1 ) k++;
                else {
                    k = vec[k].first + k - 1;
                }
                printf(" i : %d price : %d + %d\n", k, price, vec[k].second);
                if( k + vec[k].first - 1 < N ) price += vec[k].second;
                
                
            }
            
            
            printf("price : %d\n", price);
            MAX = max(price, MAX);
            printf("\n");
            
            
        }
        
        
        
        //    cout << price << endl;
        
        printf("MAX : %d\n", MAX);
        
    }
    return 0;
}
