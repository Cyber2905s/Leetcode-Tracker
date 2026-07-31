class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> res;
        vector<int> mp(26,-1);
        for(int i=0;i<n;i++){
            int j = s[i]-'a';
            mp[j]=i;
        }
        int i = 0;
        int size = 0;
        int end = 0;
        while(i<n){
            end = max(end,mp[s[i]-'a']);
            size++;
            if(i==end){
                res.push_back(size);
                size=0;
            }
            i++;
        }
        return res;
    }
};
