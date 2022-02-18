// C++ program for the above approach
#include <iostream>
#include<exception>
using namespace std;

// Node class to represent
// a node of the linked list.
class Node {
public:
	int data;
	Node* next;

	// Default constructor
	Node()
	{
		data =-99;
		next = NULL;
	}

	// Parameterised Constructor
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

// Linked list class to
// implement a linked list.
class Linkedlist {
	Node* head;
    int     one;
    int  two;
    int *ptr;
    Node* oper;


public:
	// Default constructor
	Linkedlist() { head = NULL; }
    Linkedlist(int n) 
    { 
        head = NULL; 
        for(int i=0;i<n;i++)
        {
            insert(-99);
        }
        
    }
    Linkedlist(const  Linkedlist &rhs)
    {
        cout<<"Copy Constructor Called";
        Node * temp=rhs.head;
        cout<<(rhs.head)->data<<endl;
        while(temp!=NULL)
        {
        insert(temp->data);
        temp=temp->next;
        }

    }
    void push_back(int);
	void insert(int);
    void pop_back();
    string front();
    string back();
    int empty();
    int size();
    void clear();
    void erase(int ,int );
	void printList();
	void deleteNode(int);
    void replaceData(int,int);
    int& operator[](int index);
    Linkedlist& operator=( const Linkedlist& s );
    void append( Node* node );
  //  void deleteNode(int position);
    

 
 
};
int& Linkedlist::operator[](int index)
    { 

        int count=0;
        Node* temp = head;
        int *ptr;
        // Check for empty list.


        // Traverse the list.
        while ( count!=(index-1) ) 
        {
            temp = temp->next;
            count++;
        }

        return temp->data;
       
    } 
void Linkedlist::clear()
{
 
    /* deref head_ref to get the real head */
    Node* current = head;
    Node* next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
 
    /* deref head_ref to affect the real head back
        in the caller. */
    *head = NULL;
}
int Linkedlist::empty()
{
    if(size()>0) return 1;
    else return 0;
}
string Linkedlist:: front()
{
    if(size()==0) 
    {
        cout<<"Empty"<<endl;
        return "-";
    }
if(head->data!=-99)    return to_string(head->data);
else return "?";
}
string Linkedlist::back()
{   Node* temp = head;
    if(size()==0) 
    {
        cout<<"Empty"<<endl;
        return "-";
    }
    int len=size();
    int count=0;
    while(count++!=(len-1)) temp=temp->next;

    if(temp->data!=-99)    return to_string(temp->data);
    else return "?";

}
int Linkedlist:: size()
    {
                int count = 0; // Initialize count
                Node* current = head; // Initialize current
                while (current != NULL)
                {
                    count++;
                    current = current->next;
                }
                return count;
    }
// Function to delete the
// node at given position
void Linkedlist::deleteNode(int nodeOffset)
{
	Node *temp1 = head, *temp2 = NULL;
	int ListLen = 0;

	if (head == NULL) {
		cout << "List empty." << endl;
		return;
	}

	// Find length of the linked-list.
	while (temp1 != NULL) {
		temp1 = temp1->next;
		ListLen++;
	}

	// Check if the position to be
	// deleted is less than the length
	// of the linked list.
	if (ListLen < nodeOffset) {
		cout << "Index out of range"
			<< endl;
		return;
	}

	// Declare temp1
	temp1 = head;

	// Deleting the head.
	if (nodeOffset == 1) {

		// Update head
		head = head->next;
		delete temp1;
		return;
	}

	// Traverse the list to
	// find the node to be deleted.
	while (nodeOffset-- > 1) {

		// Update temp2
		temp2 = temp1;

		// Update temp1
		temp1 = temp1->next;
	}

	// Change the next pointer
	// of the previous node.
	temp2->next = temp1->next;

	// Delete the node
	delete temp1;
}

// Function to insert a new node.
void Linkedlist::push_back(int data)
{
    this->insert(data);
}
void Linkedlist::insert(int data)
{
	// Create the new Node.
	Node* newNode = new Node(data);

	// Assign to head
	if (head == NULL) {
		head = newNode;
		return;
	}

	// Traverse till end of list
	Node* temp = head;
	while (temp->next != NULL) {

		// Update temp
		temp = temp->next;
	}

	// Insert at the last.
	temp->next = newNode;
}

// Function to print the
// nodes of the linked list.
void Linkedlist::printList()
{
	Node* temp = head;

	// Check for empty list.
	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}

	// Traverse the list.
	while (temp != NULL) {
        if(temp->data==-99) cout<<"?"<<" ";
		else cout << temp->data << " ";
		temp = temp->next;
	}
    cout<<endl;
}

void Linkedlist:: pop_back()
{   Node *temp1 = head, *temp2 = NULL;
    int len=size();
    temp1 = head;
    int count=0;
    if(size()==0)
    {
        cout<<"Empty Linkedlist"<<endl;
        return;
    }

	// Deleting the head.
	if (len == 1) 
    {
		// Update head
		head = head->next;
		delete temp1;
		return;
	}

	// Traverse the list to
	// find the node to be deleted.
	while (count!=len-1) {

		// Update temp2
		temp2 = temp1;

		// Update temp1
		temp1 = temp1->next;
        count++;
	}

	// Change the next pointer
	// of the previous node.
	temp2->next = temp1->next;

	// Delete the node
	delete temp1;
}

void Linkedlist::erase(int pos,int count)
{   
    if(pos>0 && pos<=size() && (pos+count)<=size())
    {
            //If removing starts from Head
            for(int i=0;i<count;i++) deleteNode(pos);
    }
    else cout<<"Error"<<endl;

}

Linkedlist& Linkedlist::operator=(const  Linkedlist &rhs )
{   
    Node * temp=rhs.head;
    cout<<(rhs.head)->data<<endl;
    while(temp!=NULL)
    {
        push_back(temp->data);
        temp=temp->next;
    }

    return *this;
}
void Linkedlist::append( Node* node ){

    if (NULL == head) {
        Node *newNode = new Node(node->data);
        head = newNode;
    } else {
        Node *current = head;

        while (current -> next) {
            current = current -> next;
        }


        Node *newNode = new Node(node->data);
        current -> next = newNode;
    }
}
// Driver Code
int main()
{
	Linkedlist list(5);

	// Inserting nodes
	cout << "Elements of the list are: ";
	// Print the list
	list.printList();
    cout<<"Front:"<<list.front()<<endl;
    cout<<"Length of LL:"<<list.size()<<endl;

	// Delete node at position 2.
	list.deleteNode(3);
    list.push_back(23);
    list.printList();
    cout<<list[2]<<endl;
    list[3]=99;
    list[1]=7;

    list.pop_back();
	cout << "Elements of the list are: ";
	list.printList();
    cout<<"Back:"<<list.back()<<endl;
    cout<<"Empty Status:"<<list.empty()<<endl;
    //list.clear();
    cout<<"Length of LL:"<<list.size()<<endl;
    cout<<"Empty Status:"<<list.empty()<<endl;
    list.printList();
    cout<<"After Deleting using Methods"<<endl;
    list.erase(8,4);
    list.printList();
    Linkedlist list2;
    list2=list;
    list2.printList();
    list2[1]=12;
    list2.printList();
    list.printList();
	return 0;
}
