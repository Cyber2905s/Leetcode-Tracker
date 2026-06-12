class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> Num(nums.begin(),nums.end());
        int longest=0;
        for(int num: Num){
            if(Num.find(num-1)==Num.end()){
                int len=1;
                while(Num.find(num+len)!=Num.end()){
                    len++;
                }
                longest=max(len,longest);
            }
        }
        return longest;
    }
};
