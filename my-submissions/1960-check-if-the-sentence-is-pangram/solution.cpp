class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.size()<26) return false;
        vector<bool> map(26,0);
        for(int i=0;i<sentence.size();i++){
            if(map[sentence[i]-'a']==false){
                map[sentence[i]-'a'] = true;
            }
            else{
                continue;
            }
        }
        for(int i=0;i<26;i++){
            if(map[i]==false) return false;
        }
        return true;
    }
};
