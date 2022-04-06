# class StringClass:
#     def __init__(self):
#         self.str1 = ""
 
#     def get_String(self):
#         self.str1 = input("Enter a string\n")
 
#     def print_String(self):
#         print(self.str1.upper())

# if __name__=="__main__":
#     strobj = StringClass()
#     strobj.get_String()
#     strobj.print_String()

class StringClass:
    def __init__(self):
        self.str1 = ""
    @property
    def string(self):
        print('getter')
        return self.str1.upper()
    @string.setter
    def string(self, s):
        print('setter')
        self.str1 = s

    def get_String(self):
        self.str1 = input("Enter a string\n")
 
    def print_String(self):
        print(self.str1.upper())

if __name__=="__main__":
    strobj = StringClass()
    # s = input("Enter a string\n")
    # strobj.string = s
    # print(strobj.string)
    strobj.get_String()
    strobj.print_String()