class Solution {
    void mark_curr_island(vector<vector<char>>&grid, int x, int y, int r, int c)
    {
        
        if(x<0||y<0||x>=r||y>=c||grid[x][y]!='1')
            return ;
        
        grid[x][y]='2';
        mark_curr_island(grid, x, y+1, r, c);
        mark_curr_island(grid, x+1, y, r, c);
        mark_curr_island(grid, x-1, y, r, c);
        mark_curr_island(grid, x, y-1, r, c);
        
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int r=grid.size();
        if(r==0)
            return 0;
        int c=grid[0].size();
        
        int cnt=0;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]=='1')
                {
                    mark_curr_island(grid, i, j, r, c);
                    cnt++;
                }
            }
           
        }
         return cnt;
    }
    
};
