#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    int itr = 1;
    int cnt = 0;
    vector<string> tmp;
    for(int i = 0; i < words.size(); i++) {
        cnt++;

        string str = words[i];
        char ch = str[0];

        if( tmp.size() > 0 ) {
            string last = tmp.back();
            cout << "last : " << last << endl;
            if( last[last.size()-1] != ch ) {
                answer.push_back( i % n + 1); //탈락하는 사람의 번호
                answer.push_back(itr);
                return answer;
            }
        }

        // 반복 체크
        for(int j = 0; j < tmp.size(); j++) {
            if( str == tmp[j] ) {
                answer.push_back( i % n + 1);
                answer.push_back(itr);
                return answer;
            }
        }
        if( cnt == n ) {
            itr++;
            cnt = 0;
        }
        tmp.push_back(str);
    }

    answer.push_back(0);
    answer.push_back(0);

    return answer;

}

int main() {
    //{"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"}
    //{"hello", "one", "even", "never", "now", "world", "draw"}
    vector<string> test{"hello", "one", "even", "never", "now", "world", "draw"};
    vector<int> output = solution(2, test);
    for(int i = 0; i < output.size(); i++) cout << output[i] << endl;
    return 0;
}