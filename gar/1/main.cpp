#include <iostream>
#include <cmath>

using namespace std;

long long factorial(long long num) {
    long long result = 1;

    for( long long i = 1; i <= num; i++) {
        result *= i;
    }

    return result;
}

int returnTail(long long num) {
    string str = to_string(num);
    int cnt = 0;
    for(int i = str.size() - 1; i >= 0; i--) {
        if( str[i] != '0' ) return cnt;
        else if( str[i] == '0' ) cnt++;
    }
}

int tailZero(int n) {
    int cnt  = 0;
    int p = 1;
    while ( n > p )  {
        p *= 5;
        cnt += floor( n / p);
    }
    return cnt;
}

int tailZero2(int n) {
    int cnt  = 0;
    int p = floor(n / 5);

    for(int i = p; i > 0; i--) {
        int mul = pow(5, i);
        for(int j = mul; j <= n; j = j + mul) cnt++;
    }
    return cnt;
}


int solution(int n)
{
    int answer = 2;
    cout << tailZero2(10);
//    cout << factorial(n) << endl;
//    answer = returnTail(factorial(n));
//    cout << "cnt : " << answer << endl;
    return answer;
}

int main() {
    solution(20);
}