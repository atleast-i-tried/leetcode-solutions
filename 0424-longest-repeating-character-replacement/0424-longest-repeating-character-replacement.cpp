class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int maxLength = 0;
        int maxFreq = 0;
        unordered_map<char, int> mp;

        for(right = 0; right < s.size(); right++) {

            mp[s[right]]++;

            maxFreq = max(maxFreq, mp[s[right]]);

// a logical question that arises is why are we not using while, kyuki technically we need to use while na
// so if we think about it
// 'AABABBA' suppose our sliding window as of now is "AABA", now when we move right, our window becomes "AABAB" 
// and the below given if condition fails, now we have 2 options
// 1. while, what while will do is, it will remove both "AA" from the starting, kyuki maxFreq is 3
// 2. if, what if will do it, it will only remove the first "A" and then the question continues.
// THE REASON we will use if is, hamare pas already 4 hai, as an answer, right? to hame usse chota kuch nahi chahiye.
// what we need is an answer >4, so if the right moves and window becomes 5, and the condition fails, removing 2 "AA"'s is 
// pointless kyuki fir the window will be lenght 3, jabki we already have length 4, so we use if, so that agar window, 5 pe
// condition fails, then we only remove 1 letter from the starting
// IN SHORT: hame maxLenght se chota answer nahi chaiye, to we check only for biggger lengths.
            if((right - left + 1)- maxFreq > k) {
                mp[s[left]]--;
                left++;
            } 

            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

// INTUITION

// intuition in this question is ki har bar maxFreq nikal lo hashmap se, then use current windoe length se minus kardo, 
// it will give us the no. of elements that are distinct from maxFreq wala element,  ab agar vo 'k' se kam hai, it means ki 
// we can change them, as soon as they start crossing k, window choti kardo