#include <iostream>
#include <vector>

using namespace std;

vector<long long> getBinary(int num) {
    vector<long long> result;
    if (num == 0) result.push_back(0);
    else {
        while (num != 0) {
            long long mok = num / 2;
            long long rem = num % 2;
            result.push_back(rem);
            num = mok;
        }
    }
    reverse(result.begin(),result.end());
    return result;
}

long long getTen(vector<long long> res) {
    reverse(res.begin(), res.end());
    long long sum = 0;
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == 1) {
            sum += pow(2, i);
        }
    }
//    cout << "ten : " << sum;
    return sum;
}
//x+y
bool isXplusY(long long x, long long y, long long a) {
    if (x+y == a) return true;
    return false;
}

//xoy
bool isXoY(long long x, long long y, long long b) {
    vector<long long> xBi = getBinary(x);
    vector<long long> yBi = getBinary(y);
    int size = -1;
    if (xBi.size() > yBi.size()) {
        reverse(yBi.begin(),yBi.end());
        size = xBi.size() - yBi.size();
        for(int i = 0; i < size; i++) {
            yBi.push_back(0);
        }
        reverse(yBi.begin(),yBi.end());
    } else if (xBi.size() < yBi.size()) {
        reverse(xBi.begin(),xBi.end());
        size = yBi.size()-xBi.size();
        for(int i = 0; i < size; i++) {
            xBi.push_back(0);
        }
        reverse(xBi.begin(),xBi.end());
    }
    vector<long long> result;
    for (int i = 0; i < xBi.size(); i++) {
        if (xBi[i] != yBi[i]) result.push_back(1);
        else result.push_back(0);
    }
    if (getTen(result) == b) return true;
    return false;
}
vector<long> bitwiseEquations(vector<long> a, vector<long> b) {
    vector<long> ans;
    for(int i = 0; i < a.size(); i++) {
        bool find = false;
        for(long long x = 0; x <= a[i]; x++) {
            long long y = a[i] - x;
            if (isXplusY(x, y, a[i]) && isXoY(x, y, b[i])) {
                ans.push_back(2*x+3*y);
                find = true;
                break;
            }
        }
        if (!find) ans.push_back(0);
    }
    return ans;
}

int main() {
//    cout << isXoY(2,27,25);
//    cout << isXoY(1,3,2);
    vector<long> ans = bitwiseEquations({4,3,57},{2,4,49});
    return 0;
}
