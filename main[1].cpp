#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

class Person {
protected:
    char name[20];              //this variable captures an employees name
    int employee_number;        //this variable captures the employees number
public:
    friend class PaySlip;       //the PaySlip class has been friended so as to create an association relationship with the Person class
     void GetDetail(void) {      //function that captures data and keeps it during run time so that it can be accessed for displaying and editing
        cout << "\n\nEnter name :-";
        cin>>name;
        cout << "Enter code :-";
        cin>>employee_number;
    }

    void DisplayDetail(void) {   //function to display employee's information 
        cout << "\n\nNAME      :-" << name;
        cout << "\nCODE      :-" << employee_number;
    }
};

class PaySlip : virtual public Person {     //class amount inherits from the class person 
protected:
    float pay;                              //variable to hold the worker's monthly pay
public:
    friend class Master;                    //PaySlip class has befriended the Master class so that the Master class can access what it requires from the PaySlip class without inheriting everything
    void GetPay(void) {                             
        cout << "\nEnter Pay amount :-";
        cin>>pay;
    }

    void DisplayPay(void) {
        cout << "\nPAY       :-" << pay;
    }
};

class Admin : virtual public Person {       //the Admin class inherited all of person's attributes and functionality
protected:
    int experience;
public:
    friend class Master;
    void GetExperience(void) {
        cout << "\nEnter Experience in years :-";
        cin>>experience;
    }

    void DisplayExperience(void) {
        cout << "\nEXPERIENCE:-" << experience;
    }
};

class Master : public PaySlip, public Admin {           //Master class inherits all the classes' attributes and functionalities so that it can be able to instantiate objects
public:
    
    void Create(void) {
        cout << "\n\n=====GETDATA IN=====\n";
        Person::GetDetail();                            //this is a friend function that establishes the association relationship between the Master class and the Person class
        GetPay();
        Admin::GetExperience();
    }

    void Display(void) {
        cout << "\n\n=====DISPLAY DETAILS=====\n";
        Person::DisplayDetail();
        Display();
        Admin::DisplayExperience();
    }

    void Update(void) {
        cout << "\n\n=====UPDATE DETAILS=====\n";
        cout << "\nChoose detail you want to update\n";
        cout << "1)  NAME\n";
        cout << "2)  CODE\n";
        cout << "3)  PAY\n";
        cout << "4)  EXPERIENCE\n";
        cout << "Enter your choice:-";
        int choice;
        cin>>choice;
                switch (choice) {                      
            case 1: cout << "\n\nEnter name : -";
                cin>>name;
                break;
            case 2: cout << "\n\nEnter code :-";
                cin>>employee_number;
                break;
            case 3: cout << "\n\nEnter pay :-";
                cin>>pay;
                break;
            case 4: cout << "\n\nEnter Experience :-";
                cin>>experience;
                break;
            default: cout << "\n\nInvalid choice\n\n";
        }
    }
};

int main() {
    Master ob1;
    int choice;
    while (1) {
        cout << "\n=====MASTER DATABASE=====\n\n";
        cout << "\nChoose Operation you want to perform\n";
        cout << "1)  Create  Record\n";
        cout << "2)  Display Record\n";
        cout << "3)  Update  Record\n";
        cout << "4)  Exit\n";
        cout << "Enter your choice:-";
        cin>>choice;
        switch (choice) {                        //switch case which allows a user to select the function they want to carry out
            case 1: ob1.Create();
                break;
            case 2: ob1.Display();
                getch();
                break;
            case 3: ob1.Update();
                break;
            case 4: exit(1);
            default: cout << "\n\nInvalid Choice\nTry Again\n\n";
        }
    }
}