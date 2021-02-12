// max (which finds maximum among three integers and returns the maximum integer) 

// max (which finds maximum among three floating point numbers and returns the maximum among them) 

// max (which finds the maximum in an array and returns it) 

// max (which finds the maximum in a matrix and returns the result) 

// Place this in a package called p1. Let this package be present in a folder called “myPackages”,   which   is   a   folder   in   your    present    working    directory  (eg: c\student\3rdsem \mypackages\p1). Write a main method to use the methods of Max class in a package p1. 

package myPackages.p1;

public class Maximum{
	public static int max(int a, int b, int c){
		return (a>b) ? ((a>c) ? a : c) : ((b>c) ? b : c);
	}

	public static float max(float a, float b, float c){
		return (a>b) ? ((a>c) ? a : c) : ((b>c) ? b : c);
	}	

	public static int max(int[] arr){
		int max = arr[0];
		for(int i = 0; i < arr.length; i++){
			if(arr[i] > max){
				max = arr[i];
			}
		}
		return max;
	}

	public static int max(int[][] arr, int r, int c){
		int max = arr[0][0];
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(arr[i][j] > max){
					max = arr[i][j];
				}
			}
		}
		return max;
	}
}