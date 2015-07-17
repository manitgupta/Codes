 struct DLLNode
 {
 	int data;
 	struct DLLNode *next;
 	struct DLLNode *prev;
 };

typedef struct DLLNode dllnode;

 void DLLInsert(dllnode **head, int data, int position)
 {
 	int k = 1;			//head is pointer to a pointer
 	dllnode *temp, *newNode;	//temp and new are just pointers of type dllnode
 	newNode = (dllnode*)malloc(sizeof(dllnode));
 	if(!newNode)
 	{
 		printf("%s\n","Memory Error");
 		return;
 	}
 	newNode->data = data;

 	if(position ==1)
 	{
 		newNode->prev = NULL;
 		newNode->next = *head;

 		if(*head)
 			(*head)->prev = newNode;
 		*head = newNode;
 		return;		
 	}
 	temp = *head;
 	while((k < position -1) && temp->next!=NULL)
 	{
 		temp = temp->next;
 		k++;
 	}
 	if(k!=position)
 	{
 		printf("%s\n","Invalid Position");
 	}
 	newNode->next = temp->next;
 	newNode->prev = temp;
 	if (temp->next)
 		temp->next->prev = newNode;

 	temp->next = newNode;
 	return;
 }