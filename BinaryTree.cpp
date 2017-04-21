#include<iostream>
#include<assert.h>
using namespace std;

typedef struct BinaryTreeNode
{  
    char m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
}BTNode, *BiTreeNode;  

/*����һ�Ŷ�����,��'#'��ʾ�ӽڵ�Ϊ��,�磺abf##d##c#e## */
void createBiTree(BiTreeNode &T)  
{  
    char c;  
    cin >> c;  
    if('#' == c)  
        T = NULL;  
    else  
    {  
        T = new BinaryTreeNode;  
        T->m_nValue = c;  
        createBiTree(T->m_pLeft);  
		createBiTree(T->m_pRight);  
    }  
} 

/*���ʸ��ڵ㺯��,����ֱ�Ӵ�ӡ�����ڵ��ֵ*/
void Visit(BinaryTreeNode * pRoot){
	cout<<pRoot->m_nValue<<" ";
}

/*��������еĽڵ����*/
int GetNodeNum(BinaryTreeNode * pRoot){
	if(pRoot==NULL)
		return 0;
	return GetNodeNum(pRoot->m_pLeft)+GetNodeNum(pRoot->m_pRight)+1;
}

/*������������*/
int GetDepth(BinaryTreeNode * pRoot){
	if(pRoot==NULL)
		return 0;
	return GetDepth(pRoot->m_pLeft)>GetDepth(pRoot->m_pRight)?GetDepth(pRoot->m_pLeft)+1:GetDepth(pRoot->m_pRight)+1;
}

/*ǰ���������*/
void PreOrderTraverse(BinaryTreeNode * pRoot)  
{  
    if(pRoot == NULL)  
        return;  
    Visit(pRoot); // ���ʸ��ڵ�  
    PreOrderTraverse(pRoot->m_pLeft); // ǰ�����������  
    PreOrderTraverse(pRoot->m_pRight); // ǰ�����������  
}

/*��α�������*/
//void LevelTraverse(BinaryTreeNode * pRoot){
//	if(pRoot == NULL)  
//        return;  
//    Qnode<BiTreeNode *> q;  
//    q.push(pRoot);  
//    while(!q.empty())  
//    {  
//        BinaryTreeNode * pNode = q.front();  
//        q.pop();  
//        Visit(pNode); // ���ʽڵ�  
//        if(pNode->m_pLeft != NULL)  
//            q.push(pNode->m_pLeft);  
//        if(pNode->m_pRight != NULL)  
//            q.push(pNode->m_pRight);  
//    }  
//    return;  
//}

/*���������K��Ľڵ����*/
int GetNodeNumKthLevel(BinaryTreeNode * pRoot, int k){
	if(pRoot == NULL || k<0)
		return 0;
	else if(k==1)
		return 1;
	else{
		int left=GetNodeNumKthLevel(pRoot->m_pLeft,k-1);
		int right=GetNodeNumKthLevel(pRoot->m_pRight,k-1);
		return left+right;
	}
}

/*���������Ҷ�ӽڵ�ĸ���*/
int GetLeafNodeNum(BinaryTreeNode * pRoot){
	if(pRoot == NULL)
		return 0;
	if(pRoot->m_pLeft==NULL && pRoot->m_pRight==NULL)
		return 1;
	return GetLeafNodeNum(pRoot->m_pLeft)+GetLeafNodeNum(pRoot->m_pRight);
			
}

/*�ж����ö������Ƿ�ṹ��ͬ*/
bool StructureCmp(BinaryTreeNode * pRoot1, BinaryTreeNode * pRoot2){
	if(pRoot1 == NULL && pRoot2 == NULL) // ��Ϊ�գ�������  
        return true;  
    else if(pRoot1 == NULL || pRoot2 == NULL) // ��һ��Ϊ�գ�һ����Ϊ�գ����ؼ�  
        return false;  
    bool resultLeft = StructureCmp(pRoot1->m_pLeft, pRoot2->m_pLeft); // �Ƚ϶�Ӧ������   
    bool resultRight = StructureCmp(pRoot1->m_pRight, pRoot2->m_pRight); // �Ƚ϶�Ӧ������  
    return (resultLeft && resultRight);
}

/*�ж϶������ǲ���ƽ�������*/
bool IsAVL(BinaryTreeNode * pRoot, int & height){
	if(pRoot == NULL){
		height=0;
		return true;
	}
	int heightLeft;  
    bool resultLeft = IsAVL(pRoot->m_pLeft, heightLeft);  
    int heightRight;  
    bool resultRight = IsAVL(pRoot->m_pRight, heightRight);  
    if(abs(heightLeft - heightRight) <= 1){   // ������������������AVL�����Ҹ߶�������1��������  
        height = max(heightLeft, heightRight) + 1;  
        return true;  
    }  
    else{  
        height = max(heightLeft, heightRight) + 1;  
        return false;  
    }  
}

/*��������ľ���*/
BinaryTreeNode * Mirror(BinaryTreeNode * pRoot)  
{  
    if(pRoot == NULL) // ����NULL  
        return NULL;  
    BinaryTreeNode * pLeft = Mirror(pRoot->m_pLeft); // ������������  
    BinaryTreeNode * pRight = Mirror(pRoot->m_pRight); // ������������  
    // ������������������  
    pRoot->m_pLeft = pRight;  
    pRoot->m_pRight = pLeft;  
    return pRoot;  
} 
  
