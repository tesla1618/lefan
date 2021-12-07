#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <locale.h>
#include <bits/stdc++.h>
#include<unistd.h>
using namespace std;

class Functions
{
public:
    string up,pwd,mail;
    int ay;

    void main1()
    {
        int opts;
        cout<<"\n\n\t\t\t\t=============\n\t\t\t\t    \e[1mLEFAN\e[0m\n\t\t\t\t=============\n\n";
        cout<<"\n\tHey \033[32mAnon\033[0m, Welcome to Linear Equations and Function Analysis!\n\tA coordinate geometry Calculator and Function Analyzer.\n\n";
        cout<<"\t   \033[36m[1] Sign in\n\t   [2] Sign up\n\t   [3] Forgot Password?\n\t   [4] Continue as \033[32mAnon\033[36m (calculation history will not be saved)\n\t   [5] Docs\033[0m\n\n";
        cout<<"\tEnter the \e[1mnumber \e[0mbefore the options to operate the program: ";
        cin>>opts;

        if (opts == 1)
        {
            ay=0;
            system("clear");
            in();
        }

        if (opts == 2)
        {
            system("clear");
            reg();
        }
        if (opts == 3)
        {
            system("clear");
            lpass();
        }
        if (opts == 4)
        {
            ay=1;
            system("clear");
            anonmenu();

        }


    }

    void reg()
    {
        string uname, pword,email;
        cout<<endl<<"\033[34m\t\e[1mNew User Registration\033[0m\e[0m"<<endl<<endl;
        cout<<"\t | Username: ";
        cin>>uname;
        cout<<"\t | Password: ";
        cin>>pword;
        cout<<"\t | Email(optional for resetting password): ";
        cin>>email;
        ofstream file;
        file.open("Users/"+uname+".txt");
        file << uname <<endl << pword<<endl <<email;
        file.close();
        //up = uname;
        cout<<endl<<endl;
        this_thread::sleep_for(chrono::milliseconds(600));
        cout<<"\t\033[32mAccount Created! Signing in...\033[0m"<<endl;
        this_thread::sleep_for(chrono::milliseconds(800));
        cout<<endl;
        system("clear");
        umenu();
    }

    void cname () {

    string uname,chname, np, u, p,email,e;
    np = pwd; email = mail;uname=up;
        cout<<endl<<"\033[31m\t\e[1mChange Username:\033[0m\e[0m"<<endl<<endl;
        cout<<"\tEnter your Desired Username to search for account and then reset it"<<endl;
        cout<<"\t | Username: "; cin>>chname;
        ifstream read("Users/"+chname+".txt");
        getline(read, u);
        cout<<endl;
        this_thread::sleep_for(chrono::milliseconds(600));
        cout<<endl<<"\t\033[0mPlease wait while checking if "<<uname<<" exits...\033[0m"<<endl;
        if (u == chname) {
            cout<<endl<<"\033[31m\tUser already exists!!\033[0m"<<endl<<"\tUsername could not be changed."<<endl<<endl;
                this_thread::sleep_for(chrono::milliseconds(1020));
            system("clear");
            cname();

            }
            else{
            cout<<endl<<"\033[32m\tUsername Changed!!\033[0m"<<endl;
            up = chname;
                ofstream file;
                filesystem::remove("Users/"+uname+".txt");
                file.open("Users/"+chname+".txt");
                file << chname <<endl << np<<endl <<email;
                file.close();
                this_thread::sleep_for(chrono::milliseconds(1000));
                system("clear");
                umenu();


            }
        }


    void cpass(){
        string uname, np, u, p,email,e;
        cout<<endl<<"\033[31m\t\e[1mChange Password\033[0m\e[0m"<<endl<<endl;
        uname = up;
        ifstream read("Users/"+uname+".txt");
        getline(read, u);
        getline(read,p);
        getline(read,e);
            cout<<endl<<"\tHello,"<<uname<<endl<<"\tEnter email provided while signing up: "; cin>>email;
            cout<<endl<<"\t\033[0mPlease wait while your email is being verified...\033[0m"<<endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            if (e == email){
                ofstream file;
                cout<<endl<<"\033[32m\tEmail Matched!\033[0m"<<endl;
                cout<<"\t | New Password: "; cin>>np;
                file.open("Users/"+uname+".txt");
                file << uname <<endl << np<<endl <<email;
                file.close();
                cout<<endl<<"\033[32m\tPassword Change done, Redirecting to Menu Page...\033[0m"<<endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
                system("clear");
                umenu();

            }
            else{
                cout<<endl<<"\033[31m\tInvalid Email!!\033[0m"<<endl<<"\tPassword could not be Changed."<<endl<<endl;
                this_thread::sleep_for(chrono::milliseconds(1020));
            system("clear");
            main1();
            }
    }


