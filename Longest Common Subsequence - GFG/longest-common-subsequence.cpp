//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int solve(int x,int y, string s1, string s2,vector<vector<int>>&dp){
        
        if(x==0 || y==0)
        return 0;
        
        if(dp[x][y]!=-1)
        return dp[x][y];
        
        if(s1[x-1]==s2[y-1]){
            return dp[x][y]=1+solve(x-1,y-1,s1,s2,dp);
        }
        return dp[x][y]=max(solve(x-1,y,s1,s2,dp),solve(x,y-1,s1,s2,dp));
    }
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        for(int i=0;i<x+1;i++){
            for(int j=0;j<y+1;j++){
                if(i==0 || j==0)
                 dp[i][j]=0;
            }
        }
        
        for(int i=1;i<x+1;i++){
            for(int j=1;j<y+1;j++){
            if(s1[i-1]==s2[j-1]){
            dp[i][j]=1+dp[i-1][j-1];
             }
             else
             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[x][y];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends