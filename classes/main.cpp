/*
classes code by caley epstein
a database of a bunch medias, uses mutliple classes

this is the parent class

help from stefan

11/8/19

code is very segmented, formatted badly, and incomplete. This is the best mish-mash of code I could turn in before the deadline



 */


//inclusions
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
using namespace std;



//main function
int main()
{

  char input[7];
  

  int input1;
  bool running = true;
  vector<Media*> mediaArr;


  //before exit command switches program off
  while(running == true)
  {



    cin.get(input, 7);


    cin.clear;
    if (strcmp(input, "add")==0)
    {
      //array
      ADD(&mediaArr);
      cout << dynamic_cast<Movies*>(mediaArr[0])->year;
    }

    //setting variables after input
    
    else if(strcmp(input, "search") == 0)
    {
      cout << "enter title or year";
      auto input2;
      cin >> input2;
      cin.clear();
      cin.ignore(1000000, '\n');
      PRINT();
    }

    

    //switches while statement off
    else if(strcmp(input, "exit") == 0)
    {
      running = false;
    }

    //other
    else
    {
      cout << "not a valid input" << endl;
    }


  
    return 0;



  }

}

void ADD(vector<Media*>*media);

void ADD(vector<Media*>* media)
{
   //variables
   
   char input[10];
   char title[10];
   int year;
   char director[10];
   char durration[8];
   float rating;


   //allows for input of media type
   cout << "what kind of media would you like to add?" << endl;
   cin.get(input, 10);
   cin.clear();
   cin.ignore(10000, '\n');
   //different inputs for movue option
   if(strcmp(input, "movie") == 0)
   {
     Movies* movie = new Movies();
     cout << "Title: ";
     cin.get(movie -> title, 10);
     cin.clear();
     cin.ignore(10000, '\n');
     cout << "Year: ";
     cin >> movie -> year;
     cin.clear();
     cin.ignore(10000, '\n');
     cout << "Director: ";
     cin.get(movie -> director, 10);
     cin.clear();
     cin.ignore(10000, '\n');
     cout << "Durration: ";
     cin.get(movie -> duration, 8);
     cin.clear();
     cin.ignore(10000, '\n');
     cout << "Rating: ";
     cin >> movie -> rating;
     cin.clear();
     cin.ignore(10000, '\n');
     media->push_back(movie);
   }

   
   else
   {
     cout << "not a media type";
   }


 }
