#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void print_treeArr(vector<char>& treeArr){
   cout << "------------------------------------------ treeArr ------------------------------------------" << endl << endl;
   for(int i=0;i<treeArr.size();++i)
      cout << i << '\t';
   cout << endl;
   
   for(int i=0;i<treeArr.size();++i)
      cout << treeArr[i] << '\t';
   cout << endl << endl;
   cout << "---------------------------------------------------------------------------------------------" << endl << endl;
}

void processing(istream& is)
{
   vector<char> treeArr(4,'0');
   int N;
   is >> N >> treeArr[1] >>  treeArr[2] >> treeArr[3];
   print_treeArr(treeArr);
   char tmp;
   vector<char>::iterator it;
   int new_size;
   int target_index;

   for(int i=1;i<N;++i){
      is >> tmp;                     // parent
      target_index = find(treeArr.begin(), treeArr.end(), tmp) - treeArr.begin();   
      new_size = (target_index)*2 + 2;
      if(treeArr.size() < new_size)
         treeArr.resize(new_size,'0');

      is >> tmp;
      cout << "tmp : " << tmp << endl;
      cout << target_index*2 << endl;
      if(tmp!='.')
         treeArr[target_index*2] = tmp;         // left child

      is >> tmp;   
      if(tmp!='.')
         treeArr[target_index*2 + 1] = tmp;      // right child
      
      print_treeArr(treeArr);
   }

   print_treeArr(treeArr);
   
}


int main(void)
{
   const char* ifn = "TreeOrdering_1991.txt";
   
   ifstream ifs(ifn);
   if(!ifs.is_open()){
      cerr << "Error: the input file cannot be opened." << endl;
      return -1;
   }
   
   processing(ifs);
   
   ifs.close();
    
   return 0;
}
