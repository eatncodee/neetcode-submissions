class Solution {
public:
    int n;
    int m;
    void solve(vector<vector<int>>& heights,vector<vector<int>>& vis,queue<pair<int,int>> &q){
        while(!q.empty()){
            auto t=q.front();
            int r=t.first;
            int c=t.second;
            q.pop();
            int delrow[]={0,0,-1,1};
            int delcol[]={-1,1,0,0};
            for(int k=0;k<4;k++){
                int nrow=r+delrow[k];
                int ncol=c+delcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && heights[nrow][ncol]>=heights[r][c] && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<int>> visp(n,vector<int>(m,0));
        vector<vector<int>> visa(n,vector<int>(m,0));
        queue<pair<int,int>> qp;
        queue<pair<int,int>> qa;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    visp[i][j]=1;
                    qp.push({i,j});
                }
                if(j==m-1 || i==n-1){
                    visa[i][j]=1;
                    qa.push({i,j});
                }
            }
        }
        vector<vector<int>> ans;
        solve(heights,visp,qp);
        solve(heights,visa,qa);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visa[i][j] && visp[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

    }
};