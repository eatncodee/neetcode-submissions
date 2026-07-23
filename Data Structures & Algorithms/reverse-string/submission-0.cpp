class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int l=0;int r=n-1;
        while(l<=r){
            char t=s[l];
            char t2=s[r];
            s[l]=t2;
            s[r]=t;
            l++;r--;
        }
        
    }
};