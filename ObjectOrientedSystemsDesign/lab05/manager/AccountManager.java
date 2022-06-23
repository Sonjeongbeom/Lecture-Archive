package manager;

import account.Account;
import java.time.LocalDate;
import java.time.Period;
import java.util.Random;

public class AccountManager {

	public static void main(String[] args) {
		LocalDate created = LocalDate.of(2021, 12, 1);
		Account account = new Account("Son", 5, created);
		
		// 초기 출력
		System.out.println(account.toString());
		
		LocalDate currentDate = account.getCreated();
		LocalDate startDate = account.getCreated();
		int flag = 0;
		
		while (true) {
			double myBalance = account.getBalance();
	
			// 탈출 조건
			if (myBalance >= 10000) {
				break;
			}
			
			// while문 돌면서 1달씩 증가, 임급 및 이자 지급
			currentDate = currentDate.plusMonths(1);
			account.receiveIncome(100);
			account.receiveInterest();
			
			Period period = Period.between(startDate, currentDate);
			
			// 1년 경과 후 1월에 이벤트 진행
			if (period.getYears() >= 1 && currentDate.getMonthValue() == 1) {
				
				Random rnd = new Random();
				int myNum = rnd.nextInt(9);
				int luckyNum = rnd.nextInt(9);
				
				if (myNum == luckyNum) {
					System.out.println("이벤트 당첨! " + currentDate);
					account.receiveIncome(100);
				}
			}
			
			// 여기 다시 해야함
			// 3년 경과 후 연이자율 증가
			if (period.getYears() >= 3 && currentDate.getMonthValue() == 1 && flag == 0) {
				account.increaseYearlyInterest(2);
				System.out.println("가입 후 3년이 지나서 이자율이 2% 인상되었습니다.");
				flag = 1;
			}
			
		}
		
		
		// 최종 출력
		System.out.println(account.toString() + ", 1억 모으기 끝 : " + currentDate);
		
	}

}
