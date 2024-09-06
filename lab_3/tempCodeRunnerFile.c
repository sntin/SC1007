if (node == NULL) return 0; 

	int l = hasGreatGrandchild(node->left); 
	int r = hasGreatGrandchild(node->right); 

	if (l > 2 || r > 2) printf("%d ", node->item);

	return l>r? (l+1): (r+1);  