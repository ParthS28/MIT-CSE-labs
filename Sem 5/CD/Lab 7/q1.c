/*
start->SUBTRACT idnum from-clause
idnum->term, idnum | term
term->id|num
from-clause->FROM identifiers
identifiers->id,identifiers|id
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char s[2048];
int cur = 0;

void valid(){
    printf("success\n");
    exit(0);
}
void invalid(){
    printf("%c\n%d\n", s[cur], cur);
    printf("invalid\n");
    exit(0);
}

void start();
void idnum();
void idnum_prime();
void term();
void fromclause();
void identifiers();
void identifiers_prime();

void start(){
    if(s[cur] == 'S'){
        cur++;
        if(s[cur] == 'U'){
            cur++;
            if(s[cur] == 'B'){
                cur++;
                if(s[cur] == 'T'){
                    cur++;
                    if(s[cur] == 'R'){
                        cur++;
                        if(s[cur] == 'A'){
                            cur++;
                            if(s[cur] == 'C'){
                                cur++;
                                if(s[cur] == 'T'){
                                    cur++;
                                    while(s[cur] == ' '){
                                        cur++;
                                    }
                                    idnum();
                                    while(s[cur] == ' '){
                                        cur++;
                                    }
                                    fromclause();
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
        else{
            invalid();
        }
    }
    else{
        invalid();
    }
}
    

void idnum(){
    term();
    idnum_prime();
}

void idnum_prime(){
    if(s[cur] == ','){
        cur++;
        while(s[cur] == ' '){
            cur++;
        }
        idnum();
    }
    else{
        return;
    }
}

void term(){
    while(isalnum(s[cur])){
        cur++;
    }
}

void fromclause(){
    if(s[cur] == 'F'){
        cur++;
        if(s[cur] == 'R'){
            cur++;
            if(s[cur] == 'O'){
                cur++;
                if(s[cur] == 'M'){
                    cur++;
                    while(s[cur] == ' '){
                        cur++;
                    }
                    identifiers();
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
    else{
        invalid();
    }
}

void identifiers(){
    while(isalnum(s[cur])){
        cur++;
    }
    while(s[cur] == ' '){
        cur++;
    }
    identifiers_prime();
}

void identifiers_prime(){
    if(s[cur] == ','){
        cur++;
        while(s[cur] == ' '){
            cur++;
        }
        identifiers();
    }
    else{
        return;
    }
}


int main(){
    FILE *f;
    f = fopen("input.txt", "r");
    char buf[2048];
    fgets(buf, 2048, f);
    printf("%s\n", buf);
    strcpy(s, buf);
    start();
    if(s[cur] == '$')
        valid();
    else
        invalid();
}