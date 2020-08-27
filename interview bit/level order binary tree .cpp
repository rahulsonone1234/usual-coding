// Function to print all nodes of a given level from left to right
bool printLevel(Node* root, int level)
{
	if (root == nullptr)
		return false;

	if (level == 1)
	{
		cout << root->key << " ";

		// return true if at-least one node is present at given level
		return true;
	}

	bool left = printLevel(root->left, level - 1);
	bool right = printLevel(root->right, level - 1);

	return left || right;
}

// Function to print level order traversal of given binary tree
void levelOrderTraversal(Node* root)
{
	// start from level 1 -- till height of the tree
	int level = 1;

	// run till printLevel() returns false
	while (printLevel(root, level))
		level++;
}
////////////////////////////////////////////////////////////////////////////////////////////////
// Function to print level order traversal of given binary tree
void levelOrderTraversal(Node* root)
{
	// create an empty queue and enqueue root node
	list<Node*> queue;
	queue.push_back(root);

	// pointer to store current node
	Node* curr = nullptr;

	// loop till queue is empty
	while (queue.size())
	{
		// process each node in queue and enqueue their
		// non-empty left and right child to queue
		curr = queue.front();
		queue.pop_front();

		cout << curr->key << " ";

		if (curr->left)
		   queue.push_back(curr->left);

		if (curr->right)
		   queue.push_back(curr->right);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////
// traverse the tree in pre-order fashion and store nodes into the map
// corresponding to their level
void preorder(Node *root, int level, auto &map)
{
	// base case: empty tree
	if (root == nullptr)
		return;

	// insert current node and its level into the map
	map[level].push_back(root->key);

	// recur for left and right subtree by increasing level by 1
	preorder(root->left, level + 1, map);
	preorder(root->right, level + 1, map);
}

// Recursive function to print level order traversal of given binary tree
void levelOrderTraversal(Node *root)
{
	// create an empty map to store nodes between given levels
	unordered_map<int, vector<int>> map;

	// traverse the tree and insert its nodes into the map
	// corresponding to the their level
	preorder(root, 1, map);

	// iterate through the map and print all nodes between given levels
	for (int i = 1; map[i].size() > 0; i++)
	{
		cout << "Level " << i << ": ";
		for (int i: map[i])
			cout << i << " ";

		cout << endl;
	}
}
