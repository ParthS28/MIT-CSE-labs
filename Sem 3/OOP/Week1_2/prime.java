// a. Write a method isPrime to accept one integer parameter and  to check whether  that parameter is prime or not. 

// b. Using this method, generate first N prime numbers in the main method. 
import java.util.Scanner;

class Prime{
	boolean isPrime(int n){
		for(int i = 2; i < n; i++){
			if(n % i == 0)
				return false;
		}
		return true;
	}

	public static void main(String []args){
		Prime p = new Prime();
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i = 1; i <= n; i++){
			if(p.isPrime(i))
				System.out.println(i);
		}
	}
}