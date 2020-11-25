#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000

using namespace std;

int n;
int maxElement = -1;
int minElement = -1;
int minIdx = -1;
int answer = 0;

vector<int> vec;
vector<int> tmp;

void Print() {
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}
void init() {
    cin >> n;
    int input;

    for(int i = 0; i < n; i++) {
        cin >> input;
        vec.push_back(input);
    }


    maxElement = *max_element(vec.begin(), vec.end());
//    cout << maxElement << endl;
}
int Find(int value) {
    for(int i = 0; i < vec.size(); i++) {
        if( vec[i] == value ) return i;
    }
}
int findTwo() {
    int MIN = INF;
    for(int i = 0; i < vec.size(); i++) {
        if( vec[i] < MIN && vec[i] != minElement ) {
            MIN = vec[i];
        }
    }
    return MIN;
}
pair<int,int> findRange(int target) {
    pair<int,int> pos;

    for(int i = minIdx; i >= 0; i--) {
        if( vec[i] != target ) {
            pos.first = i + 1;
            break;
        } else if ( vec[i] == target ) {
            pos.first = i;
        }
    }

    for(int i = minIdx; i < vec.size(); i++) {
        if( vec[i] != target ) {
            pos.second = i - 1;
            break;
        } else if ( vec[i] == target ) {
            pos.second = i;
        }
    }

    return pos;
}

void sol() {

    while( true ) {
        minElement = *min_element(vec.begin(), vec.end());
        minIdx = Find(minElement);
        if( minElement == maxElement ) break;
//        cout << "min , max " << minElement << "," << maxElement<< endl;


        int nextMin = findTwo();
        answer += nextMin - minElement;
//        cout << "answer : " << answer << endl;

        int start = findRange(minElement).first;
        int end = findRange(minElement).second;

//        cout << start << "," << end << endl;
        for (int i = start; i <= end; i++)
            vec[i] = nextMin;
    }

}
int main() {
    init();
    sol();
    cout << answer << endl;
//    Print();
    return 0;
}
