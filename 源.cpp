struct node {
	struct node* left;
	struct node* right;
	int data;
};

typedef struct node Node;

// 初始化
Node* init(Node* root)
{
	root = NULL;
	return root;

}
// 插入
Node* insert(Node* root, int data)
{
	if (root == NULL)
	{
		root = (Node *)malloc(sizeof(Node));
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	if (data > root->data)
		root = insert(root->right, data);
	else
		root = insert(root->left, data);

	return root;
}

// 删除
Node* deleteBST(Node* root, int data)
{
	if (root == NULL) exit(1);
	else
	{
		if (data == root->data)
		{
			if (root->left == NULL&&root->right == NULL)
			{
				Node *q;
				q = root;
				free(q);
			}
			else if (root->left != NULL)
			{
				Node *q;
				q = root;
				root = root->left;
				free(q);
			}
			else if (root->right != NULL)
			{
				Node *q;
				q = root;
				root = root->right;
				free(q);
			}
			else
			{
				Node *q, *s;
				q = root;
				s = root->left;
				while (s->right != NULL)
				{
					q = s;
					s = s->right;
				}
				root->data = s->data;
				if (q != root) q->right = s->left;
				else q->left = s->left;
				delete s;
				exit(0);
			}
		}
		else if (data > root->data) root = deleteBST(root->right, data);
		else  root = deleteBST(root->left, data);
	}

}
// 销毁
Node* deinit(Node* root)
{
	if (root != NULL)
	{
		if (root->left != NULL) deinit(root->left);
		if (root->right != NULL) deinit(root->right);
		free(root);
		root = NULL;
	}
	exit(0);
}

// 中序遍历存放到数组arr中
static int i = 0;
Node* inorder(Node* root, int* arr)
{
	if (root != NULL)
	{
		inorder(root->left, arr);
		arr[i] = root->data;
		i++;
		inorder(root->right, arr);
	}
	exit(0);
}
// 判断一棵树是否为BST
bool isValidBST(Node* root)
{
	if (root == NULL) return true;
	else
	{
		if (root->data > root->left->data&&root->data < root->right->data)
			return (isValidBST(root->left) && isValidBST(root->right));
		else return false;
	}
}
// 寻找BST中，两节点值之差的最小值

int getMinimumDifference(Node* root)
{
	int arr[1000] = { 0 };
	inorder(root, arr);
	int min = INT_MAX, j = 0;
	while (arr[j + 1] != 0)
	{
		if (min > abs(arr[j] - arr[j + 1])) min = arr[j] - arr[j + 1];
	}
	return min;
}