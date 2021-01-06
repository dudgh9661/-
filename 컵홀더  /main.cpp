#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
string input;

//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
int main() {
    cin >> N;

    char ch;
    for(int i = 0; i < N; i++) {
        cin >> ch;
        input += ch;
    }
    int ans = 1;

    int Lcnt = 0;
    for(int i = 0; i < input.size(); i++) {
        if( input[i] == 'S' ) ans++;
        else if( input[i] == 'L') {
            Lcnt++;
            if( Lcnt == 2 ) {
                ans++;
                Lcnt = 0;
            }
        }
    }

    if( ans > N ) cout << N << endl;
    else cout << ans << endl;
    return 0;
}
