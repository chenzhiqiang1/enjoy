#include<iostream>
#include<assert.h>
using namespace std;

typedef struct BinaryTreeNode
{  
    char m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
}BTNode, *BiTreeNode;  

/*创建一颗二叉树,以'#'表示子节点为空,如：abf##d##c#e## */
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

/*访问根节点函数,用于直接打印出根节点的值*/
void Visit(BinaryTreeNode * pRoot){
	cout<<pRoot->m_nValue<<" ";
}

/*求二叉树中的节点个数*/
int GetNodeNum(BinaryTreeNode * pRoot){
	if(pRoot==NULL)
		return 0;
	return GetNodeNum(pRoot->m_pLeft)+GetNodeNum(pRoot->m_pRight)+1;
}

/*求二叉树的深度*/
int GetDepth(BinaryTreeNode * pRoot){
	if(pRoot==NULL)
		return 0;
	return GetDepth(pRoot->m_pLeft)>GetDepth(pRoot->m_pRight)?GetDepth(pRoot->m_pLeft)+1:GetDepth(pRoot->m_pRight)+1;
}

/*前序遍历函数*/
void PreOrderTraverse(BinaryTreeNode * pRoot)  
{  
    if(pRoot == NULL)  
        return;  
    Visit(pRoot); // 访问根节点  
    PreOrderTraverse(pRoot->m_pLeft); // 前序遍历左子树  
    PreOrderTraverse(pRoot->m_pRight); // 前序遍历右子树  
}

/*层次遍历函数*/
//void LevelTraverse(BinaryTreeNode * pRoot){
//	if(pRoot == NULL)  
//        return;  
//    Qnode<BiTreeNode *> q;  
//    q.push(pRoot);  
//    while(!q.empty())  
//    {  
//        BinaryTreeNode * pNode = q.front();  
//        q.pop();  
//        Visit(pNode); // 访问节点  
//        if(pNode->m_pLeft != NULL)  
//            q.push(pNode->m_pLeft);  
//        if(pNode->m_pRight != NULL)  
//            q.push(pNode->m_pRight);  
//    }  
//    return;  
//}

/*求二叉树第K层的节点个数*/
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

/*求二叉树中叶子节点的个数*/
int GetLeafNodeNum(BinaryTreeNode * pRoot){
	if(pRoot == NULL)
		return 0;
	if(pRoot->m_pLeft==NULL && pRoot->m_pRight==NULL)
		return 1;
	return GetLeafNodeNum(pRoot->m_pLeft)+GetLeafNodeNum(pRoot->m_pRight);
			
}

/*判断两棵二叉树是否结构相同*/
bool StructureCmp(BinaryTreeNode * pRoot1, BinaryTreeNode * pRoot2){
	if(pRoot1 == NULL && pRoot2 == NULL) // 都为空，返回真  
        return true;  
    else if(pRoot1 == NULL || pRoot2 == NULL) // 有一个为空，一个不为空，返回假  
        return false;  
    bool resultLeft = StructureCmp(pRoot1->m_pLeft, pRoot2->m_pLeft); // 比较对应左子树   
    bool resultRight = StructureCmp(pRoot1->m_pRight, pRoot2->m_pRight); // 比较对应右子树  
    return (resultLeft && resultRight);
}

/*判断二叉树是不是平衡二叉树*/
bool IsAVL(BinaryTreeNode * pRoot, int & height){
	if(pRoot == NULL){
		height=0;
		return true;
	}
	int heightLeft;  
    bool resultLeft = IsAVL(pRoot->m_pLeft, heightLeft);  
    int heightRight;  
    bool resultRight = IsAVL(pRoot->m_pRight, heightRight);  
    if(abs(heightLeft - heightRight) <= 1){   // 左子树和右子树都是AVL，并且高度相差不大于1，返回真  
        height = max(heightLeft, heightRight) + 1;  
        return true;  
    }  
    else{  
        height = max(heightLeft, heightRight) + 1;  
        return false;  
    }  
}

