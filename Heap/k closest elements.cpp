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

/////////////////////////////////////////
vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        
          int rIndex = arr.size(),lIndex = -1; //we try to find the indices in which x can lie in O(log n )
        
        int low = 0,high = arr.size()-1;
        vector<int> ans;
        
        while(low <= high)
        {
            int mid = (low+high)/2;
            
            if(arr[mid] == x)
            {
                lIndex = mid-1;
                rIndex = mid+1;
                break;
            }
            else if(arr[mid] < x)
            {
                lIndex = max(mid,lIndex);
                low = mid+1;
            }
            else
            {
                rIndex = min(mid,rIndex);
                high = mid-1;
            }
        }
		
		int left = lIndex,right = rIndex; //two pointers used as maintained above
		
		while(left>=0 && right<n && k > 0)
		{
			if(arr[left] == x) //if element is same as X,discard it
			{
				--left;
				continue;
			}
			if(arr[right] == x) //if element is same as X,discard it
			{
				++right;
				continue;
			}
			
			int diff1 = x - arr[left];
			int diff2 = arr[right] - x;
			
			if(diff1 < diff2)
			{
				ans.push_back(arr[left]);
				--left;
			}
			else
			{
				ans.push_back(arr[right]);
				++right;
			}
			
			--k;
		}
		
		while(k>0 && left < 0) //if some k is left,and left part is empty,than include only right part
		{
			ans.push_back(arr[right]);
			++right;
			--k;
		}
		
		while(k>0 && right >=n) //if some k is left,and right part becomes empty,than only includes left part elements
		{
			ans.push_back(arr[left]);
			--left;
			--k;
		}
        
        return ans;
    }
