class Solution {
public:
    int maxDiff(int num) {
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
            if (flag && one[i] == temp) {
                one[i] = '9';
            }
        }

        

        flag = false;  
        bool flag2 = false;
        
        if(two[0] != '1') {
            temp = two[0];
            for(int i = 0; i < two.size(); i++) {
                if(two[i] == temp) {
                    two[i] = '1';
                }
            }
        }
        else {
            for (int i = 1; i < two.size(); i++) {
                if (two[i] == '0' || two[i] == '1') continue;
                if (!flag) {
                    temp = two[i];
                    flag = true;
                }
                if (flag && two[i] == temp) {
                    two[i] = '0';
                }
            }
        }

        

        cout << one << "  " << two;

        int maxVal = stoi(one);
        int minVal = stoi(two);

    
        return maxVal - minVal;
    }
};