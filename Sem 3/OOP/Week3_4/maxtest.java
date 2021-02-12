// To test the package

import java.util.Scanner;
import myPackages.p1.Maximum;

class MaxTest{
	public static void main(String []args){
		Scanner sc = new Scanner(System.in);
		int a, b, c;
		System.out.println("Enter 3 integers");
		a = sc.nextInt();
		b = sc.nextInt();
		c = sc.nextInt();
		System.out.println("Maximum = " + Maximum.max(a, b, c));

		float d, e, f;
		System.out.println("Enter 3 floats");
		d = sc.nextFloat();
		e = sc.nextFloat();
		f = sc.nextFloat();
		System.out.println("Maximum = " + Maximum.max(d, e, f));
		System.out.println("Enter 5 nos");
		int arr[] = new int[5];
		for(int i = 0; i < 5; i++)
			arr[i] = sc.nextInt();
		System.out.println("Maximum = " + Maximum.max(arr));
		System.out.println("Enter 3x3 matrix");
		int mat[][] = new int[3][3];
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				mat[i][j] = sc.nextInt();
		System.out.println("Maximum = " + Maximum.max(mat, 3, 3));
	}
}