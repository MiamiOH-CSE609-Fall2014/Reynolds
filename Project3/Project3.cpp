#include<fstream>
#include<iostream>
#include<tuple>
#include<string>
#include<list>
#include<map>
#include<vector>
using namespace std;
using std::string;

tuple<string, list<string>, string> parseFastaFile(string);
map<string, int> digramFreqScores(string);
vector<int> digramFreqMatrix(map<string,int>);
void PrintScore(vector<int>);
vector<int> parseScoringFile(string);
tuple<int, int> scoreSequence(string, string, vector<int>);
tuple<int, int, string> findHighScore(string, string, vector<int>);
string DNA;

int main(int argc, char** argv)
{
  tuple<string, list<string>, string> parseFasta;
  map<string, int> Digram;
  vector<int> scores;
  vector<int> scoreMatrix; 
  tuple<int, int> max_score;
  tuple<int, int, string> max_score2;

  parseFasta = parseFastaFile(argv[1]);
  Digram = digramFreqScores(DNA);
  scores = digramFreqMatrix(Digram);

  cout << "Diagram Frequency Matrix" << endl;
  PrintScore(scores);
  cout << " \n\n";

  scoreMatrix = parseScoringFile(argv[2]);

  cout << "Scoring Matrix" << endl;
  PrintScore(scoreMatrix);

  cout << " \n\n";

  int seqCount = 0;
  vector<string> sequence;
  cout << "How many sequences would you like to score? ";
  cin >> seqCount;
  int i = 1;
  while(i <= seqCount)
    {
      cout << "Enter Sequence #" <<  i << " on a single line:\n";
      string seq;
      cin >> seq;
      sequence.push_back(seq);
      i++;
    }

  cout << "\n\n";

  for(int i = 0; i < sequence.size(); i++)
    {
      tuple<int, int, string> max_score2;
      max_score2 = findHighScore(DNA, sequence.at(i), scoreMatrix);
      cout << "Sequence:" << endl;
      cout  << "\"" << get<2>(max_score2) << "\"\n";
      cout << "Score: " <<  get<1>(max_score2) << " at position " << get<0>(max_score2) << "\n\n";
      
    }
  
  
  //  cout << get<0>(max_score2) << " " << get<1>(max_score2) << " " << get<2>(max_score2) << endl;
  return 0;
}

tuple<int, int, string> findHighScore(string haystack, string needle, vector<int> score_m)
{
   int pos = 0;
  int maxScore = 0;
  int hayLength = haystack.length();
  int needleLength = needle.length();
  string match;
  // cout << "Hay = " << haystack <<  " Length " << hayLength << " \n";
  //cout << "Needle = " << needle << " Length " << needleLength << " \n";

  map<string, int> Score = {
    {"AA", score_m.at(0)},
    {"AG", score_m.at(1)},
    {"AC", score_m.at(2)},
    {"AT", score_m.at(3)},
    {"GA", score_m.at(4)},
    {"GG", score_m.at(5)},
    {"GC", score_m.at(6)},
    {"GT", score_m.at(7)},
    {"CA", score_m.at(8)},
    {"CG", score_m.at(9)},
    {"CC", score_m.at(10)},
    {"CT", score_m.at(11)},
    {"TA", score_m.at(12)},
    {"TG", score_m.at(13)},
    {"TC", score_m.at(14)},
    {"TT", score_m.at(15)}
  };

  //  for(const pair<string, int> &bar : Score){
  // cout << bar.first << " : " << bar.second << endl;
  // }


  for(int i = 0; i < hayLength - needleLength + 1; i++){
    int tempScore = 0;
    for(int j = 0; j < needleLength; j++)
      {
        string hay = haystack.substr(i+j,1);
        string need = needle.substr(j,1);
        string compare = need;
        compare += hay;
        tempScore += Score[compare];

        //      cout << "Needle = " << need << endl;
        //      cout << "Haystack = " << hay << endl;
        //      cout << "Compare " << compare;
        //      cout << " Score = " << Score[compare] << endl;
      }
    if(tempScore >= maxScore)
      {
        maxScore = tempScore;
        pos = i;
	//        cout << "Max Score = " << maxScore << endl;
	match = haystack.substr(i,needleLength);
	//   cout << "Position = " << pos << endl;
      }

  }

  tuple<int, int, string> max_score{pos, maxScore,match};
  return max_score;

}



tuple<int, int> scoreSequence(string haystack, string needle, vector<int> score_m)
{
    int pos = 0;
  int maxScore = 0;
  int hayLength = haystack.length();
  int needleLength = needle.length();

  // cout << "Hay = " << haystack <<  " Length " << hayLength << " \n";
  //cout << "Needle = " << needle << " Length " << needleLength << " \n";
 
  
  map<string, int> Score = {
    {"AA", score_m.at(0)},
    {"AG", score_m.at(1)},
    {"AC", score_m.at(2)},
    {"AT", score_m.at(3)},
    {"GA", score_m.at(4)},
    {"GG", score_m.at(5)},
    {"GC", score_m.at(6)},
    {"GT", score_m.at(7)},
    {"CA", score_m.at(8)},
    {"CG", score_m.at(9)},
    {"CC", score_m.at(10)},
    {"CT", score_m.at(11)},
    {"TA", score_m.at(12)},
    {"TG", score_m.at(13)},
    {"TC", score_m.at(14)},
    {"TT", score_m.at(15)}
  };

  //  for(const pair<string, int> &bar : Score){
  // cout << bar.first << " : " << bar.second << endl;
  // }

  
  for(int i = 0; i < hayLength - needleLength + 1; i++){
    int tempScore = 0;
    for(int j = 0; j < needleLength; j++)
      {
	string hay = haystack.substr(i+j,1);
	string need = needle.substr(j,1);
        string compare = need;
	compare += hay;
	tempScore += Score[compare];
	
	//	cout << "Needle = " << need << endl;
	//	cout << "Haystack = " << hay << endl;
	//	cout << "Compare " << compare;
	//	cout << " Score = " << Score[compare] << endl;
      }
    if(tempScore >= maxScore)
      {
	maxScore = tempScore;
	pos = i;
	//	cout << "Max Score = " << maxScore << endl;
	//	cout << "Position = " << pos << endl;
      }

  }
  tuple<int, int> max_score{pos, maxScore};
  return max_score;
  
}

