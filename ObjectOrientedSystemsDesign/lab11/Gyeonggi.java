package lab11;

public class Gyeonggi extends Hub {
	
	public static int init_num = 1000;
	public static String init_area = "Gyeonggi";
	public static int init_per_box = 3000;
	
	public Gyeonggi(String description) {
		setNumber(++init_num);
		setDescription(description);
		setArea(init_area);
		setPricePerBox(init_per_box);
	}
	
}
