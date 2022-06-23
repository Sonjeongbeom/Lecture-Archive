package lab09;
import lab09.*;
import java.lang.Exception;

public class Wallet {

	private String name;
	private int balance;
	private int txIndex;
	
	public Wallet(String name) {
		this.name = name;
		this.balance = 100;
		this.txIndex = 0;
	}
	
	public int getBalance() {
		return balance;
	}
	
	public void increaseIndex() {
		txIndex++;
	}
	
	public void decreseBalance(int expense) {
		balance -= expense;
	}
	
	public String toString() {
		return "name: " + this.name + ", #" + this.txIndex + ", balance: " +  this.balance;
	}
	
	public void empty() throws Exception {
		if (getBalance() <= 0 ) {
			throw new Exception("Go Home");
		}
	}
	
	
}
