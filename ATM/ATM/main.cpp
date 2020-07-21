#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
    //시간을 저장할 배열
    int person = 0;
    cin >> person;
    vector<int> vec(person,0);
    
    //더한값을 저장할 변수
    int sum = 0;
    int total = 0;
    //0. 입력을 받아 저장한다.
    for(int i = 0; i < person; i++) {
        scanf("%d", &vec[i]);
    }//    //1. 배열을 오름차순으로 정렬
    sort(vec.begin(), vec.end(), less<int>() );
    
    //2. 각 배열을 중첩하여 더한다.
    for(int i = 0; i < person; i++ ) {
        sum += vec[i];
        total += sum;
        cout << "total : " << total << endl;
    }
    
    //3. 그게 최솟값.
    cout << total << endl;
 
    return 0;
}
