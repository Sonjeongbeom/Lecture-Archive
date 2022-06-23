package manager;

import account.Account;
import java.time.LocalDate;
import java.time.Period;
import java.util.Random;

public class AccountManager {

	public static void main(String[] args) {
		LocalDate created = LocalDate.of(2021, 12, 1);
		Account account = new Account("Son", 5, created);
		
		// �ʱ� ���
		System.out.println(account.toString());
		
		LocalDate currentDate = account.getCreated();
		LocalDate startDate = account.getCreated();
		int flag = 0;
		
		while (true) {
			double myBalance = account.getBalance();
	
			// Ż�� ����
			if (myBalance >= 10000) {
				break;
			}
			
			// while�� ���鼭 1�޾� ����, �ӱ� �� ���� ����
			currentDate = currentDate.plusMonths(1);
			account.receiveIncome(100);
			account.receiveInterest();
			
			Period period = Period.between(startDate, currentDate);
			
			// 1�� ��� �� 1���� �̺�Ʈ ����
			if (period.getYears() >= 1 && currentDate.getMonthValue() == 1) {
				
				Random rnd = new Random();
				int myNum = rnd.nextInt(9);
				int luckyNum = rnd.nextInt(9);
				
				if (myNum == luckyNum) {
					System.out.println("�̺�Ʈ ��÷! " + currentDate);
					account.receiveIncome(100);
				}
			}
			
			// ���� �ٽ� �ؾ���
			// 3�� ��� �� �������� ����
			if (period.getYears() >= 3 && currentDate.getMonthValue() == 1 && flag == 0) {
				account.increaseYearlyInterest(2);
				System.out.println("���� �� 3���� ������ �������� 2% �λ�Ǿ����ϴ�.");
				flag = 1;
			}
			
		}
		
		
		// ���� ���
		System.out.println(account.toString() + ", 1�� ������ �� : " + currentDate);
		
	}

}
