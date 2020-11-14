#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
int N;

bool visit[2000000] = { false };

pair<int, int> ans;
int MAX = -100;

void Find(int yellow, int total) {
    if( yellow == 1 ) {
        ans = make_pair(1,1);
        return;
    }
    int range = sqrt(yellow);
    // printf("range : %d", range);
    for(int i = 1; i <= range; i++) {

        for(int j = i; j <= yellow; j++) {
            // printf("%d %d\n", i, j);
            if( (i * j) == yellow && (i+2)*(j+2) == total)  {
                // visit[j] = true;
                if( MAX < i ) {
                    MAX = i;
                    ans = make_pair(i,j);

                }
            }
        }
    }
}

vector<int> solution(int brown, int yellow) {
    N = yellow;
    //1. yellow를 만들 수 있는 가장 큰 몫들을 뽑는다
    Find(yellow, brown + yellow);
    //2. 그 몫들 각각 + 2가 정답
    if( ans.first < ans.second) {
        int tmp = ans.second;
        ans.second = ans.first;
        ans.first = tmp;

    }

    // printf("%d, %d\n", ans.first, ans.second);

    vector<int> answer;
    answer.push_back(ans.first+2);
    answer.push_back(ans.second+2);
    return answer;
}