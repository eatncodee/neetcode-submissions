class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }
            }
        }
        int ans=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            auto &temp=q.front();
            int d=temp.first;
            int r=temp.second.first;
            int c=temp.second.second;
            q.pop();
            ans=max(ans,d);
            for(int k=0;k<4;k++){
                int nrow=r+delrow[k];
                int ncol=c+delcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                    q.push({d+1,{nrow,ncol}});
                    grid[nrow][ncol]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};