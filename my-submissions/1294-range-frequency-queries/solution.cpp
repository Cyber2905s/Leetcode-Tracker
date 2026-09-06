class RangeFreqQuery {
private:
    unordered_map<int,vector<int>> mp;
public:
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        auto it = mp.find(value);
        if(it==mp.end()){
            return 0;
        }
        const vector<int>& ind = it->second;
        int l = 0;
        int r = ind.size()-1;
        int fo = -1;
        int lo = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(ind[mid]>=left){
                fo = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        l = 0;
        r = ind.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(ind[mid]<=right){
                lo = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        if (fo == -1 || lo == -1 || fo > lo){
            return 0;
        }
        return lo-fo+1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
