#include <iostream>
#include <fstream>
#include <sstream>
#include<string>

using namespace std;

int main(){
    int a,i=0;
    string text,old,password1,password2,password0,pass,name,password,age,user,word,word1;
    string creds[2],cp[2];


    cout<<"        security system       "<<endl<<endl;
    cout<<" _______________________________ "<<endl;
    cout<<" |         1.Register           |  "<<endl;
    cout<<" |         2.Log-in             |  "<<endl;
    cout<<" |         3.Change password    |  "<<endl;
    cout<<" |_________4.End session________|  "<<endl;

    do{
       cout<<endl<<endl;
       cout<<"enter your choice"<<endl;
       cin>>a;
       switch(a)
       {
           case 1:{
               cout<<"___________________"<<endl<<endl;
               cout<<"|------------------|"<<endl;
               cout<<"|___________________|"<<endl<<endl;
               cout<<"enter your name"<<endl;
               cin>>name;
               cout<<"enter your password"<<endl;
               cin>>password0;
               cout<<"enter your age"<<endl;
               cin>>age;

             ofstream of1;
             of1.open("file.txt");
                if(of1.is_open()){
                    of1<<name<<"\n";
                    of1<<password0;
                    cout<<"Registration successful!"<<endl;
                }



             break;
           }
           case 2:{
               i=0;
               cout<<"_______________________________"<<endl<<endl;
               cout<<"|----------Login-----------------|"<<endl;
               cout<<"__________________________________"<<endl<<endl;

                ifstream of2;
                of2.open("file.txt");
                cout<<"please enter a user-name:-";
                cin>>user;
                cout<<"please enter your password:-";
                cin>>pass;

                if(of2.is_open())
                {
                  while(!of2.eof())
                  {
                      while(getline(of2,text)){
                        istringstream iss(text);
                        iss>>word;
                        creds[i]=word;
                        i++;
                      }
                      if(user==creds[0] && pass==creds[1])
                      {
                          cout<<"-----log In successful-----";
                          cout<<endl<<endl;

                          cout<<"details: "<<endl;
                          cout<<"User-name: " + name<<endl;
                          cout<<"password: " + pass<<endl;
                          cout<<"age: " + age<<endl;

                      }
                      else{
                        cout<<endl<<endl;
                        cout<<"Incorrect Credentials: "<<endl;
                        cout<<"|     1. Press 2 to Log In          | "<<endl;
                        cout<<"|     2. Press 3 to Change Password | "<<endl;
                        break;
                      }
                  }
                }

           break;
           }
           case 3:{
               i=0;
               cout<<"-----------Change Password---------"<<endl;


               ifstream of0;
               of0.open("file.txt");
               cout<<"enter the old password:"<<endl;
               cin>>old;
               if(of0.is_open())
               {
                   while(of0.eof())
                   {
                       while(getline(of0,text)){
                        istringstream iss(text);
                        iss>>word1;
                        cp[i]=word1;
                        i++;
                       }
                       if(old==cp[1])
                       {
                           of0.close();
                           ofstream of1;
                           if(of1.is_open())
                           {
                               cout<<"enter your new password: "<<endl;
                               cin>>password1;
                               cout<<"enter your new password again: "<<endl;
                               cin>>password2;

                               if(password1==password2)
                               {
                                   of1<<cp[0]<<"\n";
                                   of1<<password1;
                                   cout<<"password changed successfully: "<<endl;
                               }
                               else{
                                of1<<cp[0]<<"\n";
                                of1<<old;
                                cout<<"password do not match: "<<endl;
                               }
                           }
                       }
                       else{
                         cout<<"please enter a valid password: "<<endl;
                         break;
                       }
                   }
               }


               break;
           }
           case 4:
            {

                cout<<"__________Thankyou!_________"<<endl;
                break;
            }
           default:
            cout<<"enter a valid choice";
       }
    }
    while(a!=4);
    return 0;
}







