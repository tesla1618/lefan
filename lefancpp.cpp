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
    string up;
    int ay;

    void main1()
    {
        int opts;
        cout<<"\n\n\t\t\t\t=============\n\t\t\t\t    \e[1mLEFAN\e[0m\n\t\t\t\t=============\n\n";
        cout<<"\n\tHey \033[32mAnon\033[0m, Welcome to Linear Equations and Function Analysis!\n\tA coordinate geometry Calculator and Function Analyzer.\n\n";
        cout<<"\t   \033[36m[1] Sign in\n\t   [2] Sign up\n\t   [3] Continue as \033[32mAnon\033[36m (calculation history will not be saved)\n\t   [4] Docs\033[0m\n\n";
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
            ay=1;
            system("clear");
            anonmenu();

        }


    }

    void reg()
    {
        string uname, pword,up;
        cout<<"Username: ";
        cin>>uname;
        cout<<"Password: ";
        cin>>pword;
        ofstream file;
        file.open("Users/"+uname+".txt");
        file << uname <<endl << pword;
        file.close();
    }
    void in()
    {
        int opr;
        ofstream file;
        string uname, pword, u, p;
        cout<<"Username: ";
        cin>>uname;
        cout<<"Password: ";
        cin>>pword;
        ifstream read("Users/"+uname+".txt");
        getline(read, u);
        getline(read, p);

        if (u == uname && p == pword)
        {
            ifstream read("Users/"+uname+".txt");
            getline(read, u);
            up = u;
            file.open("History/"+uname+".txt");
            file << uname<<" Logged In"<<endl;
            file.close();
            system("clear");
            umenu();
        }
        else cout<<"Error";
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

        int choose;
        cout<<"Press 1 to Calculate another, 2 to go back to options page and 0 to log out/exit: ";
        cin>>choose;
        if (choose == 1)
        {
            pol();
        }
        if (choose == 2)
        {
            system("clear");
            umenu();
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

    int choose;
        cout<<"Press 1 to Calculate another, 2 to go back to options page and 0 to log out/exit: ";
        cin>>choose;
        if (choose == 1)
        {
            diff();
        }
        if (choose == 2)
        {
            system("clear");
            umenu();
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

   cout<<"Press 1 to Calculate another, 2 to go back to options page and 0 to log out/exit"<<endl;
    int choose;
    cin>>choose;

    if (choose == 1) {
        dis_2();
    }
    if (choose == 2) {
        system("clear");
        umenu();
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


    int choose;
	cout<<"\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n";

	cin>>choose;

	if (choose == 1) {
		slopeq();
	}
	if (choose == 2) {
		system("clear");
		umenu();
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

   double a,b;
   cout<<"Enter two coordinates (X,Y) : ";
   cin>>a;
   cin>>b;
   cout<<endl;
   if(a > 0.00 && b > 0.00){
        cout<<"Point ("<<a<<","<<b<<") lies in the 1st Quadrant.\n"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|\t("<<a<<","<<b<<")"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        cout<<"\t----------------------------------"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;

   }
   else if(a < 0.00 && b > 0.00) {
        cout<<"Point ("<<a<<","<<b<<") lies in the 2nd Quadrant.\n"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t("<<a<<","<<b<<")\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        cout<<"\t----------------------------------"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
   }
   else if(a < 0.00 && b < 0.00){
      cout<<"Point ("<<a<<","<<b<<")lies in the 3rd Quadrant.\n"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        cout<<"\t----------------------------------"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t("<<a<<","<<b<<")\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
   }
   else if(a > 0.00 && b < 0.00){
            cout<<"Point ("<<a<<","<<b<<")lies in the 4th Quadrant.\n"<<endl;
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            cout<<"\t----------------------------------"<<endl;
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|\t("<<a<<","<<b<<")"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
   }

   else{
      cout<<"Point ("<<a<<","<<b<<") lies in the Origin.\n";
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            cout<<"\t--------------(0,0)--------------"<<endl;
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
   }


       int choose;
	cout<<endl<<"\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n";

	cin>>choose;

	if (choose == 1) {
		qua();
	}
	if (choose == 2) {
		system("clear");
		umenu();
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

	}


	 int choose;
	cout<<"\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n";

	cin>>choose;

	if (choose == 1) {
		mircor();
	}
	if (choose == 2) {
		system("clear");
		umenu();
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

    int choose;
	cout<<"\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n";

	cin>>choose;

	if (choose == 1) {
		invelyz();
	}
	if (choose == 2) {
		system("clear");
		umenu();
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
        cout<<"\t\033[35m\e[1m[3]\033[0m\e[0m  Quadrant of a Coordinate\n";
        cout<<"\t\033[35m\e[1m[4]\033[0m\e[0m  Mirror of a point\n";
        cout<<"\t\033[35m\e[1m[5]\033[0m\e[0m  Distance of a Coordinate from O(0,0)\n";
        cout<<"\t\033[35m\e[1m[6]\033[0m\e[0m  Angle made by the point with respect to x & y axis.\n";
        cout<<"\n\n\033[36m\t\e[1mStraight Lines\033[0m\e[0m\n";
        cout<<"\t\033[36m\e[1m[7]\033[0m\e[0m  St. Line Equation Generator\n";
        cout<<"\t\033[36m\e[1m[8]\033[0m\e[0m  Distance between two st. lines\n";
        cout<<"\t\033[36m\e[1m[9]\033[0m\e[0m  Slope of a st. Line\n";
        cout<<"\t\033[36m\e[1m[10]\033[0m\e[0m Intersect Point of two st. lines\n";
        cout<<"\n\n\033[33m\t\e[1mCurves Analysis\033[0m\e[0m\n";
        cout<<"\t\033[33m\e[1m[11]\033[0m\e[0m  Maxima & Minima of a Function\n";
        cout<<"\t\033[33m\e[1m[12]\033[0m\e[0m  Differentiation of a Function\n";
        cout<<"\t\033[33m\e[1m[13]\033[0m\e[0m  Area of a Function binded by x=a,y=b\n";
        cout<<"\n\n\033[32m\t\e[1mBusiness Analysis\033[0m\e[0m\n";
        cout<<"\t\033[32m\e[1m[14]\033[0m\e[0m  Invest Analysis\n";
        cout<<"\t\033[32m\e[1m[15]\033[0m\e[0m  Profit Diagram\n";
        cout<<"\n\n";
        cout<<"20. History"<<endl;
        cout<<"\t\033[31m\e[1m[0]\033[0m\e[0m  Log Out ("<<uname<<")"<<endl<<endl;
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
            outfile <<uname<<" Opened Coordinate Geometry"<<endl;
            dis_1();

        }
        if(opr ==2 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Vector Geometry"<<endl;
            pol();
        }
        if(opr ==3 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Quadrant of a Point"<<endl;
            qua();

        }
        if(opr ==4 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Mirror of a Point"<<endl;
            system("clear");
            mircor();

        }
        if(opr ==7 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Distance of a Coordinate from O(0,0)"<<endl;
            dis_2();
        }
        if(opr ==9 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Slope of a st. Line"<<endl;
            slopeq();
        }
        if(opr ==12 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Differentiator"<<endl;
            system("clear");
            diff();
        }
        if(opr ==14 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Invest Analysis"<<endl;
            system("clear");
            invelyz();
        }
        /* if (opr == 20){
                string ax,ay,az;
            ifstream read("History/"+uname+".txt");
            getline(read, ax);
            getline(read, ay);
            getline(read, az);
            cout<<ax<<ay<<az;

        } */

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
        cout<<"\t\033[35m\e[1m[3]\033[0m\e[0m  Quadrant of a Coordinate\n";
        cout<<"\t\033[35m\e[1m[4]\033[0m\e[0m  Mirror of a point\n";
        cout<<"\t\033[35m\e[1m[5]\033[0m\e[0m  Distance of a Coordinate from O(0,0)\n";
        cout<<"\t\033[35m\e[1m[6]\033[0m\e[0m  Angle made by the point with respect to x & y axis.\n";
        cout<<"\n\n\033[36m\t\e[1mStraight Lines\033[0m\e[0m\n";
        cout<<"\t\033[36m\e[1m[7]\033[0m\e[0m  St. Line Equation Generator\n";
        cout<<"\t\033[36m\e[1m[8]\033[0m\e[0m  Distance between two st. lines\n";
        cout<<"\t\033[36m\e[1m[9]\033[0m\e[0m  Slope of a st. Line\n";
        cout<<"\t\033[36m\e[1m[10]\033[0m\e[0m Intersect Point of two st. lines\n";
        cout<<"\n\n\033[33m\t\e[1mCurves Analysis\033[0m\e[0m\n";
        cout<<"\t\033[33m\e[1m[11]\033[0m\e[0m  Maxima & Minima of a Function\n";
        cout<<"\t\033[33m\e[1m[12]\033[0m\e[0m  Differentiation of a Function\n";
        cout<<"\t\033[33m\e[1m[13]\033[0m\e[0m  Area of a Function binded by x=a,y=b\n";
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
            qua();

        }
        if(opr ==4 )
        {
            mircor();

        }
        if(opr ==7 )
        {
            dis_2();
        }
        if(opr ==9 )
        {
            slopeq();
        }
        if(opr ==12 )
        {
            system("clear");
            diff();
        }
        if(opr ==14 )
        {
            system("clear");
            invelyz();
        }

    }



};




int main()
{
    Functions ob;
    ob.main1();

}
