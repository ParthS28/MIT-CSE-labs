// Design a class which represents a student. Every student record is made up of the following fields. 

//     Registration number (int) 

//     Full Name (String) 

//     Date of joining (Gregorian calendar) 

//     Semester (short) 

//     GPA (float) 

//     CGPA (float) 

// Whenever a student joins he will be given a new registration number. Registration number is calculated as follows. If year of joining is 2012 and he is the 80th student to join then his registration number will be 1280. 

// Write member functions to do the following. 

// Provide default and parameterized constructors to this class 

// Write display method which displays the record. Test the class by writing suitable main method. 

// Create an array of student record to store minimum of 5 records in it. Input the records and display them. 

import java.util.Scanner;

class Student{
    int reg_no;
    int date, month, year;
    String name;
    short sem;
    float gpa, cgpa;
    static int count;

    Student(){
        name = "";
        reg_no = 0;
        date = 0;
        month = 0;
        year = 0;
        sem = 0;
        gpa = 0;
        cgpa = 0;
        count++;
    }

    Student(String s, int d, int m, int y, short sem_no, float gp, float cg){
        count++;
        name = s;
        date = d;
        month = m;
        year = y;
        reg_no = calcReg(year, count);
        sem = sem_no;
        gpa = gp;
        cgpa = cg;
    }

    int calcReg(int year, int count){
        return (year%100)*100+count;
    }

    void display(){
        System.out.println("Name: " + name);
        System.out.println("Registration number: " + reg_no);
        System.out.println("Semester " + sem);
        System.out.println("GPA = " + gpa);
        System.out.println("CGPA = " +cgpa);
    }    
}

class StudentDemo{
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        Student[] stu = new Student[5];

        float gp,cg;
        int d, m, y;
        short sem;
        String name = "";
        for(int i = 0 ; i<5 ; i++){
            System.out.println("Student " + i);
            System.out.println("Enter name");
            name = sc.nextLine();
            System.out.println("Enter date of joining(dd mm yyyy)");
            d = sc.nextInt();
            m = sc.nextInt();
            y = sc.nextInt();
            System.out.println("Enter GPA");
            gp= sc.nextFloat();
            System.out.println("Enter CGPA");
            cg = sc.nextFloat();
            System.out.println("Enter semester");
            sem = sc.nextShort();
            stu[i] = new Student(name, d, m, y, sem, gp, cg);
            sc.nextLine();
        }
        for(int i = 0 ; i<5 ; i++){
            stu[i].display();
            System.out.println();
        }
    }
}