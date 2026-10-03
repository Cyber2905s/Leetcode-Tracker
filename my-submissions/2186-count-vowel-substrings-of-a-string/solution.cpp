class Solution {
private:
    bool vowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
public:
    int countVowelSubstrings(string word) {
        unordered_map<char,int> lseen;
        int last = -1;
        int ans = 0;
        int n = word.size();
        for(int r=0;r<n;r++){
            if(vowel(word[r])){
                lseen[word[r]] = r;
                if(lseen.size()==5){
                    int mInd = min({lseen['a'],lseen['e'],lseen['i'],lseen['o'],lseen['u']});
                    if(mInd>last){
                        ans += mInd-last;
                    }
                }
            }
            else{
                last = r;
                lseen.clear();
            }
        }
        return ans;
    }
};
