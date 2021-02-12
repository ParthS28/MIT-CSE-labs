// Stack operations
# define MAX 10
# define true 1
# define false 0

typedef struct{
	char arr[MAX];
	int top;
}Stack;

void push(Stack *s, char c);
char pop(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void display(Stack *s);

void push(Stack *s, char c){
	if (!isFull(s)){ 
		// s->top++;
		s->arr[s->top++] = c;
	}
}

char pop(Stack *s){
	if(!isEmpty(s)){
		s->top--;
		return s->arr[s->top];
		// return(s->arr[s->top--]);
	}
}

int isEmpty(Stack *s){
	if (s->top==-1)
		return(true);
	else
		return(false);
}

int isFull(Stack *s){
	if(s->top == MAX-1)
		return true;
	return false;
}

void display(Stack *s){
	printf("Stack: \n");
	for(int i = 0; i < s->top; i++){
		printf("%c ", s->arr[i]);
	}
	printf("\n");
}