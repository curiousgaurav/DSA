class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void dfs(int i, int j, vector<vector<int>>& image,
             int originalColor, int color) {

        image[i][j] = color;

        for (int k = 0; k < 4; k++) {

            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && y >= 0 &&
                x < image.size() && y < image[0].size() &&
                image[x][y] == originalColor) {

                dfs(x, y, image, originalColor, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr, int sc, int color) {

        int originalColor = image[sr][sc];

        // Already the required color
        if (originalColor == color)
            return image;

        dfs(sr, sc, image, originalColor, color);

        return image;
    }
};