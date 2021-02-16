// Design a stack class. 
// Provide your own stack exceptions namely Push Exception and Pop Exception, 
// which throw exceptions when the stack is full and when the stack is empty respectively. 
// Show the usage of these exceptions in handling a stack object in the main. 

class PushException extends Exception{
	private int code;

	PushException(int c){
		this.code = c; 
	}

	int getCode(){ 
		return code;
	} 
}

class PopException extends Exception{
	private int code;

	PopException(int c){
		this.code = c; 
	}

	int getCode(){ 
		return code;
	} 
}
class Stack{
	char a[];
	int top;
	int size;

	Stack(){
		a = new char[0];
		top = -1;
		size = 0;
	}
	Stack(int s){
		a = new char[s];
		top = -1;
		size = s;
	}

	boolean isEmpty(){
		if(top == -1)
			return true;
		return false;
	}
	boolean isFull(){
		if(top == size-1)
			return true;
		return false;
	}

	boolean push(char c) throws PushException{ 
		if(isFull()){ 
			throw new PushException(1);
		}
		a[++top] = c;
		return (true);
	}
	char pop() throws PopException{
		if(isEmpty()){ 
			throw new PopException(-1);
		}
		return(a[top--]);
	}

	void display(){
		if(isEmpty())
			return;
		System.out.println("Stack: ");
		for(int i = 0; i < top+1; i++)
			System.out.println(a[i]);
	}
}

class Test{
	public static void main(String []args){
		Stack s = new Stack(3);
		s.display();
		System.out.println("Popping an empty stack.");
		try{ 
			char el = s.pop();
			System.out.println("Popped element: " + el);
		}catch(PopException e){
			System.out.print("Caught PopException with code ");
			System.out.println(e.getCode());
		}
		try{ 
			s.push('a');
		}catch(PushException e){
			System.out.print("Caught PushException with code ");
			System.out.println(e.getCode());
		}
		try{ 
			s.push('b');
		}catch(PushException e){
			System.out.print("Caught PushException with code ");
			System.out.println(e.getCode());
		}
		try{ 
			s.push('c');
		}catch(PushException e){
			System.out.print("Caught PushException with code ");
			System.out.println(e.getCode());
		}
		System.out.println("Stack is currently full, push another element will give us an error!");
		try{ 
			s.push('d');
		}catch(PushException e){
			System.out.print("Caught PushException with code ");
			System.out.println(e.getCode());
		}
		s.display();
	}
}