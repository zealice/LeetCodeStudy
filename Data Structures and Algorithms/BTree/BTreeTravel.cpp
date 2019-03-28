#include<iostream>
//#include<vector>
#include<array>
#include<string>
#include<stack>
using namespace std;

struct BSTreeNode{
	int data;
	BSTreeNode* left;
	BSTreeNode* right;
	BSTreeNode(int d) :data(d),left(nullptr),right(nullptr){}
};

//递归法
void midTravel(BSTreeNode * root){//中
	if (root == NULL){
		return;
	}
	midTravel(root->left);
	cout << root->data << " ";
	midTravel(root->right);
}

void preTravel(BSTreeNode * root){//前
	if (root == NULL){
		return;
	}
	cout << root->data << " ";
	preTravel(root->left);
	preTravel(root->right);
}

void backTravel(BSTreeNode * root){//后
	if (root == NULL){
		return;
	}
	backTravel(root->left);
	backTravel(root->right);
	cout << root->data << " ";
}

//循环法（写出流程或画出流程图，更清晰）

void preTravel1(BSTreeNode * root){//前
	BSTreeNode *p = root;
	stack<BSTreeNode*> stackNode;
	while (p != nullptr || !(stackNode.empty())){
		cout << p->data << " ";
		stackNode.push(p);
		p = p->left;
		while (p == nullptr && !stackNode.empty()){
			p = stackNode.top();
			stackNode.pop();
			p = p->right;
		}
	}
}


void midTravel1(BSTreeNode * root){//中
	BSTreeNode *p = root;
	stack<BSTreeNode*> stackNode;
	while (p != nullptr || !(stackNode.empty())){
		stackNode.push(p);
		p = p->left;
		while (p == nullptr && !stackNode.empty()){
			p = stackNode.top();
			stackNode.pop();
			cout << p->data << " ";
			p = p->right;
		}
	}
}

void backTravel1(BSTreeNode * root){//后
	BSTreeNode *p = root;
	BSTreeNode *pre = nullptr;//指向刚刚输出的node
	stack<BSTreeNode*> stackNode;

	while (p != nullptr){
		stackNode.push(p);
		p = p->left;
		if (p == nullptr){
			while (!stackNode.empty()) {
				p = stackNode.top()->right;
				if (p != nullptr && pre != p){
					break;
				}
				p = stackNode.top();
				cout << p->data << " ";
				pre = p;
				stackNode.pop();
			}
		}
		if (stackNode.empty()){//因为输出一个，就pop一个，全部pop完，代表全部输出了。
			break;
		}
	}
}

int main(){
	//int arr[] = { 4, 3, 2, 4, 5, 8, 0};
	//quickSort(arr, 0, sizeof(arr) / sizeof(int)-1);
	//guibingSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	//xuanzeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	//charuSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	//paoSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	//heapSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	//array.sort(arr);
	//int* p;
	//int *a = nullptr;
	//string c;
	//c = "123";
	//c[1] = '4';
	//int arr[] = { 1, 2, 3 };
	//char arr1[] = "123";

	//char* ps="123";
	////*ps = "123";
	//int *a1 = new int;
	//int (*a2)[5] = new int[2][5];//
	//int *a3 = new int[5];
	//cout << arr << endl;
	//cout << arr1 << endl;
	//cout << *ps << endl<<ps[1]<<endl<<&(ps);
	BSTreeNode *root = new BSTreeNode(1);
	root->left = new BSTreeNode(2);
	root->right = new BSTreeNode(3);
	root->left->left = new BSTreeNode(4);
	root->left->left->right = new BSTreeNode(7);
	root->right->left = new BSTreeNode(5);
	root->right->right = new BSTreeNode(6);
	root->right->right->left = new BSTreeNode(8);
	preTravel(root);
	cout << endl;
	preTravel1(root);
	cout << endl;
	backTravel1(root);
	return 0;
}