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
	p=NULL;          // pָ��ǰ����ǰһ�����
	q=head->next;    // qָ��ǰ���ڱ�����Ľ��  
	if(NULL==q)
		return head;
	s=q->next;  // sָ��ǰ������һ�����  
	if(NULL==s)
		return head;
	while(s->next!=NULL){ // ����������ʱ����ʾsָ����������е����һ��Ԫ��  
		q->next=p;        // p,q,s��������һ��λ��  
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

