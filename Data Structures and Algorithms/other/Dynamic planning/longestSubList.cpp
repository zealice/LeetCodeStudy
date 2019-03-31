#include<iostream>
#include<string>
//#include<cstring>
#include<vector>
using namespace std;

//最长公共子序列问题
//最长公共子序列问题是要找到两个字符串间的最长公共子序列。
//假设有两个字符串sudjxidjs和xidjxidpolkj，其中djxidj就是他们的最长公共子序列。
//许多问题都可以看成是公共子序列的变形。例如语音识别问题就可以看成最长公共子序列问题。
//主要是掌握状态的转移
//分治思想，从右往左看，相同则比两个的子序列，不同则...。普通递归（自上而下）
vector<int> longLst(vector<int> &lst1, vector<int> &lst2){
	if (lst1.empty() || lst2.empty())return vector<int>();
	vector<int> result;
	int m = lst1.size();
	int n = lst2.size();
	if (lst1[m-1] == lst2[n-1]){
		vector<int> sublst1(lst1.begin(), lst1.end() - 1);
		vector<int> sublst2(lst2.begin(), lst2.end() - 1);
		result = longLst(sublst1, sublst2);
		result.push_back(lst1[m - 1]);
	}
	else{
		vector<int> sublst1(lst1.begin(), lst1.end() - 1);
		vector<int> sublst2(lst2.begin(), lst2.end() - 1);
		vector<int> result1 = longLst(lst1, sublst2);
		result = longLst(sublst1, lst2);                      //重复计算
		result = (result.size() > result1.size()) ? result: result1;
	}
	return result;
}
//动态规划（自下而上，存入规划表，避免重复计算）
vector<int> longLst1(vector<int> &lst1, vector<int> &lst2){
	if (lst1.empty() || lst2.empty())return vector<int>();
	int m = lst1.size();
	int n = lst2.size();
	vector<vector<vector<int>>> lstArr(m + 1, vector<vector<int>>(n + 1, vector<int>()));
	for (int raw = 1; raw <= m; raw++){
		for (int col = 1; col <= n; col++){
			if (lst1[raw-1] == lst2[col-1]){
				lstArr[raw][col] = lstArr[raw-1][col-1];
				lstArr[raw][col].push_back(lst1[raw - 1]);//相等时，将该元素放入子序列
			}
			else{
				lstArr[raw][col] = (lstArr[raw-1][col].size()>lstArr[raw][col-1].size()) ? lstArr[raw-1][col] : lstArr[raw][col-1];//不等时，等于之前两个子序列中的较大的那个
			}
		}
	}
	return lstArr[m][n];
}
//总结：思考自上而下，编程要自下而上。


//最长公共子字符串（区别于最长公共子序列，子序列各元素有序不用连续，而相同的子字符串是两段有序且连续的相同字符串）
//分治思想1（从左往右看，字符相同就两字符串都看右一个字符，若不相同则先将左边已判断相同的这个子字符串保存下来，再看后面剩余的两个字符串的最长子串等于什么）（1、2处有重复的子问题，最好用动态规划）
string longString(string & str1, string & str2){
	vector<string> strv;
	if (str1 == "" || str2 == "")return "";
	int len = (str1.size() < str2.size()) ? str1.size() : str2.size();
	for (int i = 0; i < len; i++){
		if (str1[i] != str2[i]){
			strv.push_back(str1.substr(0, i));
			strv.push_back(longString(str1.substr(i + 1), str2.substr(i)));//1
			strv.push_back(longString(str1.substr(i), str2.substr(i + 1)));//2
			break;
		}
		else if (i == len - 1){
			strv.push_back(str1.substr(0, len));
			break;
		}
	}
	vector<string>::iterator max=strv.begin();
	vector<string>::iterator it = strv.begin();
	while (it != strv.end()){
		if (max->size() < it->size()){
			max = it;
		}
		it++;
	}
	return *max;
}
//分治2（字符串从右往左）
string longString1(string  &str1, string  &str2){
	if (str1 == "" || str2 == "")return "";
	vector<string> strv;
	int m = str1.size();
	int n = str2.size();
	while (str1[m - 1] == str2[n - 1]){
		if (m == 1){
			return str1;
		}
		if (n == 1){
			return str2;
		}
		m--;
		n--;
	}
	strv.push_back(str1.substr(m));
	string result1 = longString1(str1.substr(0, m), str2.substr(0, n - 1));
	string result = longString1(str1.substr(0, m - 1), str2.substr(0, n));
	result = (result1.size() > result.size())? result1:result;
	strv.push_back(result);
	vector<string>::iterator max = strv.begin();
	vector<string>::iterator it = strv.begin();
	while (it != strv.end()){
		if (max->size() < it->size()){
			max = it;
		}
		it++;
	}
	return *max;
}
//动态规划（规划表，避免重复计算）
string longString2(string  &str1, string  &str2){
	if (str1 == "" || str2 == "")return "";
	int m = str1.size();
	int n = str2.size();
	string max = "";
	vector<vector<string>> strArr(m+1, vector<string>(n+1,""));
	for (int raw = 1; raw <= m; raw++){
		for (int col = 1; col <= n; col++){
			if (str1[raw-1] == str2[col-1]){
				strArr[raw][col] = strArr[raw - 1][col - 1] + str1[raw-1];
				if (max.size() < strArr[raw][col].size()){
					max = strArr[raw][col];
				}
			}
		}
	}
	return max;
}

int main(){
	string str1 = "abcdaac";
	string str2 = "adbcd";
	string str3 = longString2(str1, str2);
	vector<int> lst1(4);
	vector<int> lst2(5);
	lst1[0] = 1;
	lst1[1] = 5;
	lst1[2] = 7;
	lst1[3] = 6;

	lst2[0] = 1;
	lst2[1] = 7;
	lst2[2] = 6;
	lst2[3] = 5;
	lst2[4] = 0;
	vector<int> lst3 = longLst1(lst1, lst2);
	return 0;
}