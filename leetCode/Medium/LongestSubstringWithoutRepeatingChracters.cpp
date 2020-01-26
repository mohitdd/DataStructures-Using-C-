class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") {
            return 0;
        }
        int start=0;
        int end=0;
        int max = end-start;
        
        map<char,int> queryMap;
        map<char,int>::iterator itr;
        
        for(int i=0; i<s.length();i++) {
            itr = queryMap.find(s[i]);
            if(itr == queryMap.end()) {
                queryMap.insert(make_pair(s[i],i));
                end=i;
            }
            else if(itr->second < start) {
                queryMap.erase(s[i]);
                queryMap.insert({s[i], i});
                end=i;
            }
            else {
                if(i-itr->second == 1 ) {
                    queryMap.clear();
                    end=i;
                    start=i;
                    queryMap.insert({s[i], i});
                }
                else {
                start=itr->second+1;
                queryMap.erase(s[i]);
                queryMap.insert({s[i], i});
                
                end=i;
                }
            }
            max = (end-start > max) ? (end-start) : max;
        }
      
        return max+1;
    }
};