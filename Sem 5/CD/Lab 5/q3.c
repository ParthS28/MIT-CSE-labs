/*
S -> aAcBe
A -> Ab | b
B -> d

After eliminating left recursion,
S -> aAcBe
A -> bA’ 
A’ -> bA’ | E
B -> d
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cur = 0;
char s[1000];

void S();
void A();
void Aprime();
void B();

void invalid(){
	printf("------------------ERROR!------------------\n");
	exit(0);
}

void valid(){
	printf("------------------SUCCESS!------------------\n");
	exit(0);
}

void S(){
    if(s[cur] == 'a'){
        cur++;
        A();
        if(s[cur] == 'c'){
            cur++;
            B();
            if(s[cur] == 'e'){
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
    else{
        invalid();
    }
}

void A(){
    if(s[cur] == 'b'){
        cur++; 
        Aprime();
    }
    else{
        invalid();
    }
}

void Aprime(){
    if(s[cur] == 'b'){
        cur++; 
        Aprime();
    }
}

void B(){
    if(s[cur] == 'd'){
        cur++;
        return;
    }
    else{
        invalid();
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