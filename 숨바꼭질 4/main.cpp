#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int N, K;
int ans = 0;
int node = -1;

bool visited[100001] = { false };
int arr[100001] = { 0 };
void init() {
    cin >> N >> K;
    fill(arr, arr+100001, -1);
}

bool inRange(int cur) {
    if ( cur < 0 || cur > 100000 ) return false;
    return true;
}

struct cmp {
    bool operator() (pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};

void BFS(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push({start, 0});
    visited[start] = true;

    while ( !pq.empty() ) {
        int cur = pq.top().first;
        int t = pq.top().second;
        pq.pop();


        if ( cur == K ) {
            ans = t;
            node = cur;
            return;
        }
        if ( inRange(cur+1) && !visited[cur+1]) {
            pq.push({cur + 1, t + 1});
            visited[cur+1] = true;
            arr[cur+1] = cur;
        }
        if ( inRange(cur-1) && !visited[cur-1]) {
            pq.push({cur-1, t+1});
            visited[cur-1] = true;
            arr[cur-1] = cur;
        }
        if ( inRange(cur*2) && !visited[cur*2]) {
            pq.push({cur * 2, t + 1});
            visited[cur*2] = true;
            arr[cur*2] = cur;
        }
    }

}
int main() {
    init();
    BFS(N);
    cout << ans << endl;

    stack<int> st;
    st.push(K);

    while ( node != N ) {
        st.push(arr[node]);
        node = arr[node];
    }

    while ( !st.empty() ) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
