class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>> result;
        map<int, vector<int>> mp;

        for(int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            int dist = x*x + y*y;

            mp[dist].push_back(i);
        }

        for(auto it : mp) {

            for(int index : it.second) {

                result.push_back(points[index]);

                if(result.size() == k)
                    return result;
            }
        }

        return result;
    }
};