//#include<iostream>
//
//using namespace std;
//
////������ʵ��ջ����������Ϊ0��λ��Ϊջ�ף�����topָ��ջ��  
//template<typename T>  
//class Stack  
//{  
//public:  
//    Stack(int capcity=20);  
//    ~Stack();  
//    void ClearStack();  
//    bool isEmpty();  
//    bool isFull();  
//    int StackLength();    
//    T GetTop();  
//    void Push(T e);  
//    void Pop();   
//private:  
//    T* elemArray;  
//    int top;  
//    int capcity;  
//}; 
//
//template<typename T>  
//Stack<T>::Stack(int capcity)  
//{  
//    if (capcity<0)  
//        return;   
//    this->capcity=capcity;  
//    top=0;  
//    elemArray=new T[capcity];  
//}  
//      
//template<typename T>  
//Stack<T>::~Stack()  
//{  
//    delete[] elemArray;  
//}  
//      
//template<typename T>  
//void Stack<T>::ClearStack()  
//{  
//    top=0;  
//}  
//      
//template<typename T>  
//bool Stack<T>::isEmpty()  
//{  
//    return (top==0);  
//}  
//      
//template<typename T>  
//bool Stack<T>::isFull()  
//{  
//    return (top==capcity);  
//}  
//      
//template<typename T>  
//int Stack<T>::StackLength()  
//{  
//    return top;  
//}  
//      
//template<typename T>  
//T Stack<T>::GetTop()  
//{  
//    if (isEmpty())  
//        return 0;   
//    return elemArray[top-1];  
//}  
//      
//template<typename T>  
//void Stack<T>::Push(T e)  
//{  
//    if (isFull())  
//    {  
//        cout<<"The stack is full"<<endl;  
//        return;  
//    }  
//    elemArray[top]=e;  
//    top++;    
//}  
//      
//template<typename T>  
//void Stack<T>::Pop()  
//{  
//    if (isEmpty())  
//        return ;  
//    top--;  
//}  
//
//void main(){
//	Stack<int> s1;  
//    s1.Push(10);  
//    s1.Push(21);  
//    s1.Push(32);  
//    s1.Push(32); 
//	cout<<s1.StackLength()<<endl;
//	while(!s1.isEmpty())
//	{
//		cout<<s1.GetTop()<<"  ";//������3 2 1 0  
//		s1.Pop();
//	}
//	cout<<endl;
//	s1.ClearStack(); 
//}


#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAXSIZE   0xFFFF

template<class type>
class SeqStack
{
	int   top;        //ջ��ָʾ
	type *stacka;     //������
	int   maxsize;    //ջ��������Ԫ�ظ���
public:
	SeqStack();
	SeqStack(int size);
	SeqStack(type data[],int size);
	~SeqStack()
	{
	   delete []stacka;
	}

	void Push(const type &item);    //Ԫ��itemѹջ
	void Pop();        //����Ԫ�س�ջ,����֮
	type Top();       //��ջ������Ԫ�ز�����

	int   Empty()const
	{
	   return top==-1;
	}           //�ж�ջ�Ƿ�Ϊ��
	int   Full()const
	{
	   return top==maxsize-1;
	}           //�ж�ջ�Ƿ�Ϊ��
	void Clear()
	{
	   top=-1;
	}           //���ջ
};

template<class type>
SeqStack<type>::SeqStack():top(-1),maxsize(MAXSIZE)
{
	stacka=new type[maxsize];
	if(stacka==NULL){
	   cerr<<"��̬�洢����ʧ��!"<<endl;
	   exit(1);
	}
}

template<class type>
SeqStack<type>::SeqStack(int size):top(-1),maxsize(size)
{
	stacka=new type[maxsize];    //�����洢ջ������

	if(stacka==NULL){      //���䲻�ɹ�
	   cerr<<"��̬�洢����ʧ��!"<<endl;
	   exit(1);
	}
}

template<class type>
SeqStack<type>::SeqStack(type data[],int size):top(-1),maxsize(size)
{
	stacka=new type[maxsize];    //�����洢ջ������

	if(stacka==NULL){      //���䲻�ɹ�
	   cerr<<"��̬�洢����ʧ��!"<<endl;
	   exit(1);
	}
	for(int i=0;i<maxsize;i++){
	   stacka[i]=data[i];
	}
    top+=maxsize;
}


