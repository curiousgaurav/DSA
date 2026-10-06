class Solution {
public:
void dfs(int i,int j,vector<vector<int>>& image,int oc,int color,int n,int m){
    image[i][j]=color;
    int dx[4] = {0,0,1,-1};
    int dy[4]= {1,-1,0,0};
    for(int k=0;k<4;k++){
        int x = dx[k]+i;
        int y = dy[k]+j;
        if(x>=0 && y>=0 && x<n && y<m && image[x][y]==oc){
            dfs(x,y,image,oc,color,n,m);

        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int oc = image[sr][sc];
        if(oc==color){
            return image;
        }
        dfs(sr,sc,image,oc,color,n,m);
        return image;
        
    }
};