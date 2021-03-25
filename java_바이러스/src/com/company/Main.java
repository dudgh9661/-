package com.company;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    static ArrayList< Integer > [] arrayLists = new ArrayList[101];
    static boolean visited[] = new boolean[101];

    public static void main(String[] args) {
        int answer = 0;
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int tmp = sc.nextInt();

        for(int i = 1; i <= n; i++) {
            arrayLists[i] = new ArrayList<>();
        }

        for(int i = 0; i < tmp; i++) {
            int from = sc.nextInt();
            int to = sc.nextInt();
            arrayLists[from].add(to);
            arrayLists[to].add(from);
        }

        DFS(1);

        for(int i = 1; i <= 100; i++) {
            if( visited[i] ) answer++;
        }

        System.out.println(answer-1);
    }

    static void DFS(int start) {
        visited[start] = true;

        for(int i = 0; i < arrayLists[start].size(); i++) {
            int next = arrayLists[start].get(i);
            if( !visited[next] ) DFS(next);
        }
    }
}
