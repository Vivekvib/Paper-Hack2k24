#include <iostream>
using namespace std;

class Matrix{
	int size;
	int **matrix;
	bool rflag, sflag, asflag, tflag;
	public:
		Matrix(): size(1), rflag(false), sflag(false), asflag(false), tflag(false) {
			matrix = new int*[size];
			for(int i=0;i<size;i++){
				matrix[i] = new int[size];
			}
		}
		Matrix(int s): size(s), rflag(false), sflag(false), asflag(false), tflag(false) {
			matrix= new int*[size];
			for(int i=0;i<size;i++){
				matrix[i] = new int[size];
			}

		}
		void genMatrix();
		void displayMatrix();
		void is_Reflexive();
		void is_Symmetric();
		void is_AntiSymmetric();
		void is_Transitive();
		void relCheck();
};

void Matrix::genMatrix(){
	int i=0,element;
	while(i<size){
		cout << "What elements are related to " << i << "(-1 to terminate): " << endl;
		for(int j=0;j<size;j++){
			cin >> element;
			if(element != -1){
				matrix[i][element] = 1;
			}
			else{
				break;
			}
		}
		i++;
	}
}

void Matrix::displayMatrix(){
	cout << endl << "Given matrix:- " << endl;
	for(int x=0;x<size;x++){
		for(int y = 0;y<size;y++){
			cout << matrix[x][y] << " ";
		}
		cout << endl;
	}
}

void Matrix::is_Reflexive(){
	int i;
	bool flag=true;
	for(i=0;i<size;i++){
		if(matrix[i][i]==0){
			flag=false;
		}
	}
	cout << endl;
	if(flag == true){
		cout << "The given matrix is reflexive.";
		rflag = true;
	}
	else{
		cout << "The given matrix is not reflexive.";
	}
	cout << endl;
}

void Matrix::is_Symmetric(){
	int i,j;
	bool flag=true;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if(matrix[i][j] != matrix[j][i]){
				flag=false;
			}
		}
	}
	if(flag==true){
		cout << "The given matrix is symmetric.";
		sflag = true;
	}
	else{
		cout << "The given matrix is not symmetric.";
	}
	cout << endl;
}

void Matrix::is_AntiSymmetric(){
	int i, j;
	bool flag=true;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if(matrix[i][j] == 1 && matrix[j][i] == 1){
				if(i!=j){
					flag=false;
				}
			}
		}
	}
	if(flag==true){
		cout << "The given matrix is antisymmetric.";
		asflag = true;
	}
	else{
		cout << "The given matrix is not antisymmetric.";
	}
	cout << endl;

}

void Matrix::is_Transitive(){
	int a,b,c;
	bool flag=true;
	for(a=0;a<size;a++){
		for(b=0;b<size;b++){
			for(c=0;c<size;c++){
				if(matrix[a][b] == 1 && matrix[b][c] == 1 && matrix[a][c] != 1){
					flag = false;
				}
			}
		}
	}
	if(flag == true){
		cout << "The given matrix is transitive.";
		tflag = true;
	}
	else{
		cout << "The given matrix is not transitive.";
	}
	cout << endl;
}

void Matrix::relCheck(){
	if (rflag == true && sflag == true && tflag == true){
		cout << "Thus, the given relation is an Equivalence relation." << endl;
	}
	else if(rflag == true && asflag == true && tflag == true){
		cout << "Thus the given relation is a Partial Order relation." << endl;
	}
	else{
		cout << "Thus, the given relation is neither an Equivalence relation nor a Partial Order relation.";
	}
}

int main() { 
	Matrix obj(3);
	obj.genMatrix();
	obj.displayMatrix();
	obj.is_Reflexive();
	obj.is_Symmetric();
	obj.is_AntiSymmetric();
	obj.is_Transitive();
	obj.relCheck();
}
