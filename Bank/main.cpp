#include <bits/stdc++.h>
using namespace std;

class Validation
{
public:
    static bool name_is_valid(string name)
    {
        if (name.length() < 5 || name.length() > 20)
        {
            return false;
        }

        for (char x : name)
        {
            if (!isalpha(x) && x != ' ')
            {
                return false;
            }
        }
        return true;
    }

    static bool password_is_valid(string pass)
    {
        if (pass.length() < 8 || pass.length() > 20)
        {
            return false;
        }

        bool has_capital = false;
        bool has_digit = false;
        for (char x : pass)
        {
            if (isupper(x))
            {
                has_capital = true;
            }
            if (isdigit(x))
            {
                has_digit = true;
            }
        }
        return has_capital && has_digit;
    }

    static bool balace_is_min(double b)
    {
        return b >= 1500;
    }
    static bool salary_is_min(double s)
    {
        return s >= 5000;
    }
};

class Person
{
protected:
    string name;
    string password;
    int id;
    double balance;

public:
    Person()
    {
        this->name = "unknow";
        this->password = "wasn't added";
        this->id = 0;
        this->balance = 0;
    }
    Person(string name, string password, int id, double balance)
    {
        this->name = name;
        this->password = password;
        this->id = id;
        this->balance = balance;
    }

    void set_name(string n)
    {
        if (Validation::name_is_valid(n))
        {
            this->name = n;
        }
        else
        {
            cout << "the name is invalid" << endl;
        }
    }
    void set_password(string pass)
    {
        if (Validation::password_is_valid(pass))
        {
            this->password = pass;
        }
        else
        {
            cout << "the password is invalid" << endl;
        }
    }
    void set_id(int id)
    {
        this->id = id;
    }
    void set_balance(double bal)
    {
        if (Validation::balace_is_min(bal))
        {
            this->balance = bal;
        }
        else
        {
            cout << "the balance is invalid " << endl;
        }
    }

    string get_name()
    {
        return name;
    }
    string get_password()
    {
        return password;
    }
    int get_id()
    {
        return id;
    }
    double get_balance()
    {
        return balance;
    }

    void display_info()
    {
        cout << "the name is: " << name << endl;
        cout << "the password is: " << password << endl;
        cout << "the id is: " << id << endl;
        cout << "the balance is: " << balance << endl;
    }
};

class Client : public Person
{
public:
    Client()
    {
    }
    Client(string name, string password, int id, double balance) : Person(name, password, id, balance)
    {
    }
    void withdraw(double amount)
    {
        if (balance < amount)
        {
            cout << "you can not withdraw" << endl;
        }
        balance -= amount;
    }
    void deposit(double amount)
    {
        balance += amount;
    }
    void check_balance()
    {
        cout << "your balance is: " << balance << endl;
    }
    bool transfer_to(double amount, Client &c2)
    {
        if (balance < amount)
        {

            cout << "you can not transfer this amount" << endl;
            return false;
        }
        if (this == &c2)
        {
            cout << "enter another account to transfer to" << endl;
            return false;
        }
        if (amount <= 0)
        {
            cout << "enter another amount to transfer" << endl;
            return false;
        }
        withdraw(amount);
        c2.deposit(amount);
        return true;
    }
};

class Employee : public Person
{
protected:
    double salary;

public:
    Employee()
    {
    }
    Employee(string name, string password, int id, double balance, double salary) : Person(name, password, id, balance)
    {
        this->salary = salary;
    }
    void set_salary(double salary)
    {
        if (Validation::salary_is_min(salary))
        {
            this->salary = salary;
        }
        else
        {
            cout << "the salay is invalid" << endl;
        }
    }

    double get_salary()
    {
        return this->salary;
    }

    void display_info()
    {
        Person::display_info();
        cout << "the salary is: " << this->salary << endl;
    }
};

class Admin : public Employee
{
public:
    Admin()
    {
    }
    Admin(string name, string password, int id, double balance, double salary) : Employee(name, password, id, balance, salary)
    {
    }
};

int main()
{

    cout<<"working";
}
