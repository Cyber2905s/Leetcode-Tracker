class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        for(int num: nums){
            st.insert(num);
        }
        for(int i=1;i<=n;i++){
            if(st.find(i*k)==st.end()){
                return i*k;
            }
        }
        return k*(n+1);
    }
};
