#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>

struct usr {
    char name[50];
    char user_id[10];
    char password [32];
};

reg() {
    char close;
    FILE *usr_info;
    usr_info=fopen("reg_info.txt", "w");
    struct usr up;
    printf("----------------------------------\n\tREGISTRATION\n----------------------------------\n");
    printf("Enter Your Name: ");
    scanf("%s", &up.name);
    printf("Enter User ID: ");
    scanf("%s", &up.user_id);
    printf("Enter Password: ");
    scanf("%s", &up.password);
    fwrite(&up, sizeof(up),1,usr_info);

    fclose(usr_info);

    printf("You are sucessfully registered!!\n");
    printf("Press any key to continue...\n");
    scanf("%c", &close);
    if (close == '\n') {
		system("clear");
     	in();
    }

}

in() {
    char user_id[10];
    char password [32];
	char close;
    FILE *usr_info;
    usr_info=fopen("reg_info.txt", "r");
    struct usr up;
    printf("Enter User ID: ");
    scanf("%s", &user_id);
    printf("Enter Password: ");
    scanf("%s", &password);

    while(fread(&up, sizeof(up),1,usr_info)) {
        if (strcmp(user_id,up.user_id)== 0 && strcmp(password,up.password)==0) {
            printf("You are now logged in!\n");
			printf("Press Any key to show Analytical Options...\n");
			scanf("%c", &close);
			if (close == '\n') {
		system("clear");
     	wlc();
    }
            }
        else printf("Incorrect Information or maybe you are trying to break into the system!\n");
}

    fclose(usr_info);



}


dis_1() {
	double sqrt = 0, a,b,c,d,s1=0,s2=0,s3=0,root=0;

	printf("\n========================================\n");
	printf("Distance between two points");
	printf("\n========================================\n\n");
	printf("Enter coordinates of first point (x1 , y1) : ");
	scanf("%lf %lf", &a, &b);
    printf("Enter coordinates of second point (x2 , y2) : ");
	scanf("%lf %lf", &c, &d);
	s1 = (a-c)*(a-c);
	s2 = (b-d)*(b-d);
	s3 = s1+s2;
	sqrt = s3/2;
	double temp = 0;
    while(sqrt != temp){
        temp = sqrt;
        sqrt = ( s3/temp + temp) / 2;
    }
    printf("Distance between two points : %.3lf units \n", sqrt);

	int choose;
	printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n");

	scanf("%d",&choose);

	if (choose == 1) {
		dis_1();
	}
	if (choose == 2) {
		system("clear");
		wlc();
	}
	if (choose == 0) {
		system("clear");
		main();
	}
}

pol() {
	double x,y,theta=0,r=0;
    double pi = 3.1416, k = 0, k2 = 0, b = 0.596227,s3=0,sqrt=0,hor=0,lob=0;
    int choose;

	printf("\n========================================\n");
	printf("Polar to Cartesian Conversion");
	printf("\n========================================\n\n");

    printf("Enter the X and Y coordinates : ");
    scanf("%lf %lf",&x,&y);
	s3 = (x*x)+(y*y);
	sqrt = s3/2;
	double temp = 0;
    while(sqrt != temp){
        temp = sqrt;
        sqrt = ( s3/temp + temp) / 2;
    }
	r = sqrt;
	k = y/x;
	k2 = k*k;
	lob = (b*k) + k2;
	hor = (1+(2*b*k) + k2);
    theta = lob/hor;
    theta = theta * 90;

    printf("Polar Coordinates : (r,theta) = (%.2lf , %.2lf)\n\n",r,theta);

	printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n");

	scanf("%d",&choose);

	if (choose == 1) {
		pol();
	}
	if (choose == 2) {
		system("clear");
		wlc();
	}
	if (choose == 0) {
		system("clear");
		main();
	}

}

