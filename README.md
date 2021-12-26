#### BiTree

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

