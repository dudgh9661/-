#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    //덤프 횟수, 1이상 1000이하
    freopen("input.txt", "r", stdin);
    
    for(int tc = 1; tc <= 10; tc++) {
        int dump = 0;
        scanf("%d", &dump);
        //상자의 높이
        
        vector<int> vec;
        
        for(int i = 0; i < 100; i++) {
            int height = 0;
            scanf("%d", &height);
            
            vec.push_back(height);
        }
        
        // 가로 길이는 항상 100, 상자 높이는 1이상 100이하
        
        vector<int>::iterator itr;
        vector<int>::iterator itr2;
        
        int answer = 0;
        
        while( dump > 0 ) {
            //        printf("dump : %d\n", dump);
            dump--;
            itr = max_element(vec.begin(), vec.end());
            itr2 = min_element(vec.begin(), vec.end());
            
            //        printf("max : %d min : %d\n", *itr, *itr2);
            *itr = *itr - 1;
            *itr2  = *itr2 + 1;
            //        printf("after max : %d min : %d\n", *itr, *itr2);
            
            itr = max_element(vec.begin(), vec.end());
            itr2 = min_element(vec.begin(), vec.end());
            
            answer = *itr - *itr2;
            if( answer == 1 ) break;
            
            
        }
        
        printf("#%d %d\n", tc, answer);
        //    for(int i = 0; i < vec.size(); i++)
        //        printf("%d ", vec[i]);
    }
    return 0;
}
