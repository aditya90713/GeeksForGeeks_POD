# Aditya Gaikwad

#User function Template for python3

class Solution:
    def isLucky(self, n): 
        #RETURN True OR False
        
        for i in range(2,n+1):
            if i<=n:
                if n%i == 0:
                    return 0
            n-=n//i
        return 1
            
        
        
        #User function Template for python3

# class Solution:
#     def isLucky(self, n):
#         i=2
#         while i<=n:
#             if n%i==0:
#                 return 0
#             n-=n//i
#             i+=1
#         return 1
        
        
        #RETURN True OR False

        
        
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB

if __name__ == '__main__':
    t=int(input())
    
    for tcs in range(t):
        n=int(input())
        obj = Solution()
        if obj.isLucky(n):
            print(1)
        else:
            print(0)
        
# } Driver Code Ends