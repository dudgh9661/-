class Solution {
public:
    queue<int> que;
    vector<int> ans;
    
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int size = deck.size();
        ans = vector<int>(size);
        sort(deck.begin(), deck.end());
        
        for (int i = 0; i < size; i++) {
            que.push(i);
        }
        
        int idx = 0;
        while (!que.empty()) {
            ans[que.front()] = deck[idx++];
            que.pop();
            if (que.empty()) break;
            que.push(que.front());
            que.pop();
        }
        
        return ans;
    }
};
