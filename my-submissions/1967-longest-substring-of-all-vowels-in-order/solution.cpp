class Solution {
private:
    bool vowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        unordered_map<char,int> fq;
        int l = 0;
        int r = 0;
        int maxi = 0;
        while(r<n){
            if(r>0 && word[r]<word[r-1]){
                fq.clear();
                l = r;
            }
            if(vowel(word[r])){
                fq[word[r]]++;
            }
            if(fq.size()== 5){
                maxi = max(maxi,r-l+1);
            }
            r++;
        }
        return maxi;
    }
};
