/*
S -> a | > | (T)
T -> T,S | S

After removing left recursion,

S -> a | > | (T)
T -> ST’
T’ -> ,ST’ | E
*/            

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cur = 0;
char s[1000];

void S();
void T();
void Tprime();

void invalid(){
	printf("----------------ERROR!----------------\n");
	exit(0);
}

void valid(){
	printf("------------------SUCCESS!------------------\n");
	exit(0);
}

void S(){
    if(s[cur] == 'a' || s[cur] == '<'){
        cur++;
        return;
    }
    else if(s[cur] == '('){
        cur++;
        T();
        if(s[cur] == ')'){
            cur++;
            return;
        }
        else{
            invalid();
        }
    }
    else{
        invalid();
    }
}

void T(){
    S();
    Tprime();
}

void Tprime(){
    if(s[cur] == ','){
        cur++;
        S();
        Tprime();
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