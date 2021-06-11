package com.company;

import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Pos implements Comparable<Pos>{
    int r;
    int c;
    int cnt;

    public Pos(int r, int c, int cnt) {
        this.r = r;
        this.c = c;
        this.cnt = cnt;
    }

    @Override
    public int compareTo(Pos pos) {
        return this.cnt - pos.cnt; //return 값이 양수이면 바뀐다.
    }
}
public class Main {

    static int[][] arr = new int[101][101];
    static boolean[][] visited = new boolean[101][101];

    static int[] UD = {-1,1,0,0};
    static int[] LR = {0,0,-1,1};

    static int M, N; // 행, 열
    static int answer = 1000000;

    public static void main(String[] args) throws IOException {
        input();
        BFS(1,1);
        System.out.println(answer);
    }

    static public void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for(int i = 1; i <= M; i++) {
            String[] s = br.readLine().split("");
            for(int j = 1; j <= N; j++) {
                arr[i][j] = Integer.parseInt(s[j-1]);
            }
        }
    }

    static public void BFS(int r, int c) {
        PriorityQueue<Pos> pq = new PriorityQueue<>();
        pq.add(new Pos(r,c,0));
        visited[r][c] = true;

        while( !pq.isEmpty() ) {
            int curR = pq.peek().r;
            int curC = pq.peek().c;
            int cnt = pq.peek().cnt;
            pq.remove();

            if( curR == M && curC == N ) {
                answer = cnt;
                break;
            }

            for(int i = 0; i < 4; i++) {
                int nr = curR + UD[i];
                int nc = curC + LR[i];

                if( !inRange(nr,nc) ) continue;
                if( visited[nr][nc] ) continue;

                if( arr[nr][nc] == 0 ) {
                    pq.add(new Pos(nr,nc, cnt ));
                    visited[nr][nc] = true;
                } else {
                    pq.add(new Pos(nr,nc, cnt + 1));
                    visited[nr][nc] = true;
                }
            }
        }
    }

    static public boolean inRange(int r, int c) {
        if( r > M || r < 1 || c > N || c < 1 ) return false;
        return true;
    }
}
