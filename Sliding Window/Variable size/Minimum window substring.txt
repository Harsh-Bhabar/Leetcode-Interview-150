class Solution {
public:
    string minWindow(string s, string t) {
        long tSize = t.size();
        long sSize = s.size();

        if(tSize > sSize){
            return "";
        } 

        string ans = "";
        long i = 0;
        long j = 0;
        int start = 0;
        int end = 0 ;
        unordered_map<char, long> mp;
        long mxlen = INT_MAX;

        for(auto c: t){
            mp[c]++;
        }

        long mapCnt = mp.size();

        while(j < sSize){
            if(mp.find(s[j]) != mp.end()){ // if required char 
                mp[s[j]]--; // decrease the needed freq
                if(mp[s[j]] == 0){ // if freq == 0 
                    mapCnt--; // these many chars needed
                }
            }
            if(mapCnt == 0){
                while(mapCnt == 0 and i<=j){ // if we've all needed chars
                    if(mxlen > j-i+1){ // since we need the minimum window
                        mxlen = j-i+1; 
                        start = i;
                        end = mxlen;
                        // ans = s.substr(i, mxlen); // this gives MLE
                    }
                    if(mp.find(s[i]) != mp.end()){ // if removed char is needed char
                        mp[s[i]]++; // add freq to map again
                        if(mp[s[i]] == 1){ // from 0->1 means we've extra 
                            mapCnt++;
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        
        return s.substr(start, end);
    }
};