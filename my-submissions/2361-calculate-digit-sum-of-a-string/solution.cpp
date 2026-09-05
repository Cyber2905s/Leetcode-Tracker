class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string ans= "";
            for(int i=0;i<s.size();i+=k){
                int sum = 0;
                for(int j=0;j<k && i+j<s.size();j++){
                    sum+=(s[i+j]-'0');
                }
                ans+=to_string(sum);
            }
            s = ans;
        }
        return s;
    }
};
