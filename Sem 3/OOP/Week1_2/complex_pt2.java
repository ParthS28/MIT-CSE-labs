// Consider the already defined Complex class. Provide a default constructor and parameterized constructor to this class. Also provide a display method. Illustrate all the constructors as well as the display method by defining Complex objects. 

import java.util.Scanner;
import java.lang.Math;

class Complex{
	int real, imaginary;

	Complex(){
		System.out.println("default constructor");
		real = 0;
		imaginary = 0;
	}
	Complex(int a, int b){
		System.out.println("parameterised with values constructor");
		real = a;
		imaginary = b;
	}
	Complex(Complex x){
		System.out.println("parameterised with object constructor");
		real = x.real;
		imaginary = x.imaginary;
	}

	void display(){
		System.out.println(real + " + i" + imaginary);
	}

	public static void main(String []args){
		Scanner sc = new Scanner(System.in);

		System.out.println("Default");
		Complex num = new Complex();
		num.display();

		System.out.println("Enter real and imaginary parts: ");
		int r = sc.nextInt();
		int i = sc.nextInt();
		Complex num1 = new Complex(r, i);
		num1.display();

		System.out.println("Change values of complex number");
		r = sc.nextInt();
		i = sc.nextInt();
		num1.real = r;
		num1.imaginary = i;
		System.out.println("Now let's create a new object using an old object with new values");
		Complex num2 = new Complex(num1);
		num2.display();
	}
		
}