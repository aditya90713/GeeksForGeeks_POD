#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

class Solution:
    def maxCombinations(self, N, K, A, B):
        # Code here
        ans = []
        A.sort()
        B.sort()
        pq = []
        s = set()
        heapq.heappush(pq, (A[-1] + B[-1], (N - 1, N - 1)))
        s.add((N - 1, N - 1))
 
        while K > 0:
            p = heapq.heappop(pq)
            sum_val, (i, j) = p
            ans.append(sum_val)
 
            if (i - 1, j) not in s:
                heapq.heappush(pq, (A[i - 1] + B[j], (i - 1, j)))
                s.add((i - 1, j))
 
            if (i, j - 1) not in s:
                heapq.heappush(pq, (A[i] + B[j - 1], (i, j - 1)))
                s.add((i, j - 1))
 
            K -= 1
 
        return ans

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        N, K = list(map(int, input().split()))
        A = list(map(int, input().split()))
        B = list(map(int, input().split()))
        ob = Solution()
        res = ob.maxCombinations(N, K, A, B)
        for val in res:
            print(val, end =' ')
        print()
# } Driver Code Ends