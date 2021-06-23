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
        if(maxheap.size()==minheap.size())
        {
            if(maxheap.size()==0)
            {
                maxheap.push(num);
            }
            else if(num<maxheap.top())
            {
                maxheap.push(num);
            }
            else
            {
                minheap.push(num);
            }
        }
        else
        {
            if(maxheap.size() > minheap.size())
            {
                if(num >=maxheap.top())
                {
                    minheap.push(num);
                }
                else
                {
                    int tmp=maxheap.top();
                    maxheap.pop();
                    minheap.push(tmp);
                    maxheap.push(num);
                }
            }
            else
            {
                if(num <=minheap.top())
                {
                    maxheap.push(num);
                }
                else
                {
                    int tmp=minheap.top();
                    minheap.pop();
                    maxheap.push(tmp);
                    minheap.push(num);
                }
            }
        }
        
    }
    
    double findMedian() {
        if(minheap.size()==maxheap.size())
        {
            return (minheap.top()+maxheap.top())/2.0;
        }
        else if(maxheap.size()>minheap.size())
        {
            return maxheap.top();
        }
        else 
        {
            return minheap.top();
        }

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

    for (int i = 1; i <= n; ++i)   //iterate till number of job i.e. the array
      for (int k = 1; k <= d; ++k) //iterate till number of allowed days
      { 
        int maxDifficulty = 0;                                   // max(job[j + 1..i])
        for (int j = i - 1; j >= k - 1; --j)
        {                                                        // 1-based
          maxDifficulty = max(maxDifficulty, jobDifficulty[j]);  // find max difficulty of the day 
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
// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
    
//     BFS

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

//LFU cache
class LFUCache {
public:
    unordered_map<int, list<int>> freq_keyslist;
    unordered_map<int, vector<int>> key_value_freq;
    unordered_map<int, list<int>::iterator> key_iterator;
    int min_freq;
    int size;
    int c;
    
    LFUCache(int capacity) {
        c = capacity;
        size = 0;
        min_freq = 0;
        
    }
    
    int get(int key) {
        if(!key_value_freq.count(key)) return -1;
        
        int value = key_value_freq[key][0];
        int freq = key_value_freq[key][1];
        freq_keyslist[freq].erase(key_iterator[key]);
        
        freq_keyslist[freq+1].push_back(key);
        key_value_freq[key][1]++;
        key_iterator[key] = --freq_keyslist[freq+1].end();
        
        if(!freq_keyslist[min_freq].size()) min_freq++;
        
        return value;
    }
    
    void put(int key, int value) {
        if(c<=0) return;
        
        if(get(key) != -1){
            key_value_freq[key][0] = value;
            return;
        }
        
        if(size==c){
            //remove the element from cache with min freq
            int key_to_remove = freq_keyslist[min_freq].front();
            freq_keyslist[min_freq].pop_front();
            key_value_freq.erase(key_to_remove);
            key_iterator.erase(key_to_remove);
        }
        
        key_value_freq[key] = {value, 1};
        freq_keyslist[1].push_back(key);
        key_iterator[key] = --freq_keyslist[1].end();
        min_freq=1;
        if(size < c) size++;
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//Pairs of Songs With Total Durations Divisible by 60
//(a+b)%c 
//(a%c + b%c)%c
//so a%c would be ranging from 0 to c
//and b%c would be ranging from 0 to c
//so adding both will be ranging from 0 to c R1 + R2 <=2c 
//so put in vec or map and find pair;
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
          vector<int>rem(60);
        
        int count=0;
        for(int t:time)
        {
            if(t%60==0){
                count+=rem[0];
            }
            else
            {
                count+=rem[60-t%60];
            }
            rem[t%60]++;
        }
        return count;
        
        
    }
};

//Maximal Square // dp /// solve over the corners and store the min of all +1
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        if(rows==0) return 0;
        
        int cols=matrix[0].size();
        
        vector<vector<int>>dp(rows+1, vector<int>(cols+1, 0));
        int largest=0;
        for(int i=1;i<=rows;i++)
        {
            for(int j=1;j<=cols;j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
                   dp[i][j]=1+min( dp[i-1][j-1],min( dp[i-1][j], dp[i][j-1]));
                                 
                    if(dp[i][j]>largest)
                    largest=dp[i][j];
                }
            }
        }
                                 
        return largest*largest;
        
    }
};
//Word Break
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
    //try all the prefix combination and for every prefix check the corressponding suffix and if both exist then return true else false
    // A recursive program to test whether a given
