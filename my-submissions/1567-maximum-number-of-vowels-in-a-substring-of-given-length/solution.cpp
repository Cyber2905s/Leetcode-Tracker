class Solution {
private:
    bool poss(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            return true;
        }
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int curr = 0;
        for(int i=0;i<k;i++){
            if(poss(s[i])) curr++;
        }
        int maxi = curr;
        if(maxi == k) return maxi;
        for(int i=k;i<n;i++){
            if(poss(s[i])) curr++;
            if(poss(s[i-k])) curr--;
            maxi = max(maxi,curr);
        }
        return maxi;
    }
};
