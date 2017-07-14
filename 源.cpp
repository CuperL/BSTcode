struct node {
	struct node* left;
	struct node* right;
	int data;
};

typedef struct node Node;

// ³õÊ¼»¯
Node* init(Node* root)
{
	root = NULL;
	return root;

}
// ²åÈë
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

// É¾³ı
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
// Ïú»Ù
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

// ÖĞĞò±éÀú´æ·Åµ½Êı×éarrÖĞ
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
// ÅĞ¶ÏÒ»¿ÃÊ÷ÊÇ·ñÎªBST
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
// Ñ°ÕÒBSTÖĞ£¬Á½½ÚµãÖµÖ®²îµÄ×îĞ¡Öµ

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