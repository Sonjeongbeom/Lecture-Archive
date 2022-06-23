package lab13;
import java.util.Random;

public class RandomNumberGenerator extends NumberGenerator {
	private Random random = new Random();
	private int number;
	
	public int getNumber() {
		return this.number;
	}
	
	public void execute() {
		for (int i = 0; i < 10; i++) {
			this.number = random.nextInt(50);
			notifyObservers();
		}
	}
}
