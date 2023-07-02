//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int o=0,o1=0,o2=0;
        
        for(int i=0;i<n;i++){
            if(a[i]==0)
            o++;
            else if(a[i]==1)
            o1++;
            else
            o2++;
        }
        
        int i=0;
        
        while(o!=0){
            a[i]=0;
            o--;
            i++;
        }
        while(o1!=0){
            a[i]=1;
            o1--;
            i++;
        }
        while(o2!=0){
            a[i]=2;
            o2--;
            i++;
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends