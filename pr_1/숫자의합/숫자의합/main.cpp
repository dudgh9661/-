#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>

using namespace std;
int main()
{
    freopen("input.txt","r", stdin);
    string input = "";
    string test = "1";
    int num = 0;
    cin >> num;
    cin >> input;
    //12345
    
    int total = 0;
    int tmp = 0;
    
    for(int i = 0; i < num; i++) {
        tmp = input[i] - '0';
//        cout << tmp << endl;
        total += tmp;
    }
    
    cout << total;
    return 0;
}

