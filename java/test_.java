//抽象クラスとポリモーフィズム
public abstract class Club{
	private String name;
	public Club(String name){this.name=name;}
	public void display(){System.out.println("club name"+name);
	public abstract void practice();
}
public class TandF extends Club{
	public TandF(String name){super(name);}
	public void practice(){
		System.out.println("junnbitaiso");
		System.out.println("hasirikomi");
	}
}
public class Football extends Club{
	public Football(String name){super(name);}
	public void practice(){
		System.out.println("doriburu");
		System.out.println("minigame");
	}
}
public class Student6{
	private String name;
	private Club club;
	public Student6(String name,Club club){
		this.name=name;
		this.club=club;}
	public void display(){
		System.out.println("student name"+name);
		club.display();}
	public void practice(){club.practice();}
}
public class Students(){
	public static void main(String[] args){
		TandF taf = new TandF("run");
		Football fb=new Football("soccer");
		Student6 stu1=new Student6("sato",taf);
		stu1.display();
		stu1.practice();
		Student6 stu2=new Student6("goisu",fb);
		stu2.display();
		stu2.practice();
	}
}
//インターフェイス
//パッケージ

