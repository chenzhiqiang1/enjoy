#include<stdio.h>
#include <iostream>    
#include<string>
#include <stack> 
using namespace std;  
#define max 1000000
 
//链表节点定义  
struct ListNode{  
    int m_nValue;  
    ListNode* m_pNext;  
	ListNode* m_prev; 
};  

//创建链表节点  
ListNode* CreateListNode(int value){  
    ListNode* pNode = new ListNode();  
    pNode->m_nValue = value;  
    pNode->m_pNext = NULL;  
    return pNode;  
}  

// 链接链表节点  
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext){  
    if (pCurrent == NULL){  
        cout << "Error to connect two nodes." << endl;  
        return ;
    }
    pCurrent->m_pNext = pNext;  
	pNext->m_prev = pCurrent;
}  

//打印链表  
void PrintList(ListNode* pHead){  
    cout << "PrintList start:" << endl;  
    ListNode* pNode = pHead;  
    while (pNode!=NULL){  
        cout << pNode->m_nValue << "   ";  
        pNode = pNode->m_pNext;  
    } 
    cout << endl << "PrintList end." << endl;  
}

//销毁链表节点  
void DestroyList(ListNode* pHead){  
    ListNode* pNode = pHead;  
    while (pNode != NULL){  
        pHead = pHead->m_pNext;  
        delete pNode;  
        pNode = pHead;  
    }  
}
    
//递归法：从尾到头打印链表  
void PrintListReversing_Recursive(ListNode* pHead){  
    if (pHead != NULL){  
        if (pHead->m_pNext != NULL){  
            PrintListReversing_Recursive(pHead->m_pNext);  
        }  
        cout << pHead->m_nValue << endl;  
    }  
}

//栈和递归  通过了80%
//int main(){  
//	ListNode* pNode = new ListNode();
//	ListNode* pHead = new ListNode();
//	//stack<ListNode*> node;  
//	int temp,count;
//	count=0;
//	pHead=pNode;
//	scanf("%d",&temp);
//	while(temp!=-1){	
//		if(count!=0){
//			ListNode* pNode1 = new ListNode(); 	
//			pNode1->m_nValue = temp;
//			ConnectListNodes(pNode, pNode1);
//			pNode=pNode->m_pNext;
//			//node.push(pNode);
//		}
//		else{
//			pNode->m_nValue = temp;
//			//node.push(pNode); 
//		}
//		count++;
//		scanf("%d",&temp);
//	}
//	/*while (!node.empty()){  
//        pNode = node.top();  
//        cout << pNode->m_nValue << endl;  
//        node.pop();  
//    }*/
//	PrintListReversing_Recursive(pHead);
//    return 0;  
//}


//双向链表  通过了80%
//int main(){  
//	ListNode* q = new ListNode();
//	int temp;
//	scanf("%d",&temp);
//	
//	q->m_prev = NULL;
//	q->m_nValue = NULL;
//	q->m_pNext = NULL; 
//	while(temp!=-1){	
//		ListNode* p = new ListNode(); 	
//		p->m_nValue=temp;
//		q->m_pNext = p; 
//		p->m_prev = q; 
//		q = q->m_pNext; 	
//		scanf("%d",&temp);
//	}
//
//	while(q->m_nValue!=NULL && q!=NULL){
//		cout<<q->m_nValue<<endl;
//		q=q->m_prev;
//	}
//    return 0;  
//}


//利用哨兵节点直接进行类似于双向链表的操作  通过了80%
//int main(){  
//	ListNode* q = new ListNode();
//	ListNode* pHead = new ListNode();
//	int temp,count;
//	count=0;
//	pHead->m_nValue=NULL;
//	pHead->m_pNext=NULL;
//	pHead->m_prev=NULL;
//	q=pHead;
//	scanf("%d",&temp);
//	while(temp!=-1){	
//		ListNode* p = new ListNode();
//		p->m_nValue=temp;
//		if(q==NULL)
//		   q->m_pNext=p;
//		else {
//			p->m_pNext=q->m_pNext;
//			q->m_pNext=p;
//		}	
//		scanf("%d",&temp);
//	}
//	while(pHead->m_pNext!=NULL && pHead->m_pNext->m_nValue!=NULL){
//		cout<<pHead->m_pNext->m_nValue<<endl;
//		pHead=pHead->m_pNext;
//	}
//    return 0;  
//}


//数组实现  AC
int main(){
	int i,count;
	count=0;
    long long a[max],temp;
	scanf("%lld",&temp);
    while(temp!=-1){
        a[count++]=temp;
		scanf("%lld",&temp);       
    }
	for(i=count-1;i>0;i--) printf("%lld\n",a[i]);
        printf("%lld\n",a[0]);       
    return 0;
}