    void lpass(){
        string uname, np, u, p,email,e;
        cout<<endl<<"\033[31m\t\e[1mPassword Reset:\033[0m\e[0m"<<endl<<endl;
        cout<<"\tEnter your Username to search for account and then reset it"<<endl;
        cout<<"\t | Username:"; cin>>uname;
        ifstream read("Users/"+uname+".txt");
        getline(read, u);
        getline(read,p);
        getline(read,e);
        cout<<endl;
        this_thread::sleep_for(chrono::milliseconds(600));
        cout<<endl<<"\t\033[0mPlease wait while your account is being found...\033[0m"<<endl;
        if (u == uname) {
            cout<<endl<<"\033[32m\tAccound Found!\033[0m"<<endl;
            cout<<endl<<"\tHello,"<<uname<<endl<<"\tEnter email provided while signing up: "; cin>>email;
            cout<<endl<<"\t\033[0mPlease wait while your email is being verified...\033[0m"<<endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            if (e == email){
                ofstream file;
                cout<<endl<<"\033[32m\tEmail Matched!\033[0m"<<endl;
                cout<<"\t | New Password: "; cin>>np;
                file.open("Users/"+uname+".txt");
                file << uname <<endl << np<<endl <<email;
                file.close();
                cout<<endl<<"\033[32m\tPassword reset done, Redirecting to Login Page...\033[0m"<<endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
                system("clear");
                in();

            }
            else{
                cout<<endl<<"\033[31m\tInvalid Email!!\033[0m"<<endl<<"\tPassword could not be resetted."<<endl<<endl;
                this_thread::sleep_for(chrono::milliseconds(1020));
            system("clear");
            main1();
            }
        }
        else {
            cout<<endl<<"\033[31m\tInvalid Username!!\033[0m"<<endl<<"\tPassword could not be resetted."<<endl<<endl;
            this_thread::sleep_for(chrono::milliseconds(1020));
            system("clear");
            main1();
        }
    }
    void in()
    {
        int opr;
        ofstream file;
        ofstream hfile;
        string uname, pword, u, p,e;
        cout<<endl<<"\033[32m\t\e[1mExisting User Login\033[0m\e[0m"<<endl<<endl;
        cout<<"\t | Username: ";
        cin>>uname;
        cout<<"\t | Password: ";
        cin>>pword;
        ifstream read("Users/"+uname+".txt");
        getline(read, u);
        getline(read, p);
        getline(read, e);

        if (u == uname && p == pword)
        {
            ifstream read("Users/"+uname+".txt");
            getline(read, u);
            up = u;
            pwd = pword;
            mail = e;
            file.open("History/"+uname+".txt");
            file << uname<<" Logged In"<<endl;
            file.close();
            hfile.open("History/"+uname+"_calculations.txt");
            hfile <<"[IN] "<<uname<<" Logged In"<<endl;
            hfile.close();
            system("clear");
            umenu();
        }
        else {
                cout<<endl;
            this_thread::sleep_for(chrono::milliseconds(600));
        cout<<"\t\033[31mIncorrect Information\033[0m"<<endl;
        int lch;
        cout<<"[1] Reset Password\t[2] Try Again\t[3]Sign Up\t[4]Anon: ";cin>>lch;
        if (lch == 1){
            system("clear");
            lpass();
        }
        if(lch == 2) {
            system("clear");
            in();
        }
        if(lch == 3) {
            system("clear");
            reg();
        }
        if(lch == 4) {
            system("clear");
            anonmenu();
        }

        }

    }

    void dis_1()
    {
        double a,b,c,d,dis=0,ab,cd;
        system("clear");
        cout<<"\n========================================\n";
        cout<<"Distance between two points";
        cout<<"\n========================================\n\n";
        cout<<"Enter coordinates of first point (x1 , y1) : ";
        cin>>a>>b;
        cout<<"Enter coordinates of first point (x2, y2) : ";
        cin>>c>>d;
        ab = (a-c)*(a-c);
        cd = (b-d)*(b-d);
        dis = sqrt(ab+cd);
        cout<<"Distance between ("<<a<<","<<b<<") and ("<<b<<","<<d<<") is: "<<dis<<endl<<endl;
        int uh = ay;

            string uname;
            uname = up;
            if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F1] "<<"Inputs: ("<<a<<","<<b<<") -- Output: "<<dis<<endl;}
        else{

        }


