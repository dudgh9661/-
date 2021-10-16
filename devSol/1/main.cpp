#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> mp;

string getNew(string id) {
    int pos = -1;
    for(int i = 0; i < id.length(); i++) {
        if (isdigit(id[i])) {
            pos = i;
            break;
        }
    }

    int n = 1;
    string base = id.substr(0, pos);
    if (pos == -1) {
        string res = base + to_string(n);
        return res;
    } else {
        n = stoi(id.substr(pos,-1));
        n++;
        string res = base + to_string(n);
        return res;
    }
}
pair<string,int> split(string str) {
    int pos = -1;
    for(int i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        return make_pair(str, 0);
    }
    string id = str.substr(0, pos);
    string num = str.substr(pos,-1);
    return {id, stoi(num)};
}

void init(vector<string> registered_list) {
    for(int i = 0; i < registered_list.size(); i++) {
        pair<string,int> p = split(registered_list[i]);
        string id = p.first;
        int num = p.second;
        if (mp.find(id) != mp.end()) {
            mp[id] = max(mp[id], num);
        } else {
            mp[id] = num;
        }
    }
}

string findId(string id) {
    pair<string,int> p = split(id);
    int n = mp.find(p.first)->second + 1;
    return p.first + to_string(n);
}

string solution(vector<string> registered_list, string new_id) {
    string answer = "";
    string id = new_id;

    init(registered_list);
    if (find(registered_list.begin(), registered_list.end(), id) == registered_list.end()) {
        return id;
    }

    while (find(registered_list.begin(), registered_list.end(), id) != registered_list.end()) {
        id = findId(id);
    }

    answer = id;
    return answer;
}

int main() {
//    {"cow", "cow1", "cow2", "cow3", "cow4", "cow9", "cow8", "cow7", "cow6", "cow5"}
//cow

//{"bird99", "bird98", "bird101", "gotoxy"}
//    {"apple1", "orange", "banana3"}
    vector<string> test = {"cow", "cow1", "cow2", "cow3", "cow4", "cow9", "cow8", "cow7", "cow6", "cow5"};
    string id = "cow";
    cout << solution(test,id);
    return 0;
}