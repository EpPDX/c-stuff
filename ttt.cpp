/*
tic tac toe
code by caley epstein
10/2/19

makes a playable 2 player ttt game
*/

#include <iostream>
#include <string.h>
using namespace std;



//pointer board
void clearBoard(char* Ptr[3][3]);
void drawBoard(char* Ptr[3][3]);
bool checkWin(char* Ptr[3][3], char player);
bool checkTie(char* Ptr[3][3]);


int xWins = 0, oWins = 0;



//main
int main()
{

  //main vars
  char player = 'O';
  char board[3][3];
  char* boardPtr[3][3];
  char input[2];
  char stillPlaying = 'y';
  bool attemptNum = true;

  
  for(int x = 0; x < 3; x++)  
  {
    for(int y = 0; y < 3; y++)
    {
      boardPtr[x][y] = &board[x][y];
    }
  }

  //counts wins
  while(stillPlaying == 'y')
  {
    cout << "X wins - " << xWins << endl << "O wins - " << oWins << endl;
    clearBoard(boardPtr);
    drawBoard(boardPtr);
    player = 'O';
    while(!checkWin(boardPtr, player) && !checkTie(boardPtr))
    {
      if(player == 'X')
      {
	player = 'O';
      }
      else
      {
	player = 'X';
      }
      do
	{
	  if(attemptNum == true)
	  {
	    cout << "make a move" << endl;
	  }

	  
	  else
	  {
	    cout << "not valid" << endl;
	  }
	  cin.get(input, 3);
	  cin.clear();
	  cin.ignore(1000000, '\n');
	  attemptNum = false;
	}
      
      while(!(input[0] == '1' || input[0] == '2' || input[0] == '3') || !(input[1] == 'a' || input[1] == 'b' || input[1] =='c') || !(board[(int)input[1] - 'a'][(int)input[0] - '1'] == ' '));
      attemptNum = true;
      board[(int)input[1] - 'a'][(int)input[0] - '1'] = player;
      drawBoard(boardPtr);
    }


    
    if(checkTie(boardPtr))
    {
      cout << "cats" << endl;
    }
    //when not a tie if a certain player one then say so
    else
    {
      cout << player << " wins" << endl;
      if(player == 'X')
      {
	xWins++;
      }
      else
      {
	oWins++;
      }
    }
    cout << "play again?(y or n)" << endl;
    cin >> stillPlaying;
    cin.clear();
    cin.ignore(1000000, '\n');
  }
}


void clearBoard(char* Ptr[3][3])
{
  for(int x = 0; x < 3; x++)
  {
    for(int y = 0; y < 3; y++)
    {
      *Ptr[x][y] = ' ';
    }
  }
}

//making grid 
void drawBoard(char* Ptr[3][3])
{
  cout << "  1 2 3" << endl;
  cout << 'a';
  for(int i = 0; i < 3; i++)
  {
    cout << ' ' << *Ptr[0][i];
  }
  cout << endl;

  cout << 'b';
  for(int i = 0; i < 3; i++)
  {
    cout << ' ' << *Ptr[1][i];
  }
  cout << endl;

  cout << 'c';
  for(int i = 0; i < 3; i++)
  {
    cout << ' ' << *Ptr[2][i];
  }
  cout << endl;
}

//win scenarios
bool checkWin(char* Ptr[3][3], char player)                                                                                                                                                        {                                                                                                                                                                                                     for(int i = 0; i < 3; i++)                                                                                                                                                                          {                                                                                                                                                                                                     if(*Ptr[0][i] == player && *Ptr[1][i] == player && *Ptr[2][i] == player)                                                                                                                            {                                                                                                                                                                                                     return true;                                                                                                                                                                                      }                                                                                                                                                                                                   if(*Ptr[i][0] == player && *Ptr[i][1] == player && *Ptr[i][2] == player)                                                                                                                            {                                                                                                                                                                                                     return true;                                                                                                                                                                                      }                                                                                                                                                                                                 }                                                                                                                                                                                                   if(*Ptr[0][0] == player && *Ptr[1][1] == player && *Ptr[2][2] == player)                                                                                                                            {                                                                                                                                                                                                     return true;                                                                                                                                                                                      }                                                                                                                                                                                                   if(*Ptr[2][0] == player && *Ptr[1][1] == player && *Ptr[0][2] == player)                                                                                                                            {                                                                                                                                                                                                     return true;                                                                                                                                                                                      }                                                                                                                                                                                                   return false;                                                                                                                                                                                      }        



//when no possible win scenarios are true
bool checkTie(char* Ptr[3][3])
{
  for(int x = 0; x < 3; x++)
  {
    for(int y = 0; y < 3; y++)
    {
      if(*Ptr[x][y] == ' ')
      {
	return false;
      }
    }
  }
  return true;
}





