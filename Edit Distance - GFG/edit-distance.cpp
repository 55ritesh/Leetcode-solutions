//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int solve(int i,int j,string s, string t,vector<vector<int>>&dp){
      
      
      if(i<0){
          return j+1;
      }
      if(j<0)
      return i+1;
      
      if(dp[i][j]!=-1)
      return dp[i][j];
      
      if(s[i]==t[j]){
          return dp[i][j]=solve(i-1,j-1,s,t,dp);
      }
      
      int in=1+solve(i,j-1,s,t,dp);
      int de=1+solve(i-1,j,s,t,dp);
      int re=1+solve(i-1,j-1,s,t,dp);
      
      return dp[i][j]=min(in,min(de,re));
  }
    int editDistance(string s, string t) {
        
        int s1=s.length();
        int t1=t.length();
        vector<vector<int>>dp(s1,vector<int>(t1,-1));
        
        return solve(s1-1,t1-1,s,t,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends