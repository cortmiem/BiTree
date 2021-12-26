#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "BiTree.h"

int main()
{
	BiTree T, T2;
	BiTree Temp;
	BiTree LT = NULL, RT = NULL;
	int Depth;
	char str[] = "A(B(D,#),C(#,E))";
	char str2[] = "X";
	//scanf("%[^\n]s", str);
	T = MakeBiTree(str, sizeof(str));
	T2 = MakeBiTree(str2, sizeof(str2));
	std::cout << "Binary Tree\t\t:";
	PrintTree(T);
	std::cout << "\nPreOrderTraverse\t:";
	PreOrderTraverse(T, visit);
	std::cout << "\nInOrderTraverse\t\t:";
	InOrderTraverse(T, visit);
	std::cout << "\nPostOrderTraverse\t:";
	PostOrderTraverse(T, visit);
	Depth = BiTreeDepth(T);
	CutLeft(T, LT);
	std::cout << "\nCutLeft:T\t\t:";
	PrintTree(T);
	std::cout << "\nCutLeft:LT\t\t:";
	PrintTree(LT);
	ReplaceLeft(T, LT);
	std::cout << "\nReplaceLeftwithLT\t:";
	PrintTree(T);
	CutRight(T, RT);
	std::cout << "\nCutRight:T\t\t:";
	PrintTree(T);
	std::cout << "\nCutRight:RT\t\t:";
	PrintTree(RT);
	ReplaceRight(T, RT);
	std::cout << "\nReplaceRightwithRT\t:";
	PrintTree(T);
	BreakBiTree(T, LT, RT);
	std::cout << "\nBreakTree:T\t\t:";
	PrintTree(T);
	std::cout << "\nBreakTree:LT\t\t:";
	PrintTree(LT);
	std::cout << "\nBreakTree:RT\t\t:";
	PrintTree(RT);
	std::cout << "\nDestoyTree\t\t:";
	DestoryBiTree(T);
	if (T == NULL) std::cout << "Success.";

	return 0;
}

BiTree MakeBiTree(char str[], int length) {
	BiTree T = NULL, temp = NULL;
	SqStack S;
	if (!InitStack(S, length)) return NULL;

	int child = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		switch (str[i])
		{
		case '(':
			Push(S, temp);
			child = 0;
			break;
		case ')':
			T = Pop(S);
			break;
		case ',':
			child = 1;
			break;
		case '#':
			break;
		default:
			InitBiTree(temp, str[i]);
			if (!EmptyStack(S)) {
				if (child == 0)
					GetTop(S)->lchild = temp;
				else
					GetTop(S)->rchild = temp;
			}
			break;
		}
	}
	if (temp != NULL && T == NULL) return temp;
	return T;
}

Status InitBiTree(BiTree& T, TElemType data) {
	T = (BiTree)malloc(sizeof(BiTNode));
	T->lchild = NULL;
	T->rchild = NULL;
	T->data = data;
	return SUCCESS;
}

Status PrintTree(BiTree& T) {
	if (T == NULL)
		return ERROR;
	std::cout << T->data;
	if (T->lchild != NULL) {
		std::cout << '(';
		PrintTree(T->lchild);
		if (T->rchild == NULL) {
			std::cout << ",#)";
		}
	}
	if (T->rchild != NULL) {
		if (T->lchild == NULL) {
			std::cout << "(#";
		}
		std::cout << ',';
		PrintTree(T->rchild);
		std::cout << ')';
		return SUCCESS;
	}
}

void DestoryBiTree(BiTree& T) {
	if (NULL != T) {
		if (T->lchild) DestoryBiTree(T->lchild);
		if (T->rchild) DestoryBiTree(T->rchild);
	}
	free(T);
	T = NULL;
}

Status BiTreeEmpty(BiTree& T) {
	if (NULL != T) return TRUE;
	else return FALSE;
}

Status BreakBiTree(BiTree& T, BiTree& L, BiTree& R) {
	if (NULL == T) return ERROR;
	L = T->lchild;
	R = T->rchild;
	T->lchild = NULL;
	T->rchild = NULL;
	return SUCCESS;
}

Status ReplaceLeft(BiTree& T, BiTree& LT) {
	if (NULL == T) return ERROR;
	BiTree t = T->lchild;
	T->lchild = LT;
	LT = t;
	return SUCCESS;
}

Status ReplaceRight(BiTree& T, BiTree& RT) {
	if (NULL == T) return ERROR;
	BiTree t = T->rchild;
	T->rchild = RT;
	RT = t;
	return SUCCESS;
}

Status CutLeft(BiTree& T, BiTree& LT) {
	if (NULL == T) {
		LT = NULL;
		return ERROR;
	}
	LT = T->lchild;
	T->lchild = NULL;
	return TRUE;
}

Status CutRight(BiTree& T, BiTree& LT) {
	if (NULL == T) {
		LT = NULL;
		return ERROR;
	}
	LT = T->rchild;
	T->rchild = NULL;
	return TRUE;
}

Status PreOrderTraverse(BiTree T, Status(*visit) (TElemType e)) {
	if (NULL == T) return SUCCESS;
	if (ERROR == visit(T->data)) return ERROR;
	if (ERROR == PreOrderTraverse(T->lchild, visit)) return ERROR;
	return PreOrderTraverse(T->rchild, visit);
}

Status InOrderTraverse(BiTree T, Status(*Visit) (TElemType e)) {
	if (NULL == T) return SUCCESS;
	if (ERROR == InOrderTraverse(T->lchild, visit)) return ERROR;
	if (ERROR == visit(T->data)) return ERROR;
	return InOrderTraverse(T->rchild, visit);
}

Status PostOrderTraverse(BiTree T, Status(*Visit) (TElemType e)) {
	if (NULL == T) return SUCCESS;
	if (ERROR == PostOrderTraverse(T->lchild, visit)) return ERROR;
	if (ERROR == PostOrderTraverse(T->rchild, visit)) return ERROR;
	if (ERROR == visit(T->data)) return ERROR;
}

Status visit(TElemType e) {
	std::cout << e << " ";
	return SUCCESS;
}

int BiTreeDepth(BiTree T) {
	int l = 0, r = 0;
	if (T == NULL) return 0;
	if (T->lchild != NULL) l = BiTreeDepth(T->lchild);
	if (T->rchild != NULL) r = BiTreeDepth(T->rchild);
	return (l > r ? l : r) + 1;
}
