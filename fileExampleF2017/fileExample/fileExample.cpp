#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  //Variable Declaration/Initialization
  int i = 0;
  string word = "";
  string line = "";
  

  //Open file for reading
  fstream in_file("stuff.txt", ios::in);

  //Test for open
  if (!in_file)
  {
    cout << "Cannot open stuff.txt for input" << endl;
  }

  //Open file for writing
  fstream out_file("out.txt", ios::out);

  //Test for open
  if (!out_file)
  {
    cout << "Cannot open out.txt for output" << endl;
  }

  //Read one line at a time
  while(true)
  {
    //Read the line
    getline(in_file,line);

    //Test for eof
    if (in_file.eof())
      break;

    //Display the line
    cout << line << endl;

  }
  
  //close the file
  in_file.close();

  //Re-open
  fstream in_file1("stuff.txt",ios::in);

  //Read one word at a time
  while(true)
  {
    //Read the word
    in_file1 >> word;

    //Test for eof
    if (in_file1.eof())
      break;

    //Write the field
    out_file << word << endl;

  }

  //Close the files
  out_file.close();
  in_file1.close();

  
  

  return 0;
}
  