// string can be segmented into space separated
// words in dictionary
#include <iostream>
using namespace std;

/* A utility function to check whether a word is
present in dictionary or not. An array of strings
is used for dictionary. Using array of strings for
dictionary is definitely not a good idea. We have
used for simplicity of the program*/
int dictionaryContains(string word)
{
	string dictionary[] = {"mobile","samsung","sam","sung",
							"man","mango","icecream","and",
							"go","i","like","ice","cream"};
	int size = sizeof(dictionary)/sizeof(dictionary[0]);
	for (int i = 0; i < size; i++)
		if (dictionary[i].compare(word) == 0)
		return true;
	return false;
}

// returns true if string can be segmented into space
// separated words, otherwise returns false
bool wordBreak(string str)
{
	int size = str.size();

	// Base case
	if (size == 0) return true;

	// Try all prefixes of lengths from 1 to size
	for (int i=1; i<=size; i++)
	{
		// The parameter for dictionaryContains is
		// str.substr(0, i) which is prefix (of input
		// string) of length 'i'. We first check whether
		// current prefix is in dictionary. Then we
		// recursively check for remaining string
		// str.substr(i, size-i) which is suffix of
		// length size-i
		if (dictionaryContains( str.substr(0, i) ) &&
			wordBreak( str.substr(i, size-i) ))
			return true;
	}

	// If we have tried all prefixes and
	// none of them worked
	return false;
}

// Driver program to test above functions
int main()
{
	wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
	wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
	wordBreak("")? cout <<"Yes\n": cout << "No\n";
	wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
	wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n";
	wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
	return 0;
}
then further optmize it and solve subproblems and
    //for dp solution insert all the dictionary words in set and then check for every letter ending at position i and then in next loop j will cehck for every word froming from j--> to i
    class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
         int n =s.size();
        
        set<string> dict;
        for(auto w: wordDict)
            dict.insert(w);
        
        vector<bool> dp(n+1,false);
        dp[0] = true; //You can make empty string with any wordDict
        
        //From every i position check if you can make word ending here
        for(int i=0;i<n;i++)
        {
            //If we can make a word from j->i
            //We need to check if we can make a word till j first
            for(int j=i;j>=0;j--)
            {
                string curr = s.substr(j,i-j+1); //pos,noOfChars
                
                if(dict.find(curr)!=dict.end())
                    dp[i+1] = dp[i+1] || dp[j]; //dp[j] means can be make words before j(dp is 1 indexed)
                
                if(dp[i+1])
                    break;
            }
        }
        
        return dp[n];
    }
};
// Sliding Window Maximum // deque keep tarck of max
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
       int i=0;
        int j=0;
        deque<int>dq;
        vector<int>ans;
        int size=nums.size();
        
        while(j<size)
        {
            if(j-i+1<k)
            {
                while(dq.size()!=0 && dq.back()<nums[j])
                {
                    dq.pop_back();
                }
                dq.push_back(nums[j]);
                j++;
            }
            else if(j-i+1==k)
            {
                
                while(dq.size()!=0 && dq.back()<nums[j])
                {
                    dq.pop_back();
                }
                dq.push_back(nums[j]);
                ans.push_back(dq.front());
                
                if(nums[i]==dq.front())
                    dq.pop_front();
                
                i++;
                j++;
            }
           
            
        }
        
        return ans;
    }
};

//Number of Proveinces
//connected components dfs graph
class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>&visited, int i)
    {
        visited[i]=1;
        for(int j=0;j<isConnected[i].size();j++)
        {
            if(isConnected[i][j]==1 && visited[j]==0)
            {
                dfs(isConnected, visited, j);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int size=isConnected.size();
        vector<int>visited(size, 0);
        int cnt=0;
        for(int i=0;i<size;i++)
        {
            if(!visited[i])
            {
                dfs(isConnected, visited, i);
                cnt++;
            }
        }
        return cnt;
    }
};

//Same can be made with union and find
class Solution {
public:
    
    int find(vector<int> &parent, int node) {
        if (parent[node] == -1) {
            return node;
        }
        return find(parent, parent[node]);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector <int> parent(isConnected.size(), -1);
        int provinces = isConnected.size();
        
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[0].size(); j++) {
                if (isConnected[i][j] == 1) {
                    int x = find(parent, i);
                    int y = find(parent, j);
                    
                    if (x != y) {
                        provinces--;
                        parent[y] = x;
                    }
                }
            }
        }
        
        return provinces;
    }
};