        int choose,any;
        any = ay;
        cout<<"Press 1 to Calculate another, 2 to go back to options page and 0 to log out/exit: ";
        cin>>choose;
        if (choose == 1)
        {
            dis_1();
        }
        if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
        if (choose == 0)
        {
            system("clear");
            main1();
        }


    }

    void pol() {
        double rx, x,y,r,theta;
        system("clear");
        cout<<"\tPolar to Cartesian Conversion:"<<endl<<endl;
        cout<<"Enter Coordinate (x1,y1): "; cin>>x>>y;
        rx = (x*x)+(y*y);
        r = sqrt(rx);
        theta = (atan(y/x))*57.29577;
        cout<<endl<<"Polar (r,theta) : ("<<r<<","<<theta<<")"<<endl;
        cout<<endl;

        string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F2] "<<"Inputs: ("<<x<<","<<y<<") -- Output: ("<<r<<","<<theta<<")"<<endl;}else{}

        int choose,any;
        any = ay;
        cout<<"Press 1 to Calculate another, 2 to go back to options page and 0 to log out/exit: ";
        cin>>choose;
        if (choose == 1)
        {
            pol();
        }
        if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
        if (choose == 0)
        {
            system("clear");
            main1();
        }
    }

    void diff() {

        double ara[1000],pww[1000];
    int i,t,mp,j,dp,k;
    char ch;
    cout<<endl<<"\033[35m\t\e[1mDifferentiate a Function:\033[0m\e[0m\n"<<endl<<endl<<"\tA function follows: y = ax^n+bx^(n-1)+cx^(n-2)+...+yx+z"<<endl<<"\tWhere a,b,c....z are some constant values and n is the max power"<<endl;
    cout<<endl<<"\tEnter Max Power of x: "; cin>>mp;
    t= mp+1;
    dp=mp-1;
    cout<<endl<<"\tEnter "<<"\e[1m"<<t<<"\e[0m"<<" Constant values:"<<endl;
    for (i =1, ch ='a';i<=t && ch <='z';i++, ch++){
        if (ch >= 'z') {
                ch = 'A';
        if (ch >= 'Z') {
                ch = 'a';
        if (ch >= 'z') ch = 'A';
        }
        }
        cout<<"\t "<<ch<<" : "; cin>>ara[i];
        pww[i]=i;
    }
    cout<<endl<<"\tPlease wait...";
    cout<<endl<<endl;
    this_thread::sleep_for(chrono::milliseconds(600));
    cout<<"\t\033[32mDifferentiation done!\033[0m"<<endl<<endl<<"\t\033[35m\e[1mdy/dx\e[0m\033[0m = ";
    for (i= 1,j=dp,k=mp; i<=mp && j>=1 && k>=1;i++,j--,k--){
        cout<<std::showpos<<pww[k]*ara[i]<<"x";
        if (j> 1) cout<<"^"<<std::noshowpos<<pww[j];
        if (j == 1) cout<<std::showpos<<ara[i+1];
        if(pww[j]==1) break;
    }
    cout<<endl<<endl;

    int choose,any;
    any=ay;
        cout<<std::noshowpos<<"Press 1 to Calculate another, 2 to go back to options page and 0 to log out/exit: ";
        cin>>choose;
        if (choose == 1)
        {
            diff();
        }
        if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
        if (choose == 0)
        {
            system("clear");
            main1();
        }


    }

    void dis_2() {
        system("clear");
        double x ,y ,s1=0,s2=0,s3=0,dis;
    cout<<"\tDistance of a Coordinate from O(0,0)."<<endl<<endl;
    cout<<"\tEnter the X and Y coordinates : ";
    cin>>x>>y;
    s1 = x*x;
    s2 = y*y;
    s3 = s1 + s2;
    dis = sqrt(s3);
   cout<<"\tDistance of ("<<x<<","<<y<<") from O(0,0) : "<<dis<<" units."<<endl<<endl;


            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F6] "<<"Inputs: ("<<x<<","<<y<<") -- Output: "<<dis<<endl;}
            else{}

   cout<<"Press 1 to Calculate another, 2 to go back to options page and 0 to log out/exit"<<endl;
    int choose,any;any=ay;
    cin>>choose;

    if (choose == 1) {
        dis_2();
    }
    if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
    if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
    if (choose == 0) {
        system("clear");
        main1();
    }

    }

    void slopeq(){
        system("clear");
    double slope = 0, a,b,c,angle;
	cout<<("\tFind the Slope of a Straight line\n\n");
	cout<<"\t*Readme\n";
	cout<<"\tThe equation of a straight line should be following:\n\t* ax+by+c=0 \n\t* the operator signs depend on the constant values.\n";
	cout<<"\tAs Example: if it is 12x+13y+23=0, then a = 12, b = 13, c = 23\n \tand if it is 12x-13y-23 =0, then a = 12, b = -13, c = -23.\n";
	cout<<"\n";
	cout<<"\tEnter the values of a b and c::\n";
	cout<<"\ta: ";
	cin>>a;
	cout<<"\tb: ";
    cin>>b;
	cout<<"\tc: ";
    cin>>c;
	cout<<"\n";
	slope = -b/a;
    cout<<"\tSlope of the St. line is : " <<slope<<endl;
    if (slope < 0 ) {
            angle=90 + ((-1)*(atan(slope)*57.29577));
            cout<<"\t| It makes "<<angle<<" degree with respect to X axis"<<endl<<endl;

            cout<<"       .\t\t|"<<endl<<"          .\t\t|"<<endl<<"             .\t\t|"<<endl<<"                .\t|"<<endl<<"                   .\t|  ("<<angle<<")"<<endl;
            cout<<"\t--------------(0,0)--------------"<<endl;
            cout<<"\t\t\t|."<<endl<<"\t\t\t|   ."<<endl<<"\t\t\t|      ."<<endl<<"\t\t\t|         ."<<endl<<"\t\t\t|            ."<<endl;

    }
    if (slope > 0 ) {
            angle=90 + ((-1)*(atan(slope)*57.29577));
            cout<<"\t| It makes "<<angle<<" degree with respect to X axis"<<endl<<endl;
            cout<<"\t\t\t|               ."<<endl<<"\t\t\t|            ."<<endl<<"\t\t\t|         ."<<endl<<"\t\t\t|      ."<<endl<<"\t\t\t|   .\t("<<angle<<")"<<endl;
            cout<<"\t--------------(0,0)--------------"<<endl;
            cout<<"\t               .|"<<endl<<"\t            .\t|"<<endl<<"\t         .\t|"<<endl<<"\t      .\t\t|"<<endl<<"\t   .\t\t|"<<endl;
    }

        string uname;
            int uh = ay;if(uh==0){uname = up;
            ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F9] "<<"Inputs: ("<<a<<","<<b<<","<<c<<") -- Output: ("<<slope<<","<<angle<<")"<<endl;} else{}

    int choose,any;
    any=ay;
	cout<<"\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n";

	cin>>choose;

	if (choose == 1) {
		slopeq();
	}
	if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
	if (choose == 0) {
		system("clear");
		main1();
	}


}

void qua()
{
    system("clear");
     cout<<"\n========================================\n";
    cout<<"\tQuadrant of a Coordinate";
    cout<<"\n========================================\n\n";

   double a,b,x,y;
   cout<<"Enter two coordinates (X,Y) : ";
   cin>>a;
   cin>>b;
   x=a;
   y=b;
   cout<<endl;
   if(a > 0.00 && b > 0.00){
        cout<<"Point ("<<a<<","<<b<<") lies in the 1st Quadrant.\n"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|\t("<<a<<","<<b<<")"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        cout<<"\t----------------------------------"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F4] "<<"Inputs: ("<<x<<","<<y<<") -- Output: (Lies in 1st Quadrant)"<<endl;} else{}

   }
   else if(a < 0.00 && b > 0.00) {
        cout<<"Point ("<<a<<","<<b<<") lies in the 2nd Quadrant.\n"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t("<<a<<","<<b<<")\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        cout<<"\t----------------------------------"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F4] "<<"Inputs: ("<<x<<","<<y<<") -- Output: (Lies in 2nd Quadrant)"<<endl;}else{}
   }
   else if(a < 0.00 && b < 0.00){
      cout<<"Point ("<<a<<","<<b<<")lies in the 3rd Quadrant.\n"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        cout<<"\t----------------------------------"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t("<<a<<","<<b<<")\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F4] "<<"Inputs: ("<<x<<","<<y<<") -- Output: (Lies in 3rd Quadrant)"<<endl;}else{}
   }
   else if(a > 0.00 && b < 0.00){
            cout<<"Point ("<<a<<","<<b<<")lies in the 4th Quadrant.\n"<<endl;
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            cout<<"\t----------------------------------"<<endl;
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|\t("<<a<<","<<b<<")"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F4] "<<"Inputs: ("<<x<<","<<y<<") -- Output: (Lies in 4th Quadrant)"<<endl;}else{}
   }

   else{
      cout<<"Point ("<<a<<","<<b<<") lies in the Origin.\n";
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            cout<<"\t--------------(0,0)--------------"<<endl;
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F4] "<<"Inputs: ("<<x<<","<<y<<") -- Output: (Lies in the origin)"<<endl;} else{}
   }


       int choose,any;
	cout<<endl<<"\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n";

	cin>>choose;
	any = ay;

	if (choose == 1) {
		qua();
	}
	if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
	if (choose == 0) {
		system("clear");
		main1();
	}


}

