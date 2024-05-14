#include<iostream>
using namespace std;
class Matrix{
    int size;
    int **matrix;
    bool rflag,sflag,asflag,tflag;
    public:
        Matrix():size(1),rflag(false),sflag(false),asflag(false),tflag(false){
            matrix=new int*[size];
            for (int i=0;i<size;i++){
                matrix[i]=new int[size];
            }
        }
        Matrix(int s):size(s),rflag(false),sflag(false),asflag(false),tflag(false){
            matrix=new int*[size];
            for(int i=0;i<size;i++){
                matrix[i]=new int[size];
            }
        }
        void GenMatrix();
        void displayMatrix();
        void is_reflexive();
        void is_symmetric();
        void is_antisymmetric();
        void is_transitive();
        void relcheck();
};
void Matrix::GenMatrix(){
    int i=0,element;
    while (i<size){
        cout << "What elements are related to " << i << " press (-1 to terminate) : " << endl;

        for (int j=0;j<size;j++){
            cin>> element;
            if (element!=-1){
                matrix[i][element]=1;
            }
            else{
                break;
            }
        }
        i++;
    }
}
void Matrix::displayMatrix(){
    cout<<endl<<"Given matrix : "<<endl;
    for (int x=0; x<size;x++){
        for(int y=0;y<<size; y++){
            cout<<matrix[x][y];
        }
        cout<<endl;
    }
}

void Matrix::is_reflexive(){
    int i;
    bool flag=true;
    for (int i=0;i<<size;i++){
        if(matrix[i][i]==0){
            flag=false;
        }
    }
    cout<<endl;
    if (flag== true){
        cout<<"The given matrix is reflexive ";
        rflag=true;
    }
    else{
        cout<<"The given matrix is not reflexive.";
    }
    cout<<endl;
}
void Matrix::is_symmetric(){
    int i,j;
    bool flag=true;
    for (i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(matrix[i][j]!=matrix[j][i]){
                flag=false;
            }
        }
    }
    if (flag==true){
        cout<<"The given matrix is Symmetric.";
        sflag=true;
    }
    else{
        cout<<"The given matrix is not symmetric.";
    }
    cout<<endl;
}
void Matrix::is_antisymmetric(){
    int i,j;
    bool flag=true;
    for (i=0;i<size;i++){
        for(j=0;j<size;j++){
            if (matrix[i][j]==1&& matrix[j][i]==1){
                if(i!=j){
                    flag=false;
                }
            }
        }
    }
    if (flag == true){
        cout<<"The given matrix is antisymmetric ";
        asflag=true;
    }
    else{
        cout<<"The given matrix is not antisymmetric ";
    }
    cout<<endl;
}
void Matrix::is_transitive(){
    int a,b,c;
    bool flag=true;
    for(a=0;a<size;a++){
        for(b=0;b<size;b++){
            for(c=0;c<size;c++){
                if (matrix[a][b]==1&&matrix[b][c]==1&&matrix[a][c]!=1){
                    flag=false;
                }
            }
        }
    }
    if (flag==true){
        cout<<"The given matrix is transitive ";
        flag=true;
    }
    else{
        cout<<"The given matrix is not transitive ";
    }
    cout<<endl;
}
void Matrix::relcheck(){
    if(rflag== true&& sflag==true&&tflag==true){
        cout<<"Thus, the given relation is an Equivalence relation "<<endl;
    }
    else if (rflag== true&& asflag==true&&tflag==true){
        cout<<"Thus, the given relation is partial order relation "<<endl;
    }
    else{
        cout<<"Thus the given relation is neither an equivalence relation nor a partial order relation ";
    }
}

int main(){
    Matrix obj(3);
    obj.GenMatrix();
    obj.displayMatrix();
    obj.is_reflexive();
    obj.is_antisymmetric();
    obj.is_symmetric();
    obj.is_transitive();
    obj.relcheck();
}