//Copy List with Random Pointer

Node *copylist(Node *head)
{
	Node *itr=head;
	Node *front=head;
	
	while(itr!=NULL)
	{
		front=itr->next;
		Node *copy=new Node(itr->val);
		itr->next=copy;
		copy->next=front;
		itr=front;
	}
	
	itr=head;
	while(itr!=NULL)
	{
		if(itr->random!=NULL)
		{
			itr->next->random=itr->random->next;
		}
		itr=itr->next->next;
	}
	
	itr=head;
	Node *res=new Node(0);
	Node *copy=res;
	
	while(itr!=NULL)
	{
		front=it->next->next;
		copy->next=itr->next;
		copy=copy->next;
		itr=front;
	}
	return res->next;
}

//Merge Two sorted linked lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
     
        if(l1==NULL)
            return l2;
        
        if(l2==NULL)
            return l1;
        
        if(l1->val>l2->val)
            swap(l1, l2);
        
        ListNode *res=l1;
        ListNode *tmp;
        
        while(l1!=NULL && l2!=NULL)
        {
            while(l1!=NULL && l1->val<=l2->val)
            {
                tmp=l1;
                l1=l1->next;
            }
            tmp->next=l2;
            swap(l1, l2);
        }
        return res;
    }
};
//Top K frequent Words
class Solution {
public:
    struct comp{
        bool operator() (const pair<int, string>a, const pair<int, string>b)
        {
            if(a.first!=b.first)
            {
                return a.first>b.first;
            }
            else
            {
                return a.second<b.second;
            }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int>mp;
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        
        priority_queue<pair<int, string>, vector<pair<int , string>>, comp>pq;
        
        for(auto it:mp)
        {
            pq.push({it.second ,it.first});
            if(pq.size()>k)
                pq.pop();
        }
        
        vector<string>ans;
        while(!pq.empty())
        {
            pair<int , string>a=pq.top();
            pq.pop();
            ans.insert(ans.begin(), a.second);
        }
        return ans;
        
    }
};

//Rotten Oranges
class Solution {
public:
   int orangesRotting(vector<vector<int>>& grid) {
        // solved using BFS
        queue<pair<int, int>> rotten;
        
        int freshCnt = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 2) rotten.push(make_pair(i,j)); // add coordinate to queue
                if(grid[i][j] == 1) freshCnt++; 
            }
        }
        
        vector<vector<int>> dxy = {{1,0}, {-1,0}, {0,1}, {0,-1}}; // down up right left
        int time = 0;
        while(!rotten.empty() && freshCnt > 0){
            time++;
            int sz = rotten.size();
            while(sz-- > 0){
                auto pick = rotten.front(); rotten.pop();
                for(auto it: dxy){
                    int xC = pick.first + it[0]; // x coordinate 
                    int yC = pick.second + it[1]; // y coordinate
                    // check bounds or if no fresh orange in x and yCoords
                    if(xC < 0 || xC >= grid.size() || yC < 0 || yC >= grid[0].size() ||
                      grid[xC][yC] == 0 || grid[xC][yC] == 2) continue;
                    
                    // so we have a fresh orange here. It becomes rotten so add to rotten Q and change grid val from 1 to 2
                    rotten.push(make_pair(xC, yC));
                    grid[xC][yC] = 2;
                    freshCnt--;
                }
            }
        }
        
        if(freshCnt == 0) return time;
        else return -1;
    }
};

