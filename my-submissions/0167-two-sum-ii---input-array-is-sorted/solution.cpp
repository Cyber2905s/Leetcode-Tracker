class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1;
        while(l<r){
            int curr=numbers[l]+numbers[r];
            if(curr>target){
                r--;
            }
            else if(curr<target){
                l++;
            }
            else{
                return{l+1,r+1};
            }
        }
        return {};
    }
};
