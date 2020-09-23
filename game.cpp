//Name: Alexander Connolly
//Project: Chess game
//Date: 09/15/20
//Environment: Windows, Jed
//Name: Alexander Connolly
//Date: 9/20/20
//Description: Chess Game Project
//Environment: Windows, Cygwin
//File Name: game.cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int SIDE = 8;

void makeMove(char board[][SIDE], int fromRow, int fromCol, int toRow, int toCol);

void saveBoard(string file, char board[][SIDE]);

//loadBoard function, pass file and board

void loadBoard(string file, char board[][SIDE])
{ 
   //declare the stream variable
   
   ifstream streamVar;
   
   //use streamVar to open input.txt
   
   streamVar.open("input.txt");
   
   string fileReader;
   
   //test line
   int l;
   
   for(int i = 0; i < SIDE; i++)
   {
      //get a line of input.txt
      
      getline(streamVar,fileReader);
      
      for(int j = 0; j < SIDE; j++)
      
      {
      
      //assign the current character of the current line to the character board[i][j] 
	   
      board[i][j] = fileReader.at(j);
	   
      }
      
   }
   
}


//this function is responsible for creating an input file stream object, tying it to the file on disk called file. 
//The function should then read in the represented chess board, and store it into the char array board.
  
void printBoard(char board[][SIDE])
{
   //border
   
   string border = "+---+---+---+---+---+---+---+---+";
   
   cout << border << endl;
   
   for(int i = 0; i < SIDE; i++){

        //output left edge of board
      
	cout << "|";
	
	for(int j = 0; j < SIDE; j++)
	  
	  {   
	     //output the characters, spaces and the last | representing the right edge of the board
	     
	     cout << " " << board[i][j] << " |";
	     
	  }
      
	cout << endl << border << endl;
      
   }
}


//a pretty display of the state of the chess board (see sample output for an example)

void playGame(char board[][SIDE])
{
   int fromRow, fromCol, toRow, toCol;
   
   char control = '1';
   
   string outfile;
   
   //create a bool variable done and set it to false
   
   bool done = false;
   
   //while bool is false
   
   while(!done)
     
     {
	
	//menu that asks the user to make a move or to quit the program
	
	cout << "What would you like to do?" << endl;
	
	cout << "1. Make a move." << endl;
	
	cout << "2. Quit." << endl;
	
	cout << endl;
	
	cin >> control;
	
	//if the user has selected 2
	
	if(control == '2')
	  {
	     
	     done = true;
	     
	     continue;
	     
	  }
	
	//menu that lets the user select the piece they want to move
	
	cout << "What row is the piece you want to move? (0-7) ";
	cin >> fromRow;
	
	cout << "What column is the piece you want to move? (0-7) ";
	cin >> fromCol;
	
	//menu that lets the user select where they want to move the piece
	
	cout << "What row do you want to move it to? (0-7) ";
	cin >> toRow;
	
	cout << "What column do you want to move it to? (0-7) ";
	cin >> toCol;

	makeMove(board,fromRow,fromCol,toRow,toCol);
	
	printBoard(board);
	
     }
      
   cout << "Final board: " << endl;
   
   printBoard(board);
   
   //allows the user to save the final board aftey have selected 'quit'
   
   cout << "Enter the name of the file to save to: ";
   cin >> outfile;
   
   saveBoard(outfile,board);
   
   cout << "Thanks for playing!" << endl;
   
}

//this is the main driver of your program. Main will call this after initially loading your board. 
//This function should have a loop, that prints out the current board state, 
//and asks the user what they want to do: make another move or quit the game (see sample output).
 
void makeMove(char board[][SIDE], int fromRow, int fromCol, int toRow, int toCol)
{
   
   //rule that throws an error if the starting row is out of bounds
   
   if(fromRow < 0 || fromRow > 7)
     {
	
	cout << "ERROR: Starting row is out of bounds." << endl;
	
     }
   
   //rule that throws an error if the starting column is out of bounds
   
   
   else if(fromCol < 0 || fromCol > 7)
     {
	
	cout << "ERROR: Starting column is out of bounds." << endl;
	
     }
   
   //rule that throws an error if the destination row is out of bounds
   
   else if(toRow < 0 || toRow > 7)
     {
	
	cout << "ERROR: Destination row is out of bounds." << endl;	
     
     }
   
   //rule that throws an error if the destination column is out of bounds
   
   else if(toCol < 0 || toCol > 7)
     {
	
	cout << "ERROR: Destination column is out of bounds." << endl;
	
     }
   
   else if(board[fromRow][fromCol] == ' ')
     {
	
	cout << "The space you are moving from is empty." << endl;
	
     }
   
   else
     {
	
	cout << "Moved from " << fromRow << "," << fromCol << " to " << toRow << "," << toCol << endl;
	
	board[toRow][toCol] = board[fromRow][fromCol];
	
	board[fromRow][fromCol] = ' ';
	
     }
   
}   
        

//this function checks all bounds, and ensures that a piece exists at board[fromRow][fromCol]
//should any of these checks fail, the function should print out an approprite error message and return without modifying the board. 
//If everything is OK, the piece should be moved, the board updated, and the function should print out what (if any) pieces were removed.
  
void saveBoard(string file, char board[][SIDE])
{
   ofstream fout;
   
   fout.open(file);
   
   for(int i = 0; i < SIDE; i++){	
	
	for(int j = 0; j < SIDE; j++)
	  
	  {
	     
	     //output the characters, spaces and the last | representing the right edge of the board
 
	     fout.put(board[i][j]);
	     
	  }
      
      fout.put('\n');
   }
   
   fout.close();
  
   cout << "Board saved to: " << file << endl;

}

//this function should be called once the user indicates that they are done making moves. 
//The function will need to create an output file stream and tie it to the file on disk called file. 
//NOTE: this should not look like the output of printBoard(), but have the same minimal representation as the original input file.


int main()
{
   
   string file;
   
   string outfile = "output.txt";
   
   cout << "What file would you like to open? ";
   cin >> file;
   
   char board[SIDE][SIDE];
   
   loadBoard(file,board);

   //should playGame be called here?
   
   printBoard(board);   
   
   saveBoard(outfile,board);
   
   //makeMove(board,fromRow,fromCol,toRow,toCol);
   
   playGame(board);
   
   
}
