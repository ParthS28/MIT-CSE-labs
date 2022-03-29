def add(x,y):
    return x+y

def sub(x,y):
    return x-y

def mul(x,y):
    return x*y

def div(x,y):
    return x/y

print("Calculator options:")
print("1.Addition")
print("2.Subtraction")
print("3.Multiplication")
print("4.Division")

while True:
    opt = input("Enter option:")
    
    if opt in ('1','2','3', '4'):
        n1= float(input("Enter the first number: "))
        n2= float(input("Enter the second number: "))
        
        if opt == '1':
            print(n1, "+", n2, '=' ,add(n1,n2))
            
        elif opt == '2':
            print(n1, "-", n2, '=' ,sub(n1,n2))
            
        elif opt == '3':
            print(n1, "*", n2, '=' ,mul(n1,n2))
            
        elif opt == '4':
            print(n1, "/", n2, '=' ,div(n1,n2))
        break
    else:
        print("Invalid Input")