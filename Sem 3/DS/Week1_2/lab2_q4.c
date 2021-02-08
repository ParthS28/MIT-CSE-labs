// Tower of hanoi
#include <stdlib.h>
#include <stdio.h>

int moves = 0;

void tower(int n, char from, char help, char to){
	if(n==1){
		printf("Moving disc from %c to %c\n", from, to); moves++;
		return;
	}
	tower(n-1, from, to, help);
	printf("Moving disc from %c to %c\n", from, to);
	moves++;
	tower(n-1, help, from, to);
	// moves++;
}

int main(){
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	tower(n,'a', 'b', 'c');
	printf("%d\n", moves);
	return 0;
}