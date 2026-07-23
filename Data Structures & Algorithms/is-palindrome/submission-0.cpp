class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(char &c:s){
            if(isalnum(c)){
                c=tolower(c);
                ans+=c;
            }
        }
        int n=ans.size();
        int i=0;
        int j=n-1;
        while(i<=j){
            if(ans[i]!=ans[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
};