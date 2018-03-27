#include <iostream>

using namespace std;

int main()
{
// FCI –Programming 1 –2018 -Assignment 2
// Program Name:ROT13Cipher .cpp
//Last Modification Date:26/02/2018
// Author1 and ID and Group:Abdulrahman Hussien Ali Elabied , 20170163 , G14
// Teaching Assistant:Eng.Desokii
// Purpose:..........
    int Choice;
    string Message,Chepher;
    string Ascii;
    cout<<"Ahlan ya user ya habibi."<<endl;
    cout<<"What do you like to do today?"<<endl;
    cout<<"1- Cipher a message"<<endl;
    cout<<"2- Decipher a message"<<endl;
    cout<<"3- End"<<endl;
    cout<<"Please enter your choice --> :";
    cin>>Choice;
    if(Choice == 1)
    {
        cout<<"Please enter your message you want to chipher:"<<endl;
        cin.clear();
        cin.ignore();
        getline(cin,Message);

        for(int i = 0; i < Message.length(); ++i )
        {
            int num=Message[i];

            if(num > 32 && num < 110)
            {
                num+=13;
                Chepher=char(num);
                cout<<Chepher;
            }
            else if(num >= 110)
            {
                num=(num+13)-26;
                Chepher=char(num);
                cout<<Chepher;
            }
            else if(num == 32)
            {
                num=num;
                Chepher=char(num);
                cout<<Chepher;


            }

        }
    }
    else if(Choice == 2)
    {
        cout<<"Please enter your message you want to dechipher:"<<endl;
        cin.clear();
        cin.ignore();
        getline(cin,Message);
        for(int i = 0; i < Message.length(); ++i )
        {
            int num=Message[i];

            if(num >= 110 && num < 123)
            {
                num-=13;
                Chepher=char(num);
                cout<<Chepher;
            }
            else if(num >= 97)
            {
                num=num+13;
                Chepher=char(num);
                cout<<Chepher;
            }
            else if(num == 32)
            {
                num=num;
                Chepher=char(num);
                cout<<Chepher;


            }

        }







    }

    return 0;
}

