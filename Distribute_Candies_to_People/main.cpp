class Solution {
public:
        
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int cur = 0;
        int candy = 1;
        
        while ( candies > 0 ) {
            if ( num_people - cur == 0 ) cur = 0;
            if ( candies < candy ) {
                ans[cur] += candies;
                break;
            }
            ans[cur] += candy;
            candies -= candy;
            cur++;
            candy++;
        }
        return ans;
    }
};
