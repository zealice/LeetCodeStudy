//复杂度O(N^2)
//48ms, Your runtime beats 21.80 % of cpp submissions.Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == ""){
            return 0;
        }
        vector <int> a;
        a.push_back(s[0]);
        int num = 1;
        vector<int>::iterator it;
        for(int i = 1;i < s.length();i ++){
	        while(1){
                it=find(a.begin(),a.end(),s[i]);
                if (it!=a.end()){
                    a.erase(a.begin());
                    continue;
                }else{
                    a.push_back(s[i]);
                    if(num < a.size()){
                        num = a.size();
                    }
                    break;
                }                
            }
        }
        return num;
    }
};
