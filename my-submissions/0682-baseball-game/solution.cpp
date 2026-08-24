class Solution {
public:
    int calPoints(vector<string>& op) {
        vector<int> nums;
        int n = op.size();
        for(int i=0;i<n;i++){
            if(op[i]=="+"){
                int m = nums.size();
                nums.push_back((int)(nums[m-1]+nums[m-2]));
            }
            else if(op[i]=="D"){
                nums.push_back(2*(int)nums.back());
            }
            else if(op[i]=="C"){
                nums.pop_back();
            }
            else{
                nums.push_back(stoi(op[i]));
            }
        }
        int sum = 0;
        for(auto num: nums){
            sum+=num;
        }
        return sum;
    }
};
