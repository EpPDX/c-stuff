/*
student list
code bt caley epstein
contributions from sethu eapen for pointer / iterators
october 2019

program has a list of students and keeps track of their student ids and names
 */

//inclusions
#include <iostream>
#include <vector>
#include <string.h>
#include <iomanip>

using namespace std;

//structure
struct Student
{
  char name1 [10];
  char name2 [10];
  int id;
  float gpa;
};


Student* ADD();
void PRINT(vector<Student*> students);
void DELETE(vector<Student*>* students, int id);
	   

int main()
{
  //variables

  char input[7];
  vector<Student*> students;
  bool running = false;


  int idInput;

  //runs until exit command makes running true (whoops switched it lol)
  while (!running)
  {
    //when commands are inputed then use code in functions below
	 cout << "add, print, delete, or exit?" << endl;
	 cin.get(input, 7);
	 cin.clear();
	 cin.ignore(100000, '\n');
	 if(strcmp(input, "add") == 0)
	 {
	   students.push_back(ADD());
	 }
	 else if(strcmp(input, "print") == 0)
	 {
	   PRINT(students);
	 }
	 //delete queue to choose which student to delete
	 else if(strcmp(input, "delete") == 0)
	 {
	   cout << "you entered the delete queue" << endl;
	   cout << "enter student id:";
	   cin >> idInput;
	   cin.clear();
	   cin.ignore(100000, '\n');
	   DELETE(&students, idInput);
	 }
	 //making running true ends program
	 else if(strcmp(input, "exit") == 0)
	 {
	   running = true;
	 }
	 //anything else is not accepted
	 else
	 {
	   cout << "not a valid entry" << endl;
	 }
       }
    return 0;

  }

//when user inputs add make a new student using structure from before 
Student* ADD()
{
  cout << "you entered add queue" << endl;
  Student* newStud = new Student();
  
  cout << "first name: ";
  cin >> newStud->name1;
  cin.clear();
  cin.ignore(10000, '\n');
  
  cout << "last name: ";
  cin >> newStud->name2;
  cin.clear();
  cin.ignore(10000, '\n');
  
  cout << "id: ";
  cin >> newStud->id;
  cin.clear();
  cin.ignore(10000, '\n');
  cout << "gpa: ";
  cin >> newStud->gpa;
  cin.clear();
  cin.ignore(10000, '\n');
  
  return newStud;
}



void PRINT(vector<Student*> students)
{
  cout << "you entered the print queue" << endl;
  vector<Student*>::iterator it;
  for(it = students.begin(); it != students.end(); ++it)
  {
    cout << "student name: " << (*it)->name1 << " " << (*it)->name2 << endl;
    cout << "student id: " << (*it)->id << endl;
    //makes sure gpa doesn't print more than 2 decimal points
    cout << "student gpa: " << fixed << setprecision(2) << (*it)->gpa << endl;
    cout << endl;
  }
}



//deletes student unless id isn't on list
void DELETE(vector<Student*>* students, int id)
{
  vector<Student*>::iterator it;
  for(it = students->begin(); it != students->end(); ++it)
  {
    if((*it)->id == id)
    {
      delete *it;
      students->erase(it);
      return;
    }
  }
  cout << "invalid id" << endl;
}


