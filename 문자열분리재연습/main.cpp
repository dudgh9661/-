#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

string split(string input, char ch) {
   string str;
   int start = 0;
   int pos = input.find(ch);
   str = input.substr(start, pos - start);
   cout << str << endl;
   while(pos != string::npos) {
       start = pos + 1;
       pos = input.find(ch, start);
       cout << start <<" , " << pos << " ";
       cout << input.substr(start, pos - start) << endl;
       str += input.substr(start, pos - start);
   }

   cout << "end!!!!!! " << input.substr(start, pos) << endl;
//   str += input.substr(start, pos);
//   cout << str;

   return str;
}

int main() {
    cout << split("abc 123 adsfsd 1", ' ');
    return 0;
}
