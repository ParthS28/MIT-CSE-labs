//Design an interface called Series with the following methods 

//Get Next (returns the next number in series) 

//reset(to restart the series) 

//set Start (to set the value from which the series should start) 

// Design a class named By Twos that will implement the methods of the interface Series such that it generates a series of numbers, each two greater than the previous one. 
// Also design a class which will include the main method for referencing the interface. 

import java.util.Scanner;

interface Series{
	int get_next();
	void reset();
	void set_start(int start);
}

class ByTwos implements Series{
	int current;

	public int get_next(){
		current += 2;
		return current;
	}

	public void reset(){
		current = 0;
	}

	public void set_start(int n){
		current = n;
	}
}

public class SeriesDemo{
	public static void main(String []args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter start");
		int start = sc.nextInt();
		ByTwos series = new ByTwos();
		series.set_start(start);
		System.out.println("How many values do you want?");
		int n = sc.nextInt();
		for(int i = 0; i < n; i++){
			System.out.print(series.get_next() + " ");
		}
		System.out.println("\n Resetting series");
		series.reset();
		System.out.println("How many values do you want?");
		n = sc.nextInt();
		for(int i = 0; i < n; i++){
			System.out.print(series.get_next() + " ");
		}
		System.out.println("\n");
	}
}