#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long gongDae(long long orderAmount, long long serviceFee) {
    long long res = 0;
    if (serviceFee > 0) {
        res = orderAmount - serviceFee;
    } else {
        res = orderAmount;
    }
//    cout << "공급대가 : " << res << endl;
    return res;
}

double gongGa(long long gondDaeNum, long long taxFreeAmount) {
    double num = 0;
    num = ( gondDaeNum + (taxFreeAmount * 0.1) ) * 10 / 11;
//    cout << "공급 가액 : " << num << endl;
    return ceil(num);
}

long long getAns(double gongGa, long long taxFreeAmount) {
   double ans = (gongGa -  taxFreeAmount) * 0.1;
   return ceil(ans);
}

long long solution(long long orderAmount, long long taxFreeAmount, long long serviceFee) {
    // orderAmount : 주문금액
    // taxFreeAmount : 비과세금액
    // serviceFee : 봉사료
    long long answer = 0;
    long long gongDaeNum = gongDae(orderAmount, serviceFee);
    if ( gongDaeNum - taxFreeAmount == 1 ) {
        return answer;
    }

    long long gongGaNum = gongGa(gongDaeNum, taxFreeAmount);
    answer = getAns(gongGaNum, taxFreeAmount);
//    cout << "ans : " << answer << endl;
    return answer;
}

int main() {
//    cout << ceil(9.0);
    cout << solution(120,0,20);
}