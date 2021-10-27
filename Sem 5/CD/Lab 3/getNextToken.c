#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "clean_code.h"
#include "remove_comments.h"
#include "preprocess.h"

#define SIZE 100

char *keywords[] = {"printf", "int", "float", "return", "break", "continue", "if", "else", "for", "while"};
char operators[5] = {'+','-','/','%','*'};
char brackets[6] = {'(',')','{','}','[',']'};

struct token{
	char *token_name;
	int index;
    int row, col;
	char *type;
};


struct token* hashtable[SIZE];
int size = 0;

int hashkey(int key){
    return key % SIZE;
}

int isKeyword(char buf[]){
	for(int i = 0; i< 10; i++){
		if(strcmp(buf,keywords[i]) == 0){
			return 1;
		}
	}
	return 0;
}

int isOperator(char c){
	for(int i = 0;i<5;i++)
		if(operators[i] == c) return 1;
	return 0;
}

int isBracket(char c){
	for(int i = 0;i<6;i++){
		if(brackets[i] == c) return 1;
	}
	return 0;
}

int searchHash(char buf[]){
	int index = hashkey(strlen(buf));
	if(hashtable[index] == NULL)
		return 0;

    for(int i = 0; i < size; i++){
        struct token* cur = hashtable[i];
        if(cur == NULL) continue;
        if(strcmp(cur->token_name, buf) == 0)
            return 1;
    }
	return 0;
}

void insert(char buf[],int row,int col,int type){
    if(type == 1){  // Keyword
        if(searchHash(buf) == 0){
            printf("<%s,%d,%d>\n",buf,row,col);
            int index = hashkey(strlen(buf));
            struct token* temp = (struct token*)malloc(sizeof(struct token));
			char *str = (char *)calloc(strlen(buf)+1,sizeof(char));
            strcpy(str, buf);
            temp->token_name = str;
            temp->row = row;
            temp->col = col;
            temp->index = index;
            temp->type = "KEYWORD";
        }
    }
    else{
        if(searchHash(buf) == 0){
            printf("<%s,%d,%d>\n",buf,row,col);
            int index = hashkey(strlen(buf));
            struct token* temp = (struct token*)malloc(sizeof(struct token));
			char *str = (char *)calloc(strlen(buf)+1,sizeof(char));
            strcpy(str, buf);
            temp->token_name = str;
            temp->row = row;
            temp->col = col;
            temp->index = index;
            temp->type = "IDENTIFIER";
        }
    }

}

int main(){
    /*
    Flow: input_program.c -> cleanOut.c -> remCommentsOut.c -> pre_out.c
    */
    clean_code();
    remCom();
    preprocess();
	for(int i = 0;i<SIZE;i++)
		hashtable[i] = NULL;
	FILE *fin = fopen("pre_out.c","r");
	if(!fin){
		printf("can't find file");
		return 0;
	}
	char buf[100],c=0;
	int i = 0,row = 1,globalcols=1,col;
	while(c!=EOF){
		//keywords & identifiers
		if(isalpha(c) != 0 || c == '_'){
			buf[i++] = c;
			col = globalcols;
			while(isalpha(c) != 0|| c=='_'||isdigit(c)!=0){
				c = fgetc(fin);
				globalcols++;
				if(isalpha(c)!=0 || c == '_'||isdigit(c) != 0)
					buf[i++] =c;
			}
			buf[i] = '\0';
			if(isKeyword(buf) == 1){
				insert(buf,row,col,1);
			}else{
				insert("id",row,col,0);
			}
			i = 0;
			if(c == '\n') row++,globalcols = 1;
			buf[0] = '\0';
		}
		//numbers
		else if(isdigit(c) != 0){
			buf[i++] = c;
			col = globalcols;
			while(isdigit(c)!=0 || c == '.'){
				c = fgetc(fin);
				globalcols++;
				if(isdigit(c) !=0 || c == '.')
					buf[i++] = c;
			}
			buf[i] = '\0';
			insert("num",row,col,0);
			i = 0;
			if(c == '\n') row++,globalcols = 1;
			buf[0] = '\0';
			c = fgetc(fin);
			globalcols++;
		}
		//string literals
		else if(c == '\"'){
			col = globalcols;
			buf[i++] = c;
			c = 0;
			while(c != '\"'){
				c = fgetc(fin);
				globalcols++;
				buf[i++] = c;
			}
			buf[i] = '\0';
			insert(buf,row,col,0);
			buf[0] = '\0';
			i = 0;
			c = fgetc(fin);
			globalcols++;
		}
		else{
			col = globalcols;
			if(c == '='){
				c = fgetc(fin);
				globalcols++;
				if(c == '=')
					insert("==",row,col,1);
				else{
					insert("=",row,col,1);
					fseek(fin,-1,SEEK_CUR);
					globalcols--;
				}
			}
			//relational operators
			if(c == '>' || c == '<' || c == '!'){
				c = fgetc(fin);
				globalcols++;
				if(c == '='){
					char temp[2] = {c,'='};
					insert(temp,row,col,1);
				}
				else{
					char temp[1] = {c};
					insert(temp,row,col,1);
					fseek(fin,-1,SEEK_CUR);
					globalcols--;
				}
			}
			//brackets & arithmetic operators
			if(isOperator(c) == 1 || isBracket(c) == 1){
				char temp[1] = {c};
				insert(temp,row,col,1);
			}	
			if(c == '\n') row++,globalcols=1;
			c = fgetc(fin);
			globalcols++;
		}
	}
	printf("\n");
	return 0;
}