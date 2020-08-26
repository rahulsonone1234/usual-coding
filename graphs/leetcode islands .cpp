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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

int a[20][20];
int r,c;
void dfs(int i, int j)
{
    if(i<0||j<0||i>=r||j>=c||a[i][j]!=1)
    {
        return;
    }
    a[i][j]=2;
    dfs(i, j+1);
    dfs(i, j-1);
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i+1,j+1);
    dfs(i-1,j-1);
    dfs(i+1,j-1);
    dfs(i-1,j+1);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>r>>c;
        a[20][20]={0};
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>a[i][j];
            }
        }
        int cnt=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(a[i][j]==1)
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
