/*S -> (L) | a
L -> L,S | S

After removing left recursion,

S -> (L) | a
L -> SL’
L’ -> ,SL’ | E
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cur = 0;
char s[1000];

void S();
void L();
void Lprime();

void invalid(){
	printf("------------------ERROR!------------------\n");
	exit(0);
}

void valid(){
	printf("------------------SUCCESS!------------------\n");
	exit(0);
}

void S(){
    if(s[cur] == '('){
        cur++;
        L();
        if(s[cur] == ')'){
            cur++;
            return;
        }
        else{
            invalid();
        }
    }
    else if(s[cur] == 'a'){
        cur++;
        return;
    }
    else{
        invalid();
    }
}

void L(){
    S();
    Lprime();
}

void Lprime(){
    if(s[cur] == ','){
        cur++;
        S();
        Lprime();
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