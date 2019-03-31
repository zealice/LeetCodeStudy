#include<iostream>
#include<string>
//#include<cstring>
#include<vector>
using namespace std;

//���������������
//�����������������Ҫ�ҵ������ַ����������������С�
//�����������ַ���sudjxidjs��xidjxidpolkj������djxidj�������ǵ�����������С�
//������ⶼ���Կ����ǹ��������еı��Ρ���������ʶ������Ϳ��Կ�����������������⡣
//��Ҫ������״̬��ת��
//����˼�룬�������󿴣���ͬ��������������У���ͬ��...����ͨ�ݹ飨���϶��£�
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
		result = longLst(sublst1, lst2);                      //�ظ�����
		result = (result.size() > result1.size()) ? result: result1;
	}
	return result;
}
//��̬�滮�����¶��ϣ�����滮�������ظ����㣩
vector<int> longLst1(vector<int> &lst1, vector<int> &lst2){
	if (lst1.empty() || lst2.empty())return vector<int>();
	int m = lst1.size();
	int n = lst2.size();
	vector<vector<vector<int>>> lstArr(m + 1, vector<vector<int>>(n + 1, vector<int>()));
	for (int raw = 1; raw <= m; raw++){
		for (int col = 1; col <= n; col++){
			if (lst1[raw-1] == lst2[col-1]){
				lstArr[raw][col] = lstArr[raw-1][col-1];
				lstArr[raw][col].push_back(lst1[raw - 1]);//���ʱ������Ԫ�ط���������
			}
			else{
				lstArr[raw][col] = (lstArr[raw-1][col].size()>lstArr[raw][col-1].size()) ? lstArr[raw-1][col] : lstArr[raw][col-1];//����ʱ������֮ǰ�����������еĽϴ���Ǹ�
			}
		}
	}
	return lstArr[m][n];
}
//�ܽ᣺˼�����϶��£����Ҫ���¶��ϡ�


//��������ַ���������������������У������и�Ԫ������������������ͬ�����ַ�����������������������ͬ�ַ�����
//����˼��1���������ҿ����ַ���ͬ�����ַ���������һ���ַ���������ͬ���Ƚ�������ж���ͬ��������ַ��������������ٿ�����ʣ��������ַ�������Ӵ�����ʲô����1��2�����ظ��������⣬����ö�̬�滮��
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
//����2���ַ�����������
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
//��̬�滮���滮�������ظ����㣩
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