template<class type>
void SeqStack<type>::Push(const type& item)
{
	//��ջ�����������������Ԫ��itemѹջ
	if(Full()){         
	   cerr<<"ջ����������ѹջ!"<<endl;
	   exit(1);
	}
	//�������ǲ���ָ�����ƶ���Ȼ���ٶ�Ԫ�ؽ��в����ķ�ʽ
	top++;   
	stacka[top]=item;
}

template<class type>
void SeqStack<type>::Pop()
{
	if(Empty()){
	   cerr<<"ջ�ѿ�!"<<endl;
	   exit(1);
	}
	//ջ���գ���ջ��Ԫ��
	top--;
	//����ջ��Ԫ��
	return ;
}

template<class type>
type SeqStack<type>::Top()
{
	//��ջ���գ�����ջ��Ԫ�ص�ֵ
	if(Empty()){
	   cerr<<"ջ��!"<<endl;
	   exit(1);
	}
	//����ջ��Ԫ�ص�ֵ
	return stacka[top];
}

typedef struct node  
{  
    struct node *leftChild;  
    struct node *rightChild;  
    char data;  
}BiTreeNode, *BiTree;  

void createBiTree(BiTree &T)  
{  
    char c;  
    cin >> c;  
    if('#' == c)  
        T = NULL;  
    else  
    {  
        T = new BiTreeNode;  
        T->data = c;  
        createBiTree(T->leftChild);  
        createBiTree(T->rightChild);  
    }  
}  

void preorder1(BiTree &T){  
       if(T){  
            cout<<T->data;  
			preorder1(T->leftChild);  
			preorder1(T->rightChild);  
       }  
} 

void preorder2(BiTree &T){ 
	BiTree t=T;
    if(t==NULL)  
        cout<<"The tree is empty!"<<endl;  
    SeqStack<BiTreeNode*> s;  
	while(t||!s.Empty()){  
            while(t){  
                    cout<<t->data;  
					s.Push(t);  
					t=t->leftChild;  
            }   
			t=s.Top();  
            s.Pop();  
			t=t->rightChild;   
    }  
}  

void midorder1(BiTree &T){  
    if(T){  
             
		midorder1(T->leftChild);  
		cout<<T->data; 
		midorder1(T->rightChild);  
    }  
}  

void midorder2(BiTree &T){  
	BiTree t=T;
    if(t==NULL)  
        cout<<"empty!"<<endl;  
    SeqStack<BiTreeNode*> s;
    while(t||!s.Empty()){  
            while(t){    
					s.Push(t);  
					t=t->leftChild;  
            }   
			t=s.Top();  
            s.Pop();  
			cout<<t->data;
			t=t->rightChild;   
    }  
} 

void postorder1(BiTree &T){  
        if(T){  
			postorder1(T->leftChild); 
            postorder1(T->rightChild);  
			cout<<T->data; 
       }  
}  

void postorder2(BiTree &T){  
    BiTree t=T;
    if(t==NULL)  
        cout<<"empty!"<<endl;  
    else{  
        SeqStack<BiTreeNode*> s;
        SeqStack<int> v;  
        while(t){  
            s.Push(t);  
            v.Push(0);  
			t=t->leftChild;  
        }  
        while(!s.Empty()){  
            t=s.Top();  
			while(t->rightChild && v.Top()==0){  
                v.Pop();  
                v.Push(1);  
				t=t->rightChild;  
                s.Push(t);  
                v.Push(0);  
                while(t->leftChild){  
                        s.Push(t);  
                        v.Push(0);  
						t=t->leftChild;  
                }  
            }  
            t=s.Top();  
			cout<<t->data;  
            s.Pop();  
            v.Pop();  
        }  
    }  
}  

int main()
{
	/*����: ab#d##C#e## */
	BiTree T;  
    createBiTree(T); 
	cout<<"ǰ��ݹ������";
	preorder1(T);
	cout<<endl;
	cout<<"ǰ��ǵݹ������";
	preorder2(T);
	cout<<endl;
	cout<<"����ݹ������";
	midorder1(T);
	cout<<endl;
	cout<<"����ǵݹ������";
	midorder2(T);
	cout<<endl;
	cout<<"����ݹ������";
	postorder1(T);
	cout<<endl;
	cout<<"����ǵݹ������";
	postorder2(T);
	cout<<endl;
    return 0;  
}