//Analyze User Website Visit Pattern

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& users,
                                      vector<int>& time,
                                      vector<string>& sites) {
        
  unordered_map<string, map<int, string>> userToDatas;
  unordered_map<string, int> threeSequencesToCounts;
  int maxCount = 0;
  string res;
  
  // Step 1: collect user data in a map of maps 
  // Basically store website and time data for every user name, by user name 
  for (auto i = 0; i < users.size(); ++i)
  {
      userToDatas[users[i]][time[i]] = sites[i];
  }
      
  // Step 2: collect three sequences      
  for (auto userToData: userToDatas)
  {
    unordered_set<string> threeSequences;
    // T :O(n^3)
    for (auto it = begin(userToData.second); it != end(userToData.second); ++it)
    {   
      for (auto it1 = next(it); it1 != end(userToData.second); ++it1)
      {
          for (auto it2 = next(it1); it2 != end(userToData.second); ++it2)
          {
              threeSequences.insert(it->second + "$" + it1->second + "#" + it2->second);
      
          }
      }
    }
    for (auto threeSequence : threeSequences) 
    {
        ++threeSequencesToCounts[threeSequence];
    }
  }
        
  for (auto threeSequenceToCount : threeSequencesToCounts) {
      cout<< threeSequenceToCount.first<< " "<< threeSequenceToCount.second<< endl;
    if (threeSequenceToCount.second >= maxCount) {
	// If there is more than one solution, return the lexicographically smallest such 3-sequence.
      res = res == "" || 
           threeSequenceToCount.second > maxCount ? threeSequenceToCount.first : min(res, threeSequenceToCount.first);
      maxCount = threeSequenceToCount.second;
    }
  }
  
  auto seperator1 = res.find("$");
  auto seperator2 = res.find("#");
  
        return { res.substr(0, seperator1),// element 1
                res.substr(seperator1 + 1, seperator2 - seperator1 - 1), // element 2
                res.substr(seperator2 + 1) };// element 3
}
};

//Word Break 2

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
//first take one by one word from dict and check if substring forming with that is present or length is == to w.length() and if yes then put it in result and then recursively call for the other

class Solution {
    unordered_map<string, vector<string>>dp;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        if(dp.find(s)!=dp.end()) return dp[s];
        vector<string>res;
        for(string w : wordDict)
        {
            if(s.substr(0, w.length())==w)
            {
                if(w.length()==s.length())
                {
                    res.push_back(w);
                }
                else
                {
                    vector<string>tmp=wordBreak(s.substr(w.length()), wordDict);
                    for(string t:tmp)
                    {
                    res.push_back(w+ " "+t);
                    }
                }
            }
        }
        return dp[s]=res;
    }
};


//Reorder Data in log files letter log and digit log simply use sort with custom comparator function
 
class Solution {
   
public:
    static bool compare(string str1, string str2)
    {
        int pos1=str1.find(' ');
        int pos2=str2.find(' ');
        string s1=str1.substr(pos1+1);
        string s2=str2.substr(pos2+1);
        if(s1==s2)  //if all the string is same after the let1 and let2 simply compare whole
        {
            if(str1.compare(str2)<0)
                return true;
            else
                return false;
        }
        if(s1.compare(s2)<0) // if all the string is not same then in that case compare after the let1 and let2 and so on
            return true;
        else
            return false;
        
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string>letter_log;
        vector<string>digit_log;
        vector<string>ans;
        
        for(int i=0;i<logs.size();i++)   //check for the letter log or digit log
        {
            int pos=logs[i].find(' ');
            if(logs[i][pos+1]>='0' && logs[i][pos+1]<='9')
            {
                digit_log.push_back(logs[i]);
            }
            else
            {
                letter_log.push_back(logs[i]);
            }
        }
        
        sort(letter_log.begin(), letter_log.end(), compare);
        ans.insert(ans.end(), letter_log.begin(), letter_log.end());
        ans.insert(ans.end(), digit_log.begin(), digit_log.end());
        
        return ans;
    }
};

//Count of smaller elements to right
class Solution {
public:
	vector<int> ans;
	vector<pair<int,int>> nums;

	void getRevInv(int left,int mid,int right) 
    	{
		int i=left;
        	int j=mid;
        
		vector<pair<int,int>> v;
        
		while(i<=mid-1 && j<=right)
        	{
			if(nums[j].first>=nums[i].first) 
            		{
                		v.push_back(nums[j++]);   
            		}
			else 
            		{
				v.push_back(nums[i]);
				ans[nums[i++].second]+= right-j+1;
			}
		}
        
		while(i<=mid-1) 
            		v.push_back(nums[i++]);
        
        
		while(j<=right) 
            		v.push_back(nums[j++]);
        
        
		for(auto x: v)
            	nums[left++]=x;
	}

	void merge(int i,int j) {
		if(i==j) return;
		int mid= (i+j)/2;
		if(i!=mid) merge(i,mid);
		if(mid+1!=j) merge(mid+1,j);
		getRevInv(i,mid+1,j);
	}

	vector<int> countSmaller(vector<int>& arr) {
		int n= arr.size();
		ans.clear(); ans.resize(n,0);
		nums.clear();
		for(int i=0;i<n;i++) nums.push_back({arr[i],i});
		merge(0,n-1);
		return ans;
	}
};

