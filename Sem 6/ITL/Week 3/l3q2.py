f1=open("reverse.txt","w")
with open("orig.txt","r") as f2:
    data= f2.read()
    
print(data[::-1]) 
data1 = data[::-1]
f1.write(data1)
f2.close()
f1.close()

