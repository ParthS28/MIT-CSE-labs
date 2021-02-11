// Create a class called Counter that contains a static data member to count the number of Counter objects being created.
// Also define a static member function called showCount() which displays the number of objects created at any given point of time. Illustrate this. 

import java.util.Scanner;
import java.lang.Math;

class Counter{
	static int count;

	Counter(){
		increment();
	}

	public static void increment(){
		count += 1;
	}

	public static void showCount(){
		System.out.println("The count is at " + count);
	}

	public static void main(String []args){
		Counter c1 = new Counter();
		c1.showCount();
		Counter c2 = new Counter();
		c2.showCount();
		Counter c3 = new Counter();
		c3.showCount();
	}
}