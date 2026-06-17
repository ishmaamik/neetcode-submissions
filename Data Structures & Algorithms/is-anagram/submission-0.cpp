//BRUTE FORCE SOLUTION:
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         map<char, int> m1;
//         map<char, int> m2;

//         for(auto& a: s){
//             m1[a]++;
//         }

//         for(auto& a: t){
//             m2[a]++;
//         }

//         if(m1==m2) return true;
        
//         return false;
//     }
// };

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26,0);

        for(auto& a: s){
            freq[a-'a']++;
        }

        for(auto& a: t){
            freq[a-'a']--;
        }

        for(auto& a: freq){
            if(a!=0) return false;
        }

        return true;
    }
};