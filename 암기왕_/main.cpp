#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tc;
int one,two;
vector<int> oneNote;
vector<int> twoNote;

void init() {
    oneNote.clear();
    oneNote.resize(0);

    twoNote.clear();
    twoNote.resize(0);

    cin >> one;
    int a;
    for(int i = 0; i < one; i++) {
        cin >> a;
        oneNote.push_back(a);
    }

    cin >> two;
    for(int i = 0; i < two; i++) {
        cin >> a;
        twoNote.push_back(a);
    }

    sort(oneNote.begin(), oneNote.end(), less<>());
}

void binarySearch(int target) {
    int low = 0;
    int high = oneNote.size()-1;
    while ( low <= high ) {
       int mid = (low+high) / 2;
       if (target > oneNote[mid]) {
           low = mid + 1;
       } else if ( target < oneNote[mid]) {
           high = mid - 1;
       } else {
           cout << "1" << "\n";
           return;
       }
   }
   cout << "0" << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> tc;

    for(int i = 0; i < tc; i++) {
        init();
        for(int j = 0; j < twoNote.size(); j++) {
            binarySearch(twoNote[j]);
        }
    }
    return 0;
}
