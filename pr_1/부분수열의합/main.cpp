#include <iostream>
#include <vector>

using namespace std;

int sum(vector<int> vec) {
    int sum = 0;
    for(int i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }

    return sum;
}

vector<int> vec;
vector<int> tmp;
bool visit[2000001] = { false };

void Print() {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "  end " << endl;
}

int ans = 0;
void DFS(int limit, int cnt, int find) {
    if( cnt == limit ) {
        if ( vec[0] > vec[1] ) return;
        else {
            if ( sum(vec)== find ) {
//                    cout << "find!" << endl;
            Print();
                    ans++;
            }

        }
        return;
    }

    for(int i = 0; i < tmp.size(); i++) {
        int number = tmp[i];
        if( number < 0 ) {
            number = 1000000 + (-number);
        }
        if( !visit[number] ) {
            visit[number] = true;
            vec.push_back(tmp[i]);
            cnt++;
            DFS(limit, cnt, find);
            vec.pop_back();
            visit[number] = false;
            cnt--;
        }
    }

}
int main() {

    int size = 0;
    cin >> size;
    int find = 0;
    cin >> find;
    for(int i = 0; i < size; i++) {
        int input = 0;
        cin >> input;
        tmp.push_back(input);
    }

//    for(int i = 0; i < tmp.size(); i++) {
//        cout << tmp[i] << endl;
//    }



//    tmp.push_back(-7);
//    tmp.push_back(-3);
//    tmp.push_back(-2);
//    tmp.push_back(5);
//    tmp.push_back(8);

    for(int i = 1; i < tmp.size(); i++) {
        DFS(i, 0, find);
    }

    cout << ans << endl;
    return 0;
}
