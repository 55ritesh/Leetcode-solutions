//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    bool isvalid(int nx,int ny,int n,vector<vector<int>>&vis){
        
        if(nx>=0 && nx<n && ny>=0 && ny<n && vis[nx][ny]==0)
        return true;
        
        return false;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int n=N;
	    int tposx=TargetPos[0]-1;
	    int tposy=TargetPos[1]-1;
	    int oposx=KnightPos[0]-1;
	    int oposy=KnightPos[1]-1;
	    
	    if(tposx==oposx && tposy==oposy)
	    return 0;
	    
	    vector<vector<int>>vis(n,vector<int>(n,0));
	    queue<pair<int,int>>q;
	    q.push({oposx,oposy});
	    vis[oposx][oposy]=1;
	    int ans=0;
	    
	    while(!q.empty()){
	        int sz=q.size();
	        ans++;
	        
	         while(sz!=0){
	        pair<int,int>p=q.front();
	        q.pop();
	        
	        int x=p.first;
	        int y=p.second;
	       
	        
	       
	            
	            int dx[8]={-2,-2,-1,+1,+2,+2,+1,-1};
	            int dy[8]={-1,+1,+2,+2,+1,-1,-2,-2};
	            
	            for(int i=0;i<8;i++){
	            int nx=x+dx[i];
	            int ny=y+dy[i];
	            
	            if(nx==tposx && ny==tposy)
	                return ans; 
	                
	            if(isvalid(nx,ny,n,vis)){
	                q.push({nx,ny});
	                vis[nx][ny]=1;
	            }
	        }
	         sz--;
	    }
	    }
	    return ans;
	}
};

// 	    int ans=0;
// 	    while(!q.empty()){
// 	        int sz=q.size();
// 	        ans++;
// 	        while(sz!=0){
// 	            pair<int,int>p =q.front();
// 	            q.pop();
	            
// 	            int x=p.first;
// 	            int y=p.second;
	            
	            
// 	            int dx[8]={1,1,-1,-1,2,-2,2,-2};
// 	            int dy[8]={2,-2,2,-2,1,1,-1,-1};
	            
// 	            for(int i=0;i<8;i++){
// 	                int nx=x+dx[i];
// 	                int ny=y+dy[i];
	                
// 	                if(nx==tx && ny==ty)
// 	                return ans;
	                
// 	                if(isvalid(nx,ny,vis,n)){
// 	                    q.push({nx,ny});
// 	                    vis[nx][ny]=true;
// 	                }
// 	            }
// 	            sz--;
// 	        }
// 	    }
	    
// 	    return ans;
// 	}
// };

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends