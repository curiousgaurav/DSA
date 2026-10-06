class Solution {
public:
void dfs(int i,int j,vector<vector<int>>& grid,int n,int m){
    grid[i][j]=0;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    for(int k=0;k<4;k++){
        int x = dx[k] +i;
        int y = dy[k] + j;
        if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1){
            dfs(x,y,grid,n,m);
        }
    }

}
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if ((i == 0 || j == 0 || i==n-1 || j==m-1) && grid[i][j] == 1){
                    dfs(i,j,grid,n,m);
                }else{
                    continue;
                }
            }

        }
        int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    cnt++;
                }

            }
        }
        return cnt;


        
    }
};