class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int> answer;
        int a=0,b=0;
        int s=nums.size();
        for(int i=0;i<s;i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }
            else if(nums[i]<0){
                neg.push_back(nums[i]);
            }
        }
        for(int i=0;i<s;i++){
            if(i%2==0){
                answer.push_back(pos[a]);
                a++;
            }
            else{
                answer.push_back(neg[b]);
                b++;
            }
        }
        return answer;

    }
};
