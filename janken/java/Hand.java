public enum Hand{
    ROCK,PAPER,SCISSORS;

    public static Hand getHand(int index){
        switch(index){
            case 0:return ROCK;
            case 1:return PAPER;
            case 2:return SCISSORS;
            default:
            throw new IllegalArgumentException
            ("Invalid NUM");
        }
    }
}
