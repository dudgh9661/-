#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, string> dictionary;
unordered_map<string, string> variable;

void initMap(vector<vector<string>> variables) {
    for (auto var : variables) {
        string first = var[0];
        string second = var[1];
        int startPos = second.find("{");
        if (startPos != string::npos) {
            int endPos = second.find("}");
            variable[first] = second.substr(startPos+1, endPos-1 - startPos);
            continue;
        }
        dictionary[first] = second;
    }
}

void getVariable() {
    while (true) {
        bool notFound = true;
        vector<string> eraseKey;
        for (auto p : variable) {
            string lang = p.first;
            string var = p.second;
            auto itr = dictionary.find(var);
            if (itr == dictionary.end()) continue;
            dictionary[lang] = itr->second;
            notFound = false;
            eraseKey.push_back(lang);
        }
        for (auto key : eraseKey) {
            variable.erase(key);
        }
        if (notFound) break;
    }
}

string getAnswer(string& tstring) {
    cout << endl;
    int len = tstring.length();
    for (int i = 0; i < len; i++) {
        if (tstring[i] != '{') continue;
        int pos = tstring.find('}', i);
        string var = tstring.substr(i+1, pos-1 - i);
        cout << "var : " << var << endl;
        auto itr = dictionary.find(var);
        if (itr == dictionary.end()) {
            cout << "not found : " << var << endl;
            continue;
        }
        cout << var << " ::: " << itr->second << endl;
        tstring.replace(i, pos - i + 1, itr->second);
        cout << "tstring :: " << tstring << endl;
        len = tstring.length();
    }

    cout << "whtf???";
    return tstring;
}

string solution(string tstring, vector<vector<string>> variables) {
    string answer = "";
    initMap(variables);

    for (auto p : dictionary) {
        cout << p.first << " : " << p.second << endl;
    }
    cout << "------" << endl;
    for (auto p : variable) {
        cout << p.first << " : " << p.second << endl;
    }
    getVariable();
    cout << "------" << endl;
    for (auto p : dictionary) {
        cout << p.first << " : " << p.second << endl;
    }

    answer = getAnswer(tstring);
    cout << "''12312312323";
    return answer;
}

int main() {
//    "this is {template} {template} is {state}",
//            {{"template", "string"}, {"state", "{template}"}}
    // "{a} {b} {c} {d} {i}",
    //             {{"b", "{c}"}, {"a", "{b}"}, {"e", "{f}"}, {"h", "i"}, {"d", "{e}"}, {"f", "{d}"}, {"c", "d"}}
    cout << "ans : " << solution("{a} {b} {c} {d} {i}",
             {{"b", "{c}"}, {"a", "{b}"}, {"e", "{f}"}, {"h", "i"}, {"d", "{e}"}, {"f", "{d}"}, {"c", "d"}});
    return 0;
}
