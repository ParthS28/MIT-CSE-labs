class GenClass:
    def generate(self, l):
        subs = []
        n = len(l)
        for i in range(2**n):
            temp = []
            for j in range(n):
                if(i & (1<<j)) != 0:
                    temp.append(l[j])
            if(len(temp) > 0):
                subs.append(temp)
        print(subs)

if __name__=='__main__':
    gen = GenClass()
    list = [4, 5, 6]
    gen.generate(list)