#include <iostream>

using namespace std;


int main() {
    int n, k;
    while ( cin >> n >> k ) {
        long long dojang = 0;
        long long chicken = 0;

        chicken = n;
        dojang = n;

        if (dojang != 0) {
            while (dojang / k != 0) {
                int order = dojang / k;
                chicken += order; //시킨 치킨 수
                dojang = dojang - order * k + order;
            }

        }
        cout << chicken << "\n";
    }
    return 0;
}
