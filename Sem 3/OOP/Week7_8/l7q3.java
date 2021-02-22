// Write a program to demonstrate the use of wildcard arguments. 

import java.util.Arrays; 
import java.util.List; 
  
class WildcardDemo {

    private static void printlist(List<?> list){
        System.out.println(list); 
    } 


    public static void main(String[] args){ 
        List<Integer> list1 = Arrays.asList(1, 2, 3);         
        List<String> list2 = Arrays.asList("First", "Second", "Third");
        printlist(list1);         
        printlist(list2); 
    }
} 