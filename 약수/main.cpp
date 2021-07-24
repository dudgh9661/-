/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vec;

int N;

void init() {
    int n;
    cin >> n;
    
    int num;
    for(int i = 0; i < n; i++) {
        cin >> num;
        vec.push_back(num);
    }
}

void sol() {
    sort(vec.begin(), vec.end());
    if( vec.size() == 1 ) N = vec[0] * vec[0];
    else {
        N = vec[0] * vec[vec.size() - 1];
    }
}
int main()
{
    init();
    sol();
    cout << N;
    return 0;
}

