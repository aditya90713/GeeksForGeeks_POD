#User function Template for python3

class Solution:
    def findLargest(self, N, S):
        ans = ""
        if S == 0 and N > 1:
            return "-1"
        for i in range(N):
            if S > 9:
                ans += '9'
                S -= 9
            else:
                ans += str(S)
                S -= S
        if S != 0:
            return "-1"
        return ans
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N, S = [int(x) for x in input().split()]
        
        ob = Solution()
        print(ob.findLargest(N, S))
# } Driver Code Ends