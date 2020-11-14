#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int test = 0;
    scanf("%d", &test);
    cin.ignore(256,'\n');
    string str;
    string str_copy;
    
    for(int i = 0; i < test; i++)
    {
    getline(cin,str);
    
    for(string::iterator itr = str.end()-1; itr >= str.begin(); itr--)
    {
        str_copy = str_copy + *itr;
    }
    cout << "str : " << str << " str_c : " << str_copy << endl;
    if( str.compare(str_copy) == 0 ) printf("#%d 1\n", i + 1);
    else printf("#%d 0\n", i+1);
    str.clear();
    str_copy.clear();
    
    }
    
    return 0;
    
}

