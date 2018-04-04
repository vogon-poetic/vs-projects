#include <iostream>
#include <cstring>
#include <fstream>
#include "graph1.h"
#include "Game.h"

using namespace std;


Game::Game()
{
	this->fileName = "";
	this->word = "";
}


string Game::getFileName()
{
	return this->fileName;
}
void Game::setFileName(string fn)
{
	this->fileName = fn;

}
void Game::setWord(int rand_no)
{
	fstream file;
	file.open(this->getFileName(), ios::out);

	if (!file) {
		cout << "Error: file not opened correctly." << endl;
		exit(-1);
	}

	for (int wc = 0; !file.eof(); ++wc) {
		
	}
}
string Game::getWord()
{


}
void Game::draw()
{


}
