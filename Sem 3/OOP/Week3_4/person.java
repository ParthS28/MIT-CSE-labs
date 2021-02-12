// Create a Person class with private instance variables for the person’s name and birth date.
// Add appropriate accessor methods for these variables.
// Then create a subclass College Graduate with private instance variables for the student’s GPA and year of graduation and appropriate accessors for these variables. 
// Include appropriate constructors for your classes. 
// Then create a class with main() method that demonstrates your classes. 

import java.util.*;

class Person{
	private String name ;
	private Date dob ;
	public Person(){
		name = "";
		dob = new Date() ;
	}
	public Person(String name, Date dob){
		this.dob = dob ;
		this.name = name ;
	}
	public void set_name(String name){
		this.name = name ;
	}
	public String get_name(){
		return this.name ;
	}
	public void set_dob(int year,int month,int day){
		this.dob = new Date(year-1900,month,day);
	}
	public Date get_dob(){
		return this.dob ;
	}
	public void display(){
		System.out.println("Name: " + name);
		System.out.println("DOB: " + dob.toString());
	}
}


class CollegeGraduate extends Person{
	private float gpa ;
	private int grad_year ;
	public CollegeGraduate(){
		super();
		gpa = 0 ;
		grad_year = 0;
	}
	public CollegeGraduate(String name, Date dob, float gpa , int grad_year){
		super(name,dob);
		this.gpa = gpa ;
		this.grad_year = grad_year ;
	}
	public void set_gpa(float gpa){
		this.gpa = gpa ;
	}
	public float get_gpa(){
		return this.gpa ;
	}
	public void set_grad(int grad_year){
		this.grad_year = grad_year ;
	}
	public int get_grad(){
		return this.grad_year ;
	}
	public void display(){
		super.display();
		System.out.println("GPA: " + gpa);
		System.out.println("Year: " + grad_year);
	}
}

 class Demo{
	public static void main(String []args){
		Scanner sc = new Scanner(System.in);
		Date d = new Date(2001, 5, 28);
		CollegeGraduate stu1 = new CollegeGraduate("Parth Shukla", d, 9, 2023);
		stu1.display();

		System.out.println("Enter name");
		String n = sc.nextLine();
		System.out.println("Enter DOB");
		int dat = sc.nextInt();
		int m = sc.nextInt();
		int y = sc.nextInt();
		d = new Date(y, m, dat);
		System.out.println("Enter GPA");
		int gp = sc.nextInt();
		System.out.println("Enter grad year");
		int gy = sc.nextInt();

		CollegeGraduate stu2 = new CollegeGraduate(n, d, gp, gy);
		stu2.display();
	}
}
