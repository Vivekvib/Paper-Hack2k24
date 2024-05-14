#include <iostream>
using namespace std;

class Matrix{
	int vertex;
	int **matrix;
	public:
		Matrix(int v): vertex(v) {
			matrix = new int*[vertex];
			for(int i=0;i<vertex;i++){
				matrix[i] = new int[vertex];
			}
		}
		void genMatrix();
		void display();
		bool complete();
};

void Matrix::genMatrix(){
	int elem;
	for(int i=0;i<vertex;i++){
		for(int j=0;j<vertex;j++){
			cout << "What elements are related to " << i << " (-1 to terminate): ";
			cin >> elem;
			if(elem!=-1){
				matrix[i][elem] = 1;
			}
			else{
				break;
			}
		}
	}
}

void Matrix::display(){
	cout << endl << "Given Matrix:- " << endl;
	for(int i=0;i<vertex;i++){
		cout << "[";
		for(int j=0;j<vertex;j++){
			cout << " " << matrix[i][j] << " ";
		}
		cout << "]" << endl;
	}
}

bool Matrix::complete(){
	bool flag = true;
	for(int i=0;i<vertex;i++){
		for(int j=0;j<vertex;j++){
			if(i==j && matrix[i][j] != 0){
				flag = false;
			}
			else if(i!=j && matrix[i][j] != 1){
				flag = false;
			}
		}
	}
	return flag;
}

int main() {
	int v;
	cout << "How many vertices does the graph have?: ";
	cin >> v;
	Matrix obj1(v);
	obj1.genMatrix();
	obj1.display();
	if(obj1.complete() == true){
		cout << "The given graph is a complete graph" << endl;
	}
  else{
    cout << "The given graph is not a complete graph" << endl;
  }
}
