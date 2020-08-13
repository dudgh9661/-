#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int T = 0, P = 0;
    vector< pair<int, int> > schedule;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &T, &P);
        schedule.push_back(make_pair(T, P));
        printf("wtf????\n");
    }
    printf("hhh");

    
    int next = 0;
    int price = 0;
    int MAX = 0;
    int res = 0;

    vector< pair<int, int> >::iterator current;
    vector< pair<int, int> >::iterator i;

    // i = schedule.begin() + 1;
    // current = i;

    // cout << current->first << endl;
    for(i = schedule.begin(); i != schedule.end(); i++) {
        
        for( current = i; current <= schedule.end(); current++) {
           
            T = current->first;
            P = current->second;
            price += P;
            // current = current + T - 1;
            cout << current->first << endl;
            // if( current >= schedule.end() ) break;
        }

        MAX = max(price, MAX);
    }

    printf("MAX : %d ", MAX);
    return 0;

}