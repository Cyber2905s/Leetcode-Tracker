class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(auto it: queries){
            for(auto it1: dictionary){
                int edits=0;
                for(int i=0;i<it1.size();i++){
                    if(it[i]!=it1[i]){
                        edits++;
                    }
                    if(edits>2) break;
                }
                if(edits<=2){
                    ans.push_back(it);
                    break;
                }
            }
        }
        return ans;
    }
};
