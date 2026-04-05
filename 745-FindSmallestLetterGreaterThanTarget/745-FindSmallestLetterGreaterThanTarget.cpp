// Last updated: 4/5/2026, 11:45:21 AM
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(int i=0;i<letters.size();i++)  if(target<letters[i])  return letters[i];
        return letters[0];
    }
};