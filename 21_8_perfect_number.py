#User function Template for python3

class Solution:
    def isPerfectNumber(self, N):
        if N <= 1:
            return 0 

        sqrt_N = int(N**0.5)
        divisors_sum = 1
    
        for i in range(2, sqrt_N + 1):
            if N % i == 0:
                divisors_sum += i
                if i != N // i:
                    divisors_sum += N // i
    
        return int(divisors_sum == N)
#User function Template for python3
    
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        
        ob = Solution()
        print(ob.isPerfectNumber(N))
# } Driver Code Ends