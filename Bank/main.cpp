#include <bits/stdc++.h>
using namespace std;


class Validation
{
    public:
        static bool name_is_valid(string name)
        {
          if(name.length()<5||name.length()>20)
          {
              return false;
          }

          for (char x: name)
          {
            if(!isalpha(x)&&x!=' ')
            {
                return false;
            }
          }
          return true;
        }

        static bool password_is_valid(string pass)
        {
            if(pass.length()<8||pass.length()>20)
            {
                return false;
            }

            bool has_capital = false;
            bool has_digit = false;
            for(char x: pass)
            {
                if(isupper(x))
                {
                    has_capital = true;
                }
                if(isdigit(x))
                {
                    has_digit = true;
                }
            }
            return has_capital && has_digit;
        }

        static bool balance_is_enough(double b)
        {
            if(b<1500)
            {
                return false;
            }
            return true;
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
    Person(string n,string pass,int id,double bal)
    {
        this->name = n;
        this->password = pass;
        this->id = id;
        this->balance = bal;
    }

    void set_name(string n)
    {
        this->name = n;
    }
    void set_password(string pass)
    {
        this->password = pass;
    }
    void set_id(int id)
    {
        this->id = id;
    }
    void set_balance(double bal)
    {
        this->balance = bal;
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
};

int main()
{

    cout<<"working";
}
