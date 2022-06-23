package lab07;
import lab07.Language;

public class Mayan extends Language {

	public Mayan(String name, int numSpeakers) {
		super(
			name,
			numSpeakers,
			"Central America",
			"verb-object-subject"
		);

	}
	
	public void getInfo() {
		System.out.println(name + " is spoken by " + numSpeakers + " people mainly in " + regionsSpoken + ".");
		System.out.println("The language follows the word order : " + wordOrder);
		System.out.println("* Fun facts (TMI) : ");
		System.out.println("* 1. ���� ������ 20������ ����ߴ�.");
		System.out.println("* 2. ���� 0�� ����� ������ �����̳� �ٸ� ���� ������ ��ġ���� �ʾҴ�.");
		System.out.println("* 3. ���� ���� �ڿ����ؿ� ���� �α��� 90%�� �پ� ������ ������ �����ϱ� �� �̹� ��� �����̾��� ������ ���뿡 ���� ������ �Զ��Ǿ���.");
	}
}
