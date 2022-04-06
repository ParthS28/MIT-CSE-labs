class Solution:
    def findPair(self, l, key):
        map = {}
        for i in range(len(l)):
            if(key - l[i] in map):
                return [map[key-l[i]], i]
            map[l[i]] = i
        return [-1, -1]  #no solution

if __name__=='__main__':
    gen = Solution()
    list = [10,20,10,40,50,60,70]
    print(gen.findPair(list, 50))