package lab04;

public class CityTest {

	public static void main(String[] args) {
		
		// 객체 생성
		City seoul = new City("Seoul", 23, 45);
		City paris = new City("Paris", 123, 41);
		City racoonCity = new City("Raccon City");
		City megaCity = new City("Mega City");
		
		
		// 객체 정보 출력
		System.out.println(seoul.toString());
		System.out.println(paris.toString());
		System.out.println(racoonCity.toString());
		System.out.println(megaCity.toString());
		
		
		// 도시 사이 거리 출력
		System.out.print(seoul.getName() + "-" + paris.getName() + " : ");
		System.out.println(City.distance(seoul, paris));
		
		System.out.print(seoul.getName() + "-" + racoonCity.getName() + " : ");
		System.out.println(City.distance(seoul, racoonCity));
		
		System.out.print(paris.getName() + "-" + megaCity.getName() + " : ");
		System.out.println(City.distance(paris, megaCity));
	}

}
