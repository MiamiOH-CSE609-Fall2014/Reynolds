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
vector<vector<int>> digramFreqMatrix(map<string,int>);

string DNA;

int main(int argc, char** argv)
{
  tuple<string, list<string>, string> parseFasta;
  map<string, int> Digram;
  vector<vector<int>> scores;

  parseFasta = parseFastaFile(argv[1]);
  Digram = digramFreqScores(DNA);
  scores = digramFreqMatrix(Digram);

  return 0;
}

vector<vector<int>> digramFreqMatrix(map<string, int> d)
{
  vector<vector<int>> scoreMatrix;

  //Convert the map to a vector here.
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
  cout << "Header " << endl;
  cout << get<0>(fastaFile) << endl;
  cout << "comments " << endl;
  //cout << get<1>(fastaFile) << endl;
  cout << "DNA sequence " << endl;
  cout << get<2>(fastaFile) << endl;
  DNA = DNASeq;
  return fastaFile;
  myfile.close();


}

map<string,int> digramFreqScores(string s)
{
  map<string, int> DigFreq = {
    {"AA", 0},
    {"AC", 0},
    {"AT", 0},
    {"CG", 0},
    {"CT", 0},
    {"GT", 0},
    {"CC", 0},
    {"TT", 0},
    {"AG", 0},
    {"GG", 0}
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
    cout << bar.first << " : " << bar.second << endl;
  }

  return DigFreq;
}