eqgen() {

	double x1,x2,y1,y2,x=0,y=0,xf=0,yf=0,x11,y11;
	char sx, sy;
	int i,xx1=0,yy1=0;
	printf("\n========================================\n");
	printf("Straight Line Equation Generator");
	printf("\n========================================\n\n");
	printf("Enter Coordinates respectively x1,y1,x2,y2\n");
	scanf("%lf %lf %lf %lf", &x1,&y1,&x2,&y2);
	if (x1 < 0 ) {
		sx = '+';
	}
	if (x1 >= 0 ) {
		sx = '-';
	}
	if (y1 < 0 ) {
		sy = '+';
	}
	if (y1 >= 0 ) {
		sy = '-';
	}

	x= x1-x2;
	y= y1-y2;
	if (x1<0) {
		x1 = (-1)*x1;
	}
	if (y1<0) {
		y1 = (-1)*y1;
	}
	xf = x - (int)x;
	yf = y - (int)x;
	x11 = x1 - (int)x1;
	y11 = y1 - (int)y1;
	if ( xf <= 0  && yf <= 0 && x11 <= 0  && y11 <= 0) {
		int xx = (int)x;
		int yy = (int)y;
		int x_1 = (int)x1;
		int y_1 = (int)y1;
		if (xx <= 0 && yy <= 0) {
		xx1 = (-1)*xx;
		yy1 = (-1)*yy;
	}
		printf("Equation:\n");
	printf("\n %d(x %c %d) = %d(y - %d)", xx1, x_1, yy1, y_1);

	}
	else {
	printf("Equation:\n");
	printf("\n %lf (x %c %lf) = %lf (y %c %lf)", x, sx, x1, y, sy, y1);
	}


	int choose;
	printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n");

	scanf("%d",&choose);

	if (choose == 1) {
		eqgen();
	}
	if (choose == 2) {
		system("clear");
		wlc();
	}
	if (choose == 0) {
		system("clear");
		main();
	}
}

mircor () {
	double x1,y1, mx, my, mo,x,y;
	int c;
	printf("\n========================================\n");
	printf("Mirror of a Point");
	printf("\n========================================\n\n");
	printf("*Options: \t (choose one)\n");
	printf("1. Mirror with respect to X axis\n");
	printf("2. Mirror with respect to Y axis\n");
	printf("3. Mirror with respect to Origin\n");
	printf("4. Mirror with respect to another Point\n");

	printf("\nChoose and option: ");
	scanf("%d", &c);

	if (c == 1) {
		system("clear");
		printf("Enter coordinates of the point: ");
		scanf("%lf %lf", &x1, &y1);
		printf("Mirror of (%.1lf, %.1lf) w.r.t X axis is (%.1lf, %.1lf)\n", x1,y1,x1,-y1);
	}

	if (c == 2) {
		system("clear");
		printf("Enter coordinates of the point: ");
		scanf("%lf %lf", &x1, &y1);
		printf("Mirror of (%.1lf, %.1lf) w.r.t Y axis is (%.1lf, %.1lf)\n", x1,y1,-x1,y1);
	}

	if (c == 3) {
		system("clear");
		printf("Enter coordinates of the point: ");
		scanf("%lf %lf", &x1, &y1);
		printf("Mirror of (%.1lf, %.1lf) w.r.t Origin is (%.1lf, %.1lf)\n", x1,y1,-x1,-y1);
	}

	if (c == 4) {
		system("clear");
		printf("Enter coordinates of the point: ");
		scanf("%lf %lf", &x1, &y1);
		printf("Enter coordinates of the mirroring point: ");
		scanf("%lf %lf", &mx, &my);
		x = (2*mx)-x1;
		y = (2*my)-y1;
		printf("Mirror of (%.1lf, %.1lf) w.r.t Origin is (%.1lf, %.1lf)\n", x1,y1,x,y);
	}

	int choose;
	printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n");

	scanf("%d",&choose);

	if (choose == 1) {
		mircor();
	}
	if (choose == 2) {
		system("clear");
		wlc();
	}
	if (choose == 0) {
		system("clear");
		main();
	}



}

