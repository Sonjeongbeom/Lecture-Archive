package lab10;
import lab10.*;
import java.lang.*;

public class Program {

	public static void main(String[] args) {
		Dog dog = new Dog();
		Tiger tiger = new Tiger();
		Turtle turtle = new Turtle();
		
		Animal[] animal = new Animal[3];
		animal[0] = dog;
		animal[1] = tiger;
		animal[2] = turtle;
		
		Person person = new Person() {
			private int hp = 100;

			public void control(Animal animal) {
				if (animal instanceof Tiger) {
					hp -= 80;
				}
				
				else if (animal instanceof Dog) {
					hp -= 10;
				}
				
				System.out.println("You have overpowered the " + animal.getName());
			}
			public void showInfo() {
				System.out.println("Person HP: " + hp);
			}
		
		};
		
		showResult(animal, person);
		
	}

	private static void showResult(Animal[] animals, Person p) {
		for (int i = 0; i < animals.length; i++) {
			System.out.println("Animal" + (i+1) + ":" + animals[i].getName());
			if (animals[i] instanceof Barkable) {
				System.out.print("Animal" + (i+1) + " barked ");
				System.out.println(((Barkable) animals[i]).bark());
			}
			p.control(animals[i]);
			p.showInfo();
		}
	}
	
}
