package lab11;


public class Jeju extends Hub {

	public static int init_num = 9000;
	public static String init_area = "Jeju";
	public static int init_per_box = 6000;
	
	public Jeju(String description) {
		setNumber(++init_num);
		setDescription(description);
		setArea(init_area);
		setPricePerBox(init_per_box);
	}
}
