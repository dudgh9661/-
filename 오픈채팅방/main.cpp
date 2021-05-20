#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

vector< vector<string> > vec;
map<string, string> mp;
queue<pair<string,string>> que;

vector<string> parsing(string str) {
    vector<string> res;
    int start = 0;
    int pos = str.find(' ');
    string sub;
    sub = str.substr(start, pos - start);
    res.push_back(sub);
    
    while( pos != string::npos) {
        start = pos + 1;
        pos = str.find(' ', start);
        sub = str.substr(start, pos - start);
        res.push_back(sub);
    }
    return res;
}

void init(vector<string> record) {
    for(int i = 0; i < record.size(); i++) {
        vec.push_back(parsing(record[i]));
    }
}

void mapping(vector<string> &answer) {
    while( !que.empty() ) {
        string uid = que.front().first;
        string msg = que.front().second;
        string res = mp[uid] + msg;
     
        answer.push_back(res);
        que.pop();
    }
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    init(record);
    
    for(int i = 0; i < vec.size(); i++) {
        if( vec[i][0] == "Enter") {
            mp[vec[i][1]] = vec[i][2];
            que.push({vec[i][1], "님이 들어왔습니다."});//uid, msg        
        } else if ( vec[i][0] == "Change" ) {
            mp[vec[i][1]] = vec[i][2];
            
        } else {
        
            que.push({vec[i][1], "님이 나갔습니다."});//uid, msg
        }
    }
    mapping(answer);
  
    return answer;
}
