package lab02;

import java.util.Scanner;

public class Prac01 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String[] input_arr = scan.nextLine().split(",");
		String[] name_arr = input_arr[0].trim().split(" ");
		String homework = input_arr[1].trim().replace("ppt", "pdf");
		
		System.out.println("Name Length(Korean) : " + name_arr.length);
		System.out.print(name_arr[0].substring(0,1).toUpperCase() + ".");
		System.out.print(name_arr[1].substring(0,1).toUpperCase() + ".");
		System.out.print(name_arr[2].substring(0,1).toUpperCase() + name_arr[2].substring(1));
		
		System.out.print(" submitted ");
		System.out.print(homework.substring(0,1).toUpperCase() + homework.substring(1));		
		

	}

}
