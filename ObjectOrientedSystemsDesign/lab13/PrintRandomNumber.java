package lab13;

public class PrintRandomNumber {

	public static void main(String[] args) {
		NumberGenerator a = new RandomNumberGenerator();
		DigitObserver b = new DigitObserver(a);
		GraphObserver c = new GraphObserver(a);
		
		a.execute();
	}
}
