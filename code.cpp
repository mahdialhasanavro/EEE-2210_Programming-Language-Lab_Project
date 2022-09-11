/*
Name: Mahdi Hasan
ID: 190105052
*/

#include<iostream>
using namespace std;
#include<iomanip>

class Bank
{
private:
    string name;
    string address;
    string branch;
    string accNo;
    double currentBlance;
    // This attributes consists of the information of the bank account holder

public:
    // constructor with all the attributes
    Bank(string name,string address,string branch,string accNo,double currentBlance)
    {
        this->name=name;
        this->address=address;
        this->branch=branch;
        this->accNo=accNo;
        this->currentBlance=currentBlance;
    }
    // empty constructor
    Bank()
    {

    }

    // All the setter and getter methods for the attributes
    string getName()
    {
        return this->name;
    }
    void setName(string name)
    {
        this->name = name;
    }

    string getAddress()
    {
        return this->address;
    }
    void setAddress(string address)
    {
        this->address = address;
    }

    string getBranch()
    {
        return this->branch;
    }
    void setBranch(string branch)
    {
        this->branch = branch;
    }

    string getAccNo()
    {
        return this->accNo;
    }
    void setAccNo(string accNo)
    {
        this->accNo = accNo;
    }

    double getCurrentBlance()
    {
        return this->currentBlance;
    }
    void setCurrentBlance(double currentBlance)
    {
        this->currentBlance = currentBlance;
    }

public :
    // display the current balance of the account
    void inquery()
    {
        cout<<"Your Current Balance : "<<currentBlance<<" Taka"<<endl;
    }
    // withdraw money from the account, then display the current balance
    void withdraw()
    {
        int withdraw;
        cout<<"\nBalance Amount : \t\t"<<currentBlance<<" Taka";
        cout<<"\nEnter Withdraw amount (Taka) : \t";
        cin>>withdraw;
        if(currentBlance>=withdraw)
        {
            currentBlance=currentBlance-withdraw;
            cout<<"\nAfter withdraw Balance : \t"<<currentBlance<<" Taka";
        }
        else
        {
            cout<<"\n\t Not Enough Balance";
        }
    }
    // deposit money to the account and then display the current balance
    void deposit()
    {
        int deposit=0;
        cout<<"Enter deposit Amount (Taka) : \t";
        cin>>deposit;
        currentBlance=deposit+currentBlance;
        inquery();

    }
    // subtract the payable bill from the account and then display the current balance
    void payBill()
    {
        double am;

        cout<<"Enter Amount (Taka) : ";
        cin>>am;
        cout<<"After paying balance will be "<<currentBlance-am<<" Taka"<<endl;
        cout<<"Type 1 To Confirm "<<endl;
        int temp;
        cin>>temp;
        if(temp==1)
        {
            currentBlance=currentBlance-am;
            inquery();
        }
        else
        {
            cout<<"Wrong Key Stroke!!please Try Later"<<endl;

        }
    }
};

// this class inheritance Bank Class
class ATMCard :public  Bank
{
private:
    string pin;

public:
    // Constructor with all the attributes to the current and base class
    ATMCard(string name,string address,string branch,string accNo,
            double currentBlance,string pin):Bank(name,address,branch,accNo,currentBlance)
    {

        this->pin=pin;
    }
    // getter and setter method for the attribute
    string getPin()
    {
        return this->pin;
    }
    void setPin(string pin)
    {
        this->pin = pin;
    }
};

class ATMbooth
{
public:
    // this constructor take argument of ATMCard type
    ATMbooth(ATMCard ob)
    {
        do
        {
            // Display the Menu Screen
            cout<<"\n\n\n\n ATM Main Menu Screen";
            cout<<"\n \n";
            cout<<"       Enter [1] To Balance Inquiry\n";
            cout<<"       Enter [2] To Withdraw Cash\n";
            cout<<"       Enter [3] To Deposit Cash\n";
            cout<<"       Enter [4] To Pay Bills\n";
            cout<<"       Enter [0] To Exit ATM";

            cout<<"\n\n PLEASE ENTER A SELECTION AND PRESS RETURN KEY:\n";
            int choice;
            cin>>choice;    // Select Menu

            switch(choice)      // calls the required function based on the given choice
            {
            case 1:
                ob.inquery();
                break;

            case 2:
                ob.withdraw();
                break;

            case 3:
                ob.deposit();
                break;

            case 4:
                ob.payBill();
                break;

            case 0:
                goto end;

            default:
                cout<<"\n Invalid option...";
            }

        }
        while(1);
end:
        return;
    }
};

int main()
{
    string acc;

    cout<<"Enter Account No : ";
    cin>>acc;

    // initializes two account
    ATMCard a1("Rahim","Dhaka","Mirpur","101",5000,"2345");
    ATMCard a2("Karim","Khulna","Fultola","102",7000,"4567");

    // checks if the given account number is valid
    if(a1.getAccNo()==acc)
    {
        string p;
        cout<<"Welcome Mr. " << a1.getName()<<"\nPlease Enter Your Pin : ";
        cin>>p;

        // checks if the pin number is correct and call for the ATMbooth
        if(p == a1.getPin())
        {
            ATMbooth a(a1);
        }
        else
        {
            cout<<"Pin Number Is Incorrect"<<endl;
        }
    }
    else if(a2.getAccNo()==acc)
    {
        string p;
        cout<<"Welcome Mr. " << a2.getName()<<"\nPlease Enter Your Pin : ";
        cin>>p;

        if(p==a2.getPin())
        {
            ATMbooth a(a2);
        }
        else
        {

            cout<<"Pin Number Is Incorrect"<<endl;
        }
    }
    else
    {
        cout<<"Account Number Is Incorrect"<<endl;
    }
    return 0;
}

