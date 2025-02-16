import java.util.ArrayList;
import java.util.List;
public class Main{
    public static void main(String[] args){
        int numberOfPlayers=4;
        List<Player> players = new ArrayList<>();
        for (int i = 1;i<=numberOfPlayers;i++){
            players.add(new Player("Player"+i));
        }
        for (Player player : players){
            player.chooseHand();
            System.out.println(player.getName()+"chose"+
            player.getHand());
        }
        for (Player player : players){
            String result;
            if(Player.determineWinners(player,players)) {
                System.out.println(player.getName()+"WIN");
            }else{
                System.out.println(player.getName()+"LOSE");
            }
        }
        //for (Player player : players){
        //    if(player.getFlag()){
        //        System.out.println(player.getName() + "WIN");
        //    }
        //}
    }
}
