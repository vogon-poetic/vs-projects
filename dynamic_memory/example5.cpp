#include <iostream>

using namespace std;

int* getData(int no_ele);

int main()
{
    //Variable Declaration/Initialization
    int i = 0;
    int no_elements = 0;
    int* data = NULL;

    //Prompt the user for # of elements to process
    cout << "Enter number of elements (Less than 10): ";
    cin >> no_elements;

    //Get the data as an array
    data = getData(no_elements);

    //Display all data
    for (i = 0; i < no_elements; i++)
    {
        //Display each element
        cout << data[i] << " ";
    }
    cout << endl;

    delete[] data;

    return 0;
}

int* getData(int no_ele)
{
    //Variable Declaration/Initialization
    int i = 0;

    //Declare statically allocated array (incorrect)
    const int MAX_ELE = 50;
    int array[MAX_ELE];

    //Dynamically allocate array (commented out for now)
    //int* array = new int[no_ele];    

    //Iterate thru each element
    for (i = 0; i < no_ele; i++)
    {
        cout << "Enter element # " << (i+1) << ": ";
        cin >> array[i];
    }

    return(array);
    
    
}

    

