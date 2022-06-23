package lab09;
import java.lang.Exception;


public class NegativeException extends Exception {

	public NegativeException() {
		super("price must be positive");
	}
	
	public NegativeException(String message) {
		super(message);
	}
	
	
}
