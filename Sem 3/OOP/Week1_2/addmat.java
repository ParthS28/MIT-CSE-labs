 // Find the addition of two matrices and display the resultant matrix. 

import java.util.Scanner;
import java.lang.Math;

class AddMat{
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter matrix height: ");
        int rows=sc.nextInt();
        System.out.print("Enter matrix width: ");
        int cols=sc.nextInt();
        int matrix1[][]=new int[rows][cols];
        int matrix2[][]=new int[rows][cols];
        
        System.out.println("Matrix 1: ");
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                matrix1[i][j]=sc.nextInt();
            }
        }
        
        System.out.println("Matrix 2: ");
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                matrix2[i][j]=sc.nextInt();
            }
        }
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                matrix2[i][j]=matrix1[i][j]+matrix2[i][j];
                System.out.print(matrix2[i][j]+" ");
            }
            System.out.println();
        }
    }
}