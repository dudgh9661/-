#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string a, string b) {
    return a + b > b+a;
}

string solution(vector<int> numbers) {
    string answer;   
    //1. 문자열 벡터에 numbers 원소를 하나씩 저장한다. 
    //2. 최대 숫자가 되는 기준으로 정렬한다. 
    vector<string> str; 
    for(int i = 0; i < numbers.size(); i++) {
        str.push_back( to_string(numbers[i]) );
    }
    
    sort(str.begin(), str.end(), compare );
    
    int cnt = 0;
    
    for(int i = 0; i < str.size(); i++) {
        answer += str[i];
        if( str[i].compare("0") == 0 ) {
            cnt++;
        }
    }
    
    if ( cnt == str.size() ) {
        answer = "0";
    }
    return answer;
}