
#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string roll_Num,name,father_Name,address,search;
    fstream file;
    public:
    void addStu();
    void viewStu();
    void searchStu();
}obj;

int main(){

    char choice;
    cout<<"---------------------------"<<endl;
    cout<<"1- Add Student Record"<<endl;
    cout<<"2- View All Student Record"<<endl;
    cout<<"3- Search Student Record"<<endl;
    cout<<"4- Exit"<<endl;
    cout<<"---------------------------"<<endl;
    cin>>choice;

    switch(choice){
        case '1':
            cin.ignore();
            obj.addStu();
        break;
        case '2':
            cin.ignore();
            obj.viewStu();
        break;
        case '3':
            cin.ignore();
            obj.searchStu();
        break;
        case '4':
            return 0;
        break;
        default:
            cout<<"Invalid Choice...!";
    }

}

void temp :: addStu(){
    
    cout<<"Enter Student Roll Number :: ";
    getline(cin,roll_Num);
    cout<<"Enter Student Name ::";
    getline(cin,name);
    cout<<"Enter Student Father Name ::";
    getline(cin,father_Name);
    cout<<"Enter Student Address ::";
    getline(cin,address);

    file.open("stuData.txt",ios :: out | ios :: app);
    file<<roll_Num<<"*";
    file<<name<<"*";
    file<<father_Name<<"*";
    file<<address<<endl;
    file.close();
}

void temp :: viewStu(){
    
    file.open("stuData.txt",ios :: in);
    getline(file,roll_Num,'*');
    getline(file,name,'*');
    getline(file,father_Name,'*');
    getline(file,address,'\n');
    while(!file.eof()){
        cout<<"\n";
        cout<<"Student Roll Number :: "<<roll_Num<<endl;
        cout<<"Student Name :: "<<name<<endl;
        cout<<"Student Father Name :: "<<father_Name<<endl;
        cout<<"Student Address :: "<<address<<endl;

        getline(file,roll_Num,'*');
        getline(file,name,'*');
        getline(file,father_Name,'*');
        getline(file,address,'\n');
    }
    file.close();
}

void temp :: searchStu(){

    cout<<"Enter Student Roll Number :: ";
    getline(cin,search);
    
    file.open("stuData.txt",ios :: in);
    getline(file,roll_Num,'*');
    getline(file,name,'*');
    getline(file,father_Name,'*');
    getline(file,address,'\n');
    while(!file.eof()){
        if(roll_Num == search){
            cout<<endl;
            cout<<"Student Roll Number :: "<<roll_Num<<endl;
            cout<<"Student Name :: "<<name<<endl;
            cout<<"Student Father Name :: "<<father_Name<<endl;
            cout<<"Student Address :: "<<address<<endl;       
        }
        getline(file,roll_Num,'*');
        getline(file,name,'*');
        getline(file,father_Name,'*');
        getline(file,address,'\n');
    }
    file.close();
}