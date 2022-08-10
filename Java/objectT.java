import java.util.Scanner;

class calculator{
	int all=0,a,bace;
	public void firest(int a, int bace){
		this.a=a;
		this.bace=bace;
	}
	public void sum(){
		all=a+bace;
		System.out.println("입력하신 덧셈의 결과는 "+a+" + "+bace+" = "+all+" 입니다.");
	}
	public void sub(){
		all=a-bace;
		System.out.println(a+"-"+bace+"="+all);
	}
	public void pro(){
		all=a*bace;
		System.out.println(a+"*"+bace+"="+all);
	}
	public void div(){
		if(a>bace){
			all=a/bace;
			System.out.println(a+"/"+bace+"="+all);
		}
		else{
			all=bace/a;
			System.out.println(bace+"/"+a+"="+all);
		}
	}
}

public class objectT {
	public static void main(String[] args){
		Scanner sc= new Scanner(System.in);
		Scanner sc_char= new Scanner(System.in);
		int a,b,chack=0;
		char c;
		a=sc.nextInt();
		c=sc_char.next().charAt(0);
		b=sc.nextInt();
		calculator abc = new calculator();
		if(chack==0){
			abc.firest(a,b);
			if(c=='+'){
				abc.sum();
			}
			else if(c=='-'){
				abc.sub();
			}
			else if(c=='*'){
				abc.pro();
			}
			else if (c=='/'){
				abc.div();
			}
		}
		else{
			
		}
	}
}
