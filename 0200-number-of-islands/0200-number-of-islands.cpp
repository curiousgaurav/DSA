class Solution {
public:
vector<vector<int>> vis;
       void dfs(int i,int j,vector<vector<char>>& grid,int n,int m){
        
        vis[i][j]=1;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        for(int k=0;k<4;k++){
            int x = dx[k]+i;
            int y=dy[k]+j;
            if(x>=0 && y>=0 &&x<n && y<m && grid[x][y]=='1'){
                if(!vis[x][y]){
                dfs(x,y,grid,n,m);
                }
            }
        }
       }
      
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
         vis.resize(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i,j,grid,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};