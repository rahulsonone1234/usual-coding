///////////////////////////////////////////////////////////////////////////////////////////////////////////BFS
int X[] = {0, 0, 1, 1, 1, -1, -1, -1};
int Y[] = {1, -1, 0, 1, -1, 0, 1, -1};
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
     int rect[A+1][B+1];
    memset(rect, 0 , sizeof(rect));
 
    for(int i=0;i<=A;i++)
        for(int j=0;j<=B;j++)
            for(int k=0;k<C;k++)
                if(sqrt(pow(E[k]-i, 2) + pow(F[k]-j, 2)) <= D)
                {
                    rect[i][j] = 1;
                    break;
                }
 
    if(rect[0][0]==1 || rect[A][B]==1)
        return "NO";
 
    queue<pair<int,int> >q;
    q.push({0,0});
    rect[0][0] = 1;
 
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
 
        if(x==A && y==B)
            return "YES";
 
        for(int i=0;i<8;i++)
        {
            int newx = x + X[i];
            int newy = y + Y[i];
            if(newx>=0 && newx<=A && newy>=0 && newy<=B && rect[newx][newy]==0)
            {
                rect[newx][newy] = 1;
                q.push({newx,newy});
            }
        }
    }
    return "NO";
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
DFS

int x_cood[8] = {-1,-1,0,1,1,1,0,-1};
int y_cood[8] = {0,1,1,1,0,-1,-1,-1};
bool inrange(int i,int j,int r,int c,bool **visited)
{
    return (i>=0 && j>=0 && i<=r && j<=c && !visited[i][j]);
}
bool DFS(int i,int j,int x,int y,bool** visited)
{
    if(i==x && j==y) return true;
    visited[i][j] = true;
    for(int p=0;p<8;p++)
    {
        if(inrange(i+x_cood[p],j+y_cood[p],x,y,visited))
        {
            bool b = DFS(i+x_cood[p],j+y_cood[p],x,y,visited);
            if(b) return true;
        }
    }
    return false;
}
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    bool ** visited = new bool*[A+1];
    for(int i=0;i<=A;i++)
    visited[i] = new bool[B+1];
    
    for(int i=0;i<=A;i++)
    {
       for(int j=0;j<=B;j++)
       {
            visited[i][j] = false;
       }
    }
    for(int i=0;i<=A;i++)
    {
        for(int j=0;j<=B;j++)
        {
            for(int k=0;k<C;k++)
            {
                if(sqrt(pow(E[k]-i,2)+pow(F[k]-j,2))<=D)
                {
                    visited[i][j]=true;
                    break;
                }
            }
        }
    }
    if(visited[0][0] || visited[A][B]) 
    return "NO";
    return 
    DFS(0,0,A,B,visited)?"YES":"NO";
}
