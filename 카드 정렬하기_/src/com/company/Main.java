package com.company;

import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static int N;
    static int sum = 0;
    static PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();

    static void init() {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();

        for (int i = 0; i < N; i++) {
            priorityQueue.add(sc.nextInt());
        }
    }

    static void sol() {
        if ( priorityQueue.size() == 1 ) {
            sum = 0;
            return;
        }
        while (true) {
            int one = priorityQueue.poll();
            int two = priorityQueue.poll();
            int mergeCard = one + two;
            sum += mergeCard;
            if (priorityQueue.isEmpty()) break;
            priorityQueue.add(mergeCard);
        }
    }
    public static void main(String[] args) {
        init();
        sol();
        System.out.print(sum);
    }
}
