
#include <bits/stdc++.h> 
using namespace std; 
#define endl '\n'; 
const int MXSIZE = 1e6+6; 
 
 
int parent [MXSIZE]; 
int child  [MXSIZE]; 
int low    [MXSIZE]; 
int tym    [MXSIZE]; 
bool visited  [MXSIZE]; 
bool is_cut[MXSIZE]; 
 
vector <vector <int> > adj (MXSIZE); 
 
void dfs(int s) 
{ 
  static int c=0; 
  visited[s]=true;  
  low[s]=tym[s]=c++;  
 // checking all children of s 
  for(int i=0;i<adj[s].size();i++) 
  { 
     int curr = adj[s][i]; 
     if(curr==parent[s]) 
      continue;         // do nothing if curr is its parent 
    if(!visited[curr]) 
    { 
      child[s]++; // one more independent child of s 
      parent[curr]=s;  
      dfs(curr); 
      /* the low time of the oldest ancestor reachable from both */ 
      low[s] = min(low[s] , low[curr]);  
      /* if curr has greater or equal
      low time than visited time of s then if we cut s then 
        curr will get disconnected from the graph*/ 
      if(low[curr] >= tym[s]) 
        is_cut[s]=true; 
    } 
    else 
    { 
      /* here instead of low[curr] I used 
         tym[curr] , I have explained it below*/ 
      low[s]= min(low[s],tym[curr]); 
    } 
  } 
} 
 
int main() 
{ 
  ios_base::sync_with_stdio(false);cin.tie(0);     
       
      int n,e; 
      cin>>n>>e;  
      for(int i=0;i<e;i++) 
      { 
          int x,y;
          cin>>x>>y; 
          adj[x].push_back(y); 
          adj[y].push_back(x); 
      } 
        
      parent[1]=-1; 
      dfs(1); 
 
      /* the vertex from where we started dfs 
         must have atleast two independent children  
         otherwise it is not a cut vertex  */ 
      is_cut[1]= child[1]>1 ? true : false;  
 
 
      for(int i=1;i<=n;i++) 
      { 
        if(is_cut[i]) 
        {
            cout<<i<<" is cut vertex"<<endl;   
        }
      } 
    return 0; 
} 
