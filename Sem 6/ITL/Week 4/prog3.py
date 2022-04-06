class Solution:
   def pow(self, x, n):
        if x==0 or x==1 or n==1:
            return x 
 
        if x==-1:
            if n%2 ==0:
                return 1
            else:
                return -1
        if n==0:
            return 1
        if n<0:
            return 1/self.pow(x,-n)
        val = self.pow(x,n//2)
        if n%2 ==0:
            return val*val
        return val*val*x

if __name__=='__main__':
    gen = Solution()
    print(gen.pow(-1, 5))
    print(gen.pow(50, 5))
    print(gen.pow(-6, 3))