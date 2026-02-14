class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum =0;
        int rsum=0;
        int msum;
        int ind = cardPoints.size()-1;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        msum=lsum;
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[ind];
            ind--;
            msum=max(msum,lsum+rsum); 
        }
        return msum;
    }
};
