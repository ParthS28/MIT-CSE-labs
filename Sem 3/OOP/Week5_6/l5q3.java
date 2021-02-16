// Design a Student class with appropriate data members as in Lab 5. 
// Provide your own exceptions namely Seats Filled Exception, 
// which is thrown when Student registration number is >XX25 (where XX is last two digits of the year of joining) 
// Show the usage of this exception handling using Student objects in the main. 
// (Note: Registration number must be a unique number) 

import java.util.Scanner;

class SeatsFilledException extends Exception{
	private int code;

	SeatsFilledException(int c){
		code = c;
	}
	int getcode(){
		return code;
	}
}

class Student{
	 int reg_no;    
	 int date, month, year;    
	 String name;    
	 short sem;    
	 float gpa, cgpa;

	 Student(){
	 	  name = "";        
	 	  reg_no = 0;        
	 	  date = 0;        
	 	  month = 0;        
	 	  year = 0;        
	 	  sem = 0;        
	 	  gpa = 0;
	 	  cgpa = 0;
	 }

	 Student(String s, int d, int m, int y, int reg, short sem_no, float gp, float cg)throws SeatsFilledException{
       name = s;        
       date = d;        
       month = m;        
       year = y;        
       if(reg % 100 > 25)
       	throw new SeatsFilledException(-1);
       reg_no = reg;        
       sem = sem_no;        
       gpa = gp;        
       cgpa = cg;    
     }
}

class StudentTest{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		float gp,cg;        
		int d, m, y, reg;        
		short sem;        
		String name = "";

		 System.out.println("Enter name");            
		 name = sc.nextLine();            
		 System.out.println("Enter date of joining(dd mm yyyy)");            
		 d = sc.nextInt();            
		 m = sc.nextInt();            
		 y = sc.nextInt(); 
		 System.out.println("Enter registration number");
		 reg = sc.nextInt();           
		 System.out.println("Enter GPA");            
		 gp= sc.nextFloat();            
		 System.out.println("Enter CGPA");            
		 cg = sc.nextFloat();            
		 System.out.println("Enter semester");            
		 sem = sc.nextShort();            

		 try{
		 	Student stu = new Student(name, d, m, y, reg, sem, gp, cg);
		 }
		 catch(SeatsFilledException e){
		 	System.out.println("Seats are filled. Try again next year.");
		 }
	}
}

