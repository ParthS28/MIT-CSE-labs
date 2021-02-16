// Create a class by extending Thread Class to print a multiplication table of a number supplied as parameter. 
// Create another class Tables which will instantiate two objects of the above class to print multiplication 
// table of 5 and 7. 


class Multiply extends Thread{
	public Thread t;
	public int n;

	Multiply(int num){
		System.out.println("Thread created for " + num);
		n = num;
	}

	void printTable(){
		System.out.println("Table for " + n);
		for(int i = 1; i <= 10; i++){
			System.out.println(n + " * " + i + " = " + n*i);
		}
	}
	public void run(){
		printTable();
	}
	public void start(){
		// run();
		System.out.print(String.format("Starting thread %d\n", n));
		if(t == null){ 
			t = new Thread(this, String.format("thread%d", n));
			t.start();
		}
	}
}

class Tables{
	public static void main(String []args){
		Multiply t1 = new Multiply(5);
		t1.start();
		Multiply t2 = new Multiply(7);
		t2.start();
		try {
			t1.join();
		}
		catch(InterruptedException e){
			e.printStackTrace();
		}
		
	}
}