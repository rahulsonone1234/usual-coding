vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
         auto comp=[](const pair<int, int>p1, const pair<int, int>p2){
             return p1.first*p1.first + p1.second*p1.second < p2.first*p2.first + p2.second*p2.second;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)>pq(comp);
        for(int i=0;i<points.size();i++)
        {
            pq.push({points[i][0], points[i][1]});
             
            if(pq.size()>K)
            {
                pq.pop();
            }
        }
        
       
        
        vector<vector<int>>ans;
        while(!pq.empty())
        {
            ans.push_back(vector<int>{pq.top().first, pq.top().second});
            pq.pop();
        }
        return ans;
    }
