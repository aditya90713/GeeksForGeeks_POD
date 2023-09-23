# User function Template for python3

class Solution:
    # Complete this function
    
    #Function to find equilibrium point in the array.
    def equilibriumPoint(self,a, n):
        # Your code here
        
        if n == 1:
            return 1
        sum_val = sum(a)
        left_sum = 0
        for i in range(1, n - 1):
            left_sum += a[i - 1]
            right_sum = sum_val - a[i] - left_sum
            if left_sum == right_sum:
                return i + 1
        return -1
            



#{ 
 # Driver Code Starts
# Initial Template for Python 3

import math


def main():

    T = int(input())

    while(T > 0):

        N = int(input())

        A = [int(x) for x in input().strip().split()]
        ob=Solution()

        print(ob.equilibriumPoint(A, N))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends