#include<iostream>
#include<string>
using namespace std;

class BiTreeNode{
	public:
		char data;
		BiTreeNode* LeftChild;
		BiTreeNode* RightChild;
		BiTreeNode():LeftChild(NULL),RightChild(NULL){}
		~BiTreeNode(){}
};

class BiTree{
	private:
		BiTreeNode *Root;
		int pos;
		string strTree;
		BiTreeNode* CreateBiTree();
		void PreOrder(BiTreeNode* t);
		void InOrder(BiTreeNode* t);
		void PostOrder(BiTreeNode* t);
	public:
		BiTree(){};
		~BiTree(){};
		void CreateTree(string TreeArray);
		void PreOrder();
		void InOrder();
		void PostOrder();
};

void BiTree::CreateTree(string TreeArray)
{
	pos=0;
	strTree.assign(TreeArray);
	Root = CreateBiTree();
}

BiTreeNode* BiTree::CreateBiTree()
{
	BiTreeNode *T;
	char ch;
	ch=strTree[pos++];
	if(ch=='0')
		T = NULL;
	else
	{
		T=new BiTreeNode();
		T->data = ch;
		T->LeftChild = CreateBiTree();
		T->RightChild = CreateBiTree();
	}
	return T;
}

void BiTree::PreOrder()
{
	PreOrder(Root);
}

void BiTree::PreOrder(BiTreeNode* t)
{
	if(!t==NULL){
		cout<<t->data;
		PreOrder(t->LeftChild);
		PreOrder(t->RightChild);
	}
}

void BiTree::InOrder()
{
	InOrder(Root);
}

void BiTree::InOrder(BiTreeNode* t)
{
	if(!t==NULL){
		InOrder(t->LeftChild);
		cout<<t->data;
		InOrder(t->RightChild);
	}
}

void BiTree::PostOrder()
{
	PostOrder(Root);
}

void BiTree::PostOrder(BiTreeNode* t)
{
	if(!t==NULL){
		PostOrder(t->LeftChild);
		PostOrder(t->RightChild);
		cout<<t->data;
	}
}

int main(void)
{
	BiTree bitree;
	string str;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>str;
		bitree.CreateTree(str);
		bitree.PreOrder();
		cout<<endl;
		bitree.InOrder();
		cout<<endl;
		bitree.PostOrder();
		cout<<endl;
	}
	return 0;
}