//zigzag level order traversal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>v;
        stack<TreeNode*>s1;
        if(root==NULL)  return v;
        stack<TreeNode*>s2;
        
        s1.push(root);
        while(!s1.empty() || !s2.empty())
        {
            vector<int>tmp1;
            
            while(!s1.empty())
            {
                
                auto tmp=s1.top();
              
                
                if(tmp->left)   s2.push(tmp->left);
                if(tmp->right)  s2.push(tmp->right);
                
                
               
                s1.pop();
                  tmp1.push_back(tmp->val);
            }
            
            v.push_back(tmp1);
            vector<int>tmp2;
            while(!s2.empty())
            {
               
                auto tmp=s2.top();
               
                
                if(tmp->right)  s1.push(tmp->right);
                if(tmp->left)   s1.push(tmp->left);
                
              
                s2.pop();  
                 tmp2.push_back(tmp->val);
            }
            if(tmp2.size()>0)
            v.push_back(tmp2);
        }
        return v;
    }
};

//Shortest Path in Binary Matrix
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int res = 1;
        int row = grid.size();
        if (row == 0) return -1;
        int col = grid[0].size();
        if (col == 0 ) return -1;
        if (grid[0][0] != 0 | grid[row-1][col-1] != 0) return -1;

            queue<pair<int, int>> queue;
            queue.push(make_pair(0,0));
            vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
            grid[0][0] = 1;
            while(!queue.empty()){
                auto curr = queue.front();
                int x = curr.first, y = curr.second;
                if( x == row -1 && y == col -1) return grid[x][y];

                for(auto direction : directions)
                {
                    int nx = x + direction[0];
                    int ny = y + direction[1];
                    if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 0)
                    {
                        queue.push(make_pair(nx,ny));
                        grid[nx][ny] = grid[x][y] + 1;
                    }
                }
                queue.pop();
            }
    return -1; 
    }
};


//Subtree of another tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool isidentical(TreeNode *root1, TreeNode *root2)
    {
        if(root1==NULL && root2==NULL)
        return true;

        if(root1==NULL || root2==NULL)
        return false;

        return (root1->val==root2->val && isidentical(root1->left, root2->left) && isidentical(root1->right, root2->right));
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root==NULL)
            return false;
        
        if(subRoot==NULL)
            return true;
        
        if(isidentical(root, subRoot))
            return true;
        
        else
            return isSubtree(root->left, subRoot)||isSubtree(root->right, subRoot);
    }
};

//aseroid collision stack
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> s; // use vector to simulate stack.
        for (int i = 0; i < a.size(); i++) {
            if (a[i] > 0 || s.empty() || s.back() < 0) // a[i] is positive star or a[i] is negative star and there is no positive on stack
                s.push_back(a[i]);
            else if (s.back() <= -a[i]) { // a[i] is negative star and stack top is positive star
                if(s.back() < -a[i]) i--; // only positive star on stack top get destroyed, stay on i to check more on stack.
                s.pop_back(); // destroy positive star on the frontier;
            } // else : positive on stack bigger, negative star destroyed.
        }
        return s;
    }
};

//minimum units on Truck
class Solution {
public:
    bool static comparator(vector<int> &x,vector<int> &y){
        return (x[1]>y[1]);
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comparator);
        int ans=0; //total units
		
        for(int i=0;i<boxTypes.size();i++){
            int box_count=min(boxTypes[i][0],truckSize);
            ans+=box_count*boxTypes[i][1];
            truckSize-=box_count;
            if(truckSize==0)
                break;
        }
        return ans;
    }
};

//// concatenated words
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_set<string> dict(words.begin(), words.end());
        unordered_set<string> precomputed_dict;    
        for(const auto & word : words)
        {
            if(canForm(word, /*using words from*/ dict, /*or*/precomputed_dict))
                res.push_back(word);
        }
        
        return res;
    }
    
    bool canForm(const string& word, const unordered_set<string>& dict,
                unordered_set<string>& cache)
    {   //have we seen this word before
        if(const auto it = cache.find(word); it != cache.end())
            return true;
        
        for(size_t i{1}; i < word.size(); ++i) //try all prefixes
        {
            const auto s1 = word.substr(0, i);       
            const auto s2 = word.substr(i);
            //proceed to investigare s2 only if s1 is in dictionary
            if(const auto it = dict.find(s1); it != dict.end())
            {   //recursively try to form a word with the rest of the string
                if(dict.find(s2) != dict.end() or canForm(s2, dict, cache))
                {
                    cache.insert(word);
                    return true;                    
                }   
            }
        }
        return false; //no luck
    }
};


