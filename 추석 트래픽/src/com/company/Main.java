package com.company;

import java.text.DateFormat;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        Solution sol = new Solution();
        String[] test = {"2016-09-15 20:59:57.421 0.351s",
                "2016-09-15 20:59:58.233 1.181s",
                "2016-09-15 20:59:58.299 0.8s",
                "2016-09-15 20:59:58.688 1.041s",
                "2016-09-15 20:59:59.591 1.412s",
                "2016-09-15 21:00:00.464 1.466s",
                "2016-09-15 21:00:00.741 1.581s",
                "2016-09-15 21:00:00.748 2.31s",
                "2016-09-15 21:00:00.966 0.381s",
                "2016-09-15 21:00:02.066 2.62s"};
        int ans = sol.solution(test);
//        System.out.println();
        System.out.println("answer : " + ans );
    }
}

class Solution {

    String[][] time = new String[2000][2000];

    public int solution(String[] lines) {
        int answer = 0;
        int cnt = 0;

        parsing(lines); //시작 시간, 마감 시간 별로 배열에 데이터가 저장됨

        for(int i = 0; i < lines.length; i++) {
            for(int k = 0; k < 2; k++) {
                String inputST = getTimeFormat(time[i][k]); //시작시간
                String inputET = getPlusOneSec(inputST); //1초 후 시간

                for (int j = 0; j < lines.length; j++) {
                    if (inRange(time[j][1], time[j][0], inputST, inputET)) cnt++;
                    else {
//                        System.out.println("out of Range!!!");
                    }
                }
//                System.out.println(inputST + " ~ " + inputET + " cnt : " + cnt);
//                System.out.println();
                answer = Math.max(answer, cnt);
                cnt = 0;
//                System.out.println("---------------");
//                System.out.println();

            }
        }

        return answer;
    }

    //문자열 파싱 후, 시작시간과 마감시간을 배열에 저장
    public void parsing(String[] lines) {

        for(int i = 0; i < lines.length; i++) {
            String time[] = lines[i].split(" ");
            String startTime = getStartTime(time[1],Double.parseDouble(time[2].split("s")[0]));
            this.time[i][0] = getTimeFormat(time[1]);
            this.time[i][1] = startTime;
        }
    }

    //해당 구간에 속해있는지 판단하는 함수
    public boolean inRange(String start, String end, String inputStart, String inputEnd) {
//        System.out.println("판단 시간 : " + start + " ~ " + end);
//        System.out.println("기준 시간 : " + inputStart + " ~ " + inputEnd);
        long startT = getToDoubleFormat(start);
        long endT = getToDoubleFormat(end);
        long inputS = getToDoubleFormat(inputStart);
        long inputE = getToDoubleFormat(inputEnd);

        if( startT <= inputS ) {
            if( endT >= inputS) {
//                System.out.println("x <= x` is TRUE");
                return true;
            }
//            System.out.println("x <= x` is FALSE");
            return false;
        } else {
            if( startT <= inputE ) {
//                System.out.println("x <= x` is TRUE");
                return true;
            }
//            System.out.println("x <= x` is FALSE");
            return false;
        }
    }

    public long getToDoubleFormat(String time) {
        String[] timeArr = time.split(":");

        int hour = Integer.parseInt(timeArr[0]);
        int min = Integer.parseInt(timeArr[1]);
        double sec = Double.parseDouble(timeArr[2]);
        sec += hour * 60 * 60 + min * 60;

        sec *= 1000;
        long res = (long)Math.floor(sec);

        return res;
    }
    //원하는 형식으로 데이터를 변환하는 함수
    public String getTimeFormat(String time) {
        String[] timeArr = time.split(":");

        int hour = Integer.parseInt(timeArr[0]);
        int min = Integer.parseInt(timeArr[1]);
        double sec = Double.parseDouble(timeArr[2]);

        sec *= 1000;
        sec = Math.floor(sec);
        sec /= 1000;
        String res = hour + ":" + min + ":" + sec;

        return res;
    }

    //시작 시간을 반환하는 함수
    public String getStartTime(String time, double processTime) { //03:10:33.020, 0.1
        String[] timeArr = time.split(":");

        //s초 변환
        int hour = Integer.parseInt(timeArr[0]);
        int min = Integer.parseInt(timeArr[1]);
        double sec = Double.parseDouble(timeArr[2]);
        sec *= 1000;
        sec = Math.floor(sec);
        sec /= 1000;
//        System.out.println(hour + " : " + min + " : " + sec);
        sec += hour * 60 * 60 + min * 60;


        //연산
        double startTime = sec - processTime;
        startTime += 0.001;
        //다시 hh:mm:ss로 변환
        hour = (int)(startTime / 3600);
        min = (int)(startTime % 3600) / 60;
        sec =(startTime % 3600) % 60;

        String res = hour + ":" + min + ":" + sec;
        return res;
    }

    public String getPlusOneSec(String time) {
        String[] timeArr = time.split(":");

        int hour = Integer.parseInt(timeArr[0]);
        int min = Integer.parseInt(timeArr[1]);
        double sec = Double.parseDouble(timeArr[2]);
//        System.out.println(" from >> " + hour + " : " + min + " : " + sec);
        sec += 1 - 0.001;
//        System.out.println(" to >> " + hour + " : " + min + " : " + sec);
        sec += hour * 60 * 60 + min * 60;

        //다시 hh:mm:ss로 변환
        hour = (int)(sec / 3600);
        min = (int)(sec % 3600) / 60;
        sec = (sec % 3600) % 60;

        sec *= 1000;
        sec = Math.floor(sec);
        sec /= 1000;

        String res = hour + ":" + min + ":" + sec;
//        System.out.println("1s plus : " + res);
        return res;
    }
}
