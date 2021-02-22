#include <iostream>
#include <vector>
#include <cmath>

int N;

using namespace std;

vector<int> vec;
vector<int> ans;
bool visited[8] = { false };
int answer = 0;

void init() {
    cin >> N;
    int a;
    for(int i = 0; i < N; i++) {
        cin >> a;
        vec.push_back(a);
    }
}

int sum() {
    int res = 0;
    for(int i = 0; i < ans.size()-1; i++) {
        res += abs(ans[i] - ans[i+1]);
    }
    return res;
}
void DFS(int cnt) {
   if( cnt == N ) {
//       for(int i = 0; i < ans.size(); i++) {
//           cout << ans[i] << "  ";
//       }
       int res = sum();
       answer = max(res, answer);
//       cout << "result : " << res << endl;
       return;
   }
    for(int i = 0; i < vec.size(); i++) {
        if( visited[i] ) continue;
        visited[i] = true;
        ans.push_back(vec[i]);

        DFS(cnt+1);

        visited[i] = false;
        ans.pop_back();
    }
 }
int main() {
    init();
    DFS(0);
    cout << answer << endl;
    return 0;
}
