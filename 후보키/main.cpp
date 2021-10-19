#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> candidates;
vector<int> candidate;

bool isMinimality(vector<int> vec) {
    for (int i = 0; i < candidates.size(); i++) {
        int cnt = candidates[i].size(); // 2
        for (int j = 0; j < vec.size(); j++) { // 012
            if (find(candidates[i].begin(), candidates[i].end(), vec[j]) != candidates[i].end()) {
                cnt--;
            }
            if (cnt == 0 ) return false;
        }
    }
    return true;
}

bool isUniqueness(vector<int> vec, vector<vector<string>> relation) {
    set<vector<string>> st;
    vector<string> tmp;

    for (int i = 0; i < vec.size(); i++) {
        tmp.push_back(relation[0][vec[i]]);
    }
    st.insert(tmp);

    for (int i = 1; i < relation.size(); i++) {
        tmp = vector<string>();
        for (int j = 0; j < vec.size(); j++) {
            tmp.push_back(relation[i][vec[j]]);
        }
        // 같은 원소가 있다면
        if (st.find(tmp) != st.end()) {
            return false;
        } else st.insert(tmp);
    }
    return true;
}

void DFS(int start, vector<vector<string>> relation, int cnt, int depth) {
    if (cnt == depth) {
//        cout << "if문 안" << endl;
//        for (int n : candidate) {
//            cout << n << " ";
//        }
//        cout << endl;
        if (isMinimality(candidate) && isUniqueness(candidate, relation)) {
            candidates.push_back(candidate);
        }
        return;
    }

    for (int i = start; i < relation[0].size(); i++) {
        candidate.push_back(i);
        DFS(i + 1, relation, cnt + 1, depth);
        candidate.pop_back();
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    for (int i = 1; i <= relation[0].size(); i++) {
        DFS(0, relation, 0, i);
    }
    answer = candidates.size();
//    cout << "후보키들" << endl;
//    for (auto candi : candidates) {
//        for (auto n : candi) {
//            cout << n << " ";
//        }
//        cout << endl;
//    }
    return answer;
}

int main() {
//    {{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2}}
    solution({{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}});
    return 0;
}