void mircor ()
{
	double x1,y1, mx, my, mo,x,y;
	int c;
	cout<<"\tMirror of a Point"<<endl<<endl;
	cout<<"\t*Options: \t (choose one)\n";
	cout<<"\t1. Mirror with respect to X axis\n";
	cout<<"\t2. Mirror with respect to Y axis\n";
	cout<<"\t3. Mirror with respect to Origin\n";
	cout<<"\t4. Mirror with respect to another Point\n";

	cout<<"\n\tChoose and option: ";
	cin>>c;

	if (c == 1) {
		system("clear");
		cout<<"\tEnter coordinates of the point: ";
		cin>>x1;
		cin>>y1;
		cout<<"\tMirror of ("<<x1<<","<<y1<<") w.r.t X axis is ("<<x1<<","<<-y1<<")\n"<<endl;

		cout<<"\t\t\t|"<<endl<<"\t\t\t|\t.   ("<<x1<<","<<y1<<")"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        cout<<"\t--------------(0,0)--------------"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|\t.   ("<<x1<<","<<-y1<<") mirror"<<endl<<"\t\t\t|"<<endl;
            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F5] "<<"Mirror of ("<<x1<<","<<y1<<") w.r.t X axis is ("<<x1<<","<<-y1<<")"<<endl;}else{}
	}

	if (c == 2) {
		system("clear");
		cout<<"\tEnter coordinates of the point: ";
		cin>>x1;
		cin>>y1;
		cout<<"\tMirror of ("<<x1<<","<<y1<<") w.r.t Y axis is ("<<-x1<<","<<y1<<")\n"<<endl;
		cout<<"\tmirror("<<-x1<<","<<y1<<")\t|"<<endl<<"\t\t.\t|\t.   ("<<x1<<","<<y1<<")"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            cout<<"\t--------------(0,0)--------------"<<endl;
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F5] "<<"Mirror of ("<<x1<<","<<y1<<") w.r.t Y axis is ("<<-x1<<","<<y1<<")"<<endl;} else{}
	}

	if (c == 3) {
		system("clear");
		cout<<"\tEnter coordinates of the point: ";
		cin>>x1;
		cin>>y1;
		cout<<"Mirror of ("<<x1<<","<<y1<<") w.r.t Origin is ("<<-x1<<","<<-y1<<")\n"<<endl;
		double a,b;
		a=x1;
		b=y1;
        if( a > 0.00 && b > 0.00){
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|\t.   ("<<a<<","<<b<<")"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        cout<<"\t----------------------------------"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t(("<<-a<<","<<-b<<")) .\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F5] "<<"Mirror of ("<<x1<<","<<y1<<") w.r.t origin is ("<<-x1<<","<<-y1<<")"<<endl;} else{}

   }
        if(a < 0.00 && b > 0.00) {
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t("<<a<<","<<b<<") .\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        cout<<"\t----------------------------------"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|\t. (("<<-a<<","<<-b<<"))"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
   }
        if(a < 0.00 && b < 0.00){
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|\t. (("<<-a<<","<<-b<<"))"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        cout<<"\t----------------------------------"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t("<<a<<","<<b<<") .\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
   }
        if(a > 0.00 && b < 0.00){
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t(("<<-a<<","<<-b<<")) .\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            cout<<"\t----------------------------------"<<endl;
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|\t. ("<<a<<","<<b<<")"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
   }

   cout<<endl<<"\tGraph: ((x,y)) are the mirrored points"<<endl;

	}

	if (c == 4) {
		system("clear");
		cout<<"\tEnter coordinates of the point: ";
		cin>>x1;
		cin>>y1;
		cout<<"\tEnter coordinates of the mirroring point: ";
		cin>>mx;
		cin>>my;
		x = (2*mx)-x1;
		y = (2*my)-y1;
		cout<<"\tMirror of ("<<x1<<","<<y1<<") w.r.t ("<<mx<<","<<my<<") is ("<<x<<","<<y<<")\n"<<endl;

            cout<<"\t\t\t|"<<endl<<"\t("<<x<<","<<y<<") ."<<"\t\t|\t. ("<<mx<<","<<my<<")"<<"\t\t. ("<<x1<<","<<y1<<")"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            cout<<"\t--------------(0,0)--------------"<<endl;
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F5] "<<"Mirror of ("<<x1<<","<<y1<<") w.r.t ("<<mx<<","<<my<<") is ("<<x1<<","<<-y1<<")"<<endl;}else{}

	}


	 int choose,any;any=ay;
	cout<<"\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n";

	cin>>choose;

	if (choose == 1) {
		mircor();
	}
	if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
	if (choose == 0) {
		system("clear");
		main1();
	}
}

