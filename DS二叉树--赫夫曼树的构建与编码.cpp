#include<iostream>
#include<string>
#include<cstring>
using namespace std;
 
const int MaxW=9999;//假设节点权值不超过9999
 
 
class HuffNode
{
public:
    int weight;//权值
    int parent;//父节点下标
    int leftchild;//左孩子下标
    int rightchild;//右孩子下标
};
 
//定义霍夫曼树类
class HuffMan
{
private:
    void MakeTree();//建树，私有函数，被共有函数调用
    void SelectMin(int pos,int *s1,int *s2);//从1到pos的位置找到权值最小的两个结点，把结点下标存在s1和s2中
public:
    int len;//结点数量
    int lnum;//叶子数量
    HuffNode *huffTree;//赫夫曼数，用数组表示
    string *huffCode;//每个字符对应的赫夫曼编码
    void MakeTree(int n,int wt[]);//共有函数，被主函数main调用
    void Coding();//共有函数，被主函数main调用
    void Destory();
};
 
//构建huffman树
void HuffMan::MakeTree(int n,int wt[])
{//共有函数，对外接口
    int i;
    lnum=n;
    len=2*n-1;
    huffTree=new HuffNode[2*n];
    huffCode=new string[lnum+1];//位置从1开始计算
    //huffCode实质是个二维字符数组，第i行表示第i个字符对应的编码
    //赫夫曼数huffTree初始化
    for(i=1;i<=n;i++)
        huffTree[i].weight=wt[i-1];
    for(i=1;i<=len;i++)
    {
        if(i>n) huffTree[i].weight=0;//前n个结点是叶子，已经设值
        huffTree[i].parent=0;
        huffTree[i].leftchild=0;
        huffTree[i].rightchild=0;
    }
    MakeTree();//调用私有函数建树
}
 
void HuffMan::SelectMin(int pos,int *s1,int *s2)
{
    int w1,w2,i;
    w1=w2=MaxW;
    *s1=*s2=0;
    for(i=1;i<=pos;i++)
    {
        if(huffTree[i].weight<w1 && huffTree[i].parent==0)
        {
            *s2=*s1;w2=w1;
            w1=huffTree[i].weight;*s1=i;
        }
        else if(huffTree[i].weight<w2&& huffTree[i].parent==0)
        {
            w2=huffTree[i].weight;*s2=i;
        }
    }
}
 
 
void HuffMan::MakeTree()
{
    int i,s1,s2;
    for(i=lnum+1;i<=len;i++)
    {
        SelectMin(i-1,&s1,&s2);
        huffTree[s1].parent=i;
        huffTree[s2].parent=i;
        huffTree[i].leftchild=s1;
        huffTree[i].rightchild=s2;
        huffTree[i].weight=huffTree[s1].weight+huffTree[s2].weight;
    }
}
void HuffMan::Destory()
{
    len=0;
    lnum=0;
    delete []huffTree;
    delete []huffCode;
}

//赫夫曼编码
void HuffMan::Coding()
{
    char *cd;
    int i,c,f,start;
    //求n个叶节点的霍夫曼编码
    cd=new char[lnum];
    cd[lnum-1]='\0';
    for(i=1;i<=lnum;++i)
    {
        start=lnum-1;
        for(c=i,f=huffTree[i].parent;f!=0;c=f,f=huffTree[f].parent)
            if(huffTree[f].leftchild==c)
                cd[--start]='0';
            else
                cd[--start]='1';
            huffCode[i]=new char[lnum-start];
            huffCode[i].assign(&cd[start]);
    }
    delete []cd;
}
 
 
int main()
{
    int t,n,i,j;
    int wt[800];
    HuffMan myHuff;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        for(j=0;j<n;j++)
            cin>>wt[j];
        myHuff.MakeTree(n,wt);
        myHuff.Coding();
        for(j=1;j<=n;j++)
        {
            cout<<myHuff.huffTree[j].weight<<'-';
            cout<<myHuff.huffCode[j]<<endl;
        }
        myHuff.Destory();
    }
    return 0;
}
