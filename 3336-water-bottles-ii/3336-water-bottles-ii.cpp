class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottles=0;
        while(numBottles>=numExchange){
            bottles+=numExchange;
            numBottles-=numExchange;
            numBottles+=1;
            numExchange+=1;
        }
        if(numBottles!=0)bottles+=numBottles;
        return bottles;
    }
};