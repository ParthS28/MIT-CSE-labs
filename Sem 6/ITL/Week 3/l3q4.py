def alsort(l):
    for i in range(len(l)-1):
        for j in range(i+1,len(l)):
            if l[i]>l[j]:
                # temp = l[i]
                # l[i]=l[j]
                # l[j]=temp
                l[i], l[j] = l[j], l[i]
                
                
l = ["afsd", "adfsas", "gadgf", "adsf", "grefasd"] 
alsort(l)
print(l)