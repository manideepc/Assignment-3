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
class Sequence {
	Node* head;

public:
	// Default constructor
	Sequence() { head = NULL; }
    Sequence(int n) 
    { 
        head = NULL; 
        for(int i=0;i<n;i++)
        {
            push_back(-99);
        }
        
    }
    Sequence(const  Sequence &rhs)
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
    Sequence& operator=( const Sequence& s );
    void append( Node* node );
    Node* getNode(int data);
    void insert(int pos, int data);
     //ostream& operator<<( ostream& os,Sequence& s);
};

int& Sequence::operator[](int index)
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
void Sequence::clear()
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
int Sequence::empty()
{
    if(size()>0) return 1;
    else return 0;
}
string Sequence:: front()
{
    if(size()==0) 
    {
        cout<<"Empty"<<endl;
        return "-";
    }
if(head->data!=-99)    return to_string(head->data);
else return "?";
}
string Sequence::back()
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
int Sequence:: size()
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
void Sequence::deleteNode(int nodeOffset)
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
void Sequence::push_back(int data)
{
    this->insert(data);
}
void Sequence::insert(int data)
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
void Sequence::printList()
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

void Sequence:: pop_back()
{   Node *temp1 = head, *temp2 = NULL;
    int len=size();
    temp1 = head;
    int count=0;
    if(size()==0)
    {
        cout<<"Empty Sequence"<<endl;
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

void Sequence::erase(int pos,int count)
{   
    if(pos>0 && pos<=size() && (pos+count)<=size())
    {
            //If removing starts from Head
            for(int i=0;i<count;i++) deleteNode(pos);
    }
    else cout<<"Error"<<endl;

}

Sequence& Sequence::operator=(const  Sequence &rhs )
{   
    Node * temp=rhs.head;
    //cout<<(rhs.head)->data<<endl;
    while(temp!=NULL)
    {
        push_back(temp->data);
        temp=temp->next;
    }

    return *this;
}
Node* Sequence:: getNode(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void Sequence:: insert(int position, int data)
{   
	Node* currentNode = new Node();
        currentNode->data = data;
        currentNode->next = NULL;


        if (head == NULL) {
            //if head is null and position is zero then exit->
            if (position != 0) {
                return;
            } else { //currentNode set to the head->
                this->head = currentNode;
            }
        }

        if (head != NULL && position == 0) {
            currentNode->next = head;
            this->head = currentNode;
            return;
        }

        Node* current = head;
        Node* previous = NULL;

        int i = 0;

        while (i < position) 
        {
            previous = current;
            current = current->next;

            if (current == NULL) {
                break;
            }

            i++;
        }

        currentNode->next = current;
        previous->next = currentNode;
}
ostream& operator<<( ostream& os,Sequence& s )
{
        s.printList();
        return os;
}
// Driver Code
int main()
{
	Sequence list(5);

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
    Sequence list2;
    list2=list;
    list2.printList();
    list2[1]=12;
    list2.printList();
    list.printList();
    cout<<"After Insertion:";
    list.insert(0,4);
    list.printList();
    //list2=list;
    //list2.printList();
    cout<<"Ostream Overloading:";
    cout<<list;
    cout<<list2;
	return 0;
}
