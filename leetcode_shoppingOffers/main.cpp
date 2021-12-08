class Solution {
public:
    
    int getWithoutOffer(vector<int> price, vector<int>& needs) {
        int sum = 0;
        for (int i = 0; i < needs.size(); i++) {
            sum += needs[i] * price[i];
        }
        return sum;
    }
    
    void getUsingOffer(vector<int> special, vector<int>& needs) {
        for (int i = 0; i < needs.size(); i++) {
            needs[i] -= special[i];
        }
    }
    
    bool existNegative(vector<int> needs) {
        for (auto need : needs) {
            if (need < 0) return true;
        }
        return false;
    }
    
    void getPreUsingOffer(vector<int> special, vector<int>& needs) {
        for (int i = 0; i < needs.size(); i++) {
            needs[i] += special[i];
        }
    }
    
    bool allZero(vector<int> price) {
        for (auto p : price) {
            if (p != 0) return false;
        }
        return true;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if (allZero(price)) return 0;
        // 1. 현재 needs를 price로 구입했을 때의 가격을 구한다.
        
        int bestPrice = getWithoutOffer(price, needs);
        // 2. 각 offer를 통해서 구입할 수 있을 경우, 구입하고 DFS 진입
        for (auto sp : special) {
            getUsingOffer(sp, needs);
            if (!existNegative(needs)) { // offer로 구입할 수 있는 경우
                int priceUsedOffer = sp.back() + shoppingOffers(price, special, needs); // offer 가격 + 최솟값 반환 재귀호출
                bestPrice = min(bestPrice, priceUsedOffer);
            }
            // offer로 구입할 수 없는 경우
            getPreUsingOffer(sp, needs);
        }
        return bestPrice;
        // 3. offer로 구입할 수 없는 경우 값 리턴
    }
};
