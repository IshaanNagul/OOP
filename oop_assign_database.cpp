#include<iostream>
#include<string>
using namespace std;

class student
{
    private:
    string name,DoB,blood_grp,addr,year_class,mob;
    int div;
    int *rollno;

    public:
    friend class faculty;
    student()
    {
        rollno = new int;
        *rollno = div = -1;
        name = blood_grp = DoB = addr = year_class = mob = "";
    }
    ~student()
    {
        delete rollno;
    }
    void add_data()
    {
        cout<<"\n Enter Student Information: ";
        cout<<"\n Enter Name: "<<endl;
        cin.ignore();
        getline(cin,name);
        cout<<"Enter Roll_no: ";
        cin>>*rollno;
        cout<<"Enter Year(SE/TE/BE): ";
        cin>>year_class;
        cout<<"Enter Division: ";
        cin>>div;
        cout<<"Enter DoB: ";
        cin>>DoB;
        cout<<"Enter Blood Group: ";
        cin>>blood_grp;
        cout<<"Enter Mobile Number: ";
        cin>>mob;
        cout<<"Enter Address: ";
        cin>>addr;
    }
    void display()
    {
        cout<<"\nName: "<<name;
        cout<<"\nRoll_no: "<<*rollno;
        cout<<"\nYear(SE/TE/BE): "<<year_class;
        cout<<"\nDiv: "<<div;
        cout<<"\nDoB: "<<DoB;
        cout<<"\nBlood Group: "<<blood_grp;
        cout<<"\nMobile Number: "<<mob;
        cout<<"\nAddress: "<<addr;    
    }
    static void header()
    {
        cout<<"\n***Student Information System***";      
    }    
};

class faculty
{
    private:
    int id;

    public:
    faculty()
    {
        id=000;
    }
    faculty(const faculty &f1)
    {
        id= f1.id;
    }
    void f_display(student &obj,int f_d)
    {
        try
        {
            if(obj.div==f_d)
            obj.display();
            else
            throw(obj.div);
        }
        catch(int x)
        {
            cout<<"\n Invalid...Error";
        }   
        
    }
};

int main()
{
    student st[5];
    faculty f;
    int ch=0,count=0;
    do
    {
        cout<<"\n***Student Information System***";
        cout<<"\n***Menu***";
        cout<<"\n 1.Add Information";
        cout<<"\n 2.Display Information";
        cout<<"\n 3.Faculty wise Information";
        cout<<"\n 4.Exit";
        cout<<"\n Enter Your Choice";
        cin>>ch;

        switch(ch)
        {
            case 1:
            st[count].add_data();
            count++;
            break;

            case 2:
            for(int j=0;j<count;j++)
            {
                student::header();
                st[j].display();
            }
            break;

            case 3:
            int f_div;
            cout<<"\n Enter Division Of Faculty: ";
            cin>>f_div;
            for(int j=0;j<count;j++)
            {
                cout<<"\n ***Student Inforrmation System***";
                f.f_display(st[j],f_div);    
            }
            break;

            case 4:
            exit(0);
        }

    }
    while(ch!=4);
    return 0;
        
};
  
         
