#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
public:
    Person(){};
    virtual void getdata() = 0;
    virtual void putdata() = 0;
protected:
    string name;
    int age;
    
};

class Professor : public Person
{
public:
    Professor(){cur_id = Professor::nextid();}
    
    static int next_id;
    static int nextid(){
        next_id++;
        return next_id;
    }
    
    void getdata(){
        cin >> name >> age >> publications;
    };
    
    void putdata(){
        cout << name << " ";
        cout << age << " ";
        cout << publications << " ";
        cout << cur_id << endl;
    };
    
protected:
    int publications;
    int cur_id;
    
};
int Professor::next_id = 0;

class Student : public Person
{
public:
    Student(){cur_id = Student::nextid();}
    static int next_id;
    
    static int nextid(){
        next_id++;
        return next_id;
    }

    void getdata(){
        cin >> name >> age;
        cin >> marks[0] >> marks[1] >> marks[2] >>
        marks[3] >> marks[4] >> marks[5];
    };
    
    void putdata(){
        cout << name << " ";
        cout << age << " ";
        cout << sumMarks() << " ";
        cout << cur_id << endl;
        
    };
    
    int sumMarks(){
        int sum = 0;
        for (int i = 0; i < 6; i ++){
            sum += marks[i];
        }
        return sum;
    };
    
protected:
    int marks[6];
    int publications;
    int cur_id;
};
int Student::next_id = 0;

int main(){
    
    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];
    
    for(int i = 0;i < n;i++){
        
        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;
            
            
        }
        else per[i] = new Student; // Else the current object is of type Student
        
        per[i]->getdata(); // Get the data from the user.
        
    }
    
    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.
    
    return 0;
    
}
