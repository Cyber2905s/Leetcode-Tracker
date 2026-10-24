class Solution {
public:
    int peakValleyDifference(vector<int>& n) {
        int p = 0;
        int v =0;
        int sz = n.size();
        for(int i=1;i<sz-1;++i){
            if(n[i]>n[i-1] && n[i]>n[i+1]) p+=n[i];
            else if(n[i]<n[i-1] && n[i]<n[i+1]) v+=n[i];
        }
        return p-v;
    }
};