slopeq () {
	double slope = 0, a,b,c;
	printf("Find the Slope of a Straight line\n\n");
	printf("*Readme\n");
	printf("The equation of a straight line should be following:\n* ax+by+c=0 * the operator signs depend on the constant values.\n");
	printf("As Example: if it is 12x+13y+23=0, then a = 12, b = 13, c = 23\n and if it is 12x-13y-23 =0, then a = 12, b = -13, c = -23.\n");
	printf("\n");
	printf("Enter the values of a b and c::\n");
	printf("a: ");
	scanf("%lf",&a);
	printf("a: ");
	scanf("%lf",&b);
	printf("a: ");
	scanf("%lf",&c);
	printf("\n");
	slope = -a/b;
	printf("Slope of the St. line is: %lf\n", slope);

	int choose;
	printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n");

	scanf("%d",&choose);

	if (choose == 1) {
		slopeq();
	}
	if (choose == 2) {
		system("clear");
		wlc();
	}
	if (choose == 0) {
		system("clear");
		main();
	}


}


qua(){

     printf("\n========================================\n");
    printf("\tQuadrant of a Coordinate");
    printf("\n========================================\n\n");

   double a,b;
   printf("Enter two coordinates (X,Y) :");
   scanf("%lf %lf",&a,&b);
   if(a > 0.00 && b > 0.00)
      printf("Point (%.1lf,%.1lf) lies in the 1st Quadrant.\n",a,b);
   else if(a < 0.00 && b > 0.00)
      printf("Point (%.1lf,%.1lf) lies in the 2nd Quadrant.\n",a,b);
   else if(a < 0.00 && b < 0.00)
      printf("Point (%.1lf,%.1lf) lies in the 3rd Quadrant.\n",a,b);
   else if(a > 0.00 && b < 0.00)
      printf("Point (%.1lf,%.1lf) lies in the 4th Quadrant.\n",a,b);
   else
      printf("Point (%.1lf,%.1lf) lies in the Origin.\n",a,b);

    printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n");
    int choose;
    scanf("%d",&choose);

    if (choose == 1) {
        qua();
    }
    if (choose == 2) {
        system("clear");
        wlc();
    }
    if (choose == 0) {
        system("clear");
        main();
    }


}


dis_2()
{
     printf("\n=======================================================\n");
    printf("\tDistance of a Coordinate from O(0,0).");
    printf("\n========================================================\n\n");
    printf("Enter the X and Y coordinates : ");

    double x ,y ,s1=0,s2=0,s3=0,root=0,sqrt;
    scanf("%lf %lf",&x,&y);

    s1 = x*x;
    s2 = y*y;
    s3 = s1 + s2;
    sqrt = s3/2;
    double temp = 0;
    while(sqrt != temp)
        {
        temp = sqrt;
        sqrt = ( s3/temp + temp) / 2;
        }

   printf("Distance of (%.1lf,%.1lf) from O(0,0) : %.3lf units \n",x,y, sqrt);

   printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n");
    int choose;
    scanf("%d",&choose);

    if (choose == 1) {
        dis_2();
    }
    if (choose == 2) {
        system("clear");
        wlc();
    }
    if (choose == 0) {
        system("clear");
        main();
    }
}


diff() {

    int a=0,b=0,c=0,d,e,mp,n,var,terms;
    char chars, sign1, sign2,sign;
    char powr;
    printf("Enter MAX power of X: ");
    scanf("%d",&mp);
    terms = mp+1;
    int ara[terms];
    printf("Enter %d Constant values:\n", terms);
    for (n = 1, chars = 'a'; n<=terms &&  chars <= 'z'; n++, ++chars) {
        printf("%c: ",chars);
        scanf("%d",&ara[n]);
    }
    if ( ara[2] > 0 ) {
        sign = '+';
    }
    if ( ara[2] < 0 ) {
        sign = '-';
        ara[2] = -ara[2];
    }
    if ( ara[3] >= 0 ) {
        sign2 = '+';
    }
    if ( ara[3] < 0 ){
        sign2 = '-';
        ara[3] = -ara[3];
    }
    printf("--------------------------\n");
    printf("The Equation is y = %dx^%d %c %dx^%d %c %d\n", ara[1],mp,sign,ara[2],(mp-1),sign2,ara[3]);
    printf("--------------------------\n");
    printf("DIFFERENTIATION of Y:\n");
    printf("--------------------------\n");
    a = ara[1]*mp;
    b = ara[2];
    if ( mp == 1) {
    printf("dy/dx = %dx\n", 2*a);
    }
    else {
    printf("dy/dx = %dx %c %d\n", a,sign,b);
    }
    printf("--------------------------\n");

    int choose;
	printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n");

	scanf("%d",&choose);

	if (choose == 1) {
		diff();
	}
	if (choose == 2) {
		system("clear");
		wlc();
	}
	if (choose == 0) {
		system("clear");
		main();
	}

}

