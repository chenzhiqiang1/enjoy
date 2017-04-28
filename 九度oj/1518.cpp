#include<stdio.h>  
#include<malloc.h>  
#include<iostream>  
using namespace std;  
struct Node{
	int data;
	Node *next;
};

Node *create(int n){
	Node *head=(Node *)malloc(sizeof(Node));
	head->next=NULL;
	Node *p=head;
	int data;
	for(int i=1;i<=n;i++){
		scanf("%d",&data);
		Node *s=(Node *)malloc(sizeof(Node));
		s->data=data;
		s->next=p->next;
		p->next=s;
		p=s;
	}
	return head;
}

Node *reverse(Node *head){
	Node *p,*q,*s;
	p=NULL;          // p指向当前结点的前一个结点
	q=head->next;    // q指向当前正在被处理的结点  
	if(NULL==q)
		return head;
	s=q->next;  // s指向当前结点的下一个结点  
	if(NULL==s)
		return head;
	while(s->next!=NULL){ // 当条件成立时，表示s指向的是链表中的最后一个元素  
		q->next=p;        // p,q,s都向右移一个位置  
		p=q;
		q=s;
		s=s->next;
	}
	q->next=p;
	s->next=q;
	head->next=s;
	return head;
}

void printNode(Node *head){
	Node *p=head->next;
	if(NULL==p)
		printf("NULL\n");
	else{
		while(p->next!=NULL){
			printf("%d ",p->data);
			p=p->next;
		}
		printf("%d\n",p->data);
	}
}

int main(){
	int n;
	Node *head;
	while(scanf("%d",&n)!=EOF){
		head=create(n);
		head=reverse(head);
		printNode(head);
	}
	return 0;
}

