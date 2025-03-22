class Solution {
public:

// this is not the most optimized approach but good for a stack and self written
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prev(n, -1);
        vector<int> next(n, -1);

        stack<int> st;

// finding the previous greatest element for every height and storing in prev[]        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && st.top() <= height[i]) {
                st.pop();
            }

            if(!st.empty()) {
                prev[i] = st.top();
            }

          
            if(!st.empty()) {
                if(st.top() < height[i]) {
                    st.push(height[i]);
                }
            } else st.push(height[i]);
            
        }
        while (!st.empty()) {
            st.pop();
        }

// finding the next greatest element for every height and storing in next[]        

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= height[i]) {
                st.pop();
            }

            if(!st.empty()) {
                next[i] = st.top();
            }

          
            if(!st.empty()) {
                if(st.top() < height[i]) {
                    st.push(height[i]);
                }
            } else st.push(height[i]);   
        }

// now at any point the trapped water will be min(prev greatest, next greatest) - height
// kyuki minimum hame bataega ki kis height tk pani rakh sakte hain
// for eg. height[5] = 0 ke lie prev greater hoga 2 and next greater hoga 3, to water agar 2 ke upar jayega
// to itll flow out
// WHY - height? Ab agar kinhi 2 buildings ke beech pani bhara hai, and uske beech me ek building hai,
// to obv pani us building ke upar hoga.
        int add = 0;
        for(int i = 0; i < n; i++) {
            if(prev[i] != -1 && next[i] != -1) {
                add += min(prev[i], next[i]) - height[i];
            }

        }
        return add;
    }
};