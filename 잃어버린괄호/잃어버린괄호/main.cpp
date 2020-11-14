#include <string>
#include <iostream>
#include <vector>

using namespace std;
int main() {
    
    string str;
    cin >> str;
    vector<string> vec;
    
    int previous = 0, current = 0;
    current = str.find('-');
    string substring;
//    cout << current << endl;
    while( current != string::npos) {
        substring = str.substr(previous, current-previous);
        vec.push_back(substring);
//        cout << substring << endl;
        
        previous = current + 1;
        current = str.find('-', previous);
    }
    substring = str.substr(previous, str.length());
    vec.push_back(substring);
    
    int total = 0;
    for( int i = 0; i < vec.size(); i++) {
        
        string input2 = vec[i];
        current = input2.find("+");
        previous = 0;
        
        int tmp = 0;
        string strTmp;
        while( current != string::npos) {
             strTmp = input2.substr(previous, current-previous);
            tmp = stoi(strTmp);
            if( i != 0 ) total -= tmp;
            else total += tmp;
            
            previous = current + 1;
            current = input2.find("+", previous);
        }
        
        strTmp = input2.substr(previous, input2.length());
        tmp = stoi(strTmp);
        if( i != 0 ) total -= tmp;
        else total += tmp;
    }
    
    cout << total << endl;
    return 0;
}
