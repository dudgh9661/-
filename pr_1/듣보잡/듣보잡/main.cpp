#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void Print( vector<string> vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
        }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //교집합 set
    int N = 0, M = 0;
    cin >> N >> M;
    string input;
    vector<string> vec;
    vector<string> vec2;
    vector<string> res;
    vector<string>::iterator itr;
    
    
    for(int i = 0; i < N; i++) {
        cin >> input;
        vec.push_back(input);
//        cout << "N : " << input << endl;
    }
    
    for(int i = 0; i < M; i++) {
        cin >> input;
        vec2.push_back(input);
//        cout << "M : " << input << endl;
    }
    sort(vec.begin(), vec.end(), less<string>());
    sort(vec2.begin(), vec2.end(), less<string>());
    
//    Print(vec);
//    Print(vec2);
    res.resize(vec.size() + vec2.size());
//    printf("res size : %d\n", res.size());
    itr = set_intersection(vec.begin(), vec.end(), vec2.begin(), vec2.end(), res.begin());
    res.resize(itr - res.begin());
//    Print(res);
    
    printf("%d\n", res.size());
    for(itr = res.begin(); itr != res.end(); itr++) {
        cout << *itr << endl;
    }
//
//    printf("siapr")
    return 0;
}
