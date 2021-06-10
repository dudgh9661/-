package com.company;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Pos {
    int r,c;

    Pos(int r, int c) {
        this.r = r;
        this.c = c;
    }
};

public class Main {

    static int[][] origin = new int[8][8];
    static int[][] arr = new int[8][8];
    static boolean[][] visited = new boolean[8][8];
    static ArrayList<Pos> safeList = new ArrayList<>(); //고정
    static ArrayList<Pos> blockList = new ArrayList<>(); //알아서 변함
    static ArrayList<Pos> virusList = new ArrayList<>(); //고정
    static int[] UD = { -1, 1, 0, 0};
    static int[] LR = { 0, 0, -1, 1};

    static int n, m;
    static int MAX = -1;

    public static void main(String[] args) {
        input();
        DFS(0,0);
        System.out.print(MAX);

    }


    static void input() {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int tmp = sc.nextInt();
                origin[i][j] = tmp;
                if (tmp == 0) {
                    safeList.add(new Pos(i, j)); //빈 공간 저장
                } else if ( tmp == 2) {
                    virusList.add(new Pos(i,j));
                }
            }
        }
        init();
    }

    static void init() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                arr[i][j] = origin[i][j];
                visited[i][j] = false;
            }

        }
        //visited 초기화
    }

    //벽을 치는 변수 생성
    static void DFS(int start, int cnt) {
        if( cnt == 3 ) {
            //만들어진 벽들의 정보로, 벽을 세워본다.
            setBlock();
            //바이러스를 확산시킨다.
            BFS();
            //안전구역을 카운팅한다.
            MAX = Math.max(getSafeCount(), MAX);
            //데이터들을 다시 초기 시켜준다.
            init();
            return;
        }

        for(int i = start; i < safeList.size(); i++) {
            blockList.add(new Pos(safeList.get(i).r, safeList.get(i).c));
            DFS(i + 1, cnt + 1);
            blockList.remove(blockList.size() - 1);
        }
    }

    //만들어진 벽의 정보를 기반으로, arr 갱신
    static void setBlock() {
        //벽의 정보 출력
        for(int i = 0; i < blockList.size(); i++) {
            int r = blockList.get(i).r;
            int c = blockList.get(i).c;
            arr[r][c] = 1;
        }
    }

    //바이러스 확산시키는 함수
    static void BFS() {
        Queue<Pos> queue = new LinkedList<>();
        for(int i = 0; i < virusList.size(); i++) {
            queue.add(virusList.get(i));
            visited[virusList.get(i).r][virusList.get(i).c] = true;
        }

        while( !queue.isEmpty() ) {
            int cR = queue.peek().r;
            int cC = queue.peek().c;
            queue.remove();

            for(int i = 0; i < 4; i++) {
                int nr = cR + UD[i];
                int nc = cC + LR[i];

                if( !inRange(nr,nc) ) continue;
                if( visited[nr][nc] ) continue;
                if( arr[nr][nc] != 0 ) continue;

                visited[nr][nc] = true;
                //확산당한 바이러스 정보를 추가
                queue.add(new Pos(nr,nc));
                arr[nr][nc] = 2;
            }
        }
    }

    //범위 계산
    static boolean inRange(int r, int c) {
        if( r >= n || r < 0 || c >= m || c < 0 ) return false;
        return true;
    }

    //안전구역 개수를 구하는 함수
    static int getSafeCount() {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }

    static void Print() {
        for(int i = 0; i < n; i++) {
            for(int j = 0 ; j < m; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }
}
