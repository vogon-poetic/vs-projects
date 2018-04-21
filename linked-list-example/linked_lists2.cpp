#include <iostream>

using namespace std;

struct Node
{
  int value;
  Node *next;
};

//Program to manage linked list - each item is appended to end of the list
int main()
{
  //Variable Declaration/Inititalization
  int  counter = 0;
  int  data = 0;
  char repeat = 'y';
  Node *first = NULL;
  Node *node;
  Node *last;
  
  //Continually prompt for values
  do
  {
    //Prompt for a value and retrieve a value
    cout << "Enter a value: ";
    cin >> data;
    
    //1. Allocate a new node
    node = new Node;
    
    //2. Store value in the node and set next to NULL (initialization)
    node->value = data;
    node->next = NULL;
  
    //3. Append this node to end of the list  
    //Check for NULL first node - if NULL, set first to this node
    if (!first)
    {
      //Equate first to current node
      first = node;
      last = first;
    }
    else
    {
      //Append node to end of the list
      last->next = node;
      last = node;
    }
   
   //See if another value is to be entered
   cout << "Enter another value? (y/n)";
   cin >> repeat;
   
  }while(repeat == 'y');
  
  //Display all values in the list
  int no_of_items = 0;
  Node *current = first;
  
  //Process loop while current is not NULL
  while (current)
  {
    //Keep track of the number of items in the list
    no_of_items++;
    
    //Display the value at this node
    cout << current->value << " ";
    
    //Step thru the list
    current = current->next;
  }

  cout << endl;
      
      
  return 0;
}    
    
    
    
      