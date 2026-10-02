class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int l = 0;
        int r = k-1;
        int cnt = 0;
        int mini = 1e9;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W') cnt++;
        }
        mini = cnt;
        for(int i=k;i<n;i++){
            if(blocks[l]=='W') cnt--;
            l++;
            r++;
            if(blocks[r]=='W') cnt++;
            mini = min(mini,cnt);
        }
        return mini;
    }
};
