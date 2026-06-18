class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }
        vector<int> s1count(26,0);
        vector<int> s2count(26,0);
        for(int i=0;i<s1.length();i++){
            s1count[s1[i]-'a']++;
            s2count[s2[i]-'a']++;
        }
        int matches=0;
        for(int i=0;i<26;i++){
            if(s1count[i]==s2count[i]){
                matches++;
            }
        }
        int l=0;
        for(int r=s1.length();r<s2.length();r++){
            if(matches==26){
                return true;
            }
            int index=s2[r]-'a';
            s2count[index]++;
            if(s2count[index]==s1count[index]){
                matches++;
            }
            else if(s1count[index]+1==s2count[index]){
                matches--;
            }
            index=s2[l]-'a';
            s2count[index]--;
            if(s2count[index]==s1count[index]){
                matches++;
            }
            else if(s1count[index]-1==s2count[index]){
                matches--;
            }
            l++;
        }
        return matches==26;
    }
};
