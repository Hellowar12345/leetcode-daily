int maxBottlesDrunk(int numBottles, int numExchange) {
    int empty=0;
    int cnt=0;
    cnt+=numBottles;
    empty+=numBottles;
    numBottles=0;
    while(empty>=numExchange){
            cnt++;//換後肯定喝掉 直接加cnt
            empty-=numExchange;
            numExchange++;
            empty++;//喝完變空瓶
    }
    return cnt;
}
