// Arrange the elements in ascending and descending order using Bubble sort method. 
import java.util.Scanner;
class Bubble{

	void display(int a[]){
		int n = a.length;
		for(int i = 0; i < n; i++){
			System.out.print(a[i] + " ");
		}
		System.out.println();
	}

	void bubblesort(int a[], boolean ascending){
		int n = a.length;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n-1-i; j++){
				if(ascending){
					if(a[j] > a[j+1]){
						int temp = a[j];
						a[j] = a[j+1];
						a[j+1] = temp;
					}
				}
				else{
					if(a[j] < a[j+1]){
						int temp = a[j];
						a[j] = a[j+1];
						a[j+1] = temp;
					}
				}
			}
		}
		display(a);
	}
	public static void main(String []args){
		Bubble b = new Bubble();
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter length and elements");
		int n = sc.nextInt();
		int a[] = new int[n];
		for(int i = 0; i < n; i++)
			a[i] = sc.nextInt();
		System.out.println("Ascending: ");
		b.bubblesort(a, true);
		System.out.println("Descending: ");
		b.bubblesort(a, false);
	}
}