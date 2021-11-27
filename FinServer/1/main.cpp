#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

/*
 *  매출액 : 고객에게 상품을 판매하고 얻은 금액
 *  매출원가 : 상품을 거래처로부터 구입할 때 지불한 금액
 *  매출원가 구하는 방식 : 선입선출법(queue), 후입선출법(stack)
 *  P : 구매
 *  S : 판
 */
struct Info{
    string ty;
    int num; // 금액
    int cnt; // 수
};

stack<pair<int,int>> st;
queue<pair<int,int>> que;

Info split(string record) {
    Info info;
    int pos = record.find(' ');
    int start = 0;
    string ty = record.substr(start, pos);

    start = pos + 1;
    pos = record.find(' ', start);
    int num = stoi(record.substr(start, pos - start));

    start = pos + 1;
    pos = record.find(' ', start);
    int cnt = stoi(record.substr(start, pos - start));

//    cout << ty << " " << num << " " << cnt << endl;
    info = {ty,num,cnt};
    return info;
}
// 선입선출
int preSale(vector<string>& records) {
    int total = 0;
    for (int i = 0; i < records.size(); i++) {
       Info info = split(records[i]);
       if (info.ty == "P") { // 구입
           que.push({info.num, info.cnt});
       } else { // 판매인 경우
           int saleCnt = info.cnt;
//           cout << "판매량 : " << saleCnt << endl;
           while (saleCnt != 0) {
               int storeCnt = que.front().second;
               if (storeCnt > saleCnt) {
                   total += que.front().first * saleCnt;
                   que.front().second = storeCnt - saleCnt;
                   saleCnt = 0;
//                   cout << "11" << endl;
               } else if (storeCnt == saleCnt) {
                   total += que.front().first * saleCnt;
                   saleCnt = 0;
                   que.pop();
//                   cout << "22" << endl;
               } else {
                   total += que.front().first * storeCnt;
                   saleCnt -= storeCnt;
                   que.pop();
//                   cout << "33" << endl;
               }
           }
       }
    }
//    cout << "total : " << total << endl;
    return total;
}

// 후입선출
int postSale(vector<string>&records) {
    int total = 0;
    for (int i = 0; i < records.size(); i++) {
        Info info = split(records[i]);
        if (info.ty == "P") {
            st.push({info.num, info.cnt});
        } else {
            int saleCnt = info.cnt;
            while (saleCnt != 0) {
                int storeCnt = st.top().second;
                if (storeCnt > saleCnt) {
                    total += st.top().first * saleCnt;
                    st.top().second = storeCnt - saleCnt;
                    saleCnt = 0;
                } else if (storeCnt == saleCnt) {
                    total += st.top().first * saleCnt;
                    saleCnt = 0;
                    st.pop();
                } else {
                    total += st.top().first * storeCnt;
                    saleCnt -= storeCnt;
                    st.pop();
                }
            }
        }
    }
    return total;
}
vector<int> solution(vector<string> record) {
    vector<int> answer;
    cout << "선입선출 : " << preSale(record) << endl;
    cout << "후입선출 : " << postSale(record);
    return answer;
}

int main() {
    // {"P 300 6", "P 500 3", "S 1000 4", "P 600 1", "S 1200 2"}
    // {"P 100 4", "P 300 9", "S 1000 7", "P 1000 8", "S 700 7", "S 700 3"}
    vector<string> test = {"P 100 4", "P 300 9", "S 1000 7", "P 1000 8", "S 700 7", "S 700 3"};
    solution(test);
}