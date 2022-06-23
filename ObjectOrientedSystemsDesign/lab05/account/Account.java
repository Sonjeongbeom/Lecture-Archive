package account;

import java.time.LocalDate;

public class Account {

		private String name;
		private double yearlyInterest;
		private double balance;
		private LocalDate created;
		
		public Account(String name, double yearlyInterest, LocalDate created) {
			this.name = name;
			this.yearlyInterest = yearlyInterest;
			this.created = created;
			this.balance = 0;
		}
		
		public double getBalance() {
			return balance;
		}
		
		public LocalDate getCreated() {
			return created;
		}
		
		public void increaseYearlyInterest(int byPercent) {
			this.yearlyInterest += byPercent;
		}
		
		public void receiveIncome(double income) {
			this.balance += income;
		}
		
		public void receiveInterest() {
			this.balance += this.balance * yearlyInterest * 0.01 / 12; 
		}
		
		public String toString() {
			return "이름 : " + name + ", 연이자 : " + yearlyInterest + ", 잔고 : " + balance + ", 가입일 : " + created;
		}
		
}
