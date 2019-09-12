/*
guessing game code by caley epstein
random number between 0 & 100 has to be guessed
stefan ene helped with random seed part of code
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;


int main()
{
  //seed based on time
  int input = 0;
  //sets random number
  int guess =1;
  bool yn = true;
  char play;
  while (yn)
    {  
      srand (time(NULL));
      int random = rand() % 101; 
    cout << "Make a guess between 0 and 100 to see if it's right" << endl;
    cin >> input;
    //loop reads input and checks, if flase it gives desired response and allows for another input (restarting loop) 
    while(input!=random)
    {
      if(input<random)
      {
        cout << "Your guess is lower than the number, guess again!" << endl;
        guess++;
        cin >> input;
      }
      else if (input > random)
      {
        cout << "Your guess is higher than the number, guess again!" << endl;
        guess++;
        cin >> input;
      }
    
    }
    //if guess is correct
    cout << "Your guess is correct! It took you " << guess++ << " guesses to get the right number" << endl;
    cout << "Do you want to play again? y/n" << endl;
    cin >> play;
    if (play == 'n')
    {
      yn =false;
    } 
  }
  
}
