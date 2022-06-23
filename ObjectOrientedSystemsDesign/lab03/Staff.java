package lab03;

public class Staff {

	private String name;
	private int age;
	private String department;
	private int workDays;
	private int vacationDays;
	
	public Staff(String name, int age) {
		this.name = name;
		this.age = age;
		this.department = "None";
		this.workDays = 0;
		this.vacationDays = 20;
	}
	
	public Staff(String name, int age, String department, int workDays, int vacationDays) {
		this.name = name;
		this.age = age;
		this.department = department;
		this.workDays = workDays;
		this.vacationDays = vacationDays;
	}

	public String getName() {
		return name;
	}
	
	public void setDepartment(String department) {
		this.department = department;
	}
	
	public void setWorkDays(int workDays) {
		this.workDays = workDays;
	}
	

	public void sameCareer(Staff staff) {
		if (this.department.equals(staff.department) && this.workDays == staff.workDays) {
			System.out.println(this.getName() + " and " + staff.getName() + ", Same.");
		}
		else {
			System.out.println(this.getName() + " and " + staff.getName() + ", Not exactly same.");
		}
	}
	
	public String toString() {
		return "Name: " + this.name + ", Age: " + this.age + ", Department: " + this.department + ", workDays: " + this.workDays + ", vacationDays: " + this.vacationDays;
	}
	
	public void vacation(int days) {
		if (this.vacationDays < days) {
			System.out.println(this.name + ", 남은 휴가 일 수 부족.");
		}
		else {
			this.vacationDays -= days;
			System.out.printf("%s, 휴가 %d 사용. 남은 휴가 일수 : %d\n", this.name, days, this.vacationDays);
		}
	}
}
