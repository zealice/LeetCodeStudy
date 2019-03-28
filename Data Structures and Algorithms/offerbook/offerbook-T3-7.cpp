#include<iostream>
#include<string>
//#include<cstring>
#include<vector>
using namespace std;

//T5�滻�ո�
void replaceSpace(char *str, int length) {
	if (str == NULL || length <= 0)return;
	int index = 0, numOfBlank = 0, oLength = 0, trueLength;

	while (str[index] != '\0'){
		oLength++;
		if (str[index] == ' '){
			//str = str.substr(0, index) + "%%20" + str.substr(index +1);
			numOfBlank++;
		}
		index++;
	}
	trueLength = oLength + 2 * numOfBlank;
	if (trueLength > length)return;
	int p1 = oLength;
	int p2 = trueLength;
	while (p1 != p2){
		if (str[p1] != ' '){
			str[p2] = str[p1];
			p1--;
			p2--;
		}
		else{
			p1--;
			str[p2] = '0';
			str[p2 - 1] = '2';
			str[p2 - 2] = '%';
			p2 -= 3;
		}
	}

}
//T5.2�����Ŀ���ϲ�����
int* hebingArray(int* A1, int *A2,int size,int n,int m){//size��A1�ܴ�С��n��m�ֱ���A1A2��Ԫ�ظ���
	if (A1 == NULL || A2 == NULL || (n == 0 && m == 0) || size < n + m) return NULL;
	int p = n + m - 1;
	int p1 = n - 1;
	int p2 = m - 1;
	while (p1 >= 0 && p2 >= 0 && p>=0){
		if (A1[p1] > A2[p2]){
			A1[p] = A1[p1];
			p1--;
		}
		else{
			A1[p] = A2[p2];
			p2--;
		}
		p--;
	}
	while (p1 >= 0 && p>=0){
		A1[p] = A1[p1];
		p--;
		p1--;
	}
	while (p2 >= 0 && p >= 0){
		A1[p] = A2[p2];
		p--;
		p2--;
	}
	return A1;
}

//T4��ά�����еĲ���
bool Find(int target, vector<vector<int> > array) {
	bool FindFlag = false;
	if (array.size() == 0)return FindFlag;
	int hang = array.size();//sizeof(array) / sizeof(int) / (sizeof(array[0]) / sizeof(int));
	int lie = array[0].size();//sizeof(array[0])/sizeof(int);
	int ph = 0;
	int pl = lie - 1;
	while (ph<hang && pl >= 0){
		if (target == array[ph][pl]){
			FindFlag = true;
			break;
		}
		else if (target > array[ph][pl]){
			ph++;
		}
		else{
			pl--;
		}
	}
	return FindFlag;
}

//t7�ؽ�������
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	if (pre.empty() || vin.empty())return NULL;
	TreeNode *root = new TreeNode(pre[0]);
	if (pre.size() == 1 && vin.size() == 1 && pre[0] == vin[0]){
		return root;
	}
	vector<int>::iterator it = find(vin.begin(), vin.end(), pre[0]);
	if (it == vin.end()){
		throw ("Invalid input.");//δ�ҵ�
	}
	else{
		int index = &*it - &vin[0];//&*it-&vin.begin()����,�����������޷����
		if (index > 0){
			vector<int> leftPre(pre.begin() + 1, pre.begin() + index + 1);
			vector<int> leftVin(vin.begin(), it);
			root->left = reConstructBinaryTree(leftPre, leftVin);
		}
		if (index < vin.size() - 1){
			vector<int> rightPre(pre.begin() + 1 + index, pre.end());
			vector<int> rightVin(it + 1, vin.end());
			root->right = reConstructBinaryTree(rightPre, rightVin);
		}
		return root;
	}
}

//T3�������ظ�������
bool dublicate(int num[], int length, int * dupliation){
	if (num == NULL || length <= 0){
		return false;
	}
	for (int i = 0; i < length;){
		if (num[i]>length) {
			cout << "error" << endl;
			return false;
		}
		if (num[i] == i){
			i++;
		}
		else if (num[i] == num[num[i]]){
			*dupliation = num[i];
			return true;
		}
		else{
			int temp = num[num[i]];
			num[num[i]] = num[i];
			num[i] = temp;
		}
	}
	return false;
}
//T3.2
bool duplicate2(int num[], int length, int start, int end, int * dup){
	*dup = -1;//û���ظ�ʱ�����-1
	if (num == NULL || length <= 0 || start > end){
		return false;
	}
	int sum = 0;//��¼�����У���С��start��end��Χ�ڵ�Ԫ�ظ���
	for (int i = 0; i < length; i++){
		if (num[i] <= end && num[i] >= start){
			sum++;
		}
	}
	if (sum > end - start + 1){
		if (start == end){
			*dup = start;
			return true;
		}
		//int m = (end - start + 2) / 2;//��λ��ȡ�ô��󡣡�
		int m = (end + start) / 2;
		int* dupl= new int();
		int* dupr= new int();
		bool left = duplicate2(num, length, start, m, dupl);//��������д��룬�����õݹ�����鷳����ΪֻҪ�ҵ���������Ͼ��ܷ��ص����������õݹ黹��һ��һ�㷵�أ�̫�鷳��������ѭ���á�
		if (left == true){
			*dup = *dupl;
			return true;
		}
		bool right = duplicate2(num, length, m + 1, end, dupr);
		if (right == true){
			*dup = *dupr;
			return true;
		}

	}
	return false;

}


//T6��β��ͷ��ӡ����
struct ListNode {
       int val;
       struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
       }
  };
vector<int> printListFromTailToHead(ListNode* head) {
	//if(head == NULL){return -1;}
	while (head != NULL){
		ListNode* pNode = head;
		vector<int> *p = new vector<int>;
		while (pNode != NULL){
			p->insert(p->begin(), pNode->val);
			pNode = pNode->next;
		}
		return *p;
	}

}


int main(){
	//char str[] = "we are happy";
	//replaceSpace(str, 100);
	//ListNode* p = NULL;
	//printListFromTailToHead(p);
	//vector<vector<int>> arr = { { 1, 2, 3 }, { 4, 5, 6 }, {8,9,10} };
	//bool flag = Find(7, arr);
	//int a[10];
	//char b[3] = {'1','2','3'};
	//string c = "123";
	//cout << sizeof(a) << endl<<sizeof(b) <<endl << sizeof(c)<<endl;
	//cout << strlen(b) << endl << c.length() << c.size() << strlen(c.c_str())<<endl;
	//vector<int> *p = new vector<int>(10,2);
	//p->push_back(0);
	//vector<int> pre = {1};// , 2, 4, 7, 3, 5, 6};
	//vector<int> vin = { 4 };// , 7, 2, 1, 5, 3, 8, 6 };
	//TreeNode* p;
	//try{
	//	p = reConstructBinaryTree(pre, vin);
	//}
	//catch (...){
	//	cerr << "invalid input";
	//}
	int arr[5] = { 1,5 };
	int arr1[3] = { 0,1,10 };
	//int* arr1 = NULL;
	//int* a = new int();//ָ����ʹ��ǰ�����ʼ��
	//cout << duplicate2(arr, 5, 1, 4, a) << endl;
	int*p = hebingArray(arr, arr1, 5, 2, 3);
	return 0;
}