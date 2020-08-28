#include <stack>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

queue<char> que;
stack<int> st;
//( : 100 , ) : - 100, [ : 200 , ] : -200

int error = 0;

void solution() {
    while (!que.empty()) {
        // 2. 큐에서 문자를 하나씩 뺀다.
        char front = que.front();
//        printf("fff %c ", front);
        que.pop();
// 2-1. 큐에서 뺀 문자를 검사한다.
// 2-1-1. 그 문자가 (, [ 이면 스택에 넣는다.
        if (front == '(') {
            st.push(100);
        } else if (front == '[') {
            st.push(200);
//            printf("\nis %c\n", front);
        }
// 2-1-2.  그 문자가 ), ] 이면
        else if (front == ')') {
//            printf("dkljfalkj");
            //stack top is 문자일 경우

            int top = st.top();
            if (top == 100) {
//                printf("hh");
                st.pop();
                st.push(2);
//                printf("here?");
            } else if (top == 200) {
                error = 1; // in case '['
                return;
            }
            else { //숫자일 경우
                st.pop(); //팝한다.
                if( st.empty() ) {
                    error = 1;
                    return;
                }
//                if (st.size() == 0) { //팝하고 난 후 스택이 비어있으면,즉 숫자가 하나 있을 경우
//                    int num = 2 + top;
//                    st.push(num); // 팝한 숫자를 더해서 다시 넣는다.
//                }
                else { //스택이 비어있지 않으면
//                int nextTop;
                    while (1) {//다시 숫자일 경우 , 즉 숫자가 여러개일 경우
//                        printf("his?");
                        if ( st.empty() ){
                            error = 1;
                            return;
                        }
                        int nextTop = st.top();

                        if (nextTop == 100) {
                            st.pop();
                            top = top * 2;
                            break;
                        }
                        st.pop();
                        top = nextTop + top;
                    }

                    st.push(top);

                }
            }
        } else if (front == ']') {
//        printf("dfkljalk\n");
            //stack top is 문자일 경우
            int top = st.top();
            if (top == 200) {
                st.pop();
                st.push(3);
            } else if (top == 100)
            {
                error = 1; // in case '['
                return;
            }
            else { //숫자일 경우
                st.pop(); //팝한다.
                if( st.empty() ) {
                    error = 1;
                    return;
                }
//                if (st.size() == 0) { //팝하고 난 후 스택이 비어있으면,즉 숫자가 하나 있을 경우
//                    int num = 3 + top;
//                    st.push(num); // 팝한 숫자를 더해서 다시 넣는다.
//                }
                else { //스택이 비어있지 않으면
//                int nextTop;
                    while (1) { //다시 숫자일 경우 , 즉 숫자가 여러개일 경우
                        if ( st.empty() ){
                            error = 1;
                            return;
                        }
                        int nextTop = st.top();

                        if (nextTop == 200) {
                            st.pop();
                            top = top * 3;
                            break;
                        }

                        st.pop();
                        top = nextTop + top;
                    }

                    st.push(top);

                }
            }

        }
    }
}

//  2-1-2-1. 현재 스택의 탑에 있는 것이 문자이고 짝이 맞으면, 팝하고 "괄호의 맞는 값"을 다시 스택에 푸시한다.
//  2-1-2-2. 현재 스택의 탑에 있는 것이 숫자일 경우,
// 1. 스택을 팝한다.
// 2. 스택이 비어있을 경우, 팝한 숫자와 괄호와 맞는 값을 "덧셈"하여 다시 푸시한다.
// 2. 탑을 검사한다. 숫자일 경우 다시 팝한다. 이전에 팝한 숫자와 더해서 다시 푸시한다.
// 2. 탑을 검사했을때, 문자이면 팝한 숫자와 괄호와 맞는 값을 "곱"하여 다시 넣어준다.


int main() {
    string input;
    cin >> input;

    if( input.size() == 0 ) {
        printf("0\n");
        return 0;
    }
    else if( input.size() > 0 ) {
        if (input[0] == ')' || input[0] == ']' || input[ input.size() - 1] == '(' || input[ input.size() - 1] == '[') {
            printf("0\n");
            return 0;
        }
    }
    for(int i = 0; i < input.length(); i++) {
        // 1. input 값을 문자열로 받아 que에 모두 넣는다.
//        printf("%c", input[i]);
        que.push( input[i] );
    }

    solution();
    if( st.empty() ) {
        printf("0\n");
        return 0;
    }

    int sum = 0;
    while ( !st.empty() ) {
        if( st.top() == 100 || st.top() == 200 ) {
            printf("0\n");
            return 0;
        }
        sum += st.top();
//        printf("%d ", st.top());
        st.pop();
    }

    if( error == 1) {
        printf("0\n");
        return 0;
    }

    printf("%d\n", sum);

    return 0;
}

 