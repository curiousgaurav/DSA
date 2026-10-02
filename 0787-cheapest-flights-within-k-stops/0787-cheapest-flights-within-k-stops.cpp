class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<list<pair<int, int>>> g(n);

        queue<tuple<int, int, int>> q;

        vector<int>dis(n,1e9);




        
        
       for (auto flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];

            g[from].push_back({to, price});
        }

        dis[src]=0;

        q.push({0,src,0});
        while(!q.empty()){
            auto[a,b,c] = q.front();
            q.pop();
            if(a>k){
                continue;
            }
            for(auto[d,f]:g[b]){
                int newcost = c+f;
                if(newcost<dis[d]){
                    dis[d]=newcost;
                    q.push({a+1,d,newcost});
                }
            }
        }


        

 if (dis[dst] == 1e9)
            return -1;

        return dis[dst];

        
    }
};