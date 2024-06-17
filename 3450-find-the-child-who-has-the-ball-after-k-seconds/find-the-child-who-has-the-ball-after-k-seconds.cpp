class Solution {
public:
    int numberOfChild(int n, int k) {
        int i = 0;
        bool moveRight = true;

        int ind = 0;
        while(i < k) {
            if(ind == n - 1 && moveRight) {
                moveRight = false;
            }
            else if(ind == 0 && moveRight == false){
                moveRight = true;
            }
            else {
                if(moveRight) {
                    ind += 1;
                }
                else {
                    ind -= 1;
                }
                i += 1;
            }


            cout << i << " " << ind << " " << moveRight << endl;
        }

        return ind;
    }
};