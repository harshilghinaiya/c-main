#include <iostream>
using namespace std;

class Time
{
public:
    void convter(int ds)
	{
        int hh=ds/3600;
        int mm=(ds%3600)/60;
        int ss=ds%60;

        cout<<"HH:MM:SS => "<<hh
		    <<":"<<mm 
			<<":"<<ss<<endl;
    }

    void convter1(int hh, int mm, int ss) 
	{
        int ts=hh*3600+mm*60+ss;
        cout<<"Total seconds: "<<ts<<endl;
    }
};

int main() 
{
    Time z;
    int ds;
    cout<<"Enter total seconds: ";
    cin>>ds;
    z.convter(ds);
    
    int hh, mm, ss;
    cout<<"Enter Hour: ";
    cin>>hh;
    cout<<"Enter minutes: ";
    cin>>mm;
    cout<<"Enter second: ";
    cin>>ss;

    cout << "\nEnter hours: "<<hh<<endl;
    cout << "Enter minutes: "<<mm<<endl;
    cout << "Enter seconds: "<<ss<<endl;
    z.convter1(hh, mm, ss);

}


/*
Enter total seconds: 4200
HH:MM:SS => 1:10:0
Enter Hour: 4
Enter minutes: 34
Enter second: 30

Enter hours: 4
Enter minutes: 34
Enter seconds: 30
Total seconds: 16470
*/