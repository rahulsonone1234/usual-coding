vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        
        int i=lower_bound(arr.begin(), arr.end(), x)-arr.begin();
        int l=i-1;
        int r=i;
        vector<int>ans;
        while(k--)
        {
            if(l<0 || (r<arr.size() && abs(arr[l]-x)>abs(arr[r]-x)))
            {
                r++;
            }
            else
            {
                l--;
            }
        }
        return vector<int>(arr.begin()+l+1, arr.begin()+r);
    }
    
    
    /////////////////////////////
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        code here
        priority_queue<pair<int, int>>pq;
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            pq.push({abs(arr[i]-x), i});
        }
        
        for(int i=k;i<n;i++)
        {
            int diff = abs(arr[i] - x);
 
            if (diff > pq.top().first)
                continue;
     
            pq.pop();
            pq.push({ diff, i });
        }
        while(!pq.empty())
        {
            ans.push_back(arr[pq.top().second]);
            pq.pop();
        }
        return ans;
        }
