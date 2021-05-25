//TWO SUM use map if n present find sum-n
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int, int>mp;
        
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};

//Robot bounded by circle // either we are not at north and x and y is 0 then there is circle
class Solution {
public:
    bool isRobotBounded(string s) {
      int x=0,y=0,i=0;
        // x and y are the co-ordinates and i=0 is the current direction which is North.
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}}; // N,E,S,W
        // dir vector is a 2d vector which stoes all directions Cordinates 
        
        int n=s.length();
        for(int j=0;j<n;j++) {
            switch(s[j]) {
                case 'G':  // Go 1 unit forward
                    x+=dir[i][0]; // pick the x part in whichever direction our robot is ponting
                    y+=dir[i][1]; // pick the y part in whichever direction our robot is ponting
                    break;
                case 'L': // If we have to turn left
                    i=(i+3)%4; //left is West, which is 3 units in clockwise direction, so just turn left from your current facing position which is my current i value and we did %4 because we are moving in those direction given in the input array infinitely, so %4 basically gives you the correct index between 0 and last index.
                    break;
                case 'R':
                    i=(i+1)%4; //Right is east, which is 1 units in clockwise direction, so just turn right from your current facing position which is my current i value
                    break;
            }
        }
        
        if((x==0 && y==0) || i != 0) return true; // either we returned to origin OR we are not facing North, which was 0
        return false;
        
    }
};

//LRU Cache
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

class LRUCache {
    list<pair<int, int>>cache;// begin of list MRU and end will be having LRU
    unordered_map<int, list<pair<int, int>>::iterator>mp;// map will store the value and index/address of the pages in the cache
    void refresh(int key, int value)    //refresh keeps updated remove it from current place and put it to the end so that it is Most recently used one
    {
        cache.erase(mp[key]);
        cache.push_front({key, value});
        mp[key]=cache.begin();
    }
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
           refresh(key,(*mp[key]).second);
            return (*mp[key]).second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            refresh(key, value);
        }
        else
        {
            cache.push_front({key, value});
            mp[key]=cache.begin();
            if(mp.size()>capacity)
            {
                mp.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//Number of Islands
class Solution {
public:
    void dfs(vector<vector<char>>&grid, int i, int j, int rows, int cols)
    {
        if(i<0 || j<0 || i>= rows || j>=cols || grid[i][j]!='1')
            return ;
        
        grid[i][j]='2';
        
        dfs(grid, i+1, j, rows, cols);
        dfs(grid, i, j+1, rows, cols);
        dfs(grid, i-1, j, rows, cols);
        dfs(grid, i, j-1, rows, cols);
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        if(rows==0) return 0;
        int cols=grid[0].size();
        
        int numberofislands=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
                
                
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid, i, j, rows, cols);
                    numberofislands++;
                }
            }
        }
        return numberofislands;
    }
};



//Merge Intervals
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
    
    
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergedIntervals;
        if(intervals.size()==0){
            return mergedIntervals;
        }

        sort(intervals.begin(), intervals.end());
        vector<int>tempInterval=intervals[0];

        for(auto it:intervals){
            if(it[0]<=tempInterval[1]){
                tempInterval[1]=max(it[1], tempInterval[1]);
            }
            else{
                mergedIntervals.push_back(tempInterval);
                tempInterval=it;
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
};


//Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
       int size=height.size();
        int low=0;
        int high=size-1;
        int lmax=0;
        int rmax=0;
        
        int res=0;
        while(low<=high)
        {
            if(height[low]<height[high])
            {
                if(height[low]>lmax)
                    lmax=height[low];
                else
                    res+=lmax-height[low];
                
                low++;
            }
            else
            {
                if(height[high]>rmax)
                    rmax=height[high];
                else
                    res+=rmax-height[high];
                
                high--;
            }
        }
        return res;
    }
};

// K closest point to origin

class Solution {
public:
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
};


//Meeting Rooms 2 same as min number of platform gfg
 int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	 sort(arr, arr+n); 
    	sort(dep, dep+n); 
    	
    	int plat_needed = 1, result = 1; 
        int i = 1, j = 0; 
     
        while (i < n && j < n) { 
            if (arr[i] <= dep[j]) { 
                plat_needed++; 
                i++; 
            } 
      
            else if (arr[i] > dep[j]) { 
                plat_needed--; 
                j++; 
            } 
     
            if (plat_needed > result) 
                result = plat_needed; 
        } 
      
        return result;
    }




