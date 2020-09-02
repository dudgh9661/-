#include <string>
#include <iostream>

using namespace std;

int main() {
        string input;
        cin >> input;
        int size = input.length();

        int pos = 0;
        int end = 10;
        while( pos < size ) {
            string sub = input.substr(pos, 10);
            pos += 10;
            cout << sub << endl;


        }
return 0;
}


