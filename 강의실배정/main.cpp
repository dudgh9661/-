#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N = 0;

typedef struct lecture{
    int s;
    int t;
}LECTURE;

vector<LECTURE> vec;

bool cmp(LECTURE a, LECTURE b) {
//    if( a.s == b.s ) {
//        return a.t <= b.t;
//    }
    return a.s < b.s;
}

void init()
{
    cin >> N;
    for(int i = 0; i < N; i++) {
        int s, t;
        cin >> s >> t;
        LECTURE lecture;
        lecture.s = s;
        lecture.t = t;
        vec.push_back(lecture);
    }

    sort(vec.begin(), vec.end(), cmp);
}

priority_queue< int, vector<int>, greater<int> > pq;
void search() {
    pq.push(vec[0].t);



    for(int i = 1; i < vec.size(); i++) {
        int t = pq.top();
        if( t  > vec[i].s ) { //강의실 1개 더 필요
            pq.push(vec[i].t);
        }
        else if ( t <= vec[i].s ){
            pq.pop();
            pq.push(vec[i].t);
        }
    }
}




int main() {
    init();
    search();

    cout << pq.size() << endl;

    return 0;
}

