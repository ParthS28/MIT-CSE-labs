#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct token
{
    char* token_name;
    unsigned int row, col;
    int index;
    char* type;
};

static int row = 1, col = 1;
char buf[2048];
char specialSymbols[] = {'?', ';', ':', ',', '.'};
char *keywords[] = {"const", "bool", "char", "short", "int", "float", "double", "unsigned", "return", "for", "while", "do", "switch", "if", "else", "case", "break", "printf", "continue", "struct", "void", "sizeof"};
char arithmeticSymbols[] = {'*', '%'};

int isKeyword(char *s)
{
	for(int i = 0; i < sizeof(keywords)/sizeof(char); i++)
	{
		if(strcmp(s, keywords[i]) == 0)
			return 1;
	}
	return 0;
}

int charBelongsTo(int c, char *strArr)
{
	int len;
	if(strArr == specialSymbols)
		len = sizeof(specialSymbols)/sizeof(char);
	else if(strArr == arithmeticSymbols)
		len = sizeof(arithmeticSymbols)/sizeof(char);

	for(int i = 0; i < len; i++)
	{
		if(c == strArr[i])
			return 1;
	}
	return 0;
}

void fillToken(struct token *tok, char c, int row, int col)
{
	tok->row = row;
	tok->col = col;
	tok->lexeme[0] = c;
	tok->lexeme[1] = '\0';
}

void newLine()
{
	row++;
	col = 1;
}

struct token getNextToken(FILE *f)
{
	int c;
	struct token tok = { .row = -1};
	int gotToken = 0;

	while(!gotToken && (c = fgetc(f)) != EOF)
	{
		if(charBelongsTo(c, specialSymbols) || charBelongsTo(c, arithmeticSymbols))
		{
			fillToken(&tok, c, row, col);
			gotToken = 1;
			col++;
		}
		else if(c == '(')
		{
			fillToken(&tok, c, row, col);
			gotToken = 1;
			col++;
		}
		else if(c == ')')
		{
			fillToken(&tok, c, row, col);
			gotToken = 1;
			col++;
		}
		else if(c == '{')
		{
			fillToken(&tok, c, row, col);
			gotToken = 1;
			col++;
		}
		else if(c == '}')
		{
			fillToken(&tok, c, row, col);
			gotToken = 1;
			col++;
		}
		else if(c == '+')
		{
			int d = fgetc(f);
			if (d != '+')
            {
                fillToken(&tok, c, row, col);
                gotToken = 1;
                ++col;
                fseek(f, -1, SEEK_CUR);
            }
            else
            {
                fillToken(&tok, c, row, col);
                strcpy(tok.lexeme, "++");
                gotToken = 1;
                col += 2;
            }
		}
		else if (c == '-')
        {
            int d = fgetc(f);
            if (d != '-')
            {
                fillToken(&tok, c, row, col);
                gotToken = 1;
                ++col;
                fseek(f, -1, SEEK_CUR);
            }
            else
            {
                fillToken(&tok, c, row, col);
                strcpy(tok.lexeme, "--");
                gotToken = 1;
                col += 2;
            }
        }
        else if (c == '=')
        {
            int d = fgetc(f);
            if (d != '=')
            {
                fillToken(&tok, c, row, col);
                gotToken = 1;
                ++col;
                fseek(f, -1, SEEK_CUR);
            }
            else
            {
                fillToken(&tok, c, row, col);
                strcpy(tok.lexeme, "==");
                gotToken = 1;
                col += 2;
            }
        }
        else if (isdigit(c))
        {
            tok.row = row;
            tok.col = col++;
            tok.lexeme[0] = c;
            int k = 1;
            while ((c = fgetc(f)) != EOF && isdigit(c))
            {
                tok.lexeme[k++] = c;
                col++;
            }
            tok.lexeme[k] = '\0';
            gotToken = 1;
            fseek(f, -1, SEEK_CUR);
        }
        else if (c == '#')
        {
            while ((c = fgetc(f)) != EOF && c != '\n')
                ;
            newLine();
        }
        else if (isspace(c))
            ++col;
        else if (isalpha(c) || c == '_')
        {
            tok.row = row;
            tok.col = col++;
            tok.lexeme[0] = c;
            int k = 1;
            while ((c = fgetc(f)) != EOF && isalnum(c))
            {
                tok.lexeme[k++] = c;
                ++col;
            }
            tok.lexeme[k] = '\0';
            gotToken = 1;
            fseek(f, -1, SEEK_CUR);
        }
        else if (c == '"')
        {
            tok.row = row;
            tok.col = col;
            int k = 1;
            tok.lexeme[0] = '"';
            while ((c = fgetc(f)) != EOF && c != '"')
            {
                tok.lexeme[k++] = c;
                ++col;
            }
            tok.lexeme[k] = '"';
            gotToken = 1;
        }
        else if (c == '&' || c == '|')
        {
            int d = fgetc(f);
            if (c == d)
            {
                tok.lexeme[0] = tok.lexeme[1] = c;
                tok.lexeme[2] = '\0';
                tok.row = row;
                tok.col = col;
                ++col;
                gotToken = 1;
            }
            else
            {
                tok.lexeme[0] = c;
                tok.lexeme[1] = '\0';
                tok.row = row;
                tok.col = col;
                ++col;
                gotToken = 1;
                fseek(f, -1, SEEK_CUR);
            }
            ++col;
        }
        else
            ++col;
    }
    return tok;
}

int main()
{
	FILE *fin = fopen("input_program.c", "r");
	FILE *fo = fopen("output.c", "w+");
	if (!fin)
	{
	printf("Error! File cannot be opened!\n");
	return 0;
	}
    struct token t;
    while ((t = getNextToken(fin)).row != -1)
		fprintf(fo, "<%s, %d, %d>\n", t.lexeme, t.row, t.col);
	fclose(fin);
}

