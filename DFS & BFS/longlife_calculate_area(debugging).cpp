#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int,int> coordinate;
typedef pair<coordinate,coordinate> rectangle;

typedef vector<int> row;

void print_paper(const vector<row>& paper)
{
	/* Debugging */
	cout << "------------paper------------" << endl << endl;
	for(int i=0;i<paper.size();++i){
		for(int j=0;j<paper[i].size();++j)
			cout << paper[i][j] << '\t';
		cout << endl << endl;
	}	
	cout << "-----------------------------" << endl;
}

bool is_rectangle(vector<row>& paper, int i, int j)
{
	return paper[i][j] == -1;
}
bool is_top_edge(int i){
	return i == 0;
}
bool is_left_edge(int j){
	return j == 0;
}
bool is_bottom_edge(int i,vector<row>& paper){
	return i == paper.size();
}
bool is_right_edge(int j,vector<row>& paper){
	return j == paper[0].size();
}
void follow_left(vector<row>& paper, int i, int j, vector<int>& area)
{
	paper[i][j] = paper[i][j-1];
	area[paper[i][j-1]]++;
}
void follow_up(vector<row>& paper, int i, int j, vector<int>& area)
{
	paper[i][j] = paper[i-1][j];
	area[paper[i-1][j]]++;
}
void add_new(vector<row>& paper,int i, int j, vector<int>& area)
{
	area.push_back(1);
	paper[i][j] = area.size()-1;
}

void look_left(vector<row>& paper, int i, int j, vector<int>& area){
	if(!is_rectangle(paper,i,j-1))
		follow_left(paper,i,j,area);
	else
		add_new(paper,i,j,area);
}

void look_up(vector<row>& paper, int i, int j, vector<int>& area){
	if(!is_rectangle(paper,i-1,j))
		follow_up(paper,i,j,area);
	else
		add_new(paper,i,j,area);
}

void follow_min(vector<row>& paper,int i,int j,int max_val,int min_val){
	print_paper(paper);
	
	if(!is_top_edge(i) && !is_left_edge(j)){
		if(paper[i-1][j]==max_val){		
			paper[i-1][j] = min_val;
			cout << "changed paper[i-1][j] : " << paper[i-1][j] << endl;
			return follow_min(paper,i-1,j,max_val,min_val);
		}
		if(paper[i][j-1]==max_val){
			paper[i][j-1] = min_val;
			cout << "changed paper[i][j-1] : " << paper[i][j-1] << endl;
			return follow_min(paper,i,j-1,max_val,min_val);
			
		}
		if(!is_right_edge(j,paper) && !is_bottom_edge(i,paper)){
			cout << "hereeeeeeeeeeeeee" << endl;
			if(paper[i+1][j]==max_val){
				cout << "hereeeeeeeeeeeeee -1" << endl;
				paper[i+1][j] = min_val;
				cout << "changed paper[i+1][j] : " << paper[i+1][j] << endl;
				return follow_min(paper,i+1,j,max_val,min_val);
			}
			if(paper[i][j+1]==max_val){
				cout << "hereeeeeeeeeeeeee -2" << endl;
				paper[i][j+1] = min_val;
				cout << "changed paper[i][j+1] : " << paper[i][j+1] << endl;
				return follow_min(paper,i,j+1,max_val,min_val);
			}
		}
	}
	else if(is_top_edge(i) && !is_left_edge(j)){
		if(paper[i][j-1]==max_val){
			paper[i][j-1] = min_val;
			return follow_min(paper,i,j-1,max_val,min_val);
		}
		if(!is_right_edge(j,paper) && !is_bottom_edge(i,paper)){
			if(paper[i+1][j]==max_val){
				paper[i+1][j] = min_val;
				return follow_min(paper,i+1,j,max_val,min_val);
			}
			
			if(paper[i][j+1]==max_val){
				paper[i][j+1] = min_val;
				return follow_min(paper,i,j+1,max_val,min_val);
			}
		}
	}
	else if(!is_top_edge(i) && is_left_edge(j)){
		if(paper[i-1][j]==max_val){		
			paper[i-1][j] = min_val;
			return follow_min(paper,i-1,j,max_val,min_val);
		}
		if(!is_right_edge(j,paper) && !is_bottom_edge(i,paper)){
			if(paper[i+1][j]==max_val){
				paper[i+1][j] = min_val;
				return follow_min(paper,i+1,j,max_val,min_val);
			}
			
			if(paper[i][j+1]==max_val){
				paper[i][j+1] = min_val;
				return follow_min(paper,i,j+1,max_val,min_val);
			}
		}
	}
	cout << "finish follow_min " << endl;
}

