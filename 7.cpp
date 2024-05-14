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
    int indegree(int);
    int outdegree(int);
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

int Matrix::indegree(int x){
  int count = 0;
  for(int i=0;i<vertex;i++){
    if(matrix[i][x] == 1){
      count ++;
    }
  }
  return count;
}

int Matrix::outdegree(int x){
  int count = 0;
  for(int i=0;i<vertex;i++){
    if(matrix[x][i] == 1){
      count ++;
    }
  }
  return count;
}


int main() {
	int v;
	cout << "How many vertices does the graph have?: ";
	cin >> v;
	Matrix obj1(v);
	obj1.genMatrix();
	obj1.display();
  for(int i=0;i<v;i++){
    cout << "\nIndegree of " << i << " = " << obj1.indegree(i) << endl;
    cout << "Outdegree of " << i << " = " << obj1.outdegree(i) << endl;
  }
}

