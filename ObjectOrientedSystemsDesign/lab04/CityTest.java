package lab04;

public class CityTest {

	public static void main(String[] args) {
		
		// ��ü ����
		City seoul = new City("Seoul", 23, 45);
		City paris = new City("Paris", 123, 41);
		City racoonCity = new City("Raccon City");
		City megaCity = new City("Mega City");
		
		
		// ��ü ���� ���
		System.out.println(seoul.toString());
		System.out.println(paris.toString());
		System.out.println(racoonCity.toString());
		System.out.println(megaCity.toString());
		
		
		// ���� ���� �Ÿ� ���
		System.out.print(seoul.getName() + "-" + paris.getName() + " : ");
		System.out.println(City.distance(seoul, paris));
		
		System.out.print(seoul.getName() + "-" + racoonCity.getName() + " : ");
		System.out.println(City.distance(seoul, racoonCity));
		
		System.out.print(paris.getName() + "-" + megaCity.getName() + " : ");
		System.out.println(City.distance(paris, megaCity));
	}

}
