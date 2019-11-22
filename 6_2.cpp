#include <iostream>
#include <stack>

using namespace std;

struct Node
{
	int t_data;
	Node* parent;
	Node* left;
	Node* right;
	Node(const int& data)
	{
		t_data = data;
		parent = nullptr;
		left = nullptr;
		right = nullptr;
	}
};

void tree_add(Node* z, Node* x)
{
	while (x != nullptr)
	{
		if (z->t_data > x->t_data)
		{
			if (x->right != nullptr)
			{
				x = x->right;
			}
			else
			{
				z->parent = x;
				x->right = z;
				break;
			}
		}
		else if (z->t_data <= x->t_data)
		{
			if (x->left != nullptr)
			{
				x = x->left;
			}
			else
			{
				z->parent = x;
				x->left = z;
				break;
			}
		}
	}
}

void print_tree(const Node* root)
{
	std::stack<const Node*> stack;

	while (root != nullptr || !stack.empty())
	{
		while (root != nullptr)
		{
			stack.push(root);
			root = root->left;
		}

		std::cout << stack.top()->t_data << ' ';
		root = stack.top()->right;
		stack.pop();
	}
}
int main()
{
	int n;//size
	cin >> n;
	Node* tree = nullptr;
	Node* tmp = nullptr;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (!tree)
		{
			tree = new Node(temp);
			continue;
		}
		tmp = new Node(temp);
		tree_add(tmp, tree);
	}
	print_tree(tree);
	return 0;
}