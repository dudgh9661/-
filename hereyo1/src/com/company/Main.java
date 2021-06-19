package com.company;

import java.util.ArrayList;
import java.util.Locale;
import java.util.StringTokenizer;

class EmployeeInfo {
    String fN;
    String mN;
    String lN;
    String email;

    EmployeeInfo(String fN, String mN, String lN, String email) {
        this.fN = fN;
        this.mN = mN;
        this.lN = lN;
        this.email = email;
    }
}

class EmailInfo {
    String email;
    int cnt;

    EmailInfo(String email, int cnt) {
        this.email = email;
        this.cnt = cnt;
    }
}

public class Main {

    public static void main(String[] args) {
        Solution sol = new Solution();
        sol.solution("John Doe, Peter Benjamin Parker, Mary Jane Watson-Parker, John Elvis Doe, John Evan Doe, Jane Doe, Peter Brian Parker", "test");
    }
}

//String s : 이름의 리스트, ",공백"으로 구분됨
//String C : 회사명
//return : ",공백"으로 구분된 이메일 주소들을 리턴해라. 순서는 input 순서와 동일하게
//form : 이름 <이메일>

class Solution {
    ArrayList<EmployeeInfo> arrayList = new ArrayList<>();
    ArrayList<EmailInfo> emailInfo = new ArrayList<>();

    public String solution(String S, String C) {
        splitName(S);
//        emailInfo.add(new EmailInfo("<peter.parker@test.com>", 3));

        for(int i = 0; i < arrayList.size(); i++) {
            int cnt = 0; //중복값
//            System.out.println(arrayList.get(i).fN + arrayList.get(i).mN + arrayList.get(i).lN);
            String resEmail = getEmail(arrayList.get(i), C);
            //이메일 중복 체크 후,
            int isExist = isEmailExist(resEmail);
            if(  isExist != -1 ) { //이메일이 중복된다면,
                //이메일 @ 앞에 숫자 추가
                StringBuffer sb = new StringBuffer(resEmail);
                int idx = resEmail.indexOf("@");
                sb.insert(idx, Integer.toString(emailInfo.get(isExist).cnt+1));
                //카운트 올리기
                emailInfo.get(isExist).cnt++;
                resEmail = sb.toString();
//                System.out.println("변경된 이메일 : " + resEmail);
            } else {
                emailInfo.add(new EmailInfo(resEmail, 1));
            }
            //이메일 정보 저장
            arrayList.get(i).email = resEmail;
        }



//        for(int i = 0; i < arrayList.size(); i++) {
//            System.out.println(arrayList.get(i).fN + arrayList.get(i).mN + arrayList.get(i).lN + " email : " + arrayList.get(i).email);
//        }
        return getAnswer();
    }

    //성과 이름을 분리해서 반환하는 함수
    public void splitName(String S) {
        String[] nameTmp = S.split(",");

        for (int i = 0; i < nameTmp.length; i++) {
            String str = nameTmp[i].trim();
            String[] strArr = str.split(" ");
            for (int j = 0; j < strArr.length; j++) {
//                System.out.print(strArr[j] + " ");
            }

            if (strArr.length == 3) {
                arrayList.add(new EmployeeInfo(strArr[0], strArr[1], strArr[2], null));
            } else {
                arrayList.add(new EmployeeInfo(strArr[0], null, strArr[1], null));
            }
        }
    }
    //이메일을 만드는 함수
    public String getEmail(EmployeeInfo employeeInfo, String C) {
        String lN = employeeInfo.lN;
        lN = lN.replace("-", "");
        String email = "<" + employeeInfo.fN + "." + lN + "@" + C + ".com"+ ">";
        email = email.toLowerCase();
//            System.out.println( employeeInfo.fN + "의 이메일은 " + email);
        return email;
    }
    //이메일 중복 체크하는 함수( 각 중복된 이메일마다 cnt 변수가 있어야 할 듯)
    public int isEmailExist(String email) {
        for(int i = 0; i < emailInfo.size(); i++) {
            if( emailInfo.get(i).email.equals(email) ) return i; //중복된 이메일이 존재함
        }
        return -1;
    }
    public String getAnswer() {
        String ans = "";
        for(int i = 0; i < arrayList.size(); i++) {
            String str = arrayList.get(i).fN + " ";
            if( !(arrayList.get(i).mN == null) ) str += arrayList.get(i).mN + " ";
            str += arrayList.get(i).lN;
            str += " ";
            str += arrayList.get(i).email;
            ans += str + ", ";
            System.out.println(str);

        }
        ans.trim();
        ans = ans.substring(0, ans.length()-2);
//        System.out.println(ans);
        return ans;
    }
}