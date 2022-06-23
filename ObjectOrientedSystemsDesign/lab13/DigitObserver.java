package lab13;

public class DigitObserver implements Observer {
	private NumberGenerator num;
	
	public DigitObserver(NumberGenerator num) {
		this.num = num;
		num.addObserver((Observer) this);
	}
	
	public void update(NumberGenerator generator) {
		System.out.println("DigitObserver: " + generator.getNumber());
	
		try {
			Thread.sleep(100);
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
}
