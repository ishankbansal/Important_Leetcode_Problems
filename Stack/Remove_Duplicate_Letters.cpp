/*
Problem link : https://leetcode.com/problems/remove-duplicate-letters/

Approach :-
* whenever we encounter a character which is not included in our answer we will try to place it according to lexographical order
* to maintain the order whenever we get a character we will remove all the character from the result string string from back which are lexographically greater and are available in future
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        string ans = "";
        vector<int> freq(26, 0);
        vector<bool> present(26, false);
        
        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']++;
        }
        
        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']--;
            if(present[s[i] - 'a']){
                continue;
            }
            while(ans.length() && s[i] < ans.back() && freq[ans.back() - 'a']){
                present[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans += s[i];
            present[s[i] - 'a'] = true;
        }
        
        return ans;
    }
};