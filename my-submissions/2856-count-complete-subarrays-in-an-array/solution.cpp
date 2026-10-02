class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int unq = 0;
        int n = nums.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            if(st.find(nums[i])==st.end()){
                unq++;
                st.insert(nums[i]);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int cnt = 0;
            unordered_set<int> st1;
            for(int j=i;j<n;j++){
                if(st1.find(nums[j])==st1.end()){
                    cnt++;
                    st1.insert(nums[j]);
                }
                if(cnt==unq) ans++;
            }
        }
        return ans;
    }
};
