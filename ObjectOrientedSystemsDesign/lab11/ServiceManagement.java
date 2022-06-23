package lab11;
import java.util.ArrayList;

public class ServiceManagement {

	public static <T extends Hub> T moveArea(T t, String area) {
		t.setArea(area);
		return t;
	}
	
	public static <T extends Hub> T raisePerBox(T t, double rate) {
		t.setPricePerBox(rate * t.getPricePerBox());
		return t;
	}
	
	public static <T extends Hub> int findIndexByNum(ArrayList<T> tList, int num) {
		for (int i = 0; i < tList.size(); i++) {
			if (num == tList.get(i).getNumber()) {
				return i;
			}
		}
		return -1;
	}
	
	public static <T extends Hub> ArrayList<T> raiseAll(ArrayList<T> tList, double rate) {
		for (int i = 0; i < tList.size(); i++) {
			tList.get(i).setPricePerBox(rate * tList.get(i).getPricePerBox());
		}
		return tList;
	}
	
}
