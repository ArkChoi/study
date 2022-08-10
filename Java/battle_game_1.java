import java.util.Scanner
import java.util.Random

class player{
	int hp=100,ra=0;
	Random ran = new Random();
	int Attack{
		while(20>ra){
			ra=ran.nexInt(35);
		}
		return ra;
	}
}

class Knight extends player{
	int shilde=5,hpd;
	void hp_decrease{
		hpd=Attack();
		hp=hp-hpd+shilde;
		System.out.println(hp);
	}
}

public class battle_game_1{
	public static void main(string[] args){
		while(1){
			Scanner sc = new Scanner(System.in);
		}
	}
}
