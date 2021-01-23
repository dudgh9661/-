#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, mp, mf, ms, mv;
int MIN = 1e9;

vector<int> vec[15];
vector<int> ans;
vector<pair<vector<int>,int>> lastAnswer;
vector<int> INFO(5,0);

void init() {
    cin >> N;
    cin >> mp >> mf >> ms >> mv;

    int p,f,s,v,c;
    for(int i = 0; i < N; i++) {
        cin >> p >> f >> s >> v >> c;
        vec[i].push_back(p);
        vec[i].push_back(f);
        vec[i].push_back(s);
        vec[i].push_back(v);
        vec[i].push_back(c);

    }
//    INFO[4] = 0;
}
bool isPossible(vector<int> info) { //조건 충족
    if( info[0] >= mp && info[1] >= mf && info[2] >= ms && info[3] >= mv) return true;
    else return false;
}
void Update(vector<int> &info, int idx, int flag) {
    // flag == 0, +
    if (flag == 0) {
        for (int i = 0; i < 5; i++) {
            info[i] += vec[idx][i];
        }
    }
        //flag == 1, -
    else if (flag == 1) {
        for (int i = 0; i < 5; i++) {
            info[i] -= vec[idx][i];
        }
    }
}

void DFS(vector<int> info, int start) {
    //종료 조건
    if(isPossible(info)) {
//        cout << "현시점 최저값 : " << MIN << endl;
        if( info[4] <= MIN ) {
            MIN = info[4];
            vector<int> tmp = ans;
            sort(ans.begin(), ans.end(), less<>());
            lastAnswer.push_back({tmp, MIN});
        }
//        cout << "조건 만족한 식재료 번호 " << endl;
//        for(int i = 0; i < ans.size(); i++) {
//            cout << ans[i] << " ";
//        }
//        cout << "이 때의 가격은 : " << info[4] << endl << endl;
        return;
    }
    //진입 조건
    for(int i = start; i < N; i++) {
        ans.push_back(i); //식재료 번호 추가
        Update(info, i, 0); //추가된 식재료 정보를 통한 정보 갱신
        if( info[4] > MIN ) {
            ans.pop_back();
            Update(info,i,1);
            continue;
        }

        DFS(info, i+1);

        ans.pop_back();
        Update(info, i, 1);

    }
}
bool cmp(pair<vector<int>,int> a, pair<vector<int>, int> b ) {
    if( a.second == b.second ) {
//        return a.first < b.first;
    }
    return a.second < b.second;
}

bool cmp2(vector<int> a, vector<int> b) {
    return a < b;
}
int main() {
    vector< vector<int> > a;
    a.push_back({1,3,4});
    a.push_back({1,2,4});
    a.push_back({4,3,4});
    a.push_back({5,3,4});
    sort(a.begin(), a.end(), cmp2);
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

//    init();;
//    DFS(INFO, 0);
//    if( MIN == 1e9 ) {
//        cout << -1 << endl;
//        return 0;
//    }
//
//    sort(lastAnswer.begin(), lastAnswer.end(), cmp);
//    cout << lastAnswer[0].second << endl;
//    for(int i = 0; i < lastAnswer[0].first.size(); i++) {
//        cout << lastAnswer[0].first[i]+1 << " ";
//    }
//    cout << lastAnswer[0].second << endl;
    return 0;
}