//break palindrome
class Solution {
public:
    string breakPalindrome(string s) {
        
        if(s.length()==1)
            return "";
        for(int i=0;i<s.length()/2;i++)
        {
            if(s[i]!='a')
            {
                s[i]='a';
                return s;
            }
            
        }
        s[s.length()-1]='b';
            return s;
        
    }
};


//self diminishing valued color balls
#define mod 1000000007
class Solution {
public:
    int maxProfit(vector<int>& v, int o) {
       long long n=v.size();
        long long res=0;
        sort(v.begin(), v.end());
        for(int i=n-1;i>=0;i--)
        {
            long long diff=v[i]-(i>0?v[i-1]:0);    // last and last second difference remember the bar graph in video
            long long x=min((long long)o, (n-i)*diff); // orders remaining
            long long r=v[i];           
            long long l=r-x/(n-i); // if in case orders remaining are not suffieceint than balls
            
            
            res+=((r*(r+1)/2)-(l*(l+1)/2))*(n-i); // trick for calculating answer
            res%=mod;
            res+=l*(x%(n-i)); //
            res%=mod;
            o-=x;
        }
        return res;
    }
};

//Interview Bit***********************************************///////////////////////////////////////////////////////////******************
//Gas Station
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int index=0;
        int tank=0;
        int total=0;
        for(int i=0;i<n;i++)
        {
            tank+=gas[i]-cost[i];
             if(tank<0)
             {
                 index=i+1;
                 tank=0;
             }
            total+=gas[i]-cost[i];
        }
        return total<0?-1:index;
       
    }
};

//Majority Element (Moore Voting Algorithm)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate =0;
        for(int num: nums){
            if(count==0){
                candidate=num;
            }
            if(num==candidate) count+=1;
            else count-=1;
        }
        return candidate;
    }
};

//Candy
//one solution is to make and tmp array distribute 1 candy to each one and then traverse from left if greater increment count and if less then 1 
//similarly do from both side left and right and then take max from both the arrays for each index
/* To use two variables 'up' and 'down' to count the steps of continuous up and down respectively, and a 'peak' representing the peak before going down. In the below example:

[0, 1, 20, 9, 8, 7]
Scan from left to right, first child is given 1 candy;
the second child is given 2 candies, and up=1;
the third child is given 3 candies, and up=2; peak=2;
the fourth child is given 1 candy, and down=1; and third child still has 3 candies since peak=2;
the fifth child is given 1 candy, and down=2; and the previous child needs 1 more candy now but the third child no need more;
the sixth child is given 1 candy, and down=3; and both the fifth and fourth child needs 1 more candy now, and the peak, the third child need 1 more as well. */


class Solution {
public:
    int candy(vector<int>& ratings) {
    
    if(ratings.size()==0)
    return 0;
    
    int res=1;
    int up=0;
    int down=0;
    int peak=0;
    
    for(int i=1;i<ratings.size();i++)
    {
        if(ratings[i-1] < ratings[i])
        {
            peak=++up;
            down=0;
            res+=1+up;
        }
        else if(ratings[i-1]==ratings[i])
        {
            peak=up=down=0;
            res+=1;
        }
        else
        {
            up=0;
            down++;
            res+=1+down+(peak>=down?-1:0);
        }
    }
    return res;
    }
};

// longest increasing subsequence
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        
        int ans=1;
        for(int i=0;i<n;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j])
                {
                    dp[i]=max(dp[i], dp[j]+1);
                    ans=max(ans, dp[i]);
                }
            }
        }
        return ans;
        
    }
};

//Max Product Subarray
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxsofar=nums[0];
        int minsofar=nums[0];
        int overall=nums[0];
        int prevmaxsofar=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            prevmaxsofar=maxsofar;
            maxsofar=max({nums[i], nums[i]*maxsofar, nums[i]*minsofar});
            
            minsofar=min({nums[i], nums[i]*minsofar, nums[i]*prevmaxsofar});
            
            overall=max(overall, maxsofar);
        }
        return overall;
    }
};

