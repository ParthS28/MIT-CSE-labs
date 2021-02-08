// Write C programs using recursion to check whether a given String is Palindrome or no
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int palindrome_check(char s[20], int left, int right){
	if(right-left == 1 || left==right){  // base condition
		return 1;
	}
	else{
		if(s[left] == s[right])
			return palindrome_check(s, left+1, right-1);
		else
			return 0;
	}
}

int main(){
	char s[20];
	scanf("%s", s);
	

	int n = strlen(s);
	if(palindrome_check(s, 0, n-1))
   {
       printf("Palindrome\n");
   }
   else
   {
       printf("Not a palindrome\n");
   }
   return 0;
}