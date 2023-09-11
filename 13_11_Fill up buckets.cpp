/*
Given n buckets and infinite number of balls. The maximum capacity of each bucket is given in an array capacity[]. Find the number of ways to fill the buckets with balls such that each bucket has atleast 1 ball and all the buckets have distinct number of balls in them.
Note: Since the answer may be very large, calculate the answer modulo 10^9+7.

Example 1:

Input: 
n = 1
capacity = [6]
Output: 6
Explanation: Since there is only one 
bucket. It may hold any number of balls 
ranging from 1 to 6.

Example 2:

Input: 
n = 2 
capacity = [5, 8]
Output: 35
Explanation: If the first bucket has 1
ball in it then the second bucket cant have 1 
ball, so the second bucket has 8-1 = 7 choices.
So the first bucket has 5 choices and for each
choice second bucket has 7 choices.
So total there are 35 ways.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function totalWays() which takes n and capacity[] as input parameters and returns the number of possible ways to fill the buckets. Since the answer may be very large, calculate the answer modulo 10^9+7.

Expected Time Complexity: O(n*log(n)) 
Expected Space Complexity: O(1)

Constraints:
1 <= n <= 100000
1 <= capacity[i] <= 100000
*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalWays(int n, vector<int>capacity) {
        // code here
        sort(capacity.begin(), capacity.end());
        
        long mod = 1000000007;
        long ans = 1;
        for(int i=0; i<n;i++){
            ans = (ans*(capacity[i]-i))%mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>capacity(n);
		for(int i = 0; i < n; i++)
			cin >> capacity[i];
		Solution ob;
		int ans = ob.totalWays(n, capacity);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends