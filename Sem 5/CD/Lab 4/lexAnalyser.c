// Using getNextToken( ) implemented in Lab No 3,design a Lexical Analyser to 
// implement  local  and  global  symbol  table  to  store  tokens  for  identifiers  using 
// array of structure.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "clean.h"
#include "preprocesses.h"
#define MAX_SIZE 30

char keywords[33][10] = {"auto", "double", "int", "struct", "break", "else",
"long", "switch", "case", "enum", "register", "typedef", "char", "extern",
"return", "union", "const", "float", "short", "default", "unsigned", "continue",
"for", "signed", "void", "goto", "sizeof", "voltile", "do", "if", "static", "while"
};

char dataTypes[][10] = {
	"double",
	"int",
	"float",
	"char"
};

char operators[5]={'-','%','+','*','/'};

char brackets[6] = {'(',')','{','}','[',']'};

char specialSymbols[12] = {
	'*',
	'<',
	'>',
	';',
	'.',
	',',
	'~',
	'`',
	':',
	'^',
	'&',
	'!'
};

enum TYPE{
	IDENTIFIER,
	STRING_LITERAL,
	KEYWORD,
	NUMERIC_CONSTANT,
	BRACKET,
	OPERATOR,
	SPECIAL_SYMBOL,
	RELATIONAL_OPERATOR,
	CHARACTER_CONSTANT
};

char types[][30] = {
	"IDENTIFIER",
	"STRING_LITERAL",
	"KEYWORD",
	"NUMERIC_CONSTANT",
	"BRACKET",
	"OPERATOR",
	"SPECIAL_SYMBOL",
	"RELATIONAL_OPERATOR",
	"CHARACTER_CONSTANT"
};

typedef struct node{
	char *cur;
	int row,col;
	struct node *next;
	enum TYPE type;
}*node;

typedef struct symbol{
	char *name;
	char *dataType;
	struct symbol *next;
	unsigned int size;
}*symbol;

node hashTable[MAX_SIZE];
symbol symTable[MAX_SIZE];

void init(){
	for(int i = 0;i<MAX_SIZE;i++){
		hashTable[i] = NULL;
	}
}

int isKeyword(char buf[]){
	for(int i =0;i<32;i++){
		if(strcmp(buf,keywords[i]) == 0)
			return 1;
	}
	return 0;
}

int isDataType(char buf[]){
	for(int i = 0;i<4;i++){
		if(strcmp(buf,dataTypes[i]) == 0)
			return 1;
	}
	return 0;
}

int isOperator(char c){
	for(int i = 0;i<5;i++){
		if(operators[i] == c)
			return 1;
	}
	return 0;
}

int isSpecialChar(char c){
	for(int i = 0;i<12;i++){
		if(specialSymbols[i] == c)
			return 1;
	}
	return 0;
}

int isBracket(char c){
	for(int i = 0;i<6;i++){
		if(brackets[i] == c){
			return 1;
		}
	}
	return 0;
}

int hashing(char* s){
	int sum = 0;
	for(int i = 0; i < strlen(s); i++){
		sum += (int)s[i];
	}
	return (sum)%MAX_SIZE;
}

void displaySymbolTable(){
	printf("\tName\t|\tType\t|\tSize\t\n\n");
	
	for(int i = 0;i<MAX_SIZE;i++){
		if(symTable[i] == NULL)
			continue;
		else{
			symbol cur = symTable[i];
			while(cur){
				printf("%10s\t|%10s\t|%10d\t\n",cur->name,cur->dataType,cur->size);
				cur = cur->next;
			}
		}
	}
}

int searchSymTable(char id[]){
	int index = hashing(id);

	if(symTable[index] == NULL)
		return -1;
	symbol cur = symTable[index];
	int i = 0;
	while(cur != NULL){
		if(strcmp(id,cur->name) == 0){
			return i;
		}
		cur = cur->next;
		i++;
	}
	return -1;
}

int searchHashTable(char buf[]){
	int index = hashing(buf);
	if(hashTable[index] == NULL)
		return 0;
	node cur= hashTable[index];
	while(cur != NULL){
		if(strcmp(cur->cur,buf) == 0)
			return 1;
		cur = cur->next;
	}
	return 0 ;
}

void insertSym(char id[],char dataType[]){
	if(searchSymTable(id)==-1){
		symbol s = (symbol)malloc(sizeof(struct symbol));
		char *str = (char*)calloc(strlen(id)+1,sizeof(char));
		strcpy(str,id);
		s->name = str;
		s->next = NULL;
		char *type = (char*)calloc(strlen(dataType)+1,sizeof(char));
		strcpy(type,dataType);
		s->dataType = type;
		if(strcmp(dataType,"int") == 0)
			s->size = 4;
		else if(strcmp(dataType,"double") == 0)
			s->size = 8;
		else if(strcmp(dataType,"char") == 0)
			s->size = 1;
		else if(strcmp(dataType,"function") == 0)
			s->size = 0;
		else 
			s->size = 4;

		int index = hashing(id);
		if(symTable[index] == NULL){
			symTable[index] = s;
			return;
		}
		symbol cur = symTable[index];
		while(cur->next !=NULL)
			cur = cur->next;
		cur ->next = s;
		return;
	}
}

