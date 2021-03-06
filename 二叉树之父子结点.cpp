#include<iostream>
#include<string>
#include <queue>
using namespace std;

class BiTreeNode{
	public:
		char data;
		BiTreeNode* LeftChild;
		BiTreeNode* RightChild;
		BiTreeNode* Parent;
		BiTreeNode():LeftChild(NULL),RightChild(NULL){}
		~BiTreeNode(){}
};

class BiTree{
	private:
		BiTreeNode *Root;
		int pos;
		int count;
		string strTree;
		BiTreeNode* CreateBiTree();
		void PreOrder(BiTreeNode* t);
		void InOrder(BiTreeNode* t);
		void PostOrder(BiTreeNode* t);
		void Leaves(BiTreeNode* t);
		void LevelOrder(BiTreeNode *t);
		void GetChild(BiTreeNode* t);
		void GetParent(BiTreeNode* t);
	public:
		BiTree(){};
		~BiTree(){};
		void CreateTree(string TreeArray);
		void PreOrder();
		void InOrder();
		void PostOrder();
		int Leaves();
		void LevelOrder();
		void GetChild();
		void GetParent();
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

int BiTree::Leaves()
{
	count=0;
	Leaves(Root);
	return count;
}

void BiTree::Leaves(BiTreeNode* t)
{
	if(!t==NULL){
		if(t->LeftChild==NULL&&t->RightChild==NULL){
			count++;	
		}
		Leaves(t->LeftChild);
		Leaves(t->RightChild);
	}
}

void BiTree::GetChild()
{
	GetChild(Root);
}

void BiTree::GetChild(BiTreeNode* t)
{
	if(!t==NULL){
		if(t->LeftChild==NULL&&t->RightChild==NULL){
			cout<<t->data<<' ';	
		}
		GetChild(t->LeftChild);
		GetChild(t->RightChild);
	}
}

void BiTree::GetParent()
{
	GetParent(Root);
}

void BiTree::GetParent(BiTreeNode* t)
{
	if(!t==NULL){
		if(t->LeftChild==NULL&&t->RightChild==NULL){
			cout<<t->Parent->data<<' ';	
		}
		if(!t->LeftChild==NULL){
			t->LeftChild->Parent=t;
		}
		if(!t->RightChild==NULL){
			t->RightChild->Parent=t;
		}
		GetParent(t->LeftChild);
		GetParent(t->RightChild);
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

void BiTree::LevelOrder()
{
	LevelOrder(Root);
}

void BiTree::LevelOrder(BiTreeNode *t)
{
	queue<BiTreeNode*> tq;
	BiTreeNode* p=t;
	if(!p==NULL){
		tq.push(p);
	}
	while(!tq.empty()){
		p=tq.front();
		cout<<p->data;
		tq.pop();
		if(p->LeftChild){
			tq.push(p->LeftChild);
		}
		if(p->RightChild){
			tq.push(p->RightChild);
		}
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
		bitree.GetChild();
		cout<<endl;
		bitree.GetParent();
		cout<<endl;
	}
	return 0;
}