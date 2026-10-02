class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return {};
        vector<int> cp;
        cp = arr;
        sort(cp.begin(),cp.end());
        unordered_map<int,int> mp;
        int unq = 1;
        mp[cp[0]] = unq;
        for(int i=1;i<n;i++){
            if(cp[i]==cp[i-1]){
                continue;
            }
            else{
                unq++;
                mp[cp[i]] = unq;
            }
        }
        for(int i=0;i<n;i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};