//Ways to Decode
	// TC - O(n) , SC - O(n)
	public static int numDecoding(String s) {
		int[] dp = new int[s.length() + 1];
		dp[0] = 1;
		dp[1] = s.charAt(0) == '0' ? 0 : 1;
		for (int i = 2; i <= s.length(); i++) {
			int onedigit = Integer.parseInt(s.substring(i - 1, i));
			int twodigit = Integer.parseInt(s.substring(i - 2, i));
			if (onedigit >= 1) {
				dp[i] += dp[i - 1];
			}
			if (twodigit >= 10 && twodigit <= 26) {
				dp[i] += dp[i - 2];
			}
		}
		return dp[s.length()];
	}

		public static int numDecodings(String s) {
		int first = 1;
		int second = s.charAt(0) == '0' ? 0 : 1;
		for (int i = 2; i <= s.length(); i++) {
			int ans = 0;
			int onedigit = Integer.parseInt(s.substring(i - 1, i));
			int twodigit = Integer.parseInt(s.substring(i - 2, i));
			if (onedigit >= 1) {
				ans += second;
			}
			if (twodigit >= 10 && twodigit <= 26) {
				ans += first;
			}
			first = second;
			second = ans;
		}
		return second;
	}


//Best Time To Sell Stock I
int Solution::maxProfit(const vector<int> &A) {
    int n=A.size();
    
    if(n==0)
    return 0;
    
    int tmp=A[0];
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(A[i]<tmp)   
        {
            tmp=A[i];
        }
        res=max(res, A[i]-tmp);
    }
    return res;
}


//Best Time To Sell Stock II
int Solution::maxProfit(const vector<int> &A) {
    int res=0;
    for(int i=1;i<A.size();i++)
    {
        if(A[i]>A[i-1])
        {
            res+= A[i]-A[i-1];
        }
    }
    return res;
}


//Best Time To Sell Stock III
int Solution::maxProfit(const vector<int> &A) {
    int n=A.size();
    
    if(n==0)
    return 0;
    
    vector<int>left(n), right(n);
    
    left[0]=A[0];
    int leftmin=0;
    for(int i=1;i<n;i++)
    {
        left[i]=max(left[i-1], A[i]-leftmin);
        leftmin=min(leftmin, A[i]);
    }
    
    int rightmax=0;
    right[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--)
    {
        right[i]=max(right[i+1], rightmax-A[i]);
        rightmax=max(rightmax, A[i]);
    }
    
    int profit=right[0];
    for(int i=1;i<n;i++)
    {
        profit=max(profit, left[i-1]+right[i]);
    }
    
    return profit;
}

//Max Path Sum
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        helper(root,sum);
        return sum;
    }
    int helper(TreeNode* root, int &sum)
    {
        if(root==NULL)
            return 0;
        int l=helper(root->left,sum);
        int r=helper(root->right,sum);
        
        int nodemax=max({l+root->val, r+root->val, root->val, root->val+l+r});
        
        sum=max(sum, nodemax);
        
        int singlepathsum=max({root->val, root->val+l, root->val+r});
        return singlepathsum;
    }
};

//Palindrome Partitioning II
#include<bits/stdc++.h>
using namespace std;
int res[1001][1001];
bool isplaindrome(string s, int i, int j)
{
    if(i==j)
    return true;
    
    if(i>j)
    return true;
    
    while(i<j)
    {
        if(s[i]!=s[j])
            return false;
            
        i++;
        j--;
    }
    return true;
    
}
int palindromePartitioning(string s, int i, int j)
{
    if(i>=j)
    return 0;
    
    if(isplaindrome(s, i, j)==true)
    return 0;
    
    if(res[i][j]!=-1)
    return res[i][j];
    
    int min=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int tmp=(palindromePartitioning(s,i,k)+palindromePartitioning(s,k+1,j))+1;
        if(tmp<min)
        {
            min=tmp;
        }
    }
    return res[i][j]=min;
}
    

int main()
{
    string s;
    cin>>s;
    int n=s.length();
    memset(res, -1, sizeof(res));
    cout<<palindromePartitioning(s, 1, n)<<endl;
    return 0;
}

