#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int maxDay = 0;

typedef struct work{
    int day;
    int score;
}WORK;

vector<WORK> vec;
bool visited[10001] = { false };

bool cmp (WORK a, WORK b) {
        return a.day > b.day;
}

void init() {
    cin >> N;
    int a, b;
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        vec.push_back({a,b});
        maxDay = max(a, maxDay);
    }
    sort(vec.begin(), vec.end(), cmp);
}

int sum = 0;

void sol() {
    //x일째 할 수 이쓴ㄴ 과제들 중 가장 큰 값을 찾는다.
    while( maxDay > 0 ) {
        int MIN = -100;
        int findIdx = -1;
        for (int i = 0; i < vec.size(); i++) {
            if (maxDay <= vec[i].day && !visited[i]) {
                if (MIN < vec[i].score) {
                    MIN = vec[i].score;
                    findIdx = i;
                }
            }
        }
        //찾은 값을 지워준다.
        if (findIdx != -1 ) {
            sum += vec[findIdx].score;
            visited[findIdx] = true;
        }
        maxDay--;
    }

}
int main() {
    init();
    sol();
    cout << sum << endl;
    return 0;
}

