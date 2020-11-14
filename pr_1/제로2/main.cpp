#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> vec;
    stack<int> st;

    for(int i = 0; i < N; i++) {
        int input = 0;
        scanf("%d", &input);
        vec.push_back(input);
    }

    for(int i = 0; i < vec.size(); i++) {
        int input = vec[i];
        if( input == 0 ) {
            st.pop();
//            printf("input : %d ", input);
        }
        else {
            st.push(input);
//            printf("input : %d ", input);

        }
    }

    int sum = 0;
    while( !st.empty() ) {
        int top = st.top();
        st.pop();
        sum += top;
    }

    printf("%d", sum);

    return 0;
}
