class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        int l = 0;
        unordered_set<int> st;
        int ans = 1e9;
        for(int r=0;r<n;r++){
            while(st.find(cards[r])!=st.end()){
                if(cards[l]==cards[r]){
                    ans = min(ans,r-l+1);
                }
                st.erase(cards[l]);
                l++;
            }
            st.insert(cards[r]);
        }
        if(ans==1e9) return -1;
        return ans;
    }
};
