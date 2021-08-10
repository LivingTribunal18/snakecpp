#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<string> field;
size_t eat_x, eat_y;
size_t head_x, head_y;
int left_c, right_c, down_c, up_c;

void parser(string s){
	string tmp_s = "";
	for (int i = 0; i < s.length(); i++){
		if(s[i] == 'n'){
			tmp_s.erase(tmp_s.length()-1);
			field.push_back(tmp_s);
			tmp_s = "";
		}else{
			tmp_s += s[i];
		}
	}
	field.pop_back();
	return;
}

void search(char ch, size_t *x, size_t *y){
	size_t eat;
	for(size_t i = 0; i < field.size(); i++){
		eat = field[i].find(ch);
		if(eat != string::npos){
			*x = eat; *y = i; 
			return;
		}
	}
	return;
}


int main(){

	srand(time(0));
	string s;
	vector<string> cours;
	vector<string> cours_1;
	vector<string> probability;	

	cin >> s;
	parser(s);
	search('o', &eat_x, &eat_y);
	search('@', &head_x, &head_y);
	
	int x_way = abs((int)(head_x - eat_x));
	int y_way = abs((int)(head_y - eat_y));

	if(field[head_y + 1][head_x] != 'x' && field[head_y + 1][head_x] != '*' && head_y + 1 > 0 && head_y + 1 < field.size()){
		cours_1.push_back("Down");
	}
	if(field[head_y - 1][head_x] != 'x' && field[head_y - 1][head_x] != '*' && head_y - 1 > 0 && head_y - 1 < field.size()){
		cours_1.push_back("Up");
	}
	if(field[head_y][head_x + 1] != 'x' && field[head_y][head_x + 1] != '*' && head_x + 1 > 0 && head_x + 1 < field.size()){
		cours_1.push_back("Right");
	}
	if(field[head_y][head_x - 1] != 'x' && field[head_y][head_x - 1] != '*' && head_x - 1 > 0 && head_x - 1 < field.size()){
		cours_1.push_back("Left");			
	}

	if (eat_y < head_y){
		cours.push_back("Up");
	}else{
		cours.push_back("Down");
	}
	if (eat_x < head_x){
		cours.push_back("Left");
	}else{
		cours.push_back("Right");
	}

	for(int i = 0; i < cours.size(); i++){
		bool f = false;
		for(int j = 0; j < cours_1.size(); j++){
			if(cours[i] == cours_1[j]){
				f = true;
			}
		}
		if(!f){
			cours.erase(cours.begin()+i);
		}
	}

	for (int i = 0; i < cours.size(); i++){
		if (cours[i] == "Left"){
			left_c += 1;
		}
		if(cours[i] == "Right"){
			right_c += 1;
		}
		if (cours[i] == "Up"){
			up_c += 1;
		}
		if(cours[i] == "Down"){
			down_c += 1;
		}			
	}

	for (int i = 0; i < cours_1.size(); i++){
		if (cours_1[i] == "Left"){
			left_c += 1;
		}
		if(cours_1[i] == "Right"){
			right_c += 1;
		}
		if (cours_1[i] == "Up"){
			up_c += 1;
		}
		if(cours_1[i] == "Down"){
			down_c += 1;
		}			
	}

	right_c += left_c;
	up_c += right_c;
	down_c += up_c;
	int max_border = up_c + down_c;
	int possibility = rand() % max_border;
	
	if(possibility >= 0 && possibility < left_c){
		cout << "Left" << endl;
		return 0;
	}else if(possibility >= left_c && possibility < right_c){
		cout << "Right" << endl;
		return 0;
	}else if(possibility >= right_c && possibility < down_c){
		cout << "Up" << endl;
		return 0;
	}else if(possibility >= up_c && possibility < max_border){
		cout << "Down" << endl;
		return 0;
	}else{
		cout << "Up" << endl; 
		return 0;
	}

	return 0;

}
