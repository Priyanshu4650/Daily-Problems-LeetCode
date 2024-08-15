class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;

        for(auto bill : bills) {
            int toGive = bill - 5;

            five += bill == 5;
            ten += bill == 10;
            twenty += bill == 20;

            while(toGive >= 20 && twenty > 0) {
                toGive -= 20;
                twenty -= 1;
            } 

            while(toGive >= 10 && ten > 0) {
                toGive -= 10;
                ten -= 1;
            }

            while(toGive >= 5 && five > 0) {
                toGive -= 5;
                five -= 1;
            }

            if(toGive != 0) {
                return false;
            }
            
            cout << five << " " << ten << " " << twenty << " " << toGive << " " << bill << endl;
        }

        return true;
    }
};