/*求二叉树的镜像*/
BinaryTreeNode * Mirror(BinaryTreeNode * pRoot)  
{  
    if(pRoot == NULL) // 返回NULL  
        return NULL;  
    BinaryTreeNode * pLeft = Mirror(pRoot->m_pLeft); // 求左子树镜像  
    BinaryTreeNode * pRight = Mirror(pRoot->m_pRight); // 求右子树镜像  
    // 交换左子树和右子树  
    pRoot->m_pLeft = pRight;  
    pRoot->m_pRight = pLeft;  
    return pRoot;  
} 
  
/*求二叉树中节点的最大距离*/
int GetMaxDistance(BinaryTreeNode * pRoot, int & maxLeft, int & maxRight){
	// maxLeft, 左子树中的节点距离根节点的最远距离  
    // maxRight, 右子树中的节点距离根节点的最远距离  
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

/*由前序遍历序列和中序遍历序列重建二叉树*/
//BinaryTreeNode * RebuildBinaryTree(int* pPreOrder, int* pInOrder, int nodeNum){  
//	if(pPreOrder == NULL || pInOrder == NULL || nodeNum <= 0)  
//        return NULL;  
//    BinaryTreeNode * pRoot = new BinaryTreeNode;  
//    // 前序遍历的第一个数据就是根节点数据  
//    pRoot->m_nValue = pPreOrder[0];  
//    pRoot->m_pLeft = NULL;  
//    pRoot->m_pRight = NULL;  
//    // 查找根节点在中序遍历中的位置，中序遍历中，根节点左边为左子树，右边为右子树  
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
//    // 重建左子树  
//    int nodeNumLeft = rootPositionInOrder;  
//    int * pPreOrderLeft = pPreOrder + 1;  
//    int * pInOrderLeft = pInOrder;  
//    pRoot->m_pLeft = RebuildBinaryTree(pPreOrderLeft, pInOrderLeft, nodeNumLeft);  
//    // 重建右子树  
//    int nodeNumRight = nodeNum - nodeNumLeft - 1;  
//    int * pPreOrderRight = pPreOrder + 1 + nodeNumLeft;  
//    int * pInOrderRight = pInOrder + nodeNumLeft + 1;  
//    pRoot->m_pRight = RebuildBinaryTree(pPreOrderRight, pInOrderRight, nodeNumRight);  
//    return pRoot;  
//}


/*判断二叉树是不是完全二叉树*/
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
//        if(mustHaveNoChild) // 已经出现了有空子树的节点了，后面出现的必须为叶节点（左右子树都为空）  
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

	cout<<"树的前序遍历为：";
	PreOrderTraverse(T);

	cout<<endl<<"树的节点个数为："<<GetNodeNum(T)<<endl;
	cout<<"树的深度为："<<GetDepth(T)<<endl;

	//cout<<"树的层次遍历为：";
	//LevelTraverse(T);

	cout<<"第3层树的节点数为："<<GetNodeNumKthLevel(T,3)<<endl;

	cout<<"叶子节点数为："<<GetLeafNodeNum(T)<<endl;

	BiTreeNode T1;  
       createBiTree(T1);
	if(true == StructureCmp(T1,T))
		cout<<"两棵树一样."<<endl;
	else 
		cout<<"两棵树不一样."<<endl;

	int height;
	if(true == IsAVL(T,height))
		cout<<"该树是平衡树"<<endl;
	else
		cout<<"该树不是平衡树"<<endl;

	BiTreeNode T2=Mirror(T);
	cout<<"镜像后的树的前序遍历为：";
	PreOrderTraverse(T2);

	int maxleft,maxright,max;
	max = GetMaxDistance(T,maxleft,maxright);
	cout<<endl<<"二叉树中节点的最大距离为"<<max<<endl;
    return 0;  
}