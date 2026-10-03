class Solution {
private:
    bool vowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    long long atLeastK(string& word, int k){
        unordered_map<char,int> fq;
        int n = word.size();
        int l = 0;
        int r = 0;
        int Ccnt = 0;
        long long ans = 0;
        while(r<n){
            if(vowel(word[r])){
                fq[word[r]]++;
            }
            else{
                Ccnt++;
            }
            while(fq.size()==5 && Ccnt>=k){
                ans += (n-r);
                if(vowel(word[l])){
                    fq[word[l]]--;
                    if(fq[word[l]]==0){
                        fq.erase(word[l]);
                    }
                }
                else{
                    Ccnt--;
                }
                l++;
            }
            r++;
        }
        return ans;
    }
public:
    long long countOfSubstrings(string word, int k) {
        return atLeastK(word,k)-atLeastK(word,k+1);
    }
};
