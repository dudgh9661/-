#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {

    string input; 
    cin >> input;
    vector<int> alphabet(26,-1);
    vector<bool> visit(26, false);

    
    for(int i = 0; i < input.length(); i++) {
        int pos = input[i] % 97;
        
        if (visit[pos] == false ) {
            visit[pos] = true;
            alphabet[pos] = i;
        }
    }

    for(int i = 0; i < alphabet.size(); i++) {
        printf("%d ", alphabet[i]);
    }
    return 0;
}