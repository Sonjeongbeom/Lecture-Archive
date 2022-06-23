package lab09;
import java.lang.Exception;

public class TooMuchExpenseException extends Exception {
	
	private int inputNum;
	
	public TooMuchExpenseException() {
		super("Not enough balance.");
	}
	
	public TooMuchExpenseException(int inputNum) {
		super("Over the limit!");
		this.inputNum = inputNum;
	}
	
	public int getInputNum() {
		return inputNum;
	}
}
