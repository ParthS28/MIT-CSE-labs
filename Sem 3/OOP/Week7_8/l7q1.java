// Write a generic method to exchange the positions of two different elements in an array. 

import java.util.Arrays; 
import java.util.List;

class Generics{
	public static final <T> void swap(T[] a, int i, int j) {
		T t = a[i]; 
		a[i] = a[j];
		a[j] = t;
	}

	public static void main(String[] args){
		String [] a = {"First", "Second"}; 
		System.out.println("Before Swapping");
		System.out.println("a:" + Arrays.toString(a));
		swap(a, 0, 1);
		System.out.println("After Swapping");
		System.out.println("a:" + Arrays.toString(a));
		Integer [] b = {1, 2}; 
		System.out.println("Before Swapping");
		System.out.println("b:" + Arrays.toString(b));
		swap(b, 0, 1);
		System.out.println("After Swapping");
		System.out.println("b:" + Arrays.toString(b));
	}
}