void invelyz (){
 int budget,n,i,tot=0, product_count[10000];
    double ivst, pricedata[10000], invested, invested_1, sell_price,x,y,z,profit,pro_sim = 0,rem_blnc = 0;
    cout<<"Welcome to Business Analysis\n";
    cout<<"Instructions:\n1. Enter your total budget\n";
    cout<<"2.Enter the number of products you are intend to sell\n";
    cout<<"\033[32m(i.e. If you are planning to sell {A,B,C} then number of products is 3)\n";
    cout<<"\033[0m3. Enter Price per product\n";
    cout<<"4. Enter product counts\n";
    cout<<"5. Enter the percentage amount of your needed profit\n";
    cout<<"\n\n";
    cout<<"Enter Your Budget: ";
    cin>>budget;
    cout<<"Number of Products: ";
    cin>>n;
    for (i = 1; i <= n; i++) {
        cout<<"\033[0mPrice of product " << i<<" : ";
       cin>>pricedata[i];
        cout<<"\033[0mQuantity of product " << i<<" : ";
       cin>>product_count[i];
        ivst = pricedata[i]*product_count[i];
        invested += ivst;
        rem_blnc = budget - invested;

        if (rem_blnc <= 0 || pricedata[i+1] >= rem_blnc) {
            cout<<"\033[31m\nBUDGET EXCEEDED OR NO INVESTMENT LEFT\n\n";
            break;
            }
            else {
                tot++;
                cout<<"\033[35mRemaining Balance : "<< rem_blnc<<endl;
            }

    }
    int tot1=0;
    if (rem_blnc == 0 ) tot1 = tot+1;
    else tot1 = tot;
   cout<<"\033[0m------------------------------------------\n";
    for (i = 1; i<= tot1; i++) {
        ivst = pricedata[i]*product_count[i];
        cout<<"\033[0mPrice of product "<< i<<"  is " << pricedata[i]<<endl;
        cout<<"\033[0mQuantity of product "<< i<<"  is "<< product_count[i]<<endl;
        cout<<"\033[0mTotal Price of product "<< i<< " is "<< ivst<<endl;
        cout<<"\033[0m------------------------------------------\n";
        invested_1 += ivst;
        if (pricedata[i] == 0) break;
    }
   cout<<"\033[32mTotal Invested: "<< invested_1<<endl;

    cout<<"\033[0m=========================================\n\n";
    cout<<"\033[0mHow much profit do you want? ";
    cin>>profit;
    pro_sim = profit/100;
    sell_price = invested_1 + (invested_1*pro_sim);
    cout<<"\n\033[0m------------------------------------------\n";
    cout<<"\n\033[33mTotal Selling Price should be: "<< sell_price<<endl;
    cout<<"\n\033[0m------------------------------------------\n";
    double dsp = 0, dsp1 = 0;
    dsp = sell_price-invested_1;
    dsp1 = dsp/tot1;
    for (i = 1; i<= tot1; i++) {
        cout<<"\033[0mSell the product "<< i<<" for "<< (pricedata[i]*pro_sim)+pricedata[i]<<endl;
        cout<<"\033[0m------------------------------------------\n";
        //if (pricedata[i] == 0) break;
    }

            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F14] "<<"Budget: "<<budget<<", Invested: "<<invested_1<<"Selling Price: "<<sell_price<<endl;}else{}

    int choose,any;any=ay;
	cout<<"\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n";

	cin>>choose;

	if (choose == 1) {
		invelyz();
	}
	if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
	if (choose == 0) {
		system("clear");
		main1();
	}
}

void isect()
 {
    double a1,b1,c1,a2,b2,c2,x1=0,y1=0,d=0,xx=0,yy=0;
    cout<<"\tEnter constant values for a1,b1,c1 respectively: ";
    cin>>a1>>b1>>c1;
    cout<<"\n";
    cout<<"\tEnter constant values for a2,b2,c2 respectively: ";
    cin>>a2>>b2>>c2;
    cout<<"\n";
    cout<<"\tThe equation of the straight line (1) is: "<<a1<<"x"<<std::showpos<<b1<<"y"<<c1 <<"= 0\n";
    cout<<"\tThe equation of the straight line (2) is: "<<std::noshowpos<<a2<<"x"<<std::showpos<<b2<<"y"<<c2 <<"= 0\n"<<endl;

    d = (a1*b2)-(b1*a2);
    if (a1*b2 != a2*b1) {
        xx = (b1*c2)-(b2*c1);
        yy = (c1*a2)-(c2*a1);
        x1 = xx/d;
        y1 = yy/d;
       cout<<"\tIntersect Point: ("<<std::noshowpos<<x1<<","<<y1<<")"<<endl;
            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F10] "<<"Intersect Points: ("<<x1<<","<<y1<<")"<<endl;}else{}
    }
    else {
            cout<<"\tThe Lines are parallel to each other, hence there is no Intersect point"<<endl;
     string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F10] "<<"Parallel Lines"<<endl;}else{}
    }


 int choose,any;any=ay;
	cout<<"\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n";

	cin>>choose;

	if (choose == 1) {
		isect();
	}
	if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
	if (choose == 0) {
		system("clear");
		main1();
	}
 }



void ntgrate ()
{
    system("clear");
    int a=0,b=0,c=0,d,e,mp,n,var,terms,i,j;
    char chars, sign1, sign2,sign,sign3,sign4,sign5,sign6,sign7,sign8,sign9,sign10,sign11;
    char powr;
    cout<<"\n\033[35m\t\e[1mIntigrate a Function\033[0m\e[0m\n";
    cout<<"\n";
    cout<<"\tIntegration of a Function is limited to only one term\n";
    cout<<"\tEnter the power (n) of x (x^n): ";
    cin>>mp;
    terms = mp+1;
    int ara[terms],cont;
    cout<<"\tEnter Constant value with x (if no, enter 1): ";
    cin>>cont;



            cout<<"\n\t--------------------------\n";
            cout<<"\tThe Equation is y = "<<cont<<"x^"<<mp<<endl;
            cout<<"\t--------------------------\n";
            cout<<"\tINTEGRATION of Y:\n";
            cout<<"\t--------------------------\n";
            cout<<"\tint(y) dx = ("<<cont<<"/"<<mp+1<<")*x^"<<mp+1<<endl;

    int choose,any;any=ay;
	cout<<"\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n";

	cin>>choose;

	if (choose == 1) {
		ntgrate();
	}
	if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
	if (choose == 0) {
		system("clear");
		main1();
	}

}


