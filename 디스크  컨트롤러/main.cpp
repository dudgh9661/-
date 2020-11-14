#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

void Print(vector<vector<int>> jobs) {
    for(int i = 0; i < jobs.size(); i++) {
        for(int j = 0; j < jobs[i].size(); j++) {
            cout << jobs[i][j] << " ";
        }
        cout << "\n";
    }
}

struct cmp{
    bool operator()(vector<int> a, vector<int> b) {
        if (a[1] == b[1]) return a[0] > b[0];
        return a[1] > b[1];
    }
};

priority_queue< vector<int>, vector< vector<int> >, cmp > que;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end(), less<vector<int> >());
    Print(jobs);

    int current = 0;
    int sum = 0;

    int idx = 0;
    while( idx < jobs.size() || !que.empty() ) {
        if( idx < jobs.size() && current >= jobs[idx][0] ) {
            que.push({jobs[idx][0], jobs[idx][1]});
            idx++;
            continue;
        }
        else {
            if( !que.empty()) {
                int delay = que.top()[0];
                int work = que.top()[1];
//                cout << "delay : "<< delay << "," << work << endl;
                cout << work << "," << sum-delay+work << endl;
                sum += current - delay + work;
                current += work;
                que.pop();

            }
            else {
                current++;
            }
        }


    }


    int answer = 0;
    return answer;

}

int main() {
    //{{0, 3}, {1, 9}, {2, 6}}
    solution({{0, 3}, {1, 9}, {2, 6}});
    return 0;
}