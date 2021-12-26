#define SUCCESS 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

/* BiTree Define */
typedef char TElemType;
typedef struct BiTNode {
	TElemType		data;
	struct BiTNode* lchild, * rchild;
} BiTNode, * BiTree;

Status InitBiTree(BiTree& T, TElemType data);
BiTree MakeBiTree(char str[], int length);
Status PrintTree(BiTree& T);
void DestoryBiTree(BiTree& T);
Status BiTreeEmpty(BiTree& T);
Status BreakBiTree(BiTree& T, BiTree& L, BiTree& R);
Status ReplaceLeft(BiTree& T, BiTree& LT);
Status ReplaceRight(BiTree& T, BiTree& RT);

Status CutLeft(BiTree& T, BiTree& LT);
Status CutRight(BiTree& T, BiTree& RT);
Status PreOrderTraverse(BiTree T, Status(*visit) (TElemType e));
Status InOrderTraverse(BiTree T, Status(*visit) (TElemType e));
Status PostOrderTraverse(BiTree T, Status(*visit) (TElemType e));
Status visit(TElemType e);
int BiTreeDepth(BiTree T);

/* SqStack Define (Internal) */
typedef BiTree SElemType;
typedef struct SqStack {
	BiTree* base;
	int		top;
	int		size;
} SqStack;

/* SqStack API (Internal) */

Status InitStack(SqStack& S, int StackSize) {
	S.base = (SElemType*)malloc(sizeof(TElemType) * StackSize);
	if (!S.base) return ERROR;
	S.top = -1;
	S.size = StackSize;
	return SUCCESS;
}

Status Push(SqStack& S, BiTree T) {
	if (S.top == S.size - 1)
		return ERROR;
	S.base[++S.top] = T;
	return SUCCESS;
}

SElemType Pop(SqStack& S) {
	SElemType T;
	if (S.top < 0) return NULL;
	T = S.base[S.top];
	S.top -= 1;
	return T;
}

SElemType GetTop(SqStack& S) {
	return S.base[S.top];
}

Status EmptyStack(SqStack& S) {
	if (S.top == -1) return TRUE;
	else return FALSE;
}