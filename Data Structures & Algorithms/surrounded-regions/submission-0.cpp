class Solution {
public:
int n;
int m;
    void solve(int r,int c,vector<vector<char>>& board,vector<vector<int>> &vis){
        vis[r][c]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nrow=r+delrow[k];
            int ncol=c+delcol[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
                solve(nrow,ncol,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j] && (i==0 || j==0 ||i==n-1 || j==m-1)){
                    vis[i][j]=1;
                    solve(i,j,board,vis);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
        
    }
};