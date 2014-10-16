#include<iostream>
#include<cstring>
#include<fstream>
#include<vector>
#include<math.h>
#include <stdio.h>

using namespace std;

void getScores(vector<string> &names, vector<int> &scores);
void printScores(vector<string> names, vector<int> scores, vector<string> grades, vector<double> scale,double mean,double  std);
void calculateGrade(vector<int> scores, vector<string> &grades, vector<double> &scale, double &mean, double &std);

//
//Main Method
//
int main()
{
    vector<string> names;
    vector<int> scores;
    vector<string> grades;
    vector<double> scale;

    double mean;
    double std;

    getScores(names, scores);
    calculateGrade(scores,grades, scale, mean, std);
    printScores(names, scores, grades, scale, mean, std);

  return 0;
}

//
//Get the names and scores of the students.
//
void getScores(vector<string> &names, vector<int> &scores)
{
  string name = " ";
  double score = 0;
     
  //Get scores until "none is typed
  while(name != "none")
    {
      cout << "Please Print Your name or none to quit: ";
      getline(cin, name);
        if(name != "none")
	{
	  names.push_back(name);
	  cout << "Enter the Score: ";
	  cin >> score;
	  if(score < 0 || score > 100)
	    {
	      cout << "Enter a score again between 0-100: ";
	      cin >> score;
	    }
	      char a; cin.get(a);
	      scores.push_back(score);
	    
	   
	 }
      }
}




//
// Print Scores
//
void printScores(vector<string> names, vector<int> scores, vector<string> grades, vector<double> scale,double mean,double std)
{
  cout << "\n Grading Scale  \n \n";

  printf(" A above %4.1f%% \n", scale.at(0));
  printf(" B %.1f%% - %.1f%%\n", scale.at(1), scale.at(0));
  printf(" C %.1f%% - %.1f%%\n", scale.at(2), scale.at(1));
  printf(" D %.1f%% - %.1f%%\n", scale.at(3), scale.at(2));
  printf(" F below %.1f%% \n \n", scale.at(3));

  cout.width(15); cout << left << "Name"; 
  cout.width(10); cout << left << "Score";
  cout.width(5); cout << left << "Grade\n";

  for(int i = 0; i < names.size(); i++)
    { 
      cout.width(15); cout << left <<  names.at(i);
      cout.width(3); cout << left << scores.at(i); 
		       cout.width(7); cout << left << "%";
      cout.width(5); cout << left << grades.at(i) << endl;
    }

  printf("\nClass Average = %.2f%%\n", mean);
  printf("Standard Deviation = %.2f \n\n", std);
}

//
//Calculate the Grades
//
void calculateGrade(vector<int> scores, vector<string> &grades, vector<double> &scale, double &mean, double &std)
{
  double sum = 0;
  for(int i = 0; i < scores.size(); i++)
    {
      sum = sum + scores.at(i);
    }

   mean = sum / scores.size();
 
  double total = 0;
  //calculate the deviation from mean for each score
 for(int i =0; i < scores.size(); i++)
   {
     total = total + pow((scores.at(i)-mean), 2);
   }
 //divide by total number of scores
 total = total/scores.size();
 //calculate sqrt
  std = sqrt(total);
 
 for(int i = 0; i < scores.size(); i++)
   {
     double score = scores.at(i)-mean;
     if(1.5*std + mean < 100)
     scale.push_back(1.5*std + mean); //A cutoff
     else
       scale.push_back(100);
     scale.push_back(0.5*std + mean); //B cutoff
     scale.push_back(-0.5*std + mean); //C cutoff
     scale.push_back(-1.5*std + mean); //D cutoff
     
     if(score <= -1.5*std) //F
       grades.push_back("F");
     else if(-1.5*std <= score && score <-0.5*std) //D
       grades.push_back("D");
     else if(-0.5*std <= score && score <0.5*std)
       grades.push_back("C");
     else if(0.5*std <= score && score <1.5*std)
       grades.push_back("B");
     else if(1.5*std <= score)
       grades.push_back("A");
   }
 
}