/*��������нڵ��������*/
int GetMaxDistance(BinaryTreeNode * pRoot, int & maxLeft, int & maxRight){
	// maxLeft, �������еĽڵ������ڵ����Զ����  
    // maxRight, �������еĽڵ������ڵ����Զ����  
    if(pRoot == NULL){  
        maxLeft = 0;  
        maxRight = 0;  
        return 0;  
    }  
    int maxLL, maxLR, maxRL, maxRR;  
    int maxDistLeft, maxDistRight;
	if(pRoot->m_pLeft != NULL){
		maxDistLeft = GetMaxDistance(pRoot->m_pLeft,maxLL,maxLR);
		maxLeft = max(maxLL,maxLR)+1;
	}
	else{
		maxDistLeft = 0;
		maxLeft = 0;
	}
	if(pRoot->m_pRight != NULL){
		maxDistRight = GetMaxDistance(pRoot->m_pRight,maxRL,maxRR);
		maxRight = max(maxRL,maxRR)+1;
	}
	else{
		maxDistRight = 0;
		maxRight = 0;
	}
	return max(max(maxDistLeft,maxDistRight),maxLeft+maxRight);
}

/*��ǰ��������к�������������ؽ�������*/
//BinaryTreeNode * RebuildBinaryTree(int* pPreOrder, int* pInOrder, int nodeNum){  
//	if(pPreOrder == NULL || pInOrder == NULL || nodeNum <= 0)  
//        return NULL;  
//    BinaryTreeNode * pRoot = new BinaryTreeNode;  
//    // ǰ������ĵ�һ�����ݾ��Ǹ��ڵ�����  
//    pRoot->m_nValue = pPreOrder[0];  
//    pRoot->m_pLeft = NULL;  
//    pRoot->m_pRight = NULL;  
//    // ���Ҹ��ڵ�����������е�λ�ã���������У����ڵ����Ϊ���������ұ�Ϊ������  
//    int rootPositionInOrder = -1;  
//    for(int i = 0; i < nodeNum; i++)  
//        if(pInOrder[i] == pRoot->m_nValue)  
//        {  
//            rootPositionInOrder = i;  
//            break;  
//        }  
//    if(rootPositionInOrder == -1)  
//    {  
//        throw std::exception("Invalid input.");  
//    }  
//    // �ؽ�������  
//    int nodeNumLeft = rootPositionInOrder;  
//    int * pPreOrderLeft = pPreOrder + 1;  
//    int * pInOrderLeft = pInOrder;  
//    pRoot->m_pLeft = RebuildBinaryTree(pPreOrderLeft, pInOrderLeft, nodeNumLeft);  
//    // �ؽ�������  
//    int nodeNumRight = nodeNum - nodeNumLeft - 1;  
//    int * pPreOrderRight = pPreOrder + 1 + nodeNumLeft;  
//    int * pInOrderRight = pInOrder + nodeNumLeft + 1;  
//    pRoot->m_pRight = RebuildBinaryTree(pPreOrderRight, pInOrderRight, nodeNumRight);  
//    return pRoot;  
//}


/*�ж϶������ǲ�����ȫ������*/
//bool IsCompleteBinaryTree(BinaryTreeNode * pRoot)  
//{  
//    if(pRoot == NULL)  
//        return false;  
//    queue<BinaryTreeNode *> q;  
//    q.push(pRoot);  
//    bool mustHaveNoChild = false;  
//    bool result = true;  
//    while(!q.empty())  
//    {  
//        BinaryTreeNode * pNode = q.front();  
//        q.pop();  
//        if(mustHaveNoChild) // �Ѿ��������п������Ľڵ��ˣ�������ֵı���ΪҶ�ڵ㣨����������Ϊ�գ�  
//        {  
//            if(pNode->m_pLeft != NULL || pNode->m_pRight != NULL)  
//            {  
//                result = false;  
//                break;  
//            }  
//        }  
//        else  
//        {  
//            if(pNode->m_pLeft != NULL && pNode->m_pRight != NULL)  
//            {  
//                q.push(pNode->m_pLeft);  
//                q.push(pNode->m_pRight);  
//            }  
//            else if(pNode->m_pLeft != NULL && pNode->m_pRight == NULL)  
//            {  
//                mustHaveNoChild = true;  
//                q.push(pNode->m_pLeft);  
//            }  
//            else if(pNode->m_pLeft == NULL && pNode->m_pRight != NULL)  
//            {  
//                result = false;  
//                break;  
//            }  
//            else  
//            {  
//                mustHaveNoChild = true;  
//            }  
//        }  
//    }  
//    return result;  
//}  

int main()  
{  
    BiTreeNode T;  
    createBiTree(T); 

	cout<<"����ǰ�����Ϊ��";
	PreOrderTraverse(T);

	cout<<endl<<"���Ľڵ����Ϊ��"<<GetNodeNum(T)<<endl;
	cout<<"�������Ϊ��"<<GetDepth(T)<<endl;

	//cout<<"���Ĳ�α���Ϊ��";
	//LevelTraverse(T);

	cout<<"��3�����Ľڵ���Ϊ��"<<GetNodeNumKthLevel(T,3)<<endl;

	cout<<"Ҷ�ӽڵ���Ϊ��"<<GetLeafNodeNum(T)<<endl;

	BiTreeNode T1;  
       createBiTree(T1);
	if(true == StructureCmp(T1,T))
		cout<<"������һ��."<<endl;
	else 
		cout<<"��������һ��."<<endl;

	int height;
	if(true == IsAVL(T,height))
		cout<<"������ƽ����"<<endl;
	else
		cout<<"��������ƽ����"<<endl;

	BiTreeNode T2=Mirror(T);
	cout<<"����������ǰ�����Ϊ��";
	PreOrderTraverse(T2);

	int maxleft,maxright,max;
	max = GetMaxDistance(T,maxleft,maxright);
	cout<<endl<<"�������нڵ��������Ϊ"<<max<<endl;
    return 0;  
}