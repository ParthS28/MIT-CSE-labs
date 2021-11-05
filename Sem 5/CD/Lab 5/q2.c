/*
S->UVW
U->(S) | aSb | d
V -> aV | empty
W -> cW | empty
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cur = 0;
char s[1000];

void invalid(){
	printf("------------------ERROR!------------------\n");
	exit(0);
}

void valid(){
	printf("------------------SUCCESS!------------------\n");
	exit(0);
}

void S();
void U();
void V();
void W();

void S(){
	U();
	V();
	W();
}
void U(){
	if(s[cur] == '('){
		cur++;
		S();
		if(s[cur] == ')'){
			cur++;
			return;
		}
		else invalid();
	}
	else if(s[cur] == 'd'){
		cur++;
		return;
	}
	else if(s[cur] == 'a'){
		cur++;
		S();
		if(s[cur] == 'b'){
			cur++;
			return;
		}
		else invalid();
	}
	else invalid();
}

void V(){
	if(s[cur] == 'a'){
		cur++;
		V();
	}
}

void W(){
	if(s[cur] == 'c'){
		cur++;
		W();
	}
}

void main(){
	printf("Enter string:\n");
	scanf("%s",s);
	S();
	if(s[cur] == '$')
		valid();
	else
		invalid();
}