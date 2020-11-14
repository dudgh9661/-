#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) { //오름차순
    return a.first < b.first;
}

int main() {
    vector< pair<int, int> > vec;
    
    int TC = 0, num = 0;
    cin >> TC;
    
    int S = 0, M = 0;
    int cnt = 0;
    vector<int> ans;
    
    for(int i = 0; i < TC; i++ ) {
        cin >> num;
        
        for(int i = 0; i < num; i++) {
            cin >> S >> M;
            vec.push_back({S, M});
        }
        
        sort(vec.begin(), vec.end(), cmp);
        cnt += 1;
        
        
        int pre = 0;
        int current = 1;
    
        for(int i = 1; i < num; i++) {
//            printf("pre (%d, %d) i (%d, %d) pre,i (%d, %d)\n", vec[pre].first, vec[pre].second, vec[i].first, vec[i].second, pre, i);
            if( vec[pre].second > vec[i].second)  {
                cnt++;
                pre = i;
//                printf("IN pre (%d, %d) i (%d, %d) pre,i (%d, %d)\n", vec[pre].first, vec[pre].second, vec[i].first, vec[i].second, pre, i);
                continue;
                
            }
            else {
                continue;
            }
        }
        
        cout << cnt << "\n";
        cnt = 0;
        vec.resize(0);
//        printf("resize : %d", vec.size());
        vec.clear();
        
    }
    

    return 0;
}

