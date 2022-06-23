package lab08;

import lab08.Car;
import java.time.*;

public class BEV extends Car {
	
	private static int carNum;
	private static int CO2emission;
	private static int GHGPERCAR = 25;
	
	public BEV() {};
	public BEV(String name, LocalDate date, int carNum) {
		this.name = name;
		this.date = date;
		this.carNum += carNum;
		this.CO2emission += (carNum * GHGPERCAR);	
	}
	
	public boolean equals(Object obj) {
		if (obj == null) {
			return false;
		}
		else if (getClass() != obj.getClass()) {
			return false;
		}
		else {
			BEV bev = (BEV) obj;
			return name.equals(bev.name) && date.equals(bev.date);
		}
	}
	
	public String toString() {
		return "name: " + name + ", date: " + date + ", carNum: " + carNum;
	}
	
	public int totalCO2() {
		System.out.println("BEV emit CO2 most when generating electric energy");
		return CO2emission;
	}
	
	
	
	
}
