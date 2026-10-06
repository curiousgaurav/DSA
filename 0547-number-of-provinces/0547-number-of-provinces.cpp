class Solution {
public:
vector<int>vis;
vector<vector<int>>g;


// void dfs(int src){
//     vis[src]=1;
//     for(auto a:g[src]){
//         if(!vis[a]){
//             dfs(a);
//         }
//     }
// }

void bfs(int src){
    queue<int>q;
    vis[src]=1;
    q.push(src);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto v:g[cur]){
            if(!vis[v]){
                bfs(v);
            }else{
                continue;
            }
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        vis.resize(n, 0);
        g.resize(n);
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    g[i].push_back(j);

                }
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i);
                cnt++;
            }
        }
        return cnt;
        
        
    }
};