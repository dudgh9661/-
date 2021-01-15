#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int k;
vector<int> vec;
vector<int> ans;
void init() {
    vec.clear();
    ans.clear();
    vec.resize(0);
    ans.resize(0);

    int a;
    for(int i = 0; i < k; i++) {
        cin >> a;
        vec.push_back(a);
    }
}

void Print() {
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

void DFS(int cnt, int start) {
    if( cnt == 6 ) {
//        printf("K : %d size : %d\n", k, vec.size());
        Print();
        cout << "\n";
        return;
    }

    for(int i = start; i < k; i++) {
        ans.push_back(vec[i]);

        DFS(cnt+1, i+1);

        ans.pop_back();
    }
}

int main() {
    while(1) {
        cin >> k;
        if( k == 0 ) break;
        init();
        DFS(0, 0);
        cout << "\n";
    }
    return 0;
}
