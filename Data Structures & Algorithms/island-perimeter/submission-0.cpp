class Solution {
public:
    int n;
    int m;
    int check(vector<vector<int>>& grid,int i,int j){
        int delrow[]={0,0,-1,1};
        int delcol[]={-1,1,0,0};
        int gg=0;
        for(int k=0;k<4;k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                if(grid[nrow][ncol]==1){
                    gg++;
                }
            }
        }
        return gg;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt=0;
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int res=check(grid,i,j);
                    cnt+=(4-res);
                }
            }
        }
        return cnt;
    }
};