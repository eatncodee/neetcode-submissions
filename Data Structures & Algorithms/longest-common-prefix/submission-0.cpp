class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        int m=strs[0].size();
        for(int i=0;i<m;i++){
            char c=strs[0][i];
            bool found=false;
            for(int j=0;j<n;j++){
                string &tt=strs[j];
                if(i>=tt.size()){
                    found=true;
                    break;
                }
                if(tt[i]!=c){
                    found=true;
                    break;
                }
            }
            if(found) break;
            ans+=c;
        }
        return ans;
    }
};