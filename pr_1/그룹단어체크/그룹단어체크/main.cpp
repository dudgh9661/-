#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int N = 0;
    scanf("%d", &N);
    
    vector<char> visit;
    
    string input;
    int idx = 0;
    bool overlap = false;
    int answer = 0;
    for(int i = 0; i < N; i++) {
        
        overlap = false;
        cin >> input;
        visit.push_back(input[0]);
//        cout << input[0];
        
        for(int j = 0; j < input.length(); j++) {
//            if( input.length() == 1) {break;}
            if( input[j] != input[j+1] ) {
                for( int k = 0; k < visit.size(); k++) {
                    if ( visit[k] == input[j+1] ) {
                        overlap = true;
                        
                        break;
                    }
                }
                
                if( overlap == false ) {
                    visit.push_back( input[j+1] );
                    
                } else {
                    break;
                }
                
            }
        } //end of for
        
//        cout << "dfadfa" <<endl;
        if( overlap == false ) answer++;
        visit.clear();
        visit.resize(0);
     
    }
    
    cout << answer << endl;
    return 0;
}
