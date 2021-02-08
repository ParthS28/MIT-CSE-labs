// WriteC programsusing recursionto copyone stringto another using Recursion. 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void copy(char s1[100], char s2[100], int cur, int n){
	if(cur==n){   // base condition
		return;
	}
	else{
		s2[cur] = s1[cur];
		copy(s1, s2, ++cur, n);
	}
}

int main(){
	char s[100];
	scanf("%s", s);
	char s_copy[100];
	int n = strlen(s);
	copy(s, s_copy, 0, n);
	printf("Copied string: %s\n", s_copy);
}