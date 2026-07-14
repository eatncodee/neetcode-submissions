class Solution {
public:
    void dfs(int node,vector<int> &vis,vector<vector<int>> & adj){
        vis[node]=1;

        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int cnt=0;
        vector<vector<int>> adj(n);
        for(auto i:edges){
            int u=i[0];
            int v=i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
                if(!vis[i]){
                    cnt++;
                    dfs(i,vis,adj);
                }
        }
        return cnt;
    }
};
