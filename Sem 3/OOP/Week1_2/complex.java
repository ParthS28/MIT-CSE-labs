    // Define a class to represent a complex number called Complex. Provide the following methods: 

    // To assign initial values to the Complex object. 

    // To display a complex number in a+ib format. 

    // To add 2 complex numbers. (the return type should be Complex) 

    // To subtract 2 complex numbers

import java.util.Scanner;
import java.lang.Math;

class Complex{
	int real, imaginary;

	Complex(int a, int b){
		real = a;
		imaginary = b;
	}

	void display(){
		System.out.println(real + " + i" + imaginary);
	}

	Complex add(Complex a){
		Complex sum = new Complex(0, 0);
		sum.real = real + a.real;
		sum.imaginary = imaginary + a.imaginary;
		return sum;
	}

	Complex sub(Complex a){
		Complex diff =  new Complex(0, 0);
		diff.real = Math.abs(real - a.real);
		diff.imaginary = Math.abs(imaginary - a.imaginary);
		return diff;
	}

	public static void main(String []args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter real and imaginary parts: ");
		int r = sc.nextInt();
		int i = sc.nextInt();
		Complex num1 = new Complex(r, i);
		num1.display();

		System.out.println("Enter real and imaginary parts: ");
		r = sc.nextInt();
		i = sc.nextInt();
		Complex num2 = new Complex(r, i);
		num2.display();
		
		System.out.print("Sum = ");
		Complex sum = num1.add(num2);
		sum.display();

		System.out.print("Difference = ");
		Complex diff = num1.sub(num2);
		diff.display();
	}
}