vector<int> parseScoringFile(string filename)
{
  string line;
  ifstream myfile;

  int i = 0;
  int j = 0;
  array<int, 4> temp;

  vector<int> score;
  myfile.open(filename.c_str());
  if(myfile.is_open())
    { 
      while(getline(myfile,line))
        {
	  int temp = line.at(0) - '0';
	  int temp1 = line.at(2) - '0';
	  int temp2 = line.at(4) - '0';
	  int temp3 = line.at(6) - '0';
	  score.push_back(temp);
	  score.push_back(temp1);
	  score.push_back(temp2);
	  score.push_back(temp3); 
	}       
    }
  /*
  for(int i = 0; i < score.size(); i++)
    {
      cout << score.at(i) << endl;
    }
  */

  return score;
}


void PrintScore(vector<int> score)
{
  vector<string> DNAsym = {"A", "G", "C", "T", 
			   "A", "G", "C", "T"};

  cout << "   ";
  //Print Heading
  for (int i = 0; i <= 3; i++)
    {cout.width(3); cout << DNAsym.at(i) << " ";}
    
  cout << endl;
  cout.width(4); cout << DNAsym.at(4);  
  for (int i = 0; i <= 3; i++)
    { cout.width(3); cout << score.at(i) << " ";}
  
  cout << endl;
  cout.width(4); cout << DNAsym.at(5);
  for (int i = 4; i <= 7; i++)
    { cout.width(3); cout << score.at(i) << " ";}

  cout << endl;
  cout.width(4); cout << DNAsym.at(6);
  for (int i = 8; i <= 11; i++)
    { cout.width(3); cout << score.at(i) << " ";}

  cout << endl;
  cout.width(4); cout << DNAsym.at(7);
  for (int i = 12; i <= 15; i++)
    { cout.width(3); cout << score.at(i) << " ";}

  cout << endl;
}

vector<int> digramFreqMatrix(map<string, int> d)
{
  vector<int> scoreMatrix;
  vector<string> DNA = {"AA", "AG", "AC", "AT",
			"GA", "GG", "GC", "GT",
			"CA", "CG", "CC", "CT",
			"TA", "TG", "TC", "TT"};

  for(int i = 0; i <= DNA.size()-1; i++)
    {
      scoreMatrix.push_back(d[DNA.at(i)]);      
    }
  return scoreMatrix;
}

tuple<string,list<string>, string> parseFastaFile(string filename)
{
  string line;
  ifstream myfile;
  string header;
  list<string> comments;
  list<string>::iterator it;
  string DNASeq;

  myfile.open(filename.c_str());
  if(myfile.is_open())
    {
      getline(myfile,header);

      while(getline(myfile,line))
	{
	  int pos = line.find(";");
	  if(pos == 0){
	      comments.push_back(line);
	      //cout << "This is a comment";
	    }    
	  else{
	    DNASeq += line;
	    //cout << line << '\n';
	  }
	}
    }

  //Printing statements to verify
  //  cout << "Header " << header << endl;
  //  cout << "Comments " << endl;
  //  for(it=comments.begin(); it!=comments.end(); it++)
  // { cout << *it << endl;}
  //  cout << "DNA Sequence" << DNASeq;

  tuple<string,list<string>, string> fastaFile;   //Change to a list!!!!
  fastaFile = make_tuple(header, comments, DNASeq);  //Replace 10 with "comments"
  //  cout << "Header " << endl;
  //  cout << get<0>(fastaFile) << endl;
  //  cout << "comments " << endl;
  //  cout << get<1>(fastaFile) << endl;
  //cout << "DNA sequence " << endl;
  //cout << get<2>(fastaFile) << endl;
  DNA = DNASeq;
  return fastaFile;
  myfile.close();


}

map<string,int> digramFreqScores(string s)
{
  map<string, int> DigFreq = {
    {"AA", 0},
    {"AG", 0},
    {"AC", 0},
    {"AT", 0},
    {"GA", 0},
    {"GG", 0},
    {"GC", 0},
    {"GT", 0},
    {"CA", 0},
    {"CG", 0},
    {"CC", 0},
    {"CT", 0},
    {"TA", 0},
    {"TG", 0},
    {"TC", 0},
    {"TT", 0}
  };

  for(const pair<string, int> &bar : DigFreq) {
    string searchfor = bar.first;
    int count = 0;

    for(int i=0; i < s.length()-1; i++){
       string curr =  s.substr(i,2);
       if(searchfor == curr)
	 count +=1;
       //	 cout << curr << endl;
    }
    DigFreq[searchfor] =  count;
  
    //    cout << "Looking for: " << searchfor << endl;
    //cout << "Found #: " << count << endl;
 
  }

  for(const pair<string, int> &bar : DigFreq){
    //  cout << bar.first << " : " << bar.second << endl;
  }

  return DigFreq;
}
