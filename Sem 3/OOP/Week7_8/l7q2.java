// Define a simple generic stack class and show the use of the generic class 
// for two different class types Student and Employee class objects. 

import java.lang.reflect.Array;

class PushException extends Exception{
	private int code;

	public PushException(int c){
		this.code = c;
	}
	public int getCode(){ 
		return code;
	}
}

class PopException extends Exception{
	private int code;
	public PopException(int c){
		this.code = c;
	}
	public int getCode(){ 
		return code;
	}
}

class Stack<T>{
	private T item[]; 
	private int top; 
	private int size;
	public Stack(Class<T[]> obj, int length){
		this.size = length;
		this.item = obj.cast(Array.newInstance(obj.getComponentType(), length)); 
		this.top = -1;
	}

	public boolean isEmpty(){
		if(this.top == -1) return (true);
		return (false);
	}

	public boolean isFull(){ 
		if(this.top == this.size -1) 
			return (true);
		return (false);
	}

	public boolean push(T elem) throws PushException{
		if(this.isFull()){ 
			throw new PushException(1);
		}
		this.item[++this.top] = elem;
		return (true); 
	}
	public T pop() throws PopException{
		if(this.isEmpty()){ 
			throw new PopException(-1);
		}

		return(this.item[this.top--]);
	}
	public void display(){
		if(this.isEmpty()) 
			return;
		for(int i = 0; i < this.top + 1; i++){
			System.out.println(this.item[i]); 
		}
		System.out.println("");
	}
}

class Student{
	String name; int reg_no;
	Student(String name, int reg_no){ 
		this.name = name;
		this.reg_no = reg_no;
	}

}
class Employee
{
	String name; 
	int emp_no;
	Employee(String name, int emp_no){ 
		this.name = name; 
		this.emp_no = emp_no;
	}
}

class StackTest{
	public static void main(String[] args) {
		System.out.println("Creating stack object for Student with size 3"); 
		Stack<Student> s1 = new Stack<Student>(Student[].class, 3);
		System.out.println("Creating stack object for Employee with size 3");
		Stack<Employee> s2 = new Stack<Employee>(Employee[].class, 3);
		System.out.println("Displaying student stack"); 
		try{
			System.out.println("Pushing elements to student stack"); 
			s1.push(new Student("Mohan", 123)); 
			s1.push(new Student("Rohan", 456)); 
			s1.push(new Student("Sohan", 789));
			System.out.println("Displaying student stack"); 
			s1.display();
			System.out.println("Pushing elements to employee stack");
			s2.push(new Employee("Ram", 12)); 
			s2.push(new Employee("Shaam", 34)); 
			s2.push(new Employee("Gyaan", 56));
			System.out.println("Displaying employee stack"); 
			s2.display();
		}catch(PushException e){
			System.out.println("Caught exception: " + e); 
		} // no exceptions caught

		try{
			System.out.println("Pushing element to an already filled student stack"); 
			s1.push(new Student("Soham", 967));
			System.out.println("Displaying student stack"); 
			s1.display();
		}catch(PushException e){
			System.out.println("Caught exception: " + e); 
		}
	}
}