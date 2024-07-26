class Solution {
public:
    bool sumGame(string num) {
        int left = 0, right = 0, diff = 0, len = num.size();

        for (int i = 0; i < len; i++) {
            if (i < len / 2) {
                if (num[i] == '?') left++;
                else diff += num[i] - '0';
            } else {
                if (num[i] == '?') right++;
                else diff -= num[i] - '0';
            }
        }

        // if there are odd numbers of ?
        // Alice will always win because she will be the last one to pick
        if ((left + right) % 2 == 1) return true;

        // if the number of left ? is equal to the number of right ?
        // if diff > 0 (left sum > right sum):
        // Alice can always put 9 on the left and win the game
        // 
        // if diff < 0 (left sum < right sum):
        // Alice can always put 9 on the right and win the game 
        if (left == right) return diff != 0;

        // --------------------------------------
        // below is the case where left != right
        // --------------------------------------

        // if diff < 0 (left sum < right sum)
        // AND there are more ? on the right than on the left
        // Alice can always win because Bob can not insert negative numbers
        if (diff < 0 && left - right < 0) return true;


        // if diff > 0 (left sum > right sum)
        // AND there are more ? on the left than on the right
        // Alice can always win because Bob can not insert negative numbers
        if (diff > 0 && left - right > 0) return true;


        // if diff == 0, Alice can always win since Bob can not insert negative numbers
        if (diff == 0) return true;
        

        // the number of rounds:
        // if round < 0, there are more ? on the right than on the left
        // if round > 0, there are more ? on the left than on the right
        // round will always be an even number
        int round = (left - right) / 2;

        // below is the case where (diff < 0 and round > 0) OR (diff > 0 and round < 0)
        // The only situation Alice will lose is when abs(diff) == abs(round * 9)
        // because whatever number Alice chose, Bob can always find a number to make the sum to 9
        //
        // if abs(diff) > abs(round * 9), Alice can simply choose 0 all the time
        // if abs(diff) < abs(round * 9), Alice can simply choose 9 all the time
        return abs(diff) != abs(round * 9);
    }
};