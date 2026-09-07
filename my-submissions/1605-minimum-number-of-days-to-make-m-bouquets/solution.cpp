class Solution {
private:
    bool poss(vector<int>& arr,int day,int m,int k){
        int n = arr.size();
        int cnt = 0;
        int bq = 0;
        for(int i=0;i<n;i++){
            if(arr[i]<=day){
                cnt++;
                if(cnt==k){
                    bq++;
                    cnt = 0;
                }
            }
            else cnt = 0;
        }
        return bq>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long total = (long long)m*k;
        if(total>n) return -1;
        int l = *min_element(bloomDay.begin(),bloomDay.end());
        int r = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(poss(bloomDay,mid,m,k)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
