package lab11;
import java.util.ArrayList;
import java.util.Scanner;

public class Logistics {

	@SuppressWarnings("unchecked")
	public static <T extends Hub> void deliverBoxes(ArrayList<T> tList, String[] description, String area) {
		for (int i = 0; i < description.length; i++) {
			if (area == "GyeongGi-dou") {
				((ArrayList<T>) tList).add((T) new Gyeonggi(description[i]));
			}
			
			if (area == "JeJu-dou") {
				((ArrayList<T>) tList).add((T) new Jeju(description[i]));
			}
		}
	}
	
	public static void main(String[] args) {
		String[] new_gyeonggi_boxes = {"SuWon#1", "SeongNam#1", "YongIn#1", "HwaSeong#1", "GaPyeong#1"};
		String[] new_jeju_boxes = {"JeJu-si#1", "SeoGuiPo-si#1"};
		ArrayList<Gyeonggi> gList = new ArrayList<>();
		ArrayList<Jeju> jList = new ArrayList<>();
		
		Scanner scan = new Scanner(System.in);
		
		deliverBoxes(gList, new_gyeonggi_boxes, "GyeongGi-dou");
		deliverBoxes(jList, new_jeju_boxes, "JeJu-dou");
		
		System.out.println("*** Oh, delivery price has been increased!! ***");
		ServiceManagement.raiseAll(gList, 1.05);
		ServiceManagement.raiseAll(jList, 1.05);
		
		System.out.println("Which box is important in Jeju-area?");
		int selected = scan.nextInt();
		int index = ServiceManagement.findIndexByNum(jList, selected);
		if(index == -1) {
			System.out.println("nothing");
		} 
		else {
			ServiceManagement.raisePerBox(jList.get(index), 1.20); // payment for risk
			System.out.println("The box to "+jList.get(index).getDescription()+" is important! be careful!\n"); 
		}
		

		System.out.println("Which box has the wrong area in Gyeonggi-area?");
		selected = scan.nextInt();
		
		index = ServiceManagement.findIndexByNum(gList, selected);
		if(index == -1) {
			System.out.println("nothing");
		} else {
			ServiceManagement.moveArea(gList.get(index), "GangWon"); // 박스의 이름과 무관, 목적 허브(area 변경) 
			ServiceManagement.raisePerBox(gList.get(index), 0.9); // discount for late delivery
			System.out.println("The box to "+gList.get(index).getDescription()+" is actually has to go to "
							+gList.get(index).getArea()+"! late! hurry up!\n"); 
		}
		
		System.out.println("-------- Delivery List --------");
		
		for(Gyeonggi g : gList) {
			System.out.println(g+"\n");
		}
		for(Jeju j : jList) {
			System.out.println(j+"\n");
		}
		scan.close();

	}

}