void pdig() {

    {

    double price,oprice,pdiff;
    int a,b,c,d,e,f,g,h,i,j,k,l,choose,any;any=ay;

    cout<<"\tWelcome to Profit Diagram"<<endl;
    cout<<"\tIf you are running a shop and you have some good amount of\n\tcompetitors around you, calculate the\n\tprobability if you can attract more customers\n\tby your servuce!"<<endl;

    cout<<endl<<"\tEnter the price of your most iconic product: ";
    cin>>price;
    cout<<endl<<"\tEnter 1 if yes/true and 0 if no/false: "<<endl;
    cout<<endl<<"\tIs there any other shop selling this product? ";
    cin>>a;
    if (a >0 ){
    cout<<"\tWhats the price of the product they are selling for? ";
    cin>>oprice;
    cout<<"\tDo they provide any warranty/after sales service? ";
    cin>>b;
    cout<<"\tDo you provide any warranty/after sales service? ";
    cin>>c;
    cout<<"\tAre they providing any offers with the product? ";
    cin>>d;
    cout<<"\tAre you providing any offers with the product? ";
    cin>>e;
    cout<<"\tWhich shop is more organized and\n\tconsumer friendly? "<<endl;
    cout<<"\tType 1 if yours, 0 if theirs: ";
    cin>>f;
    pdiff = oprice - price;

    int fb,fc,fd,fe,ff,pl;
    fb = b*30;
    fc = c*30;
    fd = d*40;
    fe = e*40;
    if (f == 1) {
        ff = f*20;
    }
    if (f == 0) {
        ff = 0;
    }
    if (pdiff > 0) {
        pl = 10;
    }
    if (pdiff < 0 ) {
        pl = -8;
    }
    if (pdiff == 0){
        if (c+e+f > b+d+1) {
            pl = 5;
        }
        if (c+e+f < b+d+1) {
            pl = 0;
        }
    }

    int sum = 0;
    sum = fc + fe + ff+pl;
    cout<<endl<<"\tYou will Attract "<<sum<<" percent of the customers!"<<endl<<endl;;
            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F15] "<<"You will Attract "<<sum<<" percent of the customers!"<<endl;}else{}
    }
    else {
        cout<<"\tYou are the only player in the field, Play as you like!!"<<endl<<endl;
        string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F15] "<<"You are the only player in the field, Play as you like!"<<endl;}else{}
    }


    cout<<"Press 1 to Calculate another, 2 to go back to options page and 0 to log out"<<endl;
    cin>>choose;

    if (choose == 1) {
            system("clear");
            pdig();
    }
    if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
    if (choose == 0) {
        system("clear");
        main1();
    }

}

}



void maxima(){
    system("clear");
    double a,b,c,x=0,y=0;
    cout<<"Enter the values of a, b, c respectively: "<<endl;
    cin>>a>>b>>c;
    cout<<"The function is y = "<<a<<"x^2"<<std::showpos<<b<<"x"<<std::showpos<<c<<endl;
    if ( a >0 ){
            x = ((-1)*b)/(2*a);
            y = (a*(x*x))+(b*x)+c;

        cout<<"The above function has minima value.\nThe minima coordinates are ("<<x<<","<<y<<")"<<endl;
       string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F11] "<<"Minima: ("<<x<<","<<y<<")"<<endl;}else{}
    }
    else {
        x = ((-1)*b)/(2*a);
            y = (a*(x*x))+(b*x)+c;
            cout<<"The above function has maxima value"<<"The maxima coordinates are ("<<x<<","<<y<<")"<<endl;
            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F11] "<<"Maxima: ("<<x<<","<<y<<")"<<endl;}else{}
    }


    cout<<endl<<"Press 1 to Calculate another, 2 to go back to options page and 0 to log out"<<endl;
int choose,any;any=ay;
    cin>>choose;

    if (choose == 1) {
        maxima();
    }
    if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
    if (choose == 0) {
        system("clear");
        main1();
    }


}

void angle()
{
    system("clear");
   cout<<"\n\t================================================================\n";
     cout<<"\tAngle made by the point with respect to x & y axis.";
     cout<<"\n\t=================================================================\n\n";
     cout<<"\tEnter the X and Y coordinates : ";
    setlocale(LC_ALL, "");

    double x ,y ,hor = 0, lob = 0, b = 0.596227, k=0, theta = 0 , k2 =0;

    cin>>x>>y;
    k = y/x;
    theta = atan(k);
    theta = theta * 57.29577;
    cout<<"\tAngle made by ("<<x<<","<<y<<") is "<<theta<<"degrees"<<endl;

    string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F7] "<<"Input: ("<<x<<","<<y<<") Angle: "<<theta<<endl;}else{}

    int choose,any;any=ay;
	cout<<"\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n";

	cin>>choose;

	if (choose == 1) {
		angle();
	}
	if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
	if (choose == 0) {
		system("clear");
		main1();
	}
}

void eqgen(){
    system("clear");
    double x1,y1,x2,y2,a,b;
    cout<<"Enter x1,y1,x2,y2 respectively: "; cin>>x1>>y1>>x2>>y2;
    a = x1-x2;
    b = y1-y2;
    cout<<endl<<"\tEquation: "<<b<<"x"<<std::showpos<<-a<<"y"<<(-b*x1)+(a*y1)<<"= 0"<<endl;

            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F8] "<<"Input: ("<<x1<<","<<y1<<","<<x2<<","<<y2<<") Equation: "<<b<<"x"<<std::showpos<<-a<<"y"<<(-b*x1)+(a*y1)<<"= 0"<<endl;}else{}

    int choose,any;any=ay;
	cout<<"\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n";

	cin>>choose;

	if (choose == 1) {
		eqgen();
	}
	if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
	if (choose == 0) {
		system("clear");
		main1();
	}
}


void car()
{
    system("clear");
	 double x, y, r, theta,thetain,PI = 3.1416;

	 cout<<"Enter radius of polar coordinate (r): ";
	 cin>>r;
	 cout<<"Enter angle of polar coordinate in degree (theta): ";
	 cin>>thetain;

	 theta = thetain * PI/180;

	 x = r * cos(theta);

	 y = r * sin(theta);

	cout<<"Cartesian coordinates are (x,y) : (" << x<<"," << y<<")"<<endl;

	string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F3] "<<"Inputs: ("<<r<<","<<thetain<<") -- Output: ("<<x<<","<<y<<")"<<endl;} else{}

	int choose,any;any=ay;
    cout<<"\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n";

	cin>>choose;

	if (choose == 1) {
		car();
	}
	if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
	if (choose == 0) {
		system("clear");
		main1();
	}

}

