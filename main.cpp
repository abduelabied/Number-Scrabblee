#include <iostream>

using namespace std;

 void sortNumber (int& n1 , int& n2){
        if(n1 > n2)
            swap(n1,n2);
}
void sortNumber(int& n1 , int& n2 , int& n3){
    sortNumber(n1,n2);
    sortNumber(n1,n3);
    sortNumber(n2,n3);

}
void sortNumber(int& n1 , int& n2 , int& n3 , int& n4){
    sortNumber(n1,n2,n3);
    sortNumber(n2,n3,n4);
    sortNumber(n1,n2);



}


int main()
{
int x,y,z,a,c,q,w,e,r;
cout<<"Please Enter Your Two number you want to sort:"<<endl;
cin>>x>>y;
sortNumber(x,y);
cout<<"sort between two numbers is :"<<endl<<x<<endl<<y<<endl<<endl;
cin>>z>>a>>c;
sortNumber(z,a,c);
cout<<endl<<z<<endl<<a<<endl<<c<<endl<<endl;
cin>>q>>w>>e>>r;
sortNumber(q,w,e,r);

cout<<endl<<q<<endl<<w<<endl<<e<<endl<<r<<endl;



    return 0;
}
