#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N = -1, M = -1;
//치킨 거리 : 집과 가장 가까운 치킨집 사이의 거
//도시의 치킨 거리 : 모든 집의 치킨 거리의 합
int city = 100000;
//이게 최소가 되기 위해선, 치킨 거리가 최소가 되어야하고, 집과 가장 가까운 치킨집들만 남겨야한다.

bool visited[13] = { false };

typedef struct pos{
    int r = 0;
    int c = 0;
} POS;
vector<POS> home;
vector<POS> chicken;
vector<int> vec;


void init() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int input;
            cin >> input;
            if (input == 1) {
                POS pos = {i,j};
                home.push_back(pos);
            } else if (input == 2) {
                POS pos = {i,j};
                chicken.push_back(pos);
            }
        }
    }
}
int dist(POS a, POS b) {
    int dis = abs(a.r - b.r) + abs(a.c - b.c);
    return dis;
}
int calCity() {
    int res = 0;
    int output = 0;
    int MIN = 100000;

//    cout << "size : " << home.size() << endl;
    for(int i = 0; i < home.size(); i++) {
        for(int j = 0; j < vec.size(); j++) {
            output = dist(home[i], chicken[vec[j]]);
            if( output < MIN ) {
                MIN = output;
//                cout << "output : " << output << endl;
            }
        }
        res += MIN;
        MIN = 100000;
    }

    return res;
}

void DFS(int limit, int cnt, int start) {
    if( limit == cnt ) {
        for(int i = 0; i < vec.size(); i++) {
            int res = calCity();
//            cout << " res : " << res << endl;
            if( city > res ) city = res;
//            for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";

        }
//        cout << endl;
        return;
    }

    else {
        for(int i = start; i < chicken.size(); i++) {
            if( !visited[i]) {
                visited[i] = true;
                vec.push_back(i);

                DFS(limit, ++cnt, i+1);

                cnt--;
                visited[i] = false;
                vec.pop_back();
            }

        }
    }


}
int main() {
    init();
//    cout << dist(home[0], chicken[2]) << endl;
    DFS(M, 0, 0);
    cout << city << endl;
    return 0;
}
