// C++ program for the above approach
#include <iostream>
using namespace std;

// Node class to represent
// a node of the linked list.
class Node {
public:
	string data;
	Node* next;

	// Default constructor
	Node()
	{
		data = "?";
		next = NULL;
	}

	// Parameterised Constructor
	Node(string data)
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
    string  two;
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
            insertNode("?");
        }
        
    }

	// Function to insert a
	// node at the end of the
	// linked list.
	void insertNode(string);
    void push_back(string);

	// Function to print the
	// linked list.
	void printList();

	// Function to delete the
	// node at given position
	void deleteNode(int);
    void replaceData(int,string);
    int  getCount()
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
    void operator[](int index)
    { 
	
        
        cout<<"Subscript operator:"<<index<<endl;
        one=index;
        int count=0;
        Node* temp = head;
        string *ptr;
        cout<<"Hello-1"<<endl;
        // Check for empty list.
		cout<<"Hello-2"<<endl;


        // Traverse the list.
        while (temp!=NULL && count!=(index) &&temp->next!=NULL) {
                    cout<<"Hello-3"<<endl;

        // cout<<"Index:"<<count<<endl;
            //cout << temp->data << " ";
            temp = temp->next;
            count++;
        }
        cout<<"Outside"<<endl;
       // temp = temp->next;
       // cout<<type(temp->data);
        //*ptr=temp->;
        cout<<":"<<temp->data;
        cout<<"Outside-1"<<endl;
       
    }
   void operator=(const int x)
   {
        cout<<"Hello";
        
        
    }
};
void Linkedlist::replaceData(int n,string value)
{
    int count=0;
    Node* temp = head;

	// Check for empty list.
	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}

	// Traverse the list.
	while (count!=(n-1)) {
       // cout<<"Index:"<<count<<endl;
		//cout << temp->data << " ";
		temp = temp->next;
        count++;
	}
    temp = temp->next;
    temp->data=value;

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
void Linkedlist::push_back(string data)
{
    this->insertNode(data);
}
void Linkedlist::insertNode(string data)
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
		cout << temp->data << " ";
		temp = temp->next;
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
    list.replaceData(3,"2");
	cout << endl;
    cout<<"Length of LL:"<<list.getCount()<<endl;

	// Delete node at position 2.
	list.deleteNode(3);
    list.push_back("23");
    list.printList();
    list[2]=99;


	cout << "Elements of the list are: ";
	list.printList();
	cout << endl;
	return 0;
}