//Palindrome Partitioning Alternative
public static int partition(String s) {
		  int n = s.length();
		  boolean palindrome[][] = new boolean[n][n]; //boolean table
		  
		  //Trivial case: single letter palindromes
		  for (int i = 0; i < n; i++) {
			  palindrome[i][i] = true;
		  }
		  
		  //Finding palindromes of two characters.
		  for (int i = 0; i < n-1; i++) {
		    if (s.charAt(i) == s.charAt(i+1)) {
		      palindrome[i][i+1] = true;
		    }
		  }
		  
		  //Finding palindromes of length 3 to n
		  for (int curr_len = 3; curr_len <= n; curr_len++) {
		    for (int i = 0; i < n-curr_len+1; i++) {
		      int j = i+curr_len-1;
		      if (s.charAt(i) == s.charAt(j) //1. The first and last characters should match 
		    	  && palindrome[i+1][j-1]) //2. Rest of the substring should be a palindrome
		      {
		    	palindrome[i][j] = true; 
		      }
		    }
		  }
		  
		  int[] cuts = new int[n];
		  for(int i=0; i<n; i++)
		  {
			  int temp = Integer.MAX_VALUE;
			  if(palindrome[0][i])
				  cuts[i] = 0;
			  else
			  {
				  for(int j=0; j<i; j++)
				  {
					 if((palindrome[j+1][i]) && temp > cuts[j] + 1) 
					 {
						 temp = cuts[j] + 1;
					 }
				  }
				  cuts[i] = temp;
			  }			  
		  }
		  return cuts[n-1];
		}

//Min Path Sum In Matrix
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows=grid.size();
        if(rows==0) return 0;
        int cols=grid[0].size();
        
        vector<vector<int>>dp(rows, vector<int>(cols));
        
        dp[0][0]=grid[0][0];
        for(int i=1;i<cols;i++)
            dp[0][i]=dp[0][i-1]+grid[0][i];
        
        for(int i=1;i<rows;i++)
            dp[i][0]=dp[i-1][0]+grid[i][0];
        
        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<cols;j++)
            {
                dp[i][j]=grid[i][j]+min(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[rows-1][cols-1];
    }
};

//Min Jump Array
int Solution::jump(vector<int> &A) {
    int maxReachable=A[0];
    int jump=1;
    int step=A[0];
    
    int n=A.size();
    
    if(n<=1)
        return 0;
    if(A[0]==0)
        return -1;
    
    for(int i=1;i<n;i++)
    {
        if(i==n-1)
        {
            return jump;
        }
        
        maxReachable=max(maxReachable, i+A[i]);
        
        step--;
        
        if(step==0)
        {
            jump++;
            if(i>=maxReachable)
            {
                return -1;
            }
            step=maxReachable-i;
        }
    }
}

//Edit Distance
int res[1001][1001];
int Solution::minDistance(string A, string B) {
    int n=A.length();
    int m=B.length();
    memset(res, -1, sizeof(res));
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0)
            res[i][j]=j;
            else if(j==0)
            res[i][j]=i;
            else if(A[i-1]==B[j-1])
            res[i][j]=res[i-1][j-1];
            else
            res[i][j]=1+min(res[i-1][j-1], min(res[i][j-1], res[i-1][j]));
        }
    }
    return res[n][m];
}

//Unique Binary Search Trees II


// Jump Game Array
int Solution::canJump(vector<int> &A) {
    int n=A.size();
    int reachable=0;
    
    for(int i=0;i<n;i++)
    {
        if(reachable <i){
            return false;
        }
        reachable=max(reachable, i+A[i]);
    }
    return true;
}

//Nth Stair
class Solution {
public:
   
    int climbStairs(int n) {
//        if(n<=0) return 0; 
//        if(n==1) return 1;
//        if(n==2) return 2;
       
//         int a=2;
//         int b=1;
//         int res=0;
//         for(int i=2;i<n;i++)
//         {
//             res=a+b;
//             b=a;
//             a=res;
//         }
//         return res;
        
        
     vector<int> steps(n+1,0);
     steps[0]=1;
     steps[1]=2;
     for(int i=2;i<n;i++)
     {
         steps[i]=steps[i-2]+steps[i-1];
     }
     return steps[n-1];
    }
};

//Swap Node Pairwise
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head!=NULL || head->next!=NULL)
        {
            swap(&head->val, &head->next->val);
            swapPairs(head->next->next);
        }
        return head;
    }
};

//Swap PairWise with change pointers
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
    if(head==NULL || head->next==NULL)
    return  head;
    
    ListNode *remaining=head->next->next;
    
    ListNode *newhead=head->next;
    
    head->next->next=head;
    
    head->next=swapPairs(remaining);
    
    return newhead;
    }
};

