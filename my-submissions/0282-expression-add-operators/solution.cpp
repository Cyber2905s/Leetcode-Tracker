class Solution {
private:
    void solve(int ind, const string& num, int target, long long currEval,long long prevNum, string& path, vector<string>& ans) {
        if(ind==num.size()){
            if(currEval == target){
                ans.push_back(path);
            }
            return;
        }
        long long currNum = 0;
        int ogLen = path.size();
        for(int i=ind;i<num.size();i++){
            if(i>ind && num[ind]=='0') break;
            currNum = currNum*10 + (num[i]-'0');
            if(ind==0){
                path+=to_string(currNum);
                solve(i+1,num,target,currNum,currNum,path,ans);
                path.resize(ogLen);
            }
            else{
                path += '+'+to_string(currNum);
                solve(i+1,num,target,currEval+currNum,currNum,path,ans);
                path.resize(ogLen);

                path += '-'+to_string(currNum);
                solve(i+1,num,target,currEval-currNum,-currNum,path,ans);
                path.resize(ogLen);

                path += '*'+to_string(currNum);
                solve(i+1,num,target,currEval-prevNum+(prevNum*currNum),prevNum*currNum,path,ans);
                path.resize(ogLen);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string path = "";
        solve(0,num,target,0,0,path,ans);
        return ans;
    }
};
