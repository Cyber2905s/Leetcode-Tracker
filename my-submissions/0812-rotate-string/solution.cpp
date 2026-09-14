class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        string final = s+s;
        for(int i=0;i<s.size();i++){
            int j = i;
            int k = 0;
            while(k<s.size() && goal[k]==final[j]){
                k++;
                j++;
            }
            if(k==s.size()) return true;
        }
        return false;
    }
};
