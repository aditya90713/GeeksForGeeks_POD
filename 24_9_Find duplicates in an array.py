class Solution:
    def duplicates(self, arr, n):

    	# code here
    	
    	ans = []
    	
    	fre = [0]*n
        for i in range(n):
            fre[arr[i]] +=1
            
        for i in range(n):
            if fre[i]>1:
                ans.append(i)
                
        if not ans:
            ans.append(-1)
        
        return ans


#{ 
 # Driver Code Starts
if(__name__=='__main__'):
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        res = Solution().duplicates(arr, n)
        for i in res:
            print(i,end=" ")
        print()



# } Driver Code Ends