#ifndef tree_h
#define tree_h

typedef int DataType;

typedef struct _node{
	DataType data;
	struct _node *left;
	struct _node *right;
} Node;

void initTree(**Node tree); 
void addNode(**Node tree, Node *);

#endif
