package lab03;

public class StaffManager {

	public static void main(String[] args) {
		Staff james = new Staff("James Wright", 29, "Accounting", 365, 15);
		Staff peter = new Staff("Peter Coolidge", 32, "R&D", 1095, 7);
		Staff amy = new Staff("Amy Smith", 27);
		
		System.out.println(james.toString());
		System.out.println(peter.toString());
		System.out.println(amy.toString());
		System.out.println("---");
		
		System.out.println("Same Career?");
		peter.sameCareer(amy);
		
		System.out.println("...A Few years later...");
		amy.setDepartment("R&D");
		amy.setWorkDays(1095);
		peter.sameCareer(amy);
		System.out.println("---");
		
		james.vacation(10);
		amy.vacation(20);
		amy.vacation(1);
	}

}

