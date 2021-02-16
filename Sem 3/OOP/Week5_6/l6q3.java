// Write and execute a java program to implement a producer and consumer problem using Inter-thread communication. 

class Q
{
	int n; 
	boolean value = false;
	synchronized int get(){ 
		while(!value){ 
			try{ 
				wait();
			}catch(InterruptedException e){
				System.out.println(e);
			}
		}
		System.out.println("Consumer got: " + n);
		value = false; 
		notify();
		return n;
	}

	synchronized void put(int n){ 
		while(value){ 
			try{ 
				wait();
			}catch(InterruptedException e){
				System.out.println(e);
			}
		}
		this.n = n; 
		value = true;
		System.out.println("Producer produced: " + n);
		notify();
	}
}

class Producer implements Runnable{ 
	Q q;
	Producer(Q q){
		this.q = q;
		System.out.println("Producer created");
		new Thread(this, "Producer").start();
	}

	public void run(){ 
		int i = 0; 
		while(i < 5){
			q.put(i++);
		}
	}
}


class Consumer implements Runnable{ 
	Q q;
	Consumer(Q q){
		this.q = q;
		System.out.println("Consumer created");
		new Thread(this, "Consumer").start();
	}
	public void run(){ 
		while(true){
			q.get();
		}
	}
}


class PCTest{ 
	public static void main(String []args){
		Q q = new Q();
		new Producer(q);
		new Consumer(q);
	} 
}