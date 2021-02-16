// Write and execute a java program to create and initialize a matrix of integers. 
// Create n threads( by implementing Runnable interface) where n is equal to the number of rows in the matrix. 
// Each of these threads should compute a distinct row sum. 
// The main thread computes the complete sum by looking into the partial sums given by  the threads. 

import java.util.Scanner;

class Matrix{
	int a[][];
	Matrix(int r, int c){
		a = new int[r][c];
	}

	int[] getRow(int r){
		int arr[] = new int[a[r].length];
		for(int i = 0; i < a[r].length; i++)
			arr[i] = a[r][i];
		return arr;
	}
	void input(int r, int c){
		System.out.println("Enter elements");
		Scanner sc = new Scanner(System.in);
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				a[i][j] = sc.nextInt();
			}
		}
	}
}

class RowSum implements Runnable{
	int a[];
	int sum;

	RowSum(int arr[]){
		a = arr;
		sum = 0;
	}

	public int getSum(){
		return sum;
	}

	public void run(){
		for(int i = 0; i < a.length; i++){
			sum += a[i];
		}
	}
}

class SumTest{
	public static void main(String []args){
		Scanner sc = new Scanner(System.in);
		int r, c;
		System.out.println("Enter rows and columns");
		r = sc.nextInt();
		c = sc.nextInt();
		Matrix mat = new Matrix(r, c);
		mat.input(r, c);

		Thread threads[] = new Thread[r];
		RowSum rowsum[] = new RowSum[r];
		for(int i=0; i<r; i++){ 
			rowsum[i] = new RowSum(mat.getRow(i));
			threads[i] = new Thread(rowsum[i]); 
			threads[i].start();
		}
		int sum = 0;
	
		try{
			for(int i=0; i<r; i++){
				threads[i].join();
				sum += rowsum[i].getSum();
			}
		}
		catch(InterruptedException e){
			e.printStackTrace();
		}
		System.out.println("Sum = " + sum);
	}
}