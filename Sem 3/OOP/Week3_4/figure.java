    // Create an abstract class Figure with abstract method area and two integer dimensions. 
    // Create three more classes Rectangle, Triangle and Square which extend Figure and implement the area method. 
    // Show how the area can be computed dynamically during run time for Rectangle, Square and Triangle to achieve dynamic polymorphism. 
    // Use the reference of Figure class to call the three different area methods) 

import java.util.Scanner;

abstract class Figure{
	int dim1, dim2;
	Figure(int d1, int d2){
		dim1 = d1;
		dim2 = d2;
	}
	abstract void area();
}

class Rectangle extends Figure{
	Rectangle(int l, int b){
		super(l, b);
	}
	void area() {
		System.out.println("Area of rectangle is: " + super.dim1 * super.dim2); 
	}
}

class Square extends Figure{
	Square(int s1){
		super(s1, s1);
	}
	void area() {
		System.out.println("Area of square is: " + super.dim1 * super.dim2); 
	}	
}

class Triangle extends Figure{
	Triangle(int b, int h){
		super(b, h);
	}
	void area() {
		System.out.println("Area of rectangle is: " + (super.dim1 * super.dim2) / 2); 
	}
}

class AbstractDemo{
	public static void main(String []args) {
		Scanner sc = new Scanner(System.in);
		int a, b;

		Figure fig;

		System.out.println("\nEnter dimensions for rectangle");
		a = sc.nextInt();
		b = sc.nextInt();
		fig = new Rectangle(a, b);
		fig.area();

		System.out.println("\nEnter dimensions for square: ");
		a = sc.nextInt();
		fig = new Square(a);
		fig.area();

		System.out.println("\nEnter dimensions for triangle: ");
		System.out.print("Enter height and base: ");
		a = sc.nextInt();
		b = sc.nextInt();
		fig = new Triangle(a, b);
		fig.area();
	}
}