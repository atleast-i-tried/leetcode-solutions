class Solution {
public:
    int minMaxDifference(int num) {
        int copy = num;

        string one = to_string(num);
        string two = to_string(copy);

        bool flag = false;
        char temp;

        for (int i = 0; i < one.size(); i++) {
            if (one[i] == '9') continue;
            if (!flag) {
                temp = one[i];
                flag = true;
            }
            if (one[i] == temp) {
                one[i] = '9';
            }
        }

        flag = false;  

        for (int i = 0; i < two.size(); i++) {
            if (two[i] == '0') continue;
            if (!flag) {
                temp = two[i];
                flag = true;
            }
            if (two[i] == temp) {
                two[i] = '0';
            }
        }

        int maxVal = stoi(one);
        int minVal = stoi(two);
        return maxVal - minVal;
    }
};
