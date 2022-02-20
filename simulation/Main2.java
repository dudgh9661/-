package com.company;

import java.util.*;

class solution {
    ArrayList<Integer> al = new ArrayList<>();
    boolean[] visited = new boolean[8];
    int MIN = Integer.MAX_VALUE;

    boolean isAns(int K) {
        for (int i = 0; i < al.size()-1; i++) {
            if (Math.abs(al.get(i) - al.get(i+1)) > K) return false;
        }
        return true;
    }

    boolean isAns(int[] numbers, int K) {
        for (int i = 0; i < numbers.length-1; i++) {
            if (Math.abs(numbers[i] - numbers[i+1]) > K) return false;
        }
        return true;
    }

    int countSwap(int[] numbers, ArrayList<Integer> newAl) {
        int cnt = 0;

        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i] == newAl.get(i)) continue;

            int idx = newAl.indexOf(numbers[i]);

            int tmp = newAl.get(i);
            newAl.set(i, newAl.get(idx));
            newAl.set(idx, tmp);

            cnt++;
        }
        System.out.println("cnt : " + cnt);
        return cnt;
    }

    public void DFS(int[] numbers, int K) {
        if (al.size() == numbers.length) {
            System.out.println(al);
            if (isAns(K)) {
                ArrayList<Integer> newAl = (ArrayList<Integer>) al.clone();
                MIN = Math.min(MIN, countSwap(numbers, newAl));
            }
            return;
        }

        for (int i = 0; i < numbers.length; i++) {
            if (visited[i]) continue;
            al.add(numbers[i]);
            visited[i] = true;

            DFS(numbers, K);

            al.remove(al.size()-1);
            visited[i] = false;
        }

    }
    public int solution(int[] numbers, int K) {
        int answer = 0;
//        int[] test = {1,2,3,4};
//        al = new ArrayList<>(Arrays.asList(3, 6, 3, 2, 1, 4, 5, 8));
//        return countSwap(numbers);
        if (isAns(numbers, K)) {
            System.out.println("이미 답");
            return 0;
        }

        Arrays.fill(visited, false);

        DFS(numbers, K);

        if (MIN == Integer.MAX_VALUE) answer = -1;
        else {
            answer = MIN;
        }
        System.out.println("answer : " +answer);
        return answer;
    }
}
public class Main {

    public static void main(String[] args) {
        solution sol = new solution();
        int[] input = {3, 7, 2, 8, 6, 4, 5, 1};
        int K = 3;
        sol.solution(input, K);
    }
}
