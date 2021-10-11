package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static boolean[] arr;
    static int N;
    static ArrayList<Integer> ans = new ArrayList<>();

    static boolean allDead() {
        for(int i = 1; i <= N; i++) {
            if (!arr[i]) return false;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        int K = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tk = new StringTokenizer(br.readLine());

        N = Integer.parseInt(tk.nextToken());
        K = Integer.parseInt(tk.nextToken());

        arr = new boolean[N+1];
        for(int i = 1; i <= N; i++) arr[i] = false;

        int delIdx = 0;
        int curIdx = 0;
        while (!allDead()) {
            int cnt = K;
            while (cnt != 0) {
                curIdx++;
                if (curIdx > N) curIdx = 1;
                if (arr[curIdx]) continue;
                cnt--;
            }
            delIdx = curIdx;
            arr[delIdx] = true;
            ans.add(delIdx);
//            System.out.println(delIdx + ", ");
        }

        System.out.print("<");
        for(int i = 0; i < ans.size()-1; i++) {
            System.out.print(ans.get(i) + ", ");
        }
        System.out.print(ans.get(ans.size()-1) + ">");
    }
}
