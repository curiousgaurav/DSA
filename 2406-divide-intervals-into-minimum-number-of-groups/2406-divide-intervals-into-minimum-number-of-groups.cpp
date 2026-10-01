class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto interval : intervals) {
            
            int start = interval[0];
            int end = interval[1];

            // If the earliest ending interval finishes
            // before this one starts, reuse that group
            if (!pq.empty() && pq.top() < start) {
                pq.pop();
            }

            // Put current interval into a group
            pq.push(end);
        }

        return pq.size();
    }
};