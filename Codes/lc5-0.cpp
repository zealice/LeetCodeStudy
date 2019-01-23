#include<iostream>
#include<string>
using namespace std;
//蛮力解决，复杂度O(n^3)
//1760 ms, faster than 0.99% of C++ online submissions for Longest Palindromic Substring.
string longestPalindrome(string s) {
	int i, j, k;
	bool f = true;
	string vs = "";
	string subs;
	for (i = 0; i < s.length(); i++){
		for (j = 1; j <= s.length() - i; j++){
			subs = s.substr(i, j);
			if (subs.length() % 2 == 0){//偶数
				for (k = 0; k < subs.length() / 2; k++){
					if (subs[subs.length() / 2 - 1 - k] != subs[subs.length() / 2 + k]){
						f = false;//不是回文
						break;
					}
				}
				if (f && subs.length() > vs.length()){
					vs = subs;
				}
			}
			else{//奇数
				for (k = 0; k <= (subs.length() - 1) / 2; k++){
					if (subs[(subs.length() - 1) / 2 - k] != subs[(subs.length() - 1) / 2 + k]){
						f = false;//不是回文
						break;
					}
				}
				if (f && subs.length() > vs.length()){
					vs = subs;
				}
			}
			f = true;//复位
		}
	}
	return vs;
}

void main(){
	string s = "babad";
	string so;
	so = longestPalindrome(s);
	cout << so << endl;
}
