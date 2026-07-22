class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        int inf=2147483647;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    pq.push({0,{i,j}});
                }
            }
        }
        while(!pq.empty()){
            auto t=pq.top();
            int d=t.first;
            int r=t.second.first;
            int c=t.second.second;
            pq.pop();
            if(d>grid[r][c]) continue;
            int delrow[]={0,0,-1,1};
            int delcol[]={-1,1,0,0};
            for(int k=0;k<4;k++){
                int nrow=r+delrow[k];
                int ncol=c+delcol[k];
                if(nrow>=0 && ncol>=0 && ncol<m && nrow<n && grid[nrow][ncol]==inf){
                    grid[nrow][ncol]=d+1;
                    pq.push({d+1,{nrow,ncol}});
                }
            }
        }

    }
};
