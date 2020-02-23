#include <iostream>
#include <fstream>

using namespace std;

void processing(istream& is)
{
	int female, male, intern, rest=0, num_team=0;
	is >> female >> male >> intern;
	
		
	if(female/2 > male) {
		cout << "< case 1 >" << endl; 
		rest += female - male*2;
	}
	else if(female/2 < male) {
		cout << "< case 2 >" << endl;
		rest += male - female/2;
		male -= rest;
		if(female%2 != 0)		// 여자가 홀수여서 한명 남음 --> 인턴수에 추가 
			rest++;
	}
	else{
		cout << "< case 3 >" << endl;
	}
	int i=0;
	
	while(rest < intern){
		cout << "while " << i << '\t' << "rest : " << rest << '\t' << "male : " << male << endl;
		rest+=3;
		male--;
		i++;
	}
	num_team = male;
	cout << num_team << endl;
}


int main(void)
{
   const char* ifn = "ContestOrIntern_2875_3.txt";
   
   ifstream ifs(ifn);
   if(!ifs.is_open()){
      cerr << "Error: the input file cannot be opened." << endl;
      return -1;
   }
   
   processing(ifs);
   
   ifs.close();
    
   return 0;
}