void look_both(vector<row>& paper,int i,int j,vector<int>& area){
	if(!is_rectangle(paper,i-1,j) && is_rectangle(paper,i,j-1)){
		cout << " 5-1" << endl;
		follow_up(paper,i,j,area);
		
	}
	else if(is_rectangle(paper,i-1,j) && !is_rectangle(paper,i,j-1)){
		cout << " 5-2" << endl;
		follow_left(paper,i,j,area);
		
	}
	else if(!is_rectangle(paper,i-1,j) && !is_rectangle(paper,i,j-1)){
		cout << " 5-3" << endl;
		if(paper[i-1][j] == paper[i][j-1]){
			cout << " 5-3-1" << endl;
			follow_up(paper,i,j,area);
		}
		else{
			cout << " 5-3-2" << endl;
			paper[i][j] = min(paper[i-1][j], paper[i][j-1]);
			cout << "min: " << paper[i][j] << endl;
			area[min(paper[i-1][j], paper[i][j-1])] += area[max(paper[i-1][j], paper[i][j-1])];
			area.erase(area.begin()+max(paper[i-1][j], paper[i][j-1]));
			area[min(paper[i-1][j], paper[i][j-1])]++;
			follow_min(paper,i,j,max(paper[i-1][j], paper[i][j-1]),min(paper[i-1][j], paper[i][j-1]));
			cout << "area size: " << area.size() << "/ ";
			for(int a=0;a<area.size();++a)
				cout << area[a] << ' ';
			cout << endl;
		}
	}
	else{
		cout << " 5-4" << endl;
		add_new(paper,i,j,area);
	}
}

void find_area(vector<row>& paper, vector<int>& area)
{
	cout << " 1" << endl;
	for(int i=0;i<paper.size();++i){
		for(int j=0;j<paper[i].size();++j){
			if(!is_rectangle(paper,i,j)){
				if(is_top_edge(i) && is_left_edge(j)){
					cout << " 2" << endl;
					paper[i][j] = 0;
					area.push_back(1);
					cout << "area size: " << area.size() << "/ ";
					for(int a=0;a<area.size();++a)
						cout << area[a] << ' ';
					cout << endl;
				} 
				else if(is_top_edge(i)){
					cout << " 3" << endl;
					look_left(paper,i,j,area);
					cout << "area size: " << area.size() << "/ ";
					for(int a=0;a<area.size();++a)
						cout << area[a] << ' ';
					cout << endl;
				}
				else if(is_left_edge(j)){
					cout << " 4" << endl;
					look_up(paper,i,j,area);
					cout << "area size: " << area.size() << "/ ";
					for(int a=0;a<area.size();++a)
						cout << area[a] << ' ';
					cout << endl;
				}
				else {
					cout << " 5" << endl;
					look_both(paper,i,j,area);
					cout << "area size: " << area.size() << "/ ";
					for(int a=0;a<area.size();++a)
						cout << area[a] << ' ';
					cout << endl;
				}
			}
		}
	}
}


int main(void)
{
	int M, N, K;
	cin >> M >> N >> K;

	vector<rectangle> list_rect(K);
	for(int i=0;i<K;++i){
		cin >> list_rect[i].first.first >> list_rect[i].first.second; 	// ���� ������ 
		cin >> list_rect[i].second.first >> list_rect[i].second.second; // ��� ������ 
	}
//	/* Debugging */
//	for(int i=0;i<K;++i){
//		cout << list_rect[i].first.first << ' ' << list_rect[i].first.second << ' '; 	// ���� ������ 
//		cout << list_rect[i].second.first << ' ' << list_rect[i].second.second << endl; // ��� ������ 
//	}
	
	vector<rectangle> new_list_rect(K);  // ���� ���� �������� ��ǥ�� ����  
	for(int i=0;i<K;++i){
		new_list_rect[i].first.first = (M-1)-list_rect[i].first.second; // ���� x
		new_list_rect[i].first.second = list_rect[i].first.first; 		// ���� y
		new_list_rect[i].second.first = M-list_rect[i].second.second; 	// ��� x
		new_list_rect[i].second.second = list_rect[i].second.first-1; 	// ��� x 
	}
	
//	/* Debugging */
//	for(int i=0;i<K;++i){
//		cout << new_list_rect[i].first.first << ' ' << new_list_rect[i].first.second << ' ' 
//		<< new_list_rect[i].second.first << ' ' << new_list_rect[i].second.second << endl;
//	}	
	
	vector<row> paper(M,row(N,111));
	vector<int> area;

	// �־��� ���簢�� ǥ�� 
	for(int i=0;i<new_list_rect.size();++i)
		for(int j=new_list_rect[i].second.first;j<=new_list_rect[i].first.first;++j)
			for(int k=new_list_rect[i].first.second;k<=new_list_rect[i].second.second;++k)
				paper[j][k] = -1;
	
	print_paper(paper);


	find_area(paper, area);

	print_paper(paper);
	
	sort(area.begin(), area.end());
	cout << "area : ";
	for(int i=0;i<area.size();++i)
		cout << area[i] << ' ';
	cout << endl;
		
	return 0;
}
 