// Find Median in datastream
class MedianFinder {
public:
    /** initialize your data structure here. */
     priority_queue<int> maxheap; //1st half (left half)
    priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int lsize = maxheap.size();
        int rsize = minheap.size();
        if(lsize==0)    //num is the 1st element in stream
            maxheap.push(num);
        else if(lsize==rsize)   //Push one element in maxheap for sure
        {
            if(num<minheap.top())   //num can be pushed to maxheap (1st half) to maintain order
                maxheap.push(num);
            else    //Push root of minheap to maxheap (Push num to 2nd half)
            {
                int temp = minheap.top();   //Save root of minheap
                minheap.pop();  //Pop the root from minheap
                minheap.push(num);  //Push num in minheap
                maxheap.push(temp); //Push the previous saved root of minheap in the maxheap
            }
        }
        else    ///We assume that maxheap can be larger than minheap by a max of 1 element only
        {
            if(minheap.size()==0)
            {
                if(num>maxheap.top()) //Push num to 2nd half
                    minheap.push(num);
                else //Push num to 1st half
                {
                    int temp = maxheap.top();
                    maxheap.pop();
                    maxheap.push(num);
                    minheap.push(temp);
                }
            }
            else if(num>=minheap.top()) //Push the element directly in minheap (2nd half)
                minheap.push(num);
            else    //Push root of maxheap to minheap
            {
                if(num<maxheap.top())   //Push num to 1st half
                {
                    int temp = maxheap.top();   //Save root of maxheap
                    maxheap.pop();  //Pop root of maxheap
                    maxheap.push(num);  //Push num to maxheap
                    minheap.push(temp); //Push previous saved root of maxheap to minheap
                }
                else    //Push num to 2nd half
                    minheap.push(num);
            }
        }
        
    }
    
    double findMedian() {
         int lsize = maxheap.size();
        int rsize = minheap.size();
        if(lsize > rsize)  //Return top of maxheap for odd no of elements
            return double(maxheap.top());
        else    //Else return avg of top of maxheap and minheap
            return (double(maxheap.top())+double(minheap.top()))/2;

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


// Min difficulty of job schedule
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        const int n = jobDifficulty.size();

    if (n < d)
      return -1;

    // dp[i][k] := min difficulty to schedule the first i jobs in k days
    vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX / 2));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i)
      for (int k = 1; k <= d; ++k) {
        int maxDifficulty = 0;                  // max(job[j + 1..i])
        for (int j = i - 1; j >= k - 1; --j) {  // 1-based
          maxDifficulty = max(maxDifficulty, jobDifficulty[j]);  // 0-based
          dp[i][k] = min(dp[i][k], dp[j][k - 1] + maxDifficulty);
        }
      }

    return dp[n][d];
    }
};


//Insert Delete Remove in O(1)
//use map and vector
https://leetcode.com/problems/insert-delete-getrandom-o1/discuss/684531/Vector-%2B-hashmap-c%2B%2B-easy-understanding-o(1)-with-picture-explanation
class RandomizedSet {
   
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(0));  
    }
     vector<int>v;
    unordered_map<int, int>m;
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
       if(m.find(val) == m.end()){
            v.emplace_back(val);
            int n = v.size();
            m[val] = n-1;
            return true;
        } 
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
       if(m.find(val) == m.end()){
            return false;
        }
        m[v.back()] = m[val];
        v[m[val]] = v.back();
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
     int r = rand() % v.size();
        return v[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
     
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int max1=horizontalCuts[0];
        int max2=verticalCuts[0];
        for(int i=0;i<horizontalCuts.size()-1;i++)
        {
            max1=max(max1, horizontalCuts[i+1]-horizontalCuts[i]);
        }
        for(int i=0;i<verticalCuts.size()-1;i++)
        {
            max2=max(max2, verticalCuts[i+1]-verticalCuts[i]);
        }
        return ((long long)(max1) * max2) % 1000000007;
    }
};


//Integer to english Word
class Solution {
public:
     string digits[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string int2string(int n) {
        if (n >= 1000000000) {
            return int2string(n / 1000000000) + " Billion" + int2string(n % 1000000000);
        } else if (n >= 1000000) {
            return int2string(n / 1000000) + " Million" + int2string(n % 1000000);
        } else if (n >= 1000) {
            return int2string(n / 1000) + " Thousand" + int2string(n % 1000);
        } else if (n >= 100) {
            return int2string(n / 100) + " Hundred" + int2string(n % 100);
        } else if (n >= 20) {
            return  " " + tens[n / 10] + int2string(n % 10);
        } else if (n >= 1) {
            return " " + digits[n];
        } else {
            return "";
        }
    }

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        } else {
            string ret = int2string(num);
            return ret.substr(1, ret.length() - 1);
        }
    }
};


//Word Ladder
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
    
    BFS

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> myset;
        bool isPresent = false; //Checks if endWord is present in Dict
        //Insert all words from Dict in myset
        for(auto word: wordList)
        {
            myset.insert(word);    //Insert word in Dict
        }
       if(myset.find(endWord)!=myset.end())
        isPresent=true;
        if(isPresent==false)    //endWord is not present in Dict
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        
        while(!q.empty())
        {
            depth+=1;
            int lsize = q.size();   //No of elements at a level
            while(lsize--)
            {
                string curr = q.front();
                q.pop();
                //check for all possible 1 depth words
                for(int i=0;i<curr.length();++i)  //For each index
                {
                    string temp = curr;
                    for(char c='a';c<='z';++c)  //Try all possible chars
                    {
                        temp[i] = c;
                        if(curr.compare(temp)==0)
                            continue;   //Skip the same word
                        if(temp.compare(endWord)==0)
                            return depth+1; //endWord found
                        if(myset.find(temp)!=myset.end())
                        {
                            q.push(temp);
                            myset.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};

//Merge K Sorted Lists
//take all the elements put it into the vector and sort
//or compare one element of linked list with all n-1 and then compare and accordingly arrange the list
//store the first element of linked list in the min heap and then remove one by one each element and check if next to it exist if exist then put it in the min heap thenheapify and then agin remove and so on  O(nLogk)
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct compare{
        
        bool operator()(const ListNode *l1, const ListNode *l2){
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue< ListNode* , vector<ListNode*>, compare>pq;
        
        for(auto l : lists)
        {
            if(l)
            {
                pq.push(l);
            }
        }
        
        ListNode pre(0);
        ListNode *node=&pre;
        
        
        while(!pq.empty())
        {
            ListNode *top=pq.top();
            pq.pop();
            node->next=top;
            node=node->next;
            
            if(top->next)
                pq.push(top->next);
        }
        return pre.next;
    }
};

//

