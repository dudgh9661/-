#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N;
int maxLen = -1;

vector<int> vec;
int position[1000001] = {0};

void init() {
    cin >> N;

    fill(position, position+1000001, -1);
    int input;
    for(int i = 0; i < N; i++) {
        cin >> input;
        vec.push_back(input);
        position[input] = i;
    }
}

void Find() {
    for(int j = 0; j < vec.size(); j++) {
        int num = vec[j];
        int prePos = position[num];
        int len = 1;

        for (int i = prePos; i < vec.size(); i++) {
            int postPos = position[++num];

            if (prePos < postPos) {
                len++;
                prePos = postPos;
                i = prePos;
            } else break;
        }

        if (len > maxLen) {
            maxLen = len;
        }
    }
//    cout << maxLen << endl;


}
int main() {
    init();
    Find();

    cout << N - maxLen << endl;
    return 0;
}
