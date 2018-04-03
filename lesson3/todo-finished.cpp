#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/* Prototypes */
void ParseFile(string, vector<bool>&, vector<string>&, vector<string>&);
void ShowList(vector<bool>, vector<string>, vector<string>);

/* Global Variables */
ifstream fileReader;
ofstream fileWriter;

/* Start of Program */
int main()
{
  // Declare 3 vectors to hold our data.
  vector<bool> myChecks;
  vector<string> myTasks;
  vector<string> myDates;

  // Open the to do file and store the data to the vector.
  ParseFile("todo-finished.txt", myChecks, myTasks, myDates);
  ShowList(myChecks, myTasks, myDates);
}

void ParseFile(string fileName,
               vector<bool>& checks,
               vector<string>& tasks,
               vector<string>& dates)
{
  // Open the file.
  fileReader.open(fileName);

  // Iterate through each line from the file.
  string line;
  while (getline(fileReader, line))
  {
    // Declare 3 variables to hold our data.
    string check = line.substr(0, 1);
    string task = line.substr(4, line.length());
    string date = task.substr(task.find("| ") + 2, task.length());
    task = task.substr(0, task.find("|"));

    // Add the data to the vectors.
    if (check == "0")
    {
      checks.push_back(false);
    }
    else
    {
      checks.push_back(true);
    }
    tasks.push_back(task);
    dates.push_back(date);
  }
}

void ShowList(vector<bool> checks,
               vector<string> tasks,
               vector<string> dates)
{
  for (int i = 0; i < checks.size(); i++)
  {
    // Output the check mark.
    if (checks[i] == false)
    {
      cout << "[ ] ";
    }
    else
    {
      cout << "[x] ";
    }

    // Output the task description.
    cout << tasks[i] << endl;

    // Output the task date.
    cout << "    " << dates[i] << endl << endl;
  }
}
