package com.company;

import java.util.*;

class Solution {
    char[] bracket = {'{', '(', '[', ']', ')', '}'};

    boolean isBracket(String s) {
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (st.isEmpty()) st.push(ch);
            else {
                if (st.peek() == '(' && ch == ')') {
                    st.pop();
                } else if (st.peek() == '[' && ch == ']') {
                    st.pop();
                } else if (st.peek() == '{' && ch == '}') {
                    st.pop();
                } else {
                    st.add(ch);
                }
            }

        }
        if (st.isEmpty()) return true;
        else return false;
    }

    char findMissBracket(String s) {
        char ch = 'x';
        Map<Character, Integer> map = new HashMap<>();
        map.put('(', 0); map.put(')', 0);
        map.put('{', 0); map.put('}', 0);
        map.put('[', 0); map.put(']', 0);


        // find
        for (int i = 0; i < s.length(); i++) {
            char key = s.charAt(i);
            map.put(key, map.getOrDefault(key, 0) + 1);
        }

        for (Map.Entry<Character, Integer> mp : map.entrySet()) {
            char key = mp.getKey();
            int val = mp.getValue();
            if (key == '(') {
                if (val > map.get(')')) {
                    ch = ')';
                    break;
                }  else if (val < map.get(')')) {
                    ch = '(';
                    break;
                }
            } else if (key == '{') {
                if (val > map.get('}')) {
                    ch = '}';
                    break;
                }  else if (val < map.get('}')) {
                    ch = '{';
                    break;
                }
            } else if (key == '[') {
                if (val > map.get(']')) {
                    ch = ']';
                    break;
                }  else if (val < map.get(']')) {
                    ch = '[';
                    break;
                }
            }
        }
        return ch;
    }

    public int solution(String s) {
        int answer = 0;
        // 올바른 괄호인 경우
        if (isBracket(s)) return 0;

        System.out.println(isBracket(s));
        char missedBracket = findMissBracket(s);
        System.out.println("missedBracket : " + missedBracket);
        for (int i = 0; i < s.length()+1; i++) {
                StringBuilder sb = new StringBuilder(s);
                char input = missedBracket;
                sb.insert(i, input);
                System.out.println("input char : " + input);
                System.out.println("making String : " + sb.toString());

                if (isBracket(sb.toString())) {
                    System.out.println(sb.toString() + " : true");
                    answer++;
                }
                System.out.println("back String : " + sb.toString());
                System.out.println();
        }
        return answer;
    }
}
public class Main {

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println("answer : " + sol.solution("{([()]))}"));
    }
}
