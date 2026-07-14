//Disjoint set
class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unionbysize(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (size[px] < size[py]) {
            parent[px] = py;
            size[py] += size[px];
        } else {
            parent[py] = px;
            size[px] += size[py];
        }
    }
};
class Solution {
public:
//dfss 
    bool dfs(int node,vector<int> &vis,vector<vector<int>> &adj,vector<int> &parent){
        vis[node]=1;
        for(auto nb:adj[node]){
            if(!vis[nb]){
                parent[nb]=node;
                if(!dfs(nb,vis,adj,parent)) return false;
            }
            else if(nb!=parent[node]){
                return false;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        /*vector<vector<int>> adj(n);
        vector<int> parent(n,-1);
        vector<int> vis(n,0);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool ans=dfs(0,vis,adj,parent);
        for(int i = 0; i < n; i++){
            if(!vis[i]) return false;
        }
        return ans;*/
        if (edges.size() != n - 1) return false;
        DSU dsu(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            if(dsu.find(u)==dsu.find(v)){
                return false;
            }
            dsu.unionbysize(u,v);
        }
        return true;

        

    }
};
