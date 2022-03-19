#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>

using namespace std;

/*
 * 제약조건
 *  1. 한번에 하나의 프로세스만 '쓰기' 가능
 *  2. '쓰기' 작업 진행 중일 경우, 새로운 읽기 && 쓰기 요청 프로세스는 모두 '대기'
 *  3. '읽기' 작업 진행 중일 경우, 새로운 '쓰기' 요청 프로세스는 모두 대기
 *      3-1. 단, 새로운 '읽기' 작업은 즉시 수행 가능
 *  4. 작업의 우선순위
 *      1. 쓰기 작업을 먼저 수행한다.
 *      2. 쓰기 작업이 여러개 -> 먼저 요청된 쓰기 작업부터 수행
 *  5. 대기중인 작업에서 수행하려 함과 동시에, 새로운 작업요청이 들어온다면
 *      1. 새 작업을 포함하여 우선순위를 다시 정한다.
 *      2. 우선수위가 높은 작업부터 실행한다.
 *
 *  OUTPUT
 *      1. 위 규칙을 적용한 작업 후, '읽기' 작업에서 읽은 내용 && 전체 프로세스가 배열을 사용한 시간
 *      2. 읽기 작업에서 읽은 순서대로, 정답 배열에 담아라
 *      3. 전체 프로세스가 배열을 사용한 시간은, 정답 배열의 '마지막'에 담아라.
 */

/*
 *  1. 쓰기 작업일 경우,
 *      1-1. if (읽기 작업 진행중) -> 대기 프로세스에 넣는다.
 *      1-2. else if (쓰기 작업 진행중) -> 대기 프로세스에 넣는다. 이 때 우선순위는 먼저 들어온 작업이 먼저이다.
 *      1-2. else // 빈 경우 -> 작업 프로세스에 넣는다.
 *  2. 읽기 작업일 경우,
 *      2-1. if (읽기 작업 진행중) -> 작업 프로세스에 넣는다. 읽기 시작
 *      2-2. else if (쓰기 작업 진행중) -> 대기 프로세스에 넣는다. 이 때, 우선순위는 쓰기 작업이 우선이다.
 *
 *  매 초마다, 현재 작업 상태를 검사한다.
 *   1. 현재 완료된 작업이
 *      1-1. if (쓰기) -> 대기 프로세스의 맨 앞 작업 투입 -> 이 때, '쓰기'가 아니라면 남아있는 것들은 '읽기'이므로 모조리 넣는다.
 *      1.2  else if (읽기) -> 대기 프로세스 맨 앞 작업 투입
 *
 */

typedef struct PROCESS {
    string status;
    int t1; // 시작 시간 (1,2) : 1초부터 2초간 즉, [1, 1+2]까지 작업
    int t2; // 작업 시간
    int start; // 읽기 시작, [start,end] 까지 write setting
    int end; // 읽기 종료 (포함),
    string write; // 데이터를 씀
}process;

struct cmp {
    bool operator() (process p, process p2) {
        if (p.status == "write" && p2.status == "write") {
            return p.start > p2.start;
        } else if (p.status == "read" && p2.status == "read") {
            return p.start > p2.start;
        } else if (p.status == "read" && p2.status == "write") {
            return true;
        }
        return false;
    }
};

vector<process> vec;
priority_queue<process, vector<process>, cmp> waitProcess;
queue<process> workProcess;

void init(vector<string>& processes) {
    for (int i = 0; i < processes.size(); i++) {
        istringstream iss(processes[i]);
        process p;
        string status;
        iss >> status;
        int t1, t2, start, end;
        string write;
        if (status == "read") {
            iss >> t1 >> t2 >> start >> end;
            p = {status, t1, t2, start, end, "-1"};
        } else {
            iss >> t1 >> t2 >> start >> end >> write;
            p = {status, t1, t2, start, end, write};
        }
        vec.push_back(p);
    }
}

string read(vector<string>& arr, process p) {
    string res = "";
    for (int i = p.start; i <= p.end; i++) {
        res.append(arr[i]);
    }
    return res;
}

void write(vector<string>& arr, process p) {
    for (int i = p.start; i <= p.end; i++) {
        arr[i] = p.write;
    }
}

void Print(process p) {
    cout << p.status << " : " << p.t1 << " " << p.t2 << " " << p.start << " " << p.end << " " << p.write << endl;
}

vector<string> solution(vector<string> arr, vector<string> processes) {
    init(processes);

    vector<string> answer;

    int cnt = processes.size()-1;
    int pIdx = 0;
    process p = vec[pIdx++];
    int curTime = p.start + p.end;
    workProcess.push(p);

    int timeCnt = 0;
    bool blocking = false;

    if (p.status == "write") {
        blocking = true;
        write(arr, p);
        Print(p);
    } else {
        answer.push_back(read(arr, p));
        Print(p);
        for (int i = 1; i < vec.size(); i++) {
            process nextP = vec[i];
            if (nextP.status == "read" && curTime >= nextP.start) {
                workProcess.push(nextP);
                pIdx = i + 1;
                answer.push_back(read(arr, nextP));
                Print(nextP);
            } else {
                pIdx = i;
                break;
            }
        }
    }


    while (!workProcess.empty()) {
        // 작업 프로레스가 빈 경우 아닌 경우
        process completeP = workProcess.front();
        workProcess.pop();
        curTime = completeP.start + completeP.end;
        cout << "in while "  << endl;
        Print(completeP);
        cout << "curTime : " << curTime << endl;

        // 대기 프로세스가 비어있지 않으면,
        if (!waitProcess.empty()) {
            process waitP = waitProcess.top();
            waitProcess.pop();
            if (waitP.status == "write") {
                if (!workProcess.empty()) continue;
                else {
                    workProcess.push(waitP);
                    write(arr, waitP);
                    Print(waitP);
                }
            } else {
                while(true) {
                    if (curTime >= waitP.start) {
                        workProcess.push(waitP);
                        Print(waitP);
                        answer.push_back(read(arr, waitP));
                    } else break;
                    waitP = waitProcess.top();
                    if (waitP.status == "write") break;
                }
            }
        } else { // 대기 프로세스가 비어있으면,
            process nextP = vec[pIdx];
            if (nextP.status == "write") {
                workProcess.push(nextP);
                blocking = true;
                write(arr, nextP);
            } else {
                while (true) {
                    if (curTime >= nextP.start) {
                        workProcess.push(nextP);
                        answer.push_back(read(arr, nextP));
                        nextP = vec[++pIdx];
                    } else {
                        if (workProcess.empty()) {
                            curTime = nextP.start;
                            while (true) {
                                workProcess.push(nextP);
                                answer.push_back(read(arr, nextP));
                                nextP = vec[++pIdx];
                                if (curTime < nextP.start) break;
                            }
                        }
                        break;
                    }
                    if (nextP.status == "write") break;
                }
            }
        }
    }

    for (auto s : answer) {
        cout << s << endl;
    }
    return answer;
}

int main() {
    solution({"1","2","4","3","3","4","1","5"},
             {"read 1 3 1 2","read 2 6 4 7","write 4 3 3 5 2","read 5 2 2 5","write 6 1 3 3 9", "read 9 1 0 7"});
    return 0;
}
