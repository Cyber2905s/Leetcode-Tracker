class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int freq[1001] = {0};
        for(int num:nums1){
            freq[num]++;
        }
        vector<int> ans;
        for(int num: nums2){
            if(freq[num]>0){
                ans.push_back(num);
                freq[num]--;
            }
        }
        return ans;
    }
};
