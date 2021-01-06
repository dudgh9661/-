#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
/*
output : 만들 수 있는 소수의 개수
*/

int limit = 2;
int answer = 0;
bool visited[10] = { false };

vector<char> vec;
set<int> st;

void Print() {
    for(auto itr = st.begin(); itr != st.end(); itr++) {
        cout << *itr << " ";
    }
}
bool isSosu(int num) {
    int range = sqrt(num);
    // cout << "range : " << range << endl;
    for(int i = 2; i <= range; i++) {
        if( num % i == 0 ) return false;
    }
    return true;
}

string STR() {
    string str;
    for(int i = 0; i < vec.size(); i++) {
        str += vec[i];
    }
    return str;
}

void DFS(int cnt, string numbers){
    if( cnt == limit ) {
        int res = stoi(STR());
        // cout << "res : " << res << endl;
        if( isSosu(res) ) {
            if( res == 0 || res == 1) return;
            st.insert(res);
            // cout << "sosu : " << res << "\n";
            // answer++;
        }
        
        return;
    }
    
    for(int i = 0; i < numbers.size(); i++) {
        if( visited[i] == true ) continue;
        vec.push_back(numbers[i]);
        visited[i] = true;
    
        DFS(cnt + 1, numbers);
        
        vec.pop_back();
        visited[i] = false;
        
    }
}

int solution(string numbers) {
    for(int i = 1; i <= numbers.size(); i++) {
        limit = i;
        DFS(0, numbers);
    }
    
    Print();
    answer = st.size();
    
    return answer;
}
