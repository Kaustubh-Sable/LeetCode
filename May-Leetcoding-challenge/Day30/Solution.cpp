class Solution {
public:
    float getDistFromOrigin(vector<int> coordinates)
    {
        return sqrt(coordinates[0]*coordinates[0] + coordinates[1]*coordinates[1]);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<float, vector<int>>> pq;
        float dist;
        
        for(int i=0;i<points.size();++i)
        {
            dist = getDistFromOrigin(points[i]);
            if(pq.size()<K)
            {
                pq.push(make_pair(dist, points[i]));
            }
            else
            {
                if(dist<pq.top().first)
                {
                    pq.pop();
                    pq.push(make_pair(dist, points[i]));
                }
            }
        }
        
        vector<vector<int>> ans;
        while (!pq.empty()) 
        { 
            ans.push_back(pq.top().second);
            pq.pop(); 
        }
        
        return ans;
    }
};
