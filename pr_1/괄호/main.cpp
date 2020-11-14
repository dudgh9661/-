#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {

    // ( 와 ) 의 총 개수가 맞으면 YES, 아니면 NO
    //1. 스택에 저장하고 하나씩 빼면서 각 기호에 맞는 카운팅을 해준다.


    int N;
    scanf("%d", &N);

    stack<char> st;
    vector<string> ans;

    for(int i = 0; i < N; i++) {

        string input;
        cin >> input;
        if ( input.length() < 2 || input.length() > 50) return 0;
        int flag = 0;

        while ( !st.empty() ) {
//            printf("kjl??");
            st.pop();
        }

//        if ( st.empty() ) { printf("this "); }

        char ch = input[0];
        if (ch == ')') {
            ans.push_back("NO");

            flag = 1;
            continue;
        }

        for (int idx = 0; idx < input.length(); idx++) {
            ch = input[idx];
            if (ch == ')') {
                if( st.empty() ) {
//                    printf("NO\n");
                    ans.push_back("NO");
                    flag = 1;
                    break;
                }
                st.pop();

            } else if (ch == '(') {
                st.push(ch);
            }
        }

        if( flag == 1 ) continue;
        else {
            if (st.empty()) {
                ans.push_back("YES");
//                printf("YES\n");
            }
            else if (!st.empty())
            {
                ans.push_back("NO");
            }
        }


    }

    for(int i = 0; i < ans.size(); i++) {
//        printf("size : %d\n", ans.size());
        cout << ans[i] << endl;
    }
    return 0;
}
