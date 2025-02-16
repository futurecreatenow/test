import java.util.Random;
import java.util.List;
import java.util.ArrayList;
public class Player{
    private String name;
    private Hand hand;
    //private List<Boolean> winflag;
    //コンストラクタ
    public Player(String name){
        this.name=name;
        //this.winflag=new ArrayList<>();
    }
    public void chooseHand(){
        Random random=new Random();
        this.hand=Hand.getHand(random.nextInt(3));
    }
    public static boolean determineWinners( Player player,List<Player> players){
            for(Player opponent : players){
                    if (opponent == players){
                        continue;
                    }
                    if (beats(player.getHand(),opponent.getHand())){
                        //addWinFlag(player,true);
                        //this.winflag.add(true);
                        return true;
                        //break;
                    }else if(draw(player.getHand(),opponent.getHand())){
                        //addWinFlag(player,false);
                        //this.winflag.add(false);
                        return false;
                        //break;
                    }else{
                        //addWinFlag(player,false);
                        //this.winflag.add(false);
                        return false;
                        //break;
                    } 
            }
            return false;
    }
    private static boolean beats(Hand hand1,Hand hand2){
        return
        (hand1==Hand.ROCK &&hand2==Hand.SCISSORS) ||
        (hand1==Hand.PAPER &&hand2==Hand.ROCK) ||
        (hand1==Hand.SCISSORS &&hand2==Hand.PAPER);
    }
    private static boolean draw(Hand hand1,Hand hand2){
        return
        (hand1==Hand.ROCK &&hand2==Hand.ROCK) ||
        (hand1==Hand.PAPER &&hand2==Hand.PAPER) ||
        (hand1==Hand.SCISSORS &&hand2==Hand.SCISSORS);
    }
   //public void addWinFlag(Player player,boolean flag){
   //    this.winflag.add(flag);
   // }
    public Hand getHand(){return hand;}
    public String getName(){return name;}
    //public Boolean getFlag(){return winflag;}
}
