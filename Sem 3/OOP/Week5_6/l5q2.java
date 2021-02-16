// Define a class CurrentDate with data members day, month and year. 
// Define a method createDate() to create date object by reading values from keyboard. 
// Throw a user defined exception by name InvalidDayException if the day is invalid 
// and InvalidMonthException if month is found invalid and display current date if the date is valid. 
// Write a test program to illustrate the functionality. 
import java.util.Scanner;

class InvalidDayException extends Exception{
	private int code;

	InvalidDayException(int c){
		code = c;
	}

	int getCode(){ 
		return code;
	} 
}

class InvalidMonthException extends Exception{
	private int code;

	InvalidMonthException(int c){
		code = c;
	}

	int getCode(){ 
		return code;
	} 
}

class CurrentDate{
	int date, month, year;

	void createDate(){
		date = 1;
		month = 1;
		year = 2000;
	}

	void createDate(int d, int m, int y) throws InvalidDayException, InvalidMonthException{
		if(m <1 || m >12)
			throw new InvalidMonthException(-1);
		month = m;
		switch(month){
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
			if(d < 1 || d > 31)
				throw new InvalidDayException(-1);
			break;
			case 4:
			case 6:
			case 9:
			case 11:
			if(d < 1 || d > 30)
				throw new InvalidDayException(-1);
			break;
			case 2:
			if(d < 1 || d > 28)
				throw new InvalidDayException(-1);
		}
		date = d;
		year = y;
	}

	public void display(){
		System.out.println(String.format("Current Date (dd-mm-yyyy): %02d-%02d-%04d", date, month, year));
	}
}

class DateTest
{
	public static CurrentDate createDate() throws InvalidDayException, InvalidMonthException
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter dd mm yyyy");
		int d = sc.nextInt();
		int m = sc.nextInt();
		int y = sc.nextInt();
		try{
			CurrentDate date = new CurrentDate();
			date.createDate(d, m, y);
			return date;
		}catch(InvalidDayException | InvalidMonthException ex){ 
			throw ex;
		}
	}

	public static void main(String[] args)
	{
		CurrentDate d; 
		try{ 
			d = createDate();
			d.display();
		}catch(InvalidDayException | InvalidMonthException ex){
			System.out.print("Caught Exception: ");
			System.out.println(ex);
		}
	}
}