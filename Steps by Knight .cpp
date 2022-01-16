Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

 

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
  
  // code
  
  class Solution 
{
    public:
    void help(int x, int y,int d1, int d2,queue<pair<int,int>>&q,vector<vector<bool>>&vis,bool &flag ,int n){
        int dx[8] = {-1,-1,1,1,-2,-2,2,2};
	    int dy[8] = {2,-2,2,-2,1,-1,1,-1};
	    for(int i=0;i<8;i++)
        {
            if(x+dx[i]<0||x+dx[i]>=n||y+dy[i]<0||y+dy[i]>=n||vis[x+dx[i]][y+dy[i]])
            {
                continue;
            }
            if(x+dx[i] == d1 && y+dy[i] == d2)
            {
                flag=true;
                return;
            }
            q.push({x+dx[i],y+dy[i]});
            vis[x+dx[i]][y+dy[i]]=true;
        }
    }
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    int s1=KnightPos[0]-1;
        int s2=KnightPos[1]-1;
        int d1=TargetPos[0]-1;
        int d2=TargetPos[1]-1;
        if(s1==d1&&d2==s2) return 0; 
        queue<pair<int,int>>q; 
        vector<vector<bool>>vis (n, vector<bool>(n, false));
        q.push({s1,s2});
        vis[s1][s2]=true;
        int step=0;
        bool flag=false;
        while(q.size())
        {
            step++;
            int t=q.size();
            while(t--)
            {
                pair<int,int>p=q.front();
                q.pop();
                help(p.first,p.second,d1,d2,q,vis,flag,n);
                if(flag) return step;
            }
        }
        return -1;
	}
};