angle()
{
     printf("\n================================================================\n");
    printf("\tAngle made by the point with respect to x & y axis.");
    printf("\n=================================================================\n\n");
    printf("Enter the X and Y coordinates : ");
    setlocale(LC_ALL, "");

    double x ,y ,hor = 0, lob = 0, b = 0.596227, k=0, theta = 0 , k2 =0;

    scanf("%lf %lf",&x,&y);
    k = y/x;
    k2 = k*k;
    lob = (b*k) + k2;
    hor = (1+(2*b*k) + k2);
    theta = lob/hor;
    theta = theta * 90;

    char ch=248;
    printf("Angle : %.2lf%c",theta,ch);

    printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out\n");
    int choose;
    scanf("%d",&choose);

    if (choose == 1) {
        angle();
    }
    if (choose == 2) {
        system("clear");
        wlc();
    }
    if (choose == 0) {
        system("clear");
        main();
    }

}


invelyz () {

    int budget,n,i,tot=0, product_count[10000];
    double ivst, pricedata[10000], invested, invested_1, sell_price,x,y,z,profit,pro_sim = 0,rem_blnc = 0;
    printf("Welcome to Business Analysis\n");
    printf("Instructions:\n1. Enter your total budget\n");
    printf("2.Enter the number of products you are intend to sell\n");
    printf("\033[32m(i.e. If you are planning to sell {A,B,C} then number of products is 3)\n");
    printf("\033[0m3. Enter Price per product\n");
    printf("4. Enter product counts\n");
    printf("5. Enter the percentage amount of your needed profit\n");
    printf("\n\n");
    printf("Enter Your Budget: ");
    scanf("%d", &budget);
    printf("Number of Products: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("\033[0mPrice of product %d: ", i);
        scanf("%lf", &pricedata[i]);
        printf("\033[0mQuantity of product %d: ", i);
        scanf("%d", &product_count[i]);
        ivst = pricedata[i]*product_count[i];
        invested += ivst;
        rem_blnc = budget - invested;

        if (rem_blnc == 0 || pricedata[i+1] > rem_blnc) {
            printf("\033[31m\nBUDGET EXCEEDED OR NO INVESTMENT LEFT\n\n");
            break;
            }
            else {
                tot++;
                printf("\033[35mRemaining Balance: %.2lf\n", rem_blnc);
            }

    }
    printf("\033[0m=======================\n");
    for (i = 1; i<= tot; i++) {
        ivst = pricedata[i]*product_count[i];
        printf("\033[0mPrice of product %d is %.2lf\n", i, pricedata[i]);
        printf("\033[0mQuantity of product %d is %d\n", i, product_count[i]);
        printf("\033[0mTotal Price of product %d is %.2lf\n", i, ivst);
        printf("\033[0m------------------------------------------\n");
        invested_1 += ivst;
        if (pricedata[i] == 0) break;
    }
    printf("\033[32mTotal Invested: %.2lf\n", invested_1);

    printf("\033[0m=======================\n\n");
    printf("\033[0mHow much profit do you want?\n");
    scanf("%lf", &profit);
    pro_sim = profit/100;
    sell_price = invested_1 + (invested_1*pro_sim);
    printf("\033[33mTotal Selling Price should be: %.2lf\n", sell_price);




    //20% code done. more to write


}


wlc() {
	int opr;
    printf("Welcome to Analysis of Functions and Linear Equations\n\n");
	printf("** This program is designed to calculate mathematical expressions and analyzing mathematical functions.\n\n");
	printf("\n--------------\n   Menu\n--------------\n\n");
	printf("The number before each option is the number you have to input in order to select.\n(If you want to select option 3, just enter 3)\n\n");
	printf("*Coordinate Geometry\n");
	printf("1. Distance between two points\n");
	printf("2. Polar to Cartesian Conversion\n");
	printf("3. Quadrant of a Coordinate\n");
	printf("4. Mirror of a point\n");
	printf("5. Distance of a Coordinate from O(0,0)\n");
	printf("6. Angle made by the point with respect to x & y axis.\n");
	printf("\n\n*Straight Lines\n");
	printf("7. St. Line Equation Generator\n");
	printf("8. Distance between two st. lines\n");
	printf("9. Slope of a st. Line\n");
	printf("10. Intersect Point of two st. lines\n");
	printf("\n\n*Curves Analysis\n");
	printf("11. Maxima & Minima of a Function\n");
	printf("12. Differentiation of a Function\n");
	printf("13. Area of a Function binded by x=a,y=b\n");
	printf("\n\n*Business Analysis Using Linear programming\n");
	printf("14. Invest Analysis\n");
	printf("15. Profit Diagram\n");
	printf("\n\n");
	printf("0. Log Out / Exit\n\n");
    while ( opr > 15) {
	printf("---------------------\nChoose Operation: "); scanf("%d",&opr);
	printf("---------------------\n");
	if (opr >= 15) {
		printf("\n\nINVALID OPERATION!!!\n\n");
		printf("---------------------\n\nChoose Operation: "); scanf("%d",&opr);
	printf("---------------------\n");

		if (opr == 0) {
		system("clear");
		main();
	}

		if (opr == 1) {
			system("clear");
			dis_1();
		}
		if (opr == 2) {
			system("clear");
			pol();
		}
		if (opr == 3) {
			system("clear");
			qua();
		}
		if (opr == 4) {
			system("clear");
			mircor();
		}
		if (opr == 5) {
			system("clear");
			dis_2();
		}
		if (opr == 6) {
			system("clear");
			angle();
		}
		if (opr == 7) {
			system("clear");
			eqgen();
		}
		if (opr == 9) {
			system("clear");
			slopeq();
		}
		if (opr == 12) {
			system("clear");
			diff();
		}
		if (opr == 14) {
			system("clear");
			invelyz();
		}
	}
	else {


		if (opr == 0) {
		system("clear");
		main();
	}

		if (opr == 1) {
			dis_1();
		}
		if (opr == 2) {
			system("clear");
			pol();
		}
		if (opr == 3) {
			system("clear");
			qua();
		}

		if (opr == 4) {
			system("clear");
			mircor();
		}
		if (opr == 5) {
			system("clear");
			dis_2();
		}
		if (opr == 6) {
			system("clear");
			angle();
		}
		if (opr == 7) {
			system("clear");
			eqgen();
		}
		if (opr == 9) {
			system("clear");
			slopeq();
		}
		if (opr == 12) {
			system("clear");
			diff();
		}
		if (opr == 14) {
			system("clear");
			invelyz();
		}

	}
}
}





int main() {
    int opts;
    char close;
    printf("Hey Anon, Welcome to Linear Equations and Function Analysis!\nA coordinate geometry Calculator and Function Analyzer.\n\n");
    printf("1. Sign In\n2. Sign Up\n3. Continue as Anon (calculation history will not be saved)\n4. Docs\n\n");
    printf("Enter the number before the options to operate the program: ");
    scanf("%d",&opts);
    while (opts > 4) {
        printf("INVALID OPTION!!\n");
        printf("Enter the number before the options to operate the program: ");
        scanf("%d",&opts);
    }

    if (opts == 1){
        in();

    if (opts == 2) {
        reg();
    }
	if (opts == 3) {
        wlc();
    }
    }

    if (opts == 1){
        in();
    }

    if (opts == 2) {
        reg();
    }
	if (opts == 3) {
        wlc();
    }
// sqrt(9); sqrt function doesnt work
}
