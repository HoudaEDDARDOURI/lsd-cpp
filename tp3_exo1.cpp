#include <iostream>

using namespace std;


//we create the contact class 
class contact {
    // private by default 
    private : 
    string first_name;
    string last_name;
    string nickname;
    string phone_number;
    
    public : 
    contact();
    contact(string s1,string s2,string s3,string s4);
    void display(int i);
};

contact::contact()
{
    
}

// here's the constructor of the contact class to define the class members 
 contact::contact(std::string s1,std::string s2,std::string s3,std::string s4) : first_name{s1} , last_name{s2}, nickname{s3},phone_number{s4}
 {
 }
 
 /*contact::contact(string s1,string s2,string s3,string s4)
 {
    first_name = s1;
    last_name = s2;
    nickname = s3;
    phone_number = s4;
 }*/


//defining the phonebook class
class PhoneBook 
{
    contact* contacts{ new contact[8]{} };
    int index;
    public :
    PhoneBook();
    void ADD();
    void SEARCH();
    void EXIT();
};

PhoneBook::PhoneBook()
{
    index = 0;
}

void PhoneBook::ADD()
{
    string firstname, lastname,nickname,phonenumber;
    cout << "enter the first name, last name, nickname and phone number following the previous order : ";
    cin >> firstname >> lastname >> nickname >> phonenumber; 
    contact contact_created(firstname,lastname,nickname,phonenumber);
    //we check if the phonebook is satured. 
    //If it's the case we attribute to the index the value 0 
    //to start the filling of the phonebook all over again   
    if(index == 8)
    {
        index = 0; 
    }
    contacts[index] = contact_created;
    //we increment the index to move to the next position 
    index = index + 1;
}

void contact::display(int i)
{
    /*cout << "here's the list of the contacts of the phonebook : ";
    cout << "|          |          |          |          |";*/
        string spaces = "          ";
        string f1,f2,f3;
        //first_name
        if(first_name.length() <= 10)
        {
            string s1 = first_name + spaces;
            f1 = s1.substr(0,10);
        }
        else 
            f1 = first_name.substr(0,9) + ".";
        
        //last_name
        if(last_name.length() <= 10)
        {
            string s2 = last_name+ spaces;
            f2 = s2.substr(0,10);
        }
        else 
            f2 = last_name.substr(0,9) + ".";
        //nickname
        if(nickname.length() <= 10)
        {
            string s3 = nickname + spaces;
            f3 = s3.substr(0,10);
        }
        else 
            f3 = nickname.substr(0,9) + ".";
        
        //displaying 
        cout << "____________________________________________" <<endl;
        cout << "|          |          |          |          |"<<endl ;
        cout << "|" << i<< "         |" << f1 << "|" << f2<< "|" << f3 << "|" <<endl;
        cout << "|__________|__________|__________|__________|" <<endl;
        
}

void PhoneBook::SEARCH()
{
    cout << "here's the list of the contacts of the phonebook : "<<endl;
    cout << "____________________________________________" <<endl;
    cout << "|  index   |first name|last name | nickname |"<<endl ;
    for(int i = 0 ; i< index; i ++ )
    {
        contacts[i].display(i);
        cout << endl;
    }
    
    int j;
    cout << "enter the index of the contact you would like to display : ";
    cin >> j;
    while(j<0 or j>index-1)
    {
        cout << "the index of the contact you're asking to diplay is invalid !" << endl;
        cout<<"enter a valid index --> ";
        cin >> j; 
    }
    contacts[j].display(j);
       
    
}

void PhoneBook:: EXIT()
{
    cout << "the contacts are lost now!";
    delete [] contacts;
    index = 0;
}


int main()
{
   PhoneBook P;
   int option;
   string str ="yes";
   
   
   while(str!= "no")
   {
        cout<<"please select the number of the command you would like to execute on your phonebook : "<<endl;
        cout<<"1. add a new contact" <<endl<<"2. display a specific contact" << endl<<"3. exit"<<endl;
        cout << "your choice is -->  " ;
        cin >> option;
         switch(option)
        {
            case 1:
                P.ADD();
                break;
            case 2:
                P.SEARCH();
                break;
            case 3 :
                P.EXIT();
                break;
            default :
                cout << "this number doesn't refer to any of the commands shown above !";
        }  
        cout << "Do you want to execute another command ? answer with yes or no !";
        cin >> str;
   }

    return 0;
}
  