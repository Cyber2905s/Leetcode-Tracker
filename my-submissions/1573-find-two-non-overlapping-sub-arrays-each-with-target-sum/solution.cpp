class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> pre(n,1e9);
        int l = 0;
        int csum = 0;
        int mini = 1e9;
        int best = 1e9;
        for(int r=0;r<n;r++){
            csum+=arr[r];
            while(csum>target){
                csum-=arr[l];
                l++;
            }
            if(csum == target){
                int clen = r-l+1;
                if(l>0 && pre[l-1]!=1e9){
                    mini = min(mini,clen+pre[l-1]);
                }
                best = min(best,clen);
            }
            pre[r] = best;
        }
        if(mini==1e9) return -1;
        return mini;
    }
};
