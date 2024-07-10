#include <iostream>
#include <string>
#include<cctype>
using namespace std;

class student
{
private:
    int rollNo;
    string name;
    int grade;
    string classIncharge;

public:
    student()
    {
        int rollNo = 0;
        string name;
        int grade = 0;
        string classIncharge;
    }
    student(int rollNo, string name, int grade, string classIncharge)
    {
        this->rollNo = rollNo;
        this->name = name;
        this->grade = grade;
        this->classIncharge = classIncharge;
    }

    int getrollNo()
    {
        return this->rollNo;
    }

    void setrollNo(int rollNo)
    {
        this->rollNo = rollNo;
    }

    string getname()
    {
        return this->name;
    }

    void setname(string name)
    {
        this->name = name;
    }

    int getgrade()
    {
        return this->grade;
    }

    void setgrade(int grade)
    {
        this->grade = grade;
    }

    string getclassIcharge()
    {
        return this->classIncharge;
    }

    void setclassIcharge(string classIncharge)
    {
        this->classIncharge = classIncharge;
    }
    void printdetails()
    {
        cout << "Roll Number:" << rollNo << endl;
        cout << "Name:" << name << endl;
        cout << "Grade:" << grade << endl;
        cout << "Class Incharge:" << classIncharge << endl;
    }
    

};
void printMenu(){
    
    cout << "A. Add record\n"; 
    cout << "B. Delete record\n";
    cout << "C. Find by name\n";
    cout << "D. Find by roll no\n";
    cout << "E. Update record\n";
    cout << "F. Show data\n";
    cout << "G. Quit\n";
    cout << "Choose an option:-";
    }
    bool isValidName(const string &name)
    {
        for (char c : name) 
        {
        if (!isalpha(c) && c != ' ')
          {
            return false;
          }
        }
    return true;
    }
    bool isValidClassIncharge(const string &classIncharge)
    {
        for(char c : classIncharge )
        {
            if (!isalpha(c) && c != ' ')
            {
                return false;
            }
        }
        return true;
    }
int main()
{
    char option = 0;
    const int max_students = 100;
    student students[max_students];
    int total=0;
    
    printMenu();
    cin>>option;
    while(option!='G')
    {
    switch (option)
    {

    case 'A':{



        int rollNo;
        string name;
        int grade;
        string classIncharge;
        int ch = 0;

        cout << "How many students do u want to enter??" << endl;
        cin >> ch;
        cin.ignore();
        
        for(int i = total; i < total +ch ; i++){

            cout<<"\n Enter data of student "<<i+1<<endl;

            cout<<"Enter roll no of student:"<<endl;
            while(!(cin >> rollNo)){
                cout << " Invalid input. Please enter an integer value for rollNo: ";
                cin.clear();
                cin.ignore();
            } 
            cin.ignore();
            
            cout << "Enter name of student: " << endl;
                getline(cin, name);

                while (!isValidName(name))
                {
                    cout << "Invalid input. Please enter an alphabetical value for student name: " << endl;
                    getline(cin, name);
                }

           
            cout << "Enter grade of student: " << endl;
                while (!(cin >> grade)) {
                    cout << "Invalid input. Please enter an integer value for grade: ";
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                cin.ignore(); 


            cout<<"Enter name of class incharge:"<<endl;
            getline(cin,classIncharge);

            while (!isValidClassIncharge(classIncharge))
            {
                cout << "Invalid input. Please enter an alphabetical value for name of class incharge:";
                getline(cin,classIncharge);
            }

            students[i]=student(rollNo,name,grade,classIncharge);
            cout<<"DATA OF RECORD ADDED"<<endl;
            students[i].printdetails();
        
        }

        total=total+ch;
    }
        break;

    case 'B':{
        int rollNo;
        cout << "Enter roll no of student to be deleted:";
        cin >> rollNo;
        bool found = false;
        for (int i = 0; i < total; i++)
        {
            if (students[i].getrollNo() == rollNo)
            {
                found = true; 
                for (int j = i; j < total - 1; j++)
                    students[i] = students[j + 1];
            }
            total--;
            cout << "Record deleted successfully!!" << endl;
            
        }

        if(!found){
            cout<<"Record not found."<<endl;
        }
    }
        break;

    case 'C':{
        string name;
        cout << "Enter name of student to find:";
        cin.ignore();
        getline(cin, name);
        bool found = false;
        for (int i = 0; i < total; i++)
        {
            if (students[i].getname() == name)
            {
                students[i].printdetails();
                found = true;
            }
        }
        if(!found){
            cout << "Record not found." << endl;
        }
    }
        break;
        case 'D':{
            int rollNo;
            cout << "Enter roll no of student to find:";
            cin >> rollNo;
            bool found = false;
            for(int i = 0; i < total; i++)
            {
                if(students[i].getrollNo() == rollNo )
                {
                    students[i].printdetails();
                    found = true;
                }
            }
            if(!found){
            cout << "Record not found." << endl;
            }
        }
        break;
        case 'E':{
            int rollNO; 
            cout << "Enter roll no of student to update:";
            cin >> rollNO;
            bool found = false;
            for(int i = 0; i < total; i++)
            {
                if(students[i].getrollNo() == rollNO) 
                {
                    found = true;
                    string name;
                    int grade;
                    string classIncharge; 

                    cout << "Enter new name:";
                    cin.ignore();
                    getline(cin,name);
                    cout << "Enter new grade:";
                    cin >> grade;
                    cout << " Enter new class incharge:";
                    cin.ignore();
                    getline(cin,classIncharge);

                    students[i].setname(name);
                    students[i].setgrade(grade);
                    students[i].setclassIcharge(classIncharge);

                    cout << "Record updated successfully\n.";
                }
            }
            if(!found)
            {
                cout << "Record not found." << endl;
            }
        }
        break;
        case 'F':{
            int rollNo;
            string name;
            int grade;
            string classIncharge;
           
            for(int i=0; i<total; i++)
            {
               
                cout << "Saved Data of Students "<<i+1<<endl;
                students[i].printdetails();
                
            }
        }
        break;
        case 'G':{
            cout << "Exiting the program." << endl;
        }
        break;
    default:{
        cout << "Enter the valid option\n";
    }
        break;
    }
    printMenu();
    cin>>option;
    }
    
return 0;
}
