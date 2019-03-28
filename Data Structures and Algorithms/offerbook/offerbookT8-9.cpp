#include<iostream>
#include<string>
//#include<cstring>
#include<vector>
#include<queue>
using namespace std;

//T8二叉树的下一个节点
struct TreeNode {
	char chval;
	TreeNode* left;
	TreeNode* right;
	TreeNode* father;
};


TreeNode* findNextNode(TreeNode* p){
	if (p == nullptr){
		return nullptr;
	}
	TreeNode* ans = p;
	if (ans->right != nullptr){
		ans = ans->right;
		while (ans->left != nullptr){
			ans = ans->left;
		}
		return ans;
	}
	else{
		while (ans->father != nullptr){
			if (ans->father->right == ans){
				ans = ans->father;
			}else if (ans->father->left == ans){
				ans = ans->father;
				return ans;
			}
		}
		return nullptr;
	}

};

//T9.2两队列实现一栈
template<typename T> class myStack{
public:
	myStack(){}
	~myStack(){}
	T myPop();
	void myPush(const T&);
private:
	queue<T> q1;
	queue<T> q2;
};

template<typename T>
void myStack<T>::myPush(const T& element){
	if (q2.empty()){
		q1.push(element);
	}
	else if (!q2.empty() && q1.empty()){
		q2.push(element);
	}
	else{
		throw ("error");
	}
}

template<typename T>
T myStack<T>::myPop(){
	if (q1.size()>0 && q2.size() == 0){
	while (q1.size()>1){
		T temp = q1.front();
		q2.push(temp);
		q1.pop();
	}
	T temp = q1.front();
	q1.pop();
	return temp;
	}
	else if (q2.size() > 0 && q1.size() == 0){
		while (q2.size() > 1){
			T temp = q2.front();
			q1.push(temp);
			q2.pop();
		}
		T temp = q2.front();
		q2.pop();
		return temp;
	}
	else if (q2.size() == 0 && q1.size() == 0){
		throw  ("empty");
	}
	else{
		throw ("error");
	}
}

int main(){
	myStack<int> intS;
	intS.myPush(1);
	intS.myPush(2);
	intS.myPop();
	intS.myPop();
	intS.myPop();
	return 0;

}