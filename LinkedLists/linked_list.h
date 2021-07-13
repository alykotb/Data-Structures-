struct Node
{
    int info;
    Node* link;
    /* data */
};

 struct Node * Add_at_Begin(struct Node *head);
 struct Node * Add_at_end();
 struct Node * Add_Element_at_Position(struct Node *head ,int position);
 void print_list_elements(struct Node *head);