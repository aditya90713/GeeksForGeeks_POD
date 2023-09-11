/*
Given two strings S and W. Find the number of times W appears as a subsequence of string S where every character of string S can be included in forming at most one subsequence.
 

Example 1:

Input: 
 S = "abcdrtbwerrcokokokd" 
 W = "bcd" 
Output: 
 2
Explanation: 
The two subsequences of string W are
{ S1 , S2 , S3 } and { S6 , S11 , S18 }
(Assuming 0- based indexing).
 

Example 2:

Input: 
S = "ascfret" 
W = "qwer" 
Output: 
0
Explanation:
No valid subsequences are possible.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function numberOfSubsequences() which takes the string S and string W as input parameters and returns the number of subsequences of string W in string S.

 

Expected Time Complexity: O(N2)
/*Expected Auxiliary Space: O(N)

*/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string s, string w){
        // code here 
        vector<int>visited(s.size(), 0);
        int i =0, j=0, ans = 0;
        
        while(i<s.size()){
            
            
            if(s[i] == w[0] && visited[i] == 0){
                
                visited[i]=1;
                j = 1;
                int k = i+1;
                
                while(j<w.size() && k<s.size()){
                    
                    if(s[k]==w[j] && visited[k] == 0){
                        s[k] = 1;
                        k++;
                        j++;
                    }else{
                        k++;
                    }
                }
                if(j == w.size()){
                    ans++;
                }
            }
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends