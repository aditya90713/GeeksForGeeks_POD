//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
            vector<int>row,col;
            row.push_back(-1);
            col.push_back(-1);
            int mxr=0,mxc=0;
            for(auto &a:enemy){
                row.push_back(a[0]-1);
                col.push_back(a[1]-1);
            }
            row.push_back(n);
            col.push_back(m);
            sort(row.begin(),row.end());
            sort(col.begin(),col.end());
            for(int i=1;i<row.size();i++){
                mxr=max(mxr,row[i]-row[i-1]-1);
            }for(int i=1;i<row.size();i++){
                mxc=max(mxc,col[i]-col[i-1]-1);
            }
            return mxc*mxr;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends