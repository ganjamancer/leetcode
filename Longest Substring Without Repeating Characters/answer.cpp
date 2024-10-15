class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>map;
        int n = s.size();
        int l = 0;
        int m = 0;
        for(int r=0;r<n;r++){
            if(map.find(s[r])==map.end()||map[s[r]]<l){
                m = max(m,r-l+1);
            }
            else{
                l = map[s[r]]+1;
            }
            map[s[r]] = r;
        }
        return m;
    }
};
