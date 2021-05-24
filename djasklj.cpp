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
    void refresh(int key, int value)
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

//