void insertHash(char buf[],int row,int col,enum TYPE type){
	if(type == IDENTIFIER || searchHashTable(buf) == 0){
		printf("<%s | %d | %d | %s >\n",buf,row,col,types[type]);
		int index = hashing(buf);
		node n = (node)malloc(sizeof(struct node));
		char *str = (char *)calloc(strlen(buf) +1,sizeof(char));
		strcpy(str,buf);
		n->cur = str;
		n->next = NULL;
		n->row =row;
		n->col = col;
		n->type = type;
		if(hashTable[index] == NULL){
			hashTable[index] = n;
			return;
		}
		node cur = hashTable[index];
		while(cur->next != NULL){
			cur = cur->next;
		}
		cur->next = n;
		return;
	}
}

int main(){
	removeSpaceComment();
	int row = removePreprocess();
	init();


	enum TYPE type;
	
	FILE *fin = fopen("pre_out.c","r");
	
	if(!fin){
		printf("can't open file\n");
		exit(0);
	}
	
	char buf[100],dataTypeBuf[100],c = 0;
	int i =0,globalCol=1,col,tempRow = row;
	

	while(c != EOF){
		if(isalpha(c) != 0||c == '_'){
			buf[i++] = c;
			col = globalCol;
			while(isalpha(c) != 0 || c =='_' || isdigit(c) != 0){
				c = fgetc(fin);
				globalCol++;
				if(isalpha(c)!= 0 || c=='_'||isdigit(c) != 0)
					buf[i++] = c;
			}
			buf[i] = '\0';
			if(isDataType(buf) == 1){
				insertHash(buf,row,col-1,KEYWORD);
				strcpy(dataTypeBuf,buf);
			}
			else if(isKeyword(buf) == 1){
				insertHash(buf,row,col-1,KEYWORD);
			}
			else{
				insertHash(buf,row,col-1,IDENTIFIER);
				if(c == '(')
					insertSym(buf,"function");
				else
					insertSym(buf,dataTypeBuf);
				dataTypeBuf[0] = '\0';
			}
			i = 0;
			if(c == '\n')
				row++,globalCol=1;
			buf[0] = '\0';
		}
		else if(isdigit(c) != 0){
			buf[i++] = c;
			col = globalCol;
			while(isdigit(c) != 0 || c=='.'){
				c = fgetc(fin);
				globalCol++;
				if(isdigit(c) != 0||c == '.')
					buf[i++] = c;
			}
			buf[i] = '\0';
			insertHash(buf,row,col-1,NUMERIC_CONSTANT);
			i = 0;
			if(c == '\n')
				row++,globalCol=1;
			buf[0] = '\0';
		}
		else if(c == '\"'){
			col = globalCol;
			buf[i++] = c;
			c = 0;
			while(c != '\"'){
				c = fgetc(fin);
				globalCol++;
				buf[i++] = c;
			}
			buf[i] = '\0';
			insertHash(buf,row,col-1,STRING_LITERAL);
			buf[0] = '\0';
			i = 0;
			c = fgetc(fin);
			globalCol++;
		}
		else if(c == '\''){
			col = globalCol;
			buf[i++] = c;
			c = fgetc(fin);
			globalCol++;
			buf[i++] = c;
			if(c=='\\'){
				c = fgetc(fin);
				globalCol++;
				buf[i++] =c ;
			}
			c = fgetc(fin);
			globalCol++;
			buf[i++] = c;
			buf[i] = '\0';
			insertHash(buf,row,col-1,CHARACTER_CONSTANT);
			buf[0] = '\0';
			i = 0;
			c = fgetc(fin);
			globalCol++;
		}
		else{
			col = globalCol;
			if(c == '='){
				c = fgetc(fin);
				globalCol++;
				if(c == '='){
					insertHash("==",row,col-1,RELATIONAL_OPERATOR);
				}
				else{
					insertHash("=",row,col-1,RELATIONAL_OPERATOR);
					fseek(fin,-1,SEEK_CUR);
					globalCol--;
				}
			}
			else if(c == '<' || c == '>' || c == '!'){
				char temp = c;
				c = fgetc(fin);
				globalCol++;
				if(c == '='){
					char tempStr[3] = {temp,'=','\0'};
					insertHash(tempStr,row,col-1,RELATIONAL_OPERATOR);

				}
				else{
					char tempStr[2] = {temp,'\0'};
					insertHash(tempStr,row,col-1,RELATIONAL_OPERATOR);
					fseek(fin,-1,SEEK_CUR);
					globalCol--;
				}
			}
			else if(isBracket(c) == 1){
				char tempStr[2] = {c,'\0'};
				insertHash(tempStr,row,col-1,BRACKET);
			}
			else if(isSpecialChar(c) == 1){
				char tempStr[2] = {c,'\0'};
				insertHash(tempStr,row,col-1,SPECIAL_SYMBOL);
			}
			else if(isOperator(c) == 1){
				char temp = c;
				c = fgetc(fin);
				globalCol++;
				if(c == '=' || (temp == '+' && c == '+')||(temp == '-' &&  c == '-'))
				{
					char tempStr[3] = {temp,c,'\0'};
					insertHash(tempStr,row,col-1,OPERATOR);
				}
				else{
					char tempStr[2] = {temp,'\0'};
					insertHash(tempStr,row,col-1,OPERATOR);
					fseek(fin,-1,SEEK_CUR);
					globalCol--;
				}
			}
			else if(c=='\n'){
				row++;
				globalCol =1;
			}
			c = fgetc(fin);
			globalCol++;
		}
	}
	printf("\nSymbol Table:\n\n");
	displaySymbolTable();
	return 0;
}
