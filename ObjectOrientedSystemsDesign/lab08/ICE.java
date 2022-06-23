package lab08;

import lab08.Car;
import java.time.*;

public class ICE extends Car {
	private static int carNum;
	private static int CO2emission;
	private static int GHGPERCAR = 35;
	
	public ICE() {};
	public ICE(String name, LocalDate date, int carNum) {
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
			ICE ice = (ICE) obj;
			return name.equals(ice.name) && date.equals(ice.date);
		}
	}
	
	public String toString() {
		return "name: " + name + ", date: " + date + ", carNum: " + carNum;
	}
	
	public int totalCO2() {
		System.out.println("ICE emit CO2 most when driving");
		return CO2emission;
	}
	
}
