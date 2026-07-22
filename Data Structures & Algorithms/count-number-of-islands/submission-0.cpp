class Solution {
public:
    int n;
    int m;
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    void dfs(int i,int j,vector<vector<char>>& grid, vector<vector<int>> &vis){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                dfs(nrow,ncol,grid,vis);
            }            
        }
    }
    void bfs(int i,int j,vector<vector<char>>& grid, vector<vector<int>> &vis){
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto &temp=q.front();
            int r=temp.first;
            int c=temp.second;
            q.pop();
            for(int k=0;k<4;k++){
                int nrow=r+delrow[k];
                int ncol=c+delcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }            
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};