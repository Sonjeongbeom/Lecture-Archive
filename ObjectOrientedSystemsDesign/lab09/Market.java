package lab09;
import lab09.*;
import java.util.Scanner;

public class Market {

	public static void main(String[] args) {
		Wallet wallet = new Wallet("my wallet");
		Scanner keyboard = new Scanner(System.in);
		
		while (true) {
			try {
				wallet.empty();
				System.out.print("Enter price : ");
				int price = keyboard.nextInt();
				keyboard.nextLine();
				
				
				if (price < 0) {
					throw new NegativeException();
				}
				else if (price > 100) {
					throw new TooMuchExpenseException(price);
				}
				else if (price > wallet.getBalance()) {
					throw new TooMuchExpenseException();
				}
				
				else {
					wallet.increaseIndex();
					wallet.decreseBalance(price);
				}
			}
			
			catch (NegativeException e) {
				System.out.println(e);
				System.out.println("\tat  " + e.getStackTrace()[0]);
			}
			
			catch (TooMuchExpenseException e) {
				System.out.println(e);
				System.out.println("\tat  " + e.getStackTrace()[0]);
				
				if (e.getMessage().equals("Over the limit!")) {
					System.out.println("you pay " + e.getInputNum());
				}	
			}
			
			catch (Exception e) {
				System.out.println(e);
				System.out.println("\tat  " + e.getStackTrace()[0]);
				System.out.println("the end...");
				keyboard.close();
				return;
			}
			
			finally {
				System.out.println(wallet.toString());
				System.out.println("---transaction complete---");
				System.out.println();
			}
			
			
		}
	}

}
