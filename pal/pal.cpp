#include <iostream>
#include <cstring>

//palendrome code by caley epstein
//9/24/19
//help from stefan ene

using namespace std;

//set count and all three versions of input (og, no punct, and flipped)
int main()
{
  char input[80];
  int invalid = 0;
  cout << "I am the pallendrome genie! Input a phrase, and I shall tell you if it is a pallendrome or nahhhhhhh" << endl;
  //to tell how long word is
  int count = 0;
  char secondi[81];
  char thirdi[81];
  
  

    for (int i = 0; i <=80; i++)
    {
      input[i]=0;
      secondi[i]=0;
      thirdi[i]=0;
    }
    //takes input
    cin.get(input, 80);

    //gets lowercase letters only
    for (int i = 0; i<80; i++)
    {
      if (input[i] >= 97 && input[1] <=122)
      {
	secondi[count] =input[i];
	count++;
      }
      //gets uppercase letters
      else if (input[i] >= 65 && input[i] <= 90)
      {
	secondi[count] = input[1]+32;
	count++;
      }


      
    }
    count--;
    //flips
    for (int i =0; i<80; i++)
    {
      if (secondi[count-i] !=0)
      {
	thirdi[i] = secondi[count-i];
      }
      
    }

    //if no punct and flipped match then we in there homie
    if(strcmp(secondi, thirdi) ==0)
    {
      cout << "ayyy lmao u got urself a pal" << endl;
    }

    else
    {
      cout << "not a pal, go type taco cat fool" << endl;  
    }

    cout << secondi << endl;
    cout << thirdi << endl;

    return 0;
    
}
