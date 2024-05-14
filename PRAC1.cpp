#include<iostream>
using namespace std;
int Num[10]={0};
bool Is_member(){
    int term;
    cout<<"Enter the term u want to check : ";
    cin>>term;
    while (term>=10 || term<=0){
        cout<<"You entetred a wrong term!!!!!!!!!!!\nEnter the term in between (0-9) u want to check : ";
        cin>>term;
    }
    if (Num[term]==1){
        return true;
    }
    else{
        return false;
    }
}


void Complement(){
    for (int i=0;i<10;i++){
        if (Num[i]==0){
            Num[i]=1;
        }
        else{
            Num[i]=0;
        }
    }
    cout<<"The Complement of the orginal set is : ";
    for (int j=0;j<10;j++){
        cout<<Num[j];
    }
}

void Uni(){
    cout<<"We have a original set and now we need a new set with which we will do the union : ";
    int Sam[10]={0};
    
    cout<<"Enter your numbers in the array and if want to stop enter -1 \n";
    int t;
    for (int i=1;i<=10;i++){
        cout<<"Enter you desired value : ";
        cin>>t;
        while (t>9 || t<-1){
            cout<<"You entered a wrong value !!!!!!!!\nEnter value in between -1 to 9 : ";
            cin>>t;
        }
        if (t!=-1){
            Sam[t]=1;
        }
        else{
            break;
        }
    }
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    cout<<"Your set in bit stream is : ";
    for (int j=0;j<10;j++){
        cout<<Sam[j];
    }
    cout<<endl;

    int un[10]={0};
    cout<<"The Union of these set is : ";
    for (int i=0;i<10;i++){
        if (Num[i]==1 || Sam[i]==1){
            un[i]=1;
        }
        else{
            un[i]=0;
        }
    }
    for (int j=0;j<10,j++){
        cout<<un[j];
    }
}

void inter(){
    cout<<"We have a original set and now we need a new set with which we will do the Intersection : ";
    int Sam[10]={0};
    
    cout<<"Enter your numbers in the array and if want to stop enter -1 \n";
    int t;
    for (int i=1;i<=10;i++){
        cout<<"Enter you desired value : ";
        cin>>t;
        while (t>9 || t<-1){
            cout<<"You entered a wrong value !!!!!!!!\nEnter value in between -1 to 9 : ";
            cin>>t;
        }
        if (t!=-1){
            Sam[t]=1;
        }
        else{
            break;
        }
    }
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    cout<<"Your set in bit stream is : ";
    for (int j=0;j<10;j++){
        cout<<Sam[j];
    }
    cout<<endl;

    int un[10]={0};
    cout<<"The Intersection of these set is : ";
    for (int i=0;i<10;i++){
        if (Num[i]==1 && Sam[i]==1){
            un[i]=1;
        }
        else{
            un[i]=0;
        }
    }
    for (int j=0;j<10,j++){
        cout<<un[j];
    }
}    

bool subset(){
    cout<<"We have a original set and now we need a new set with which we will check for subset : ";
    int Sam[10]={0};
    
    cout<<"Enter your numbers in the array and if want to stop enter -1 \n";
    int t;
    for (int i=1;i<=10;i++){
        cout<<"Enter you desired value : ";
        cin>>t;
        while (t>9 || t<-1){
            cout<<"You entered a wrong value !!!!!!!!\nEnter value in between -1 to 9 : ";
            cin>>t;
        }
        if (t!=-1){
            Sam[t]=1;
        }
        else{
            break;
        }
    }
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    cout<<"Your set in bit stream is : ";
    for (int j=0;j<10;j++){
        cout<<Sam[j];
    }
    cout<<endl;

    for (int k=0;k<Sam.size();k++){
        if (Sam[k] not in Num){
            return false;
        }
    }
    return true;
}

void set_diff(){
    cout<<"We have a original set and now we need a new set with which we will do set difference : ";
    int Sam[10]={0};    
    cout<<"Enter your numbers in the array and if want to stop enter -1 \n";
    int t;
    for (int i=1;i<=10;i++){
        cout<<"Enter you desired value : ";
        cin>>t;
        while (t>9 || t<-1){
            cout<<"You entered a wrong value !!!!!!!!\nEnter value in between -1 to 9 : ";
            cin>>t;
        }
        if (t!=-1){
            Sam[t]=1;
        }
        else{
            break;
        }
    }
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    cout<<"Your set in bit stream is : ";
    for (int j=0;j<10;j++){
        cout<<Sam[j];
    }
    cout<<endl;


    int SD[10]={0};
    for (int k=0;k<10,k++){
        if (Num[k]==1 && Num[k] not in Sam){
            SD[k]=1;
        }
    }
    cout<<"The Set difference of Universal set - Given set is : ";
    for (int l=0;l<10;l++){
        cout<<SD[l];
    }
}

void sym_diff(){
    cout<<"We have a original set and now we need a new set with which we will do symmetric difference : ";
    int Sam[10]={0};
    cout<<"Enter your numbers in the array and if want to stop enter -1 \n";
    int t;
    for (int i=1;i<=10;i++){
        cout<<"Enter you desired value : ";
        cin>>t;
        while (t>9 || t<-1){
            cout<<"You entered a wrong value !!!!!!!!\nEnter value in between -1 to 9 : ";
            cin>>t;
        }
        if (t!=-1){
            Sam[t]=1;
        }
        else{
            break;
        }
    }
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    cout<<"Your set in bit stream is : ";
    for (int j=0;j<10;j++){
        cout<<Sam[j];
    }
    cout<<endl;

    int SYD[10]={0};
    for (int h=0;h<10;h++){
        if((Num[h]==1&& not(Num[h]==1&&Sam[h]==1))&&(Sam[h]==1&& not(Num[h]==1&&Sam[h]==1))){
            SYD[10]=1;
        }
    }
}

int main(){
    cout<<"Welcome to the code lets begin the work \nThe code have a Uinversal set of u={0-9}\nLets first create a Set of your choice\n";
    cout<<"#############################################\n";
    cout<<"Enter your numbers in the array and if want to stop enter -1 \n";
    int t;
    for (int i=1;i<=10;i++){
        cout<<"Enter you desired value : ";
        cin>>t;
        while (t>9 || t<-1){
            cout<<"You entered a wrong value !!!!!!!!\nEnter value in between -1 to 9 : ";
            cin>>t;
        }
        if (t!=-1){
            Num[t]=1;
        }
        else{
            break;
        }
    }
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    cout<<"Your set in bit stream is : ";
    for (int j=0;j<10;j++){
        cout<<Num[j];
    }
    cout<<endl;
    int ch;
    cout<<"You can do the following functions:\n1. Ismember()\n2. Powerset()\n3. Complement Enter yout choice : ";
    cin>> ch;
    if ( ch== 1){
        bool res=Is_member();
        if (res==1){
            cout<<"The desired term is present in array";
        }
        else{
            cout<<"The desired term is not present in array";
        }
    }
    else if (ch==2){
        bool res=subset();
        if (res==true){
            cout<<"Yes the given set is a subset of other set!!!";
        }
        else{
            cout<<"No the given set is not a subset of other set!!!"
        }
    }

    else if (ch==3){
        Complement();
    }
    else if (ch==4){
        uni();
    }
    else if (ch==5){
        inter();
    }
    else if (ch==5){
        set_diff();
    }
    else if (ch==7){
        sym_diff();
    }
    else if (ch==8){

    }
    return 0;
    }
