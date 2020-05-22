#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void show_mat(const vector<vector<int>> &matrix){
	int N = matrix.size();
	for(int row = 0; row < N; row++){
		for(int col = 0; col < N; col++){
			cout<< matrix[row][col];
		}
		cout<<endl;
	}
		cout<<endl;
}
string remove_char(string str, char chr){
	string tmp;
	for(int i = 0; i < str.size(); i++){
		if(str[i] != chr)
			tmp += str[i];
	}
	return tmp;
}
int track(const vector<vector<int>> &matrix){
	int N = matrix.size();
	int track = 0;
	for(int i = 0; i < N; i++){
		track += matrix[i][i];
	}
	return track;
}
int num_repeated_row(const vector<vector<int>> &matrix){
	int N = matrix.size();
	int num_rows = 0;
	for(int row = 0; row < N; row++){
		bool been[N] = {0};
		for(int col = 0; col < N; col++){
			int num = matrix[row][col]-1;
			if(been[num]){
				num_rows++;
				break;
			}
			else
				been[num] = 1;
		}
	}
	return num_rows;
}
int num_repeated_col(const vector<vector<int>> &matrix){
	int N = matrix.size();
	int num_rows = 0;
	for(int row = 0; row < N; row++){
		bool been[N] = {0};
		for(int col = 0; col < N; col++){
			int num = matrix[col][row]-1;
			if(been[num]){
				num_rows++;
				break;
			}
			else
				been[num] = 1;
		}
	}
	return num_rows;
}

int main(){
	fstream file("input.txt", ios::in);
	string text;
	int line_num = 0;
	int cases;
	int case_num = 1;
	int N = 0;
	int matrix_row = 0;
	vector <vector<int>> matrix;
	while(getline(file, text)){
		if(line_num == 0){
			cases = text[0]-'0';
		}
		else{
			if(matrix_row < N){
				text = remove_char(text, ' ');
				vector <int> row(N);
				for(int i = 0; i < N; i++){
					row[i] = text[i]-'0';
				}
				matrix.push_back(row);
				matrix_row++;
			}
			else{
				N = text[0]-'0';
				matrix_row = 0;
				matrix.clear();
			}
			if(matrix_row >= N){
				cout<<"Case #"<<case_num<<": "<<track(matrix)<<" "<<num_repeated_row(matrix)<<" "<<num_repeated_col(matrix)<<endl;
				case_num++;
			}
		}
		line_num++;
	}

	return 0;
}

/*
				text = remove_char(text, ' ');
				vector <int> row(N);
					cout<<text<<endl;
				for(int i = 0; i < N; i++){
					row[i] = text[i]-'0';
				}
				matrix.push_back(row);*/