#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int N, C, M;

typedef struct info{
    int from;
    int to;
    int num;
}INFO;

vector<INFO> vec;
vector<int> village;


void Print() {
    for(int i = 1; i < village.size(); i++) {
        printf("%d : %d\n", i, village[i]);
    }
    cout << endl;
}
bool cmp(INFO a, INFO b) {
    if( a.to == b.to) {
        return a.from < b.from;
    }
    return a.to < b.to;
}
void init() {
    cin >> N >> C;
    cin >> M;

    for(int i = 0; i <= N; i++) { //1~N
        village.push_back(0);
    }
    int from, to, val;
    for(int i = 0; i < M; i++) {
        cin >> from >> to >> val;
        INFO info {from, to, val};
        vec.push_back(info);
    }
    sort(vec.begin(), vec.end(), cmp);
//    for(int i = 0; i < vec.size(); ++i) {
//        printf("%d %d %d\n", vec[i].from, vec[i].to, vec[i].num);
//    }
}

int ans = 0;

void Update(int from, int to, int val) {
    for(int i = from; i < to; i++) {
        village[i] += val;
    }
    ans += val;
}
void sol() {

    for(int i = 0; i < vec.size(); i++) {
        int input = 1e9;

        for(int j = vec[i].from; j < vec[i].to; j++) {
            if( village[j] + vec[i].num <= C ) {
                input = min(input, vec[i].num);
//                printf("if문 %d -> %d : %d\n", j, vec[i].to, input);
            } else {
                input = min(input, C - village[j]);
//                printf("%d -> %d : %d\n", j, vec[i].to, input);
            }
        }
        Update(vec[i].from, vec[i].to, input);
//        Print();
    }

    cout << ans << endl;
}
int main() {
    init();
    sol();

    return 0;
}
