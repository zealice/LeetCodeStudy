#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

int main(){
	string eFile;//�����ļ���¼
	//string eFname[8]={""};
	vector<string> eFname;//���ļ���
	vector<int> eCount;//�������
	int j = 0;//���ļ��±�
	while (getline(cin, eFile) && eFile != ""){
		int lenF = eFile.length();
		int n = 1;
		while (n != lenF && eFile[lenF - n - 1] != '\\')n++;
		int k = 0;
		while (k < j && eFname[k] != eFile.substr(lenF - n, n))k++;
		if (k == j){
			eFname.push_back(eFile.substr(lenF - n, n));
			eCount.push_back(1);
			j++;
		}
		else if (k < j){
			eCount[k]++;
		}
		eFile = "";
		//if (j == 8)break;
	}
	if (eFname[0] == "")return 0;//û�м�¼
	for (int i = 0; i < 8 && i < eFname.size(); i++){
		int k = 0;
		while (eFname[i][k] != ' ')k++;
		if (k <= 16){
			cout << eFname[i] << " " << eCount[i] << endl;
		}
		else{
			cout << eFname[i].substr(k - 16, eFname[i].length() - k + 16) << " " << eCount[i] << endl;
		}
	}
	return 0;
}