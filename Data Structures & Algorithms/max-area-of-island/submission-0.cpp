class Solution {
public:
int n;
int m;
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>>& grid,int &cnt){
        vis[row][col]=1;
        cnt++;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        for(int k=0;k<4;k++){
            int nrow=row+delrow[k];
            int ncol=col+delcol[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfs(nrow,ncol,vis,grid,cnt);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> vis(n,(vector<int>(m,0)));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int cnt=0;
                    dfs(i,j,vis,grid,cnt);
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};