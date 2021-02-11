// Create a class called Time that has instance variables to represent hours, minutes and seconds. Provide the following methods: 
// To assign initial values to the Time object. 
// To display a Time object in the form of hh:mm:ss {24 hours format} 
// To add 2 Time objects (the return type should be a Time ) 
// To subtract 2 Time objects (the return type should be a Time ) 
// To compare 2 Time objects and to determine if they are equal or if the first is greater or smaller than the second one. 
import java.util.Scanner;
import java.lang.Math;

class Time{
	int hours, minutes, seconds;

	Time(int h, int m, int s){
		hours = h;
		minutes = m;
		seconds = s;
	}

	void display(){
		System.out.println("The time is: " + hours + ":" + minutes + ":" + seconds);
	}

	Time add(Time t){
		int carry = 0;
		Time time = new Time(0,0,0);
		time.seconds = seconds + t.seconds;
		if(time.seconds > 59){
			carry = 1; time.seconds = time.seconds%60;
		}
		time.minutes = minutes + t.minutes + carry;
		carry = 0;
		if(time.minutes > 59){
			carry = 1; time.minutes = time.minutes % 60;
		}
		time.hours = hours + t.hours + carry;
		return time;
	}

	Time sub(Time t){
		Time time = new Time(0,0,0);
		time.seconds = Math.abs(seconds - t.seconds);
		time.minutes = Math.abs(minutes - t.minutes);
		time.hours = Math.abs(hours - t.hours);
		return time;
	}

	int compare(Time t){   // 1 for t1>t2, 0 for equal, -1 t2>t1 
		if(hours > t.hours)
			return 1;
		else if(t.hours > hours)
			return -1;

		if(minutes > t.minutes)
			return 1;
		else if(t.minutes > minutes)
			return -1;

		if(seconds > t.seconds)
			return 1;
		else if(t.seconds > seconds)
			return -1;

		return 0;
	}

	public static void main(String []args){
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter first time: ");
		int h = sc.nextInt();
		int m = sc.nextInt();
		int s = sc.nextInt();
		Time t1 = new Time(h, m, s);
		t1.display();
		System.out.println("Enter second time: ");
		h = sc.nextInt();
		m = sc.nextInt();
		s = sc.nextInt();
		Time t2 = new Time(h, m, s);
		t2.display();
		System.out.println("Sum");
		Time sum = t1.add(t2);
		sum.display();
		System.out.println("Diff");
		Time diff = t1.sub(t2);
		diff.display();
		int x = t1.compare(t2);
		if(x == 1)
			System.out.println("First time is bigger");
		else if(x == -1)
			System.out.println("Second time is bigger");
		else
			System.out.println("Both are equal");
	}
}