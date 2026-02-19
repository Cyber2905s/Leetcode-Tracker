class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0;
        int cnt=0;
        int n= nums.size();
        while(r<n-1){
            int far;
            for(int i=l;i<=r;i++){
                far=max(i+nums[i],far);
            }
            l=r+1;
            r=far;
            cnt++;
        }
        return cnt;
    }
};
