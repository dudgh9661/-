#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> vec;
vector<int> ans;
set< vector<int> > st;

void Print() {
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

bool visit[10001] = { false };

void DFS(int limit, int cnt) {
    if ( limit == cnt ) {

        if( limit > 1 ) {
            for(int i = 0; i < ans.size() - 1; i++) {
                if( ans[i] > ans[i+1] ) return;
            }
        }

        st.insert(ans);
        return;
    }

    else {
        for (int i = 0; i < vec.size(); i++) {
//            int number = vec[i];
            if (!visit[i]) {
                visit[i] = true;
                ans.push_back(vec[i]);
                cnt = cnt + 1;
                DFS(limit, cnt);
                visit[i] = false;
                ans.pop_back();
                cnt--;
            }
        }
    }
}
int main() {
    int N, M;
    cin >> N >> M;
//    cout << N << M << endl;
    for(int i = 0; i < N; i++) {
        int input;
        cin >> input;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end(), less<int>());

    DFS(M, 0);
    for(auto i = st.begin(); i != st.end(); i++) {
        vector<int> a = *i;
        for(int itr = 0; itr < a.size(); itr++) {
            cout << a[itr] << " ";
        }
        cout << endl;
    }

    return 0;
}
