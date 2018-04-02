#include <iostream>
#include <cstring>
#include <fstream>
#include <ctime>
#include "graph1.h"

using namespace std;

int main()
{
  //Variable Declaration/Initialization
  int i = 0;
  const int TOTAL_WORDS = 1149;
  int word_count = 0;
  int rand_word = 0;
  int length = 0;
  int startx = 100;
  int starty = 200;
  string word;
  string fn;
  string rand_word_val;
  
  //Display graphics
  displayGraphics();

  //Open file for input
  fstream in_file("words1.txt", ios::in);

  //Test for file opening
  if (!in_file)
  {
    cout << "Cannot open words1.txt for reading" << endl;
    return 0;
  }

  //Open file for output
  fstream out_file("out.txt", ios::out);

  //Test for opening
  if (!out_file)
  {
    cout << "Cannot open out.txt for writing" << endl;
    return 0;
  }

  //Generate random # between 0 and 1148
  srand(time(0));
  rand_word = rand()%TOTAL_WORDS;

  //Read words
  while(true)
  {
    //Read one word at a time
    in_file >> word;

    //Test for eof
    if (in_file.eof())
      break;

    //Test for word
    if (word_count == rand_word)
    {
      rand_word_val = word;
    }

    //Increment word
    word_count++;

    //Test for last word
    if (word_count == TOTAL_WORDS-2)
    {
      cout << "Next to Last Word Found" << endl;
    }
  }

  //Close the file

  in_file.close();

  //Get length of word
  length = rand_word_val.length();

  //Display white rectangle for each letter
  for (i = 0; i < length; i++)
  {
    drawRect(startx,starty,32,32);
    startx += 33;
  }

  //Wait
  Sleep(3000);

  //Display letters
  startx = 100;
  for (i = 0; i < length; i++)
  {
    fn = "";
   
    fn += rand_word_val[i];
    fn += ".bmp";
    displayBMP(fn,startx,starty);
    startx += 33;
  }

  //Display info
  cout << "Random Word is: " << rand_word_val << endl;
  cout  << "Random # is: " << rand_word << endl;
  gout << setPos(100,starty+48) << "Random Word is: " << rand_word_val << endg;
  gout << setPos(100,starty+63) << "Random # is: " << rand_word << endg;

  //Write out info
  out_file << "Random Word is: " << rand_word_val << endl;
  out_file << "Random # is: " << rand_word << endl;
  out_file.close();

  return 0;
}
  
 
  
    
  
  
  

  

