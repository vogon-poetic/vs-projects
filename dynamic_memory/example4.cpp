#include <iostream>
#include <cstdlib>

using namespace std;


/*Dynamic Memory Allocation
1. Declare Pointer Variable  (int* ptr; int* ptr1)

2. Use new to allocate the array (new int[no_ele))
and
Store the address returned by new in the pointer variable:
ptr = new int[no_ele];  //array of ints with no_ele elements
ptr1 = new int;         //allocates one integer off the heap

3. Initialize the data at the dynamic heap address (Just like you
would with a statically declared array)
ptr[0] = 9;
ptr[1] = 22;
......
*ptr1 = 8;
ptr1[0] = 23;  //Can only use index 0!

4. cleanup memory when done
delete[] ptr;  //Use [] when cleaning up an allocated array
delete ptr1; //When deleting a non-array*/



int main()
{
	//Variable Declaration/Initialization  
	int  i = 0;
	int* ptr = NULL; //1. Declare the pointer variable
	int no_of_ele = 0;
	const int MAX_ELE = 300000;
	//int test_scores[MAX_ELE]; //what happens here?
	int* test_scores = new int[MAX_ELE];



	/******Dynamically allocating array of integers********/
	// Get the # of elements in array of integers 
	cout << "Enter number of elements: ";
	cin >> no_of_ele;

	//2. Dynamically allocate array of ints
	ptr = new int[no_of_ele];

	//3. Initialize each element (prompt)
	for (i = 0; i < no_of_ele; i++) {
		//Prompt for each value
		cout << "Enter value for element #" << (i + 1) << ": ";
		cin >> ptr[i];
	}

	//Display all elements
	for (i = 0; i < no_of_ele; i++)
	{
		cout << "Element #" << (i + 1) << ": " << *(ptr + i) << endl;
	}

}
