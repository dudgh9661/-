#include <iostream>
#include <vector>

using namespace std;

int N;
vector< pair<int, int> > vec;

void Print() {
    for(int i = 0; i < vec.size(); i++) {
        printf("%d %d\n", vec[i].first, vec[i].second);
    }
}


int main() {
    scanf("%d", &N);
    int level = 1;
    int height = 0;
    int body = 0;

    for(int i = 0; i < N; i++) {
        scanf("%d %d", &height, &body);
        vec.push_back( {height, body} );
    }

//    Print();
    // 나보다 키도 크고 몸무게도 큰 사람이 있으면 level++;
    for(int i = 0; i < vec.size(); i++) {
        height = vec[i].first;
        body = vec[i].second;

        for(int j = 0; j < vec.size(); j++) {
            if( height < vec[j].first && body < vec[j].second) {
                level++;
            }
        }
        printf("%d ", level);
//        printf("h : %d b : %d level : %d\n", height, body, level);
        level = 1;
    }
//    PrintInf();
    //2. 모든 배열을 탐색한 후의 level 값이 내 순위가 된다.
    //2-1. 그 level 인덱스에 사람수를 한명 더한다.

    return 0;
}
