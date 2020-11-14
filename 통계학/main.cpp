#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
int N;
vector<int> vec;
map<int, int> mp;
vector<int> tmp;


void Sansul() {
    double sum = 0;

    for(int i = 0; i < N; i++) {
        sum += vec[i];
    }

    sum = sum / N;
    sum = floor(sum+0.5);
    printf("%0.lf\n", sum);
}

void Mid() {
    sort(vec.begin(), vec.end(), less<int>());
    //짝수일 땐 중앙의 기준이 머ㅓ지???????????
    int mok = vec.size() / 2;
    printf("%d\n", vec[mok]);
}

void Many() {
    //백터를 돌면서 수와 일치하는 인덱스에 카운팅 한다.
    for(int i = 0; i < vec.size(); i++) {
        int num = vec[i];
        mp[num]++;
    }
    int MAX = 0;
    int key = 0;
    for(auto i = mp.begin(); i != mp.end(); i++) {
        int num = i->second;
//        key = i->first;

        if( num > MAX ) {
            MAX = num;

        }

    }

    for(auto i = mp.begin(); i != mp.end(); i++) {
        if( i->second == MAX ) {
            tmp.push_back(i->first);
        }
    }

    sort(tmp.begin(), tmp.end(), less<int>());
    if( tmp.size() > 1 ) {
        printf("%d\n", tmp[1]);
    } else printf("%d\n", tmp[0]);
}

void Ran() {
    int size = vec.size();
    int num = vec[size - 1] - vec[0];

    printf("%d", num);
}

int main() {

    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        int input = 0;
        scanf("%d", &input);
        // 절대값에 대한 예외처리 해줄 것!!!
        if( input + 4000 < 0 ) return 0;
        vec.push_back(input);
        mp.insert( {input, 0} );
    }

    Sansul();
    Mid();
    Many();
    Ran();

    return 0;
}
