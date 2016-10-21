#include<iostream>
#include<string>
#include<cstring>
using namespace std;
 
const int MaxW=9999;//����ڵ�Ȩֵ������9999
 
 
class HuffNode
{
public:
    int weight;//Ȩֵ
    int parent;//���ڵ��±�
    int leftchild;//�����±�
    int rightchild;//�Һ����±�
};
 
//�������������
class HuffMan
{
private:
    void MakeTree();//������˽�к����������к�������
    void SelectMin(int pos,int *s1,int *s2);//��1��pos��λ���ҵ�Ȩֵ��С��������㣬�ѽ���±����s1��s2��
public:
    int len;//�������
    int lnum;//Ҷ������
    HuffNode *huffTree;//�շ��������������ʾ
    string *huffCode;//ÿ���ַ���Ӧ�ĺշ�������
    void MakeTree(int n,int wt[]);//���к�������������main����
    void Coding();//���к�������������main����
    void Destory();
};
 
//����huffman��
void HuffMan::MakeTree(int n,int wt[])
{//���к���������ӿ�
    int i;
    lnum=n;
    len=2*n-1;
    huffTree=new HuffNode[2*n];
    huffCode=new string[lnum+1];//λ�ô�1��ʼ����
    //huffCodeʵ���Ǹ���ά�ַ����飬��i�б�ʾ��i���ַ���Ӧ�ı���
    //�շ�����huffTree��ʼ��
    for(i=1;i<=n;i++)
        huffTree[i].weight=wt[i-1];
    for(i=1;i<=len;i++)
    {
        if(i>n) huffTree[i].weight=0;//ǰn�������Ҷ�ӣ��Ѿ���ֵ
        huffTree[i].parent=0;
        huffTree[i].leftchild=0;
        huffTree[i].rightchild=0;
    }
    MakeTree();//����˽�к�������
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

//�շ�������
void HuffMan::Coding()
{
    char *cd;
    int i,c,f,start;
    //��n��Ҷ�ڵ�Ļ���������
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
