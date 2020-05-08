#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    //인형을 저장한 stack
    stack<int> dollStore;
    //크레인이 내려간 위치에 인형이 있는지 검사한다.
    for(int i = 0; i < moves.size(); i++) {
        int crainPosition = moves[i]-1;
        
        for(int j = 0; j < board.size(); j++) {
            if( board[j][crainPosition] != 0 ) { // 인형이 있다면,
                int doll = board[j][crainPosition];
                //0으로 바꿔준다 (뽑았으니깐)
                board[j][crainPosition] = 0;
                
                //그 인형을 뽑아서 stack에 top에 있는 인형과 비교하여
                if( dollStore.empty() ) dollStore.push(doll);
                else { //인형저장소가 비어있지 않은 경우는
                    //같으면 넣지 않고
                    printf("top : %d ", dollStore.top());
                    if( doll == dollStore.top() ) { // 2개가 된 경우
                        dollStore.pop();
                        answer += 2;
                    }
                    //다르면 넣는다.
                    else dollStore.push(doll);
                
                    
                }
                
                
                break;
            }
        }
        
    }
    
    printf("sol : %d", answer);
    
    return answer;
}