void umenu()
    {
        string uname = up;
        int opr;
        ofstream outfile;
        cout<<"\n\t----------------"<<endl;
        cout<<"\tHello, "<<uname<<endl;
        cout<<"\t----------------\n\n";
        cout<<"\033[35m\t\e[1mCoordinate Geometry\033[0m\e[0m\n";
        cout<<"\t\033[35m\e[1m[1]\033[0m\e[0m  Distance between two points\n";
        cout<<"\t\033[35m\e[1m[2]\033[0m\e[0m  Polar to Cartesian Conversion\n";
        cout<<"\t\033[35m\e[1m[3]\033[0m\e[0m  Cartesian to Polar Conversion\n";
        cout<<"\t\033[35m\e[1m[4]\033[0m\e[0m  Quadrant of a Coordinate\n";
        cout<<"\t\033[35m\e[1m[5]\033[0m\e[0m  Mirror of a point\n";
        cout<<"\t\033[35m\e[1m[6]\033[0m\e[0m  Distance of a Coordinate from O(0,0)\n";
        cout<<"\t\033[35m\e[1m[7]\033[0m\e[0m  Angle made by the point with respect to x & y axis.\n";
        cout<<"\n\n\033[36m\t\e[1mStraight Lines\033[0m\e[0m\n";
        cout<<"\t\033[36m\e[1m[8]\033[0m\e[0m  St. Line Equation Generator\n";
        cout<<"\t\033[36m\e[1m[9]\033[0m\e[0m  Slope of a st. Line\n";
        cout<<"\t\033[36m\e[1m[10]\033[0m\e[0m Intersect Point of two st. lines\n";
        cout<<"\n\n\033[33m\t\e[1mCurves Analysis\033[0m\e[0m\n";
        cout<<"\t\033[33m\e[1m[11]\033[0m\e[0m  Maxima & Minima of a Function\n";
        cout<<"\t\033[33m\e[1m[12]\033[0m\e[0m  Differentiation of a Function\n";
        cout<<"\t\033[33m\e[1m[13]\033[0m\e[0m  Integrate a Function\n";
        cout<<"\n\n\033[32m\t\e[1mBusiness Analysis\033[0m\e[0m\n";
        cout<<"\t\033[32m\e[1m[14]\033[0m\e[0m  Invest Analysis\n";
        cout<<"\t\033[32m\e[1m[15]\033[0m\e[0m  Profit Diagram\n";
        cout<<"\n\n";
        cout<<"\033[35m\t\e[1mAccount Settings\033[0m\e[0m\n";
        cout<<"\t\033[35m\e[1m[20]\033[0m\e[0m  Surfing History\t\033[35m\e[1m[21]\033[0m\e[0m  Calculation History"<<endl;
        cout<<"\t\033[35m\e[1m[22]\033[0m\e[0m  Change Username\t\033[35m\e[1m[23]\033[0m\e[0m  Change Password"<<endl;
        cout<<endl;
        cout<<"                \t\033[31m\e[1m[0]\033[0m\e[0m   Log Out ("<<uname<<")"<<endl<<endl;
        cout<<"\tChoose: ";
        cin>>opr;
        if (opr == 0)
        {
            system("clear");
            main1();
        }
        if(opr ==1 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Distance between two points"<<endl;
            dis_1();

        }
        if(opr ==2 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Polar to Cartesian Conversion"<<endl;
            pol();
        }
        if(opr ==3 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Cartesian to Polar Conversion"<<endl;
            car();

        }
        if(opr ==4 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Quadrant of a Point"<<endl;
            qua();

        }
        if(opr ==5 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Mirror of a Point"<<endl;
            system("clear");
            mircor();

        }
        if(opr ==6 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Distance of a Coordinate from O(0,0)"<<endl;
            dis_2();
        }
        if(opr ==7 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Angle made by a point"<<endl;
            angle();
        }
        if(opr ==8)
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened St. Line Equation generator"<<endl;
            eqgen();
        }
        if(opr ==9 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Slope of a st. Line"<<endl;
            slopeq();
        }
        if(opr ==10)
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Intersect Point of two st. Line"<<endl;
            isect();
        }
        if(opr ==11)
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Maxima/Minima of a Function"<<endl;
            maxima();
        }
        if(opr ==12 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Differentiator"<<endl;
            system("clear");
            diff();
        }
        if(opr ==13 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Integrator"<<endl;
            system("clear");
            ntgrate();
        }
        if(opr ==14 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Invest Analysis"<<endl;
            system("clear");
            invelyz();
        }
        if(opr ==15 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Profit Diagram"<<endl;
            system("clear");
            pdig();
        }
            if (opr == 20){
            system("clear");
            clrh();

        }
        if (opr == 21){
            system("clear");
            calh();

        }
        if (opr == 22){
            system("clear");
            cname();

        }
        if (opr == 23){
            system("clear");
            cpass();

        }

    }


    void clrh() {

            string a1,a2,a3,a4,a5,a6,a7,uname=up;
            ifstream read("History/"+uname+".txt");
            getline(read, a1);
            getline(read, a2);
            getline(read, a3);
            getline(read, a4);
            getline(read, a5);
            getline(read, a6);
            getline(read, a7);
            cout<<endl<<"\033[35m\t\e[1mRecent History\033[0m\e[0m ("<<uname<<")"<<endl;
            if ( a1.empty() ){
                    cout<<endl<<"\t(no surfing history)!"<<endl;
                    int choose;
                    cout<<endl<<"\t[2] Return to Menu: "; cin>>choose;
                    if (choose==2) {
                        system("clear");
                        umenu();
                    }

            }
            else {
                    cout<<"\t"<<a1<<endl<<"\t"<<a2<<endl<<"\t"<<a3<<endl<<"\t"<<a4<<endl<<"\t"<<a5<<endl<<"\t"<<a6<<endl<<"\t"<<a7<<endl;
            int clh;
            cout<<endl<<"\t[1] Clear History\t[2] Return to Menu: "; cin>>clh;
            if (clh == 1){
                ofstream file;
                file.open("History/"+uname+".txt");
                file <<"";
                file.close();
                cout<<endl<<"\tPlease wait...";
                cout<<endl<<endl;
                this_thread::sleep_for(chrono::milliseconds(600));
                cout<<"\t\033[32mHistory Cleared!\033[0m"<<endl;
                this_thread::sleep_for(chrono::milliseconds(600));
                system("clear");
                clrh();
            }
            if (clh == 2){
                system("clear");
                umenu();
            }


    }
    }


    void calh() {

            string a1,a2,a3,a4,a5,a6,a7,uname=up;
            ifstream read("History/"+uname+"_calculations.txt");
            getline(read, a1);
            getline(read, a2);
            getline(read, a3);
            getline(read, a4);
            getline(read, a5);
            getline(read, a6);
            getline(read, a7);
            cout<<endl<<"\033[35m\t\e[1mRecent History\033[0m\e[0m ("<<uname<<")"<<endl;
            if ( a1.empty() ){
                    cout<<endl<<"\t(no surfing history)!"<<endl;
                    int choose;
                    cout<<endl<<"\t[2] Return to Menu: "; cin>>choose;
                    if (choose==2) {
                        system("clear");
                        umenu();
                    }

            }
            else {
                    cout<<"\t"<<a1<<endl<<"\t"<<a2<<endl<<"\t"<<a3<<endl<<"\t"<<a4<<endl<<"\t"<<a5<<endl<<"\t"<<a6<<endl<<"\t"<<a7<<endl;
            int clh;
            cout<<endl<<"\t[1] Clear History\t[2] Return to Menu: "; cin>>clh;
            if (clh == 1){
                ofstream file;
                file.open("History/"+uname+"_calculations.txt");
                file <<"";
                file.close();
                cout<<endl<<"\tPlease wait...";
                cout<<endl<<endl;
                this_thread::sleep_for(chrono::milliseconds(600));
                cout<<"\t\033[32mHistory Cleared!\033[0m"<<endl;
                this_thread::sleep_for(chrono::milliseconds(600));
                system("clear");
                calh();
            }
            if (clh == 2){
                system("clear");
                umenu();
            }


    }
    }


    void anonmenu()
    {
        int opr;
        cout<<"\n\t----------------"<<endl;
        cout<<"\tHello, Anon!"<<endl;
        cout<<"\t----------------\n\n";
        cout<<"\033[35m\t\e[1mCoordinate Geometry\033[0m\e[0m\n";
        cout<<"\t\033[35m\e[1m[1]\033[0m\e[0m  Distance between two points\n";
        cout<<"\t\033[35m\e[1m[2]\033[0m\e[0m  Polar to Cartesian Conversion\n";
        cout<<"\t\033[35m\e[1m[3]\033[0m\e[0m  Cartesian to Polar Conversion\n";
        cout<<"\t\033[35m\e[1m[4]\033[0m\e[0m  Quadrant of a Coordinate\n";
        cout<<"\t\033[35m\e[1m[5]\033[0m\e[0m  Mirror of a point\n";
        cout<<"\t\033[35m\e[1m[6]\033[0m\e[0m  Distance of a Coordinate from O(0,0)\n";
        cout<<"\t\033[35m\e[1m[7]\033[0m\e[0m  Angle made by the point with respect to x & y axis.\n";
        cout<<"\n\n\033[36m\t\e[1mStraight Lines\033[0m\e[0m\n";
        cout<<"\t\033[36m\e[1m[8]\033[0m\e[0m  St. Line Equation Generator\n";
        cout<<"\t\033[36m\e[1m[9]\033[0m\e[0m  Slope of a st. Line\n";
        cout<<"\t\033[36m\e[1m[10]\033[0m\e[0m Intersect Point of two st. lines\n";
        cout<<"\n\n\033[33m\t\e[1mCurves Analysis\033[0m\e[0m\n";
        cout<<"\t\033[33m\e[1m[11]\033[0m\e[0m  Maxima & Minima of a Function\n";
        cout<<"\t\033[33m\e[1m[12]\033[0m\e[0m  Differentiation of a Function\n";
        cout<<"\t\033[33m\e[1m[13]\033[0m\e[0m  Integrate a Function\n";
        cout<<"\n\n\033[32m\t\e[1mBusiness Analysis\033[0m\e[0m\n";
        cout<<"\t\033[32m\e[1m[14]\033[0m\e[0m  Invest Analysis\n";
        cout<<"\t\033[32m\e[1m[15]\033[0m\e[0m  Profit Diagram\n";
        cout<<"\n\n";
        cout<<"\t\033[31m\e[1m[0]\033[0m\e[0m  Exit"<<endl<<endl;
        cout<<"\tChoose: ";
        cin>>opr;
        if (opr == 0)
        {
            system("clear");
            main1();
        }
        if(opr ==1 )
        {
            dis_1();

        }
        if(opr ==2 )
        {
            pol();
        }
        if(opr ==3 )
        {
            car();
        }
        if(opr ==4 )
        {
            qua();

        }
        if(opr ==5 )
        {
            mircor();

        }
        if(opr ==6 )
        {
            dis_2();
        }
        if(opr ==7 )
        {
            angle();
        }
        if(opr ==8)
        {
            eqgen();
        }
        if(opr ==9 )
        {
            slopeq();
        }
        if(opr == 10 )
        {
            isect();
        }
        if(opr == 11 )
        {
            maxima();
        }
        if(opr ==12 )
        {
            system("clear");
            diff();
        }
        if(opr ==13 )
        {
            system("clear");
            ntgrate();
        }
        if(opr ==14 )
        {
            system("clear");
            invelyz();
        }
        if(opr ==15 )
        {
            system("clear");
            pdig();
        }

    }



};




int main()
{
    Functions ob;
    ob.main1();

}
