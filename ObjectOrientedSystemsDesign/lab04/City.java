package lab04;

import java.util.Random;

public class City {
	
	private String name;
	private int locationX;
	private int locationY;
	
	public City(String name, int locationX, int locationY) {
		this.name = name;
		this.locationX = locationX;
		this.locationY = locationY;
		
	}
	
	public City(String name) {
		this.name = name;
		Random rnd = new Random();
		this.locationX = rnd.nextInt(360);
		this.locationY = rnd.nextInt(360);
	}
	
	public String getName() {
		return name;
	}
	
	public int getLocationX() {
		return locationX;
	}
	
	public int getLocationY() {
		return locationY;
	}
	
	public boolean equals(City city) {
		if (this.name.equals(city.name) && this.locationX == city.locationX && this.locationY == city.locationY) {
			return true;
		}
		else {
			return false;
		}
	}
	
	public String toString() {
		return this.name + ", " + this.locationX + ", " + this.locationY;
	}
	
	
	public static double distance(City city1, City city2) {
		double result = Math.sqrt(Math.pow((city1.locationX - city2.locationX),2) + Math.pow((city1.locationY - city2.locationY),2));
		return result;
	}
	
}
