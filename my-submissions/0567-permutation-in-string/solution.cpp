class Solution {
public:
    bool checkequal(int a[26], int b[26]){
        for (int i=0;i<26;i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int count1[26]={0};
        for(int i=0;i<s1.length();i++){
            int index = s1[i]-'a';
            count1[index]++;
        }
        int i=0;
        int ws = s1.length();
        int count2[26]={0};
        while(i<ws && i<s2.length()){
            int index= s2[i]-'a';
            count2[index]++;
            i++;
        }
        if(checkequal(count1,count2)){
            return 1;
        }
        while(i<s2.length()){
            char newc =s2[i];
            int index = newc-'a';
            count2[index]++;
            char oldc = s2[i-ws];
            int index1 = oldc - 'a';
            count2[index1]--;
            i++;
            if(checkequal(count1,count2)){
            return 1;
            }
        }
        return 0;
    }
};
