class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size()-1;
        int MAX = 0;
        while (start != end) {
            MAX = max(MAX, min(height[start], height[end]) * abs(start - end));
            
            if (height[start] <= height[end]) {
                start++;
            } else end--;
        }
        
        return MAX;
    }
};
