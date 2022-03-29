
def binary_search(key,array, low, high):
    mid = (high + low) // 2 
    
    if high >= low:
        if (arr[mid] == key):
            return mid
        if (arr[mid] > key):
            return binary_search(key,array,low, mid - 1)
        if (arr[mid] < key):
            return binary_search(key,array,mid + 1, high)
    return - 1    

arr = [24, 213, 344, 410, 215]
x = 344

loc = binary_search(x,arr,0,len(arr)-1)

if loc == -1: 
    print("absent")
else:
    print("location:",loc)




        