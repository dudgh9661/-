class Solution {
    List<String> list = new ArrayList<String>();
    List<String> answer = new ArrayList<String>();
    
    public void DFS(String str, int curIdx, String digits) {
        if (curIdx == digits.length()) {
            // System.out.println("Maked str : " + str);
            answer.add(str);
            return;
        }
        
        int inputNum = digits.charAt(curIdx) - '0';
        for (int i = 0; i < list.get(inputNum).length(); i++) {
            str += list.get(inputNum).charAt(i);
            DFS(str, curIdx + 1, digits);
            str = str.substring(0, str.length()-1); // pop_back();
        }
    }
    
    public List<String> letterCombinations(String digits) {
        if (digits.isEmpty()) return new ArrayList<>(Arrays.asList());
        list.add("");
        list.add("");
        list.add("abc");
        list.add("def");
        list.add("ghi");
        list.add("jkl");
        list.add("mno");
        list.add("pqrs");
        list.add("tuv");
        list.add("wxyz");
        
        DFS("", 0, digits);
        return answer;
    }
}
