class Solution {
private:
    int helper(string s, int start, int end, int k){
        if(end-start<k) return 0;
        int count[26] = {0};
        for(int i=start;i<end;i++){
            count[s[i]-'a']++;
        }
        for(int mid=start;mid<end;mid++){
            if(count[s[mid]-'a']<k){
                int nstart = mid+1;
                while(nstart<end && count[s[nstart]-'a']<k){
                    nstart++;
                }
                return max(helper(s,start,mid,k),helper(s,nstart,end,k));
            }
        }
        return end-start;
    }
public:
    int longestSubstring(string s, int k) {
        return helper(s,0,s.size(),k);
    }
};
