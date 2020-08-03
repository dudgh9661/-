#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    string input;
    cin >> input;

    vector<int> visit(10, 0);

    int set = 1;


    
    for(int i = 0; i < input.length(); i++) {

        int decoNumber = input[i]-'0';
        // printf("%d ", decoNumber);
        visit[decoNumber]++;
        if( visit[decoNumber] > set ) { // 이미 한번 사용한 경우

            if( decoNumber == 6 ) { // 6이면
                if( visit[9] < set ) { 
                    visit[9]++;
                    visit[6]--;
                    continue;
                }
            } else if ( decoNumber == 9 ) { // 9이면
                if( visit[6] < set ) {
                    visit[6]++;
                    visit[9]--;
                    continue;

                }
            }
            set++;
        }
    }

    printf("%d", set);
    return 0;
}