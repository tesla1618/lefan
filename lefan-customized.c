#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
// #include <ncurses.h>
// #include <windows.h>  //uncomment it if the program is being run on windows os

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

//    printf("You are sucessfully registered!!\n");
//    printf("Press any key to continue...\n");
    scanf("%c", &close);
    if (close == '\n') {
		system("clear");
     	wlc();
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
	//FILE *history;
    //history = fopen("calculation_history_universal.txt", "w");
    //fputs("User opened Distance between two points\n",history);
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
	    //fclose(history);
		system("clear");
		wlc();
	}
	if (choose == 0) {
        //fclose(history);
		system("clear");
		main();
	}
}

pol() {
    //FILE *history;
    //history = fopen("calculation_history_universal.txt", "w");
    //fputs("User opened Cartesian to Polar Conversion\n",history);
	double x,y,theta=0,r=0;
    double pi = 3.1416, k = 0, k2 = 0, b = 0.596227,s3=0,sqrt=0,hor=0,lob=0;
    int choose;

	printf("\n========================================\n");
	printf("Cartesian to Polar Conversion");
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
        //fclose(history);
		pol();
	}
	if (choose == 2) {
        //fclose(history);
		system("clear");
		wlc();
	}
	if (choose == 0) {
        //fclose(history);
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



ntgrate () {
    int a=0,b=0,c=0,d,e,mp,n,var,terms,i,j;
    char chars, sign1, sign2,sign,sign3,sign4,sign5,sign6,sign7,sign8,sign9,sign10,sign11;
    char powr;
    printf("\n\033[35m\t\e[1mArea binded by limit under a curve\033[0m\e[0m\n");
    printf("\n");
    printf("\tEnter the power (n) of x (x^n): ");
    scanf("%d",&mp);
    terms = mp+1;
    int ara[terms],cont;
    printf("\tEnter %d Constant value with x (if no, enter 1): ");
    scanf("%d",&cont);



    printf("\n\t--------------------------\n");
            printf("\tThe Equation is y = %dx^%d\n", cont,mp);
            printf("\t--------------------------\n");
            printf("\tINTEGRATION of Y:\n");
            printf("\t--------------------------\n");
            printf("\tint(y) dx = (%d/%d)*x^%d\n", cont,mp+1,mp+1);
            printf("\t--------------------------\n");

            /*
            int ul,ll;
            printf("Enter Upper Limit and Lower Limit: ");
            scanf("%d %d",&ul,&ll);
            double area=0,div,vx=0,vu=0,vl=0;
            div = cont/mp+1;
            for (int i = 1; i <= ul; i++) {
                vu = vu*vu;
            }
            for (int i = 1; i <= ll; i++) {
                vl = vl*vl;
            }
            vx = powr(vu,mp+1)
            vx = vu-vl;
            area = div*vx;
            printf("Area binded by (%d , %d) is %.3lf\n",ul,ll,area);

            */

            printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n");
    int choose;
    scanf("%d",&choose);

    if (choose == 1) {
        system("clear");
        ntgrate();
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

    int a=0,b=0,c=0,d,e,mp,n,var,terms,i,j;
    char chars, sign1, sign2,sign,sign3,sign4,sign5,sign6,sign7,sign8,sign9,sign10,sign11;
    char powr;
    printf("\n\033[35m\t\e[1mDifferentiate a Function\033[0m\e[0m\n");
    printf("\tA function is defined as follows ax^n+bx^(n-1)+cx^(n-2)....+z\n");
    printf("\n");
    printf("\tEnter MAX power (n) of x (x^n): ");
    scanf("%d",&mp);
    terms = mp+1;
    int ara[terms];
    printf("\tEnter %d Constant values:\n", terms);
    for (n = 1, chars = 'a'; n<=terms &&  chars <= 'z'; n++, ++chars) {
        printf("\t %c: ",chars);
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
    if ( ara[4] >= 0 ) {
        sign3 = '+';
    }
    if ( ara[4] < 0 ){
        sign3 = '-';
        ara[4] = -ara[4];
    }
    if ( ara[5] >= 0 ) {
        sign4 = '+';
    }
    if ( ara[5] < 0 ){
        sign4 = '-';
        ara[5] = -ara[5];
    }
    if ( ara[6] >= 0 ) {
        sign5 = '+';
    }
    if ( ara[6] < 0 ){
        sign5 = '-';
        ara[6] = -ara[6];
    }
    if ( ara[4] >= 0 ) {
        sign6 = '+';
    }
    if ( ara[7] < 0 ){
        sign6 = '-';
        ara[7] = -ara[7];
    }
    if ( ara[8] >= 0 ) {
        sign7 = '+';
    }
    if ( ara[8] < 0 ){
        sign7 = '-';
        ara[8] = -ara[8];
    }
    if ( ara[9] >= 0 ) {
        sign8 = '+';
    }
    if ( ara[9] < 0 ){
        sign8 = '-';
        ara[9] = -ara[9];
    }
    if ( ara[10] >= 0 ) {
        sign9 = '+';
    }
    if ( ara[10] < 0 ){
        sign9 = '-';
        ara[10] = -ara[10];
    }
    if ( ara[11] >= 0 ) {
        sign10 = '+';
    }
    if ( ara[11] < 0 ){
        sign10 = '-';
        ara[11] = -ara[11];
    }
    printf("\n\t--------------------------\n");
    if ( mp == 1) {
            printf("\tThe Equation is y = %dx %c %d\n", ara[1], sign, ara[2]);
            printf("\t--------------------------\n");
            printf("\n\tDIFFERENTIATION of Y:\n");
            printf("--------------------------\n");
            a = ara[1]*mp;
            printf("\tdy/dx = %d\n", a);
            printf("\t--------------------------\n");
            }
    if(mp == 2){
            printf("\tThe Equation is y = %dx^%d %c %dx %c %d\n", ara[1],mp,sign,ara[2],sign2,ara[3]);

            printf("\t--------------------------\n");
            printf("\tDIFFERENTIATION of Y:\n");
            printf("\t--------------------------\n");
            a = ara[1]*mp;
            b = ara[2];
            printf("\tdy/dx = %dx %c %d\n", a,sign,b);
            printf("\t--------------------------\n");
    }

    if (mp == 3) {
            printf("\tThe Equation is y = %dx^%d %c %dx^%d %c %dx %c %d\n", ara[1],mp,sign,ara[2],(mp-1),sign2,ara[3], sign3, ara[4]);
            printf("\t--------------------------\n");
            printf("\tDIFFERENTIATION of Y:\n");
            printf("\t--------------------------\n");
            a = ara[1]*mp;
            b = ara[2];
            printf("\tdy/dx = %dx^2 %c %dx %c %d\n", a,sign,2*b,sign2,ara[3]);
            printf("\t--------------------------\n");
    }
    if (mp == 4) {
            printf("\tThe Equation is y = %dx^4 %c %dx^3 %c %dx^2 %c %dx %c %d\n", ara[1],sign,ara[2],sign2,ara[3], sign3, ara[4], sign4, ara[5]);
            printf("\t--------------------------\n");
            printf("\tDIFFERENTIATION of Y:\n");
            printf("\t--------------------------\n");
            a = ara[1]*mp;
            b = ara[2];
            printf("\tdy/dx = %dx^3 %c %dx^2 %c %dx %c %d\n", 4*ara[1],sign,3*ara[2],sign2,2*ara[3],sign3,ara[4]);
            printf("\t--------------------------\n");
    }
    if (mp == 5) {
            printf("\tThe Equation is y = %dx^5 %c %dx^4 %c %dx^3 %c %dx^2 %c %dx %c %d\n", ara[1],sign,ara[2],sign2,ara[3], sign3, ara[4], sign4, ara[5],sign5,ara[6]);
            printf("\t--------------------------\n");
            printf("\tDIFFERENTIATION of Y:\n");
            printf("\t--------------------------\n");
            printf("\tdy/dx = %dx^4 %c %dx^3 %c %dx^2 %c %dx %c %d\n", 5*ara[1],sign,4*ara[2],sign2,3*ara[3],sign3,2*ara[4],sign4,ara[5]);
            printf("\t--------------------------\n");
    }
    if (mp == 6) {
            printf("\tThe Equation is y = %dx^6 %c %dx^5 %c %dx^4 %c %dx^3 %c %dx^2 %c %dx %c %d\n", ara[1],sign,ara[2],sign2,ara[3], sign3, ara[4], sign4, ara[5],sign5,ara[6],sign6,ara[7]);
            printf("\t--------------------------\n");
            printf("\tDIFFERENTIATION of Y:\n");
            printf("\t--------------------------\n");
            printf("\tdy/dx = %dx^5 %c %dx^4 %c %dx^3 %c %dx^2 %c %dx %c %d\n", 6*ara[1],sign,5*ara[2],sign2,4*ara[3],sign3,3*ara[4],sign4,2*ara[5],sign5,ara[6]);
            printf("\t--------------------------\n");
    }
    if (mp == 7) {
            printf("\tThe Equation is y = %dx^7 %c %dx^6 %c %dx^5 %c %dx^4 %c %dx^3 %c %dx^2 %c %dx %c %d\n", ara[1],sign,ara[2],sign2,ara[3], sign3, ara[4], sign4, ara[5],sign5,ara[6],sign6,ara[7],sign7,ara[8]);
            printf("\t--------------------------\n");
            printf("\tDIFFERENTIATION of Y:\n");
            printf("\t--------------------------\n");
            printf("\tdy/dx = %dx^6 %c %dx^5 %c %dx^4 %c %dx^3 %c %dx^2 %c %dx %c %d\n", 7*ara[1],sign,6*ara[2],sign2,5*ara[3],sign3,4*ara[4],sign4,3*ara[5],sign5,2*ara[6],sign6,ara[7]);
            printf("\t--------------------------\n");
    }
    if (mp == 8) {
            printf("\tThe Equation is y = %dx^8 %c %dx^7 %c %dx^6 %c %dx^5 %c %dx^4 %c %dx^3 %c %dx^2 %c %dx %c %d\n", ara[1],sign,ara[2],sign2,ara[3], sign3, ara[4], sign4, ara[5],sign5,ara[6],sign6,ara[7],sign7,ara[8],sign8,ara[9]);
            printf("\t--------------------------\n");
            printf("\tDIFFERENTIATION of Y:\n");
            printf("\t--------------------------\n");
            printf("\tdy/dx = %dx^7 %c %dx^6 %c %dx^5 %c %dx^4 %c %dx^3 %c %dx^2 %c %dx %c %d\n", 8*ara[1],sign,7*ara[2],sign2,6*ara[3],sign3,5*ara[4],sign4,4*ara[5],sign5,3*ara[6],sign6,2*ara[7],sign7,ara[8]);
    }
    if (mp == 9) {
            printf("\tThe Equation is y = %dx^9 %c %dx^8 %c %dx^7 %c %dx^6 %c %dx^5 %c %dx^4 %c %dx^3 %c %dx^2 %c %dx %c %d\n", ara[1],sign,ara[2],sign2,ara[3], sign3, ara[4], sign4, ara[5],sign5,ara[6],sign6,ara[7],sign7,ara[8],sign8,ara[9],sign9,ara[10]);
            printf("\t--------------------------\n");
            printf("\tDIFFERENTIATION of Y:\n");
            printf("\t--------------------------\n");
            printf("\tdy/dx = %dx^8 %c %dx^7 %c %dx^6 %c %dx^5 %c %dx^4 %c %dx^3 %c %dx^2 %c %dx %c %d\n", 9*ara[1],sign,8*ara[2],sign2,7*ara[3],sign3,6*ara[4],sign4,5*ara[5],sign5,4*ara[6],sign6,3*ara[7],sign7,2*ara[8],sign8,ara[9]);
    }
    if (mp == 10) {
            printf("\tThe Equation is y = %dx^10 %c %dx^9 %c %dx^8 %c %dx^7 %c %dx^6 %c %dx^5 %c %dx^4 %c %dx^3 %c %dx^2 %c %dx %c %d\n", ara[1],sign,ara[2],sign2,ara[3], sign3, ara[4], sign4, ara[5],sign5,ara[6],sign6,ara[7],sign7,ara[8],sign8,ara[9],sign9,ara[10],sign10,ara[11]);
            printf("\t--------------------------\n");
            printf("\tDIFFERENTIATION of Y:\n");
            printf("\t--------------------------\n");
            printf("\tdy/dx = %dx^9 %c %dx^8 %c %dx^7 %c %dx^6 %c %dx^5 %c %dx^4 %c %dx^3 %c %dx^2 %c %dx %c %d\n", 10*ara[1],sign,9*ara[2],sign2,8*ara[3],sign3,7*ara[4],sign4,6*ara[5],sign5,5*ara[6],sign6,4*ara[7],sign7,3*ara[8],sign8,2*ara[9],sign9,ara[10]);
    }

    int choose;
	printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out/exit\n");

	scanf("%d",&choose);

	if (choose == 1) {
        system("clear");
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




isect() {
    double a1,b1,c1,a2,b2,c2,x1=0,y1=0,d=0,xx=0,yy=0;
    printf("Enter constant values for a1,b1,c1 respectively: ");
    scanf("%lf %lf %lf",&a1,&b1,&c1);
    printf("\n");
    printf("Enter constant values for a2,b2,c2 respectively: ");
    scanf("%lf %lf %lf",&a2,&b2,&c2);
    printf("\n");
    printf("The equation of the straight line (1) is: %.1lfx%+-.1lfy%+-.1lf = 0\n",a1,b1,c1);
    printf("The equation of the straight line (2) is: %.1lfx%+-.1lfy%+-.1lf = 0\n",a2,b2,c2);
    d = (a1*b2)-(b1*a2);
    if (d > 0) {
        xx = (b1*c2)-(b2*c1);
        yy = (c1*a2)-(c2*a1);
        x1 = xx/d;
        y1 = yy/d;
        printf("Intersect Point: (%.1lf , %.1lf)\n",x1,y1);
    }
    else printf("The Lines are parallel to each other, hence there is no Intersect point\n");


     printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out\n");
    int choose;
    scanf("%d",&choose);

    if (choose == 1) {
        isect();
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

dis_st () {

    int a1,b1,c1,a2,b2,c2;
    double x1=0,y1=0,d=0,xx=0,yy=0,i,a=0,ax=0,b=0,bx=0,cc=0,ab,k,sqrt,m=0,m2=0,m12=0,mm=0;
    printf("Enter constant values for a1,b1,c1 respectively: ");
    scanf("%d %d %d",&a1,&b1,&c1);
    printf("\n");
    printf("Enter constant values for a2,b2,c2 respectively: ");
    scanf("%d %d %d",&a2,&b2,&c2);
    printf("\n");
    printf("The equation of the straight line (1) is: %dx%+-dy%+-d = 0\n",a1,b1,c1);
    printf("The equation of the straight line (2) is: %dx%+-dy%+-d = 0\n",a2,b2,c2);

    if (a1 <0) a1 = (-1)*a1;
    if (a2 <0) a2 = (-1)*a2;
    if (b1 <0) b1 = (-1)*b1;
    if (b2 <0) b2 = (-1)*b2;

    //METHOD 1

    if (a1==a2 && b1 == b2){
        a = a1;
        b = b1;

        cc = c1-c2;
    ab = (a*a)+(b*b);

    sqrt = ab/2;
	double temp = 0;
    while(sqrt != temp){
        temp = sqrt;
        sqrt = ( ab/temp + temp) / 2;
    }

    if (cc <0 ) cc = (-1)*cc;
    d = cc / sqrt;
    printf("\nDistance: %.3lf units\n",d);
    }

   if (a1 != a2 && b1 != b2){
    for (i = 1; ; i++) {

        if (a2>a1 && b2 >b1 && c2>c1){
            if (a2/i == a1 && b2/i == b1) {
                a = a1;
                b = b1;
                c2 = c2/i;
            }
        if (a2/i == a1 || b2/i == b1) break;
        }
        if (a1>a2 && b1>b2 && c1>c2){
            if (a1/i == a2 && b1/i == b2) {
                a = a2;
                b = b2;
                c1 = c1/i;
            }
        if (a1/i == a2 || b1/i == b2) break;

        }


    }

    cc = c1-c2;
    ab = (a*a)+(b*b);

    sqrt = ab/2;
	double temp = 0;
    while(sqrt != temp){
        temp = sqrt;
        sqrt = ( ab/temp + temp) / 2;
    }

    if (cc <0 ) cc = (-1)*cc;
    d = cc / sqrt;
    printf("\nDistance: %.3lf units\n",d);
    }

   /* if (a1 > a2) {
        if (a1%a2 == 0) a = a2;
        if (b1 > b2) {
        if (b1%b2 == 0) b = b2;
    }
    }
    if (a2 > a1) {
        if (a2%a1 == 0) a = a1;
        if (b2 > b1) {
        if (b2%b1 == 0) b = b1;
    }
    } */


/*
    // METHOD 2

    m = 1/a1;
    m2 = m*m;
    mm= 1+m2;
    sqrt = mm/2;
	double temp = 0;
    while(sqrt != temp){
        temp = sqrt;
        sqrt = ( mmm/temp + temp) / 2;
    }

    cc = (c1/-c2;
    if (cc <0 ) cc = (-1)*cc;
    d = cc / sqrt;

    printf("\nDistance: %.3lf units\n",sqrt);
*/

 printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out\n");
int choose;
    scanf("%d",&choose);

    if (choose == 1) {
        dis_st();
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

maxima() {

    double a,b,c,x=0,y=0;
    printf("Enter the values of a, b, c respectively: ");
    scanf("%lf %lf %lf",&a,&b,&c);
    printf("The function is y = %.1lfx^2%+-.1lfx%+-.1lf", a,b,c);
    if ( a >0 ){
            x = ((-1)*b)/(2*a);
            y = (a*(x*x))+(b*x)+c;

        printf("\n\nThe above function has minima value.\nThe minima coordinates are (%.3lf , %.3lf)",x,y);
    }
    else {
        x = ((-1)*b)/(2*a);
            y = (a*(x*x))+(b*x)+c;
            printf("\n\nThe above function has maxima value.\nThe maxima coordinates are (%.3lf , %.3lf)",x,y);
    }

    printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out\n");
int choose;
    scanf("%d",&choose);

    if (choose == 1) {
        maxima();
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

        if (rem_blnc <= 0 || pricedata[i+1] >= rem_blnc) {
            printf("\033[31m\nBUDGET EXCEEDED OR NO INVESTMENT LEFT\n\n");
            break;
            }
            else {
                tot++;
                printf("\033[35mRemaining Balance: %.2lf\n", rem_blnc);
            }

    }
    int tot1=0;
    if (rem_blnc == 0 ) tot1 = tot+1;
    else tot1 = tot;
    printf("\033[0m------------------------------------------\n");
    for (i = 1; i<= tot1; i++) {
        ivst = pricedata[i]*product_count[i];
        printf("\033[0mPrice of product %d is %.2lf\n", i, pricedata[i]);
        printf("\033[0mQuantity of product %d is %d\n", i, product_count[i]);
        printf("\033[0mTotal Price of product %d is %.2lf\n", i, ivst);
        printf("\033[0m------------------------------------------\n");
        invested_1 += ivst;
        if (pricedata[i] == 0) break;
    }
    printf("\033[32mTotal Invested: %.2lf\n", invested_1);

    printf("\033[0m=========================================\n\n");
    printf("\033[0mHow much profit do you want? ");
    scanf("%lf", &profit);
    pro_sim = profit/100;
    sell_price = invested_1 + (invested_1*pro_sim);
    printf("\n\033[0m------------------------------------------\n");
    printf("\n\033[33mTotal Selling Price should be: %.2lf\n", sell_price);
    printf("\n\033[0m------------------------------------------\n");
    double dsp = 0, dsp1 = 0;
    dsp = sell_price-invested_1;
    dsp1 = dsp/tot1;
    for (i = 1; i<= tot1; i++) {
        printf("\033[0mSell the product %d for %.2lf\n", i, (pricedata[i]*pro_sim)+pricedata[i]);
        printf("\033[0m------------------------------------------\n");
        //if (pricedata[i] == 0) break;
    }


    // it took a good amount of calculation

    printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out\n");
int choose;
    scanf("%d",&choose);

    if (choose == 1) {
            system("clear");
        invelyz();
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



pdig() {

    double price,oprice,pdiff;
    int a,b,c,d,e,f,g,h,i,j,k,l;

    printf("\n\tWelcome to Profit Diagram");
    printf("\n\tIf you are running a shop and you have some good amount of\n\tcompetitors around you, calculate the\n\tprobability if you can attract more customers\n\tby your servuce!\n");

    printf("\n\tEnter the price of your most iconic product: ");
    scanf("%lf", &price);
    printf("\n\n\tEnter 1 if yes/true and 0 if no/false:");
    printf("\n\tIs there any other shop selling this product? ");
    scanf("%d",&a);
    if (a >0 ){
    printf("\n\tWhats the price of the product they are selling for? ");
    scanf("%lf",&oprice);
    printf("\n\tDo they provide any warranty/after sales service? ");
    scanf("%d",&b);
    printf("\n\tDo you provide any warranty/after sales service? ");
    scanf("%d",&c);
    printf("\n\tAre they providing any offers with the product? ");
    scanf("%d",&d);
    printf("\n\tAre you providing any offers with the product? ");
    scanf("%d",&e);
    printf("\n\tWhich shop is more organized and\n\tconsumer friendly? ");
    printf("Type 1 if yours, 0 if theirs\n");
    scanf("%d",&f);
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
    printf("\tYou will Attract %d percent of customers!\n",sum);
    }
    else {
        printf("\n\tYou are the only player in the field, Play as you like!!\n");
    }


    printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out\n");
int choose;
    scanf("%d",&choose);

    if (choose == 1) {
            system("clear");
        pdig();
    }
    if (choose == 2) {
        system("clear");
        wlc();
    }
    if (choose == 0) {
        system("clear");
        main();
    }



    printf("\n");

}




landing() {
    int ch;
    printf("\n\n\t\t\033[36mWelcome to Analysis of Functions and Linear Equations\033[0m\n\n");
	printf("\t** This program is designed to calculate mathematical expressions\n\tand analyzing mathematical functions.\n\n");

	printf("\tThe number before each option is the number you have to input\n\tin order to select.\n\t\e[3m(If you want to continue to Menu page, press 1 and\n\thit enter.)\n\n");
	printf("\e[0m\n\t---------------------------------------\n\n\n");
	printf("\n\t\t[1] I Understand and continue\n\t\t[2] Read full Documentation\n\t\t[0] Log out / Exit\n");
	printf("\t\t");scanf("%d", &ch);
	if ( ch == 1) {
            system("clear");
            wlcanon();
            }
	if (ch == 2) {
            system("clear");
            dis_1();
            }
	if (ch == 0) {
            system("clear");
            main();
            }
}

wlc() {

    char sentence[1000];
    FILE *history;
    history = fopen("calculation_history_universal.txt", "w");
	int opr;
	printf("\n\t----------------\n\t      Menu\n\t----------------\n\n");
	printf("\033[35m\t\e[1mCoordinate Geometry\033[0m\e[0m\n");
	printf("\t\033[35m\e[1m[1]\033[0m\e[0m  Distance between two points\n");
	printf("\t\033[35m\e[1m[2]\033[0m\e[0m  Polar to Cartesian Conversion\n");
	printf("\t\033[35m\e[1m[3]\033[0m\e[0m  Quadrant of a Coordinate\n");
	printf("\t\033[35m\e[1m[4]\033[0m\e[0m  Mirror of a point\n");
	printf("\t\033[35m\e[1m[5]\033[0m\e[0m  Distance of a Coordinate from O(0,0)\n");
	printf("\t\033[35m\e[1m[6]\033[0m\e[0m  Angle made by the point with respect to x & y axis.\n");
	printf("\n\n\033[36m\t\e[1mStraight Lines\033[0m\e[0m\n");
	printf("\t\033[36m\e[1m[7]\033[0m\e[0m  St. Line Equation Generator\n");
	printf("\t\033[36m\e[1m[8]\033[0m\e[0m  Distance between two st. lines\n");
	printf("\t\033[36m\e[1m[9]\033[0m\e[0m  Slope of a st. Line\n");
	printf("\t\033[36m\e[1m[10]\033[0m\e[0m Intersect Point of two st. lines\n");
	printf("\n\n\033[33m\t\e[1mCurves Analysis\033[0m\e[0m\n");
	printf("\t\033[33m\e[1m[11]\033[0m\e[0m  Maxima & Minima of a Function\n");
	printf("\t\033[33m\e[1m[12]\033[0m\e[0m  Differentiation of a Function\n");
	printf("\t\033[33m\e[1m[13]\033[0m\e[0m  Area of a Function binded by x=a,y=b\n");
	printf("\n\n\033[32m\t\e[1mBusiness Analysis\033[0m\e[0m\n");
	printf("\t\033[32m\e[1m[14]\033[0m\e[0m  Invest Analysis\n");
	printf("\t\033[32m\e[1m[15]\033[0m\e[0m  Profit Diagram\n");
	printf("\n\n");
	printf("\t\033[31m\e[1m[0]\033[0m\e[0m  Log Out / Exit\n\n");
    while ( opr > 15) {
	printf("\t---------------------\n\tChoose Operation: "); scanf("%d",&opr);
	printf("\r---------------------\n");
	if (opr > 15) {
		printf("\n\n\tINVALID OPERATION!!!\n\n");
		printf("\t---------------------\n\n\tChoose Operation: "); scanf("%d",&opr);
	printf("\t---------------------\n");

		if (opr == 0) {
		system("clear");
		main();
	}

		if (opr == 1) {
            fputs(history, "User opened Distance between two points\n");
            fclose(history);
			system("clear");
			dis_1();
		}
		if (opr == 2) {
            fputs(history, "User opened Cartesian to Polar Conversion\n");
            fclose(history);
			system("clear");
			pol();
		}
		if (opr == 3) {
            fputs(history, "User opened Quadrant of a point\n");
            fclose(history);
			system("clear");
			qua();
		}
		if (opr == 4) {
		    fputs(history, "User opened Mirror of a point\n");
            fclose(history);
			system("clear");
			mircor();
		}
		if (opr == 5) {
		    fputs(history, "User opened Distance of a point from Origin\n");
            fclose(history);
			system("clear");
			dis_2();
		}
		if (opr == 6) {
		    fputs(history, "User opened Angle made by points\n");
            fclose(history);
			system("clear");
			angle();
		}
		if (opr == 7) {
		    fputs(history, "User opened Straight line equation generator\n");
            fclose(history);
			system("clear");
			eqgen();
		}
		if (opr == 8) {
		    fputs(history, "User opened Distance between two parallel straight lines\n");
            fclose(history);
			system("clear");
			dis_st();
		}
		if (opr == 9) {
		    fputs(history, "User opened Slope of a st line\n");
            fclose(history);
			system("clear");
			slopeq();
		}
		if (opr == 10) {
		    fputs(history, "User opened intersect points of st lines\n");
            fclose(history);
			system("clear");
			isect();
		}
		if (opr == 11) {
		    fputs(history, "User opened Maxima/Minima of a function\n");
            fclose(history);
			system("clear");
			maxima();
		}
		if (opr == 12) {
		    fputs(history, "User opened Profit diagram\n");
            fclose(history);
			system("clear");
			diff();
		}
		if (opr == 13) {
		    fputs(history, "User opened Integration of a Fucntion\n");
            fclose(history);
			system("clear");
			ntgrate();
		}
		if (opr == 14) {
		    fputs(history, "User opened Investment Analysis\n");
            fclose(history);
			system("clear");
			invelyz();
		}
		if (opr == 15) {
		    fputs(history, "User opened Differentiation of a Fucntion\n");
            fclose(history);
			system("clear");
			pdig();
		}
	}
	else {


            if (opr == 0) {
		system("clear");
		main();
            }


	if (opr == 1) {
            fputs(history, "User opened Distance between two points\n");
            fclose(history);
			system("clear");
			dis_1();
		}
		if (opr == 2) {
            fputs(history, "User opened Cartesian to Polar Conversion\n");
            fclose(history);
			system("clear");
			pol();
		}
		if (opr == 3) {
            fputs(history, "User opened Quadrant of a point\n");
            fclose(history);
			system("clear");
			qua();
		}
		if (opr == 4) {
		    fputs(history, "User opened Mirror of a point\n");
            fclose(history);
			system("clear");
			mircor();
		}
		if (opr == 5) {
		    fputs(history, "User opened Distance of a point from Origin\n");
            fclose(history);
			system("clear");
			dis_2();
		}
		if (opr == 6) {
		    fputs(history, "User opened Angle made by points\n");
            fclose(history);
			system("clear");
			angle();
		}
		if (opr == 7) {
		    fputs(history, "User opened Straight line equation generator\n");
            fclose(history);
			system("clear");
			eqgen();
		}
		if (opr == 8) {
		    fputs(history, "User opened Distance between two parallel straight lines\n");
            fclose(history);
			system("clear");
			dis_st();
		}
		if (opr == 9) {
		    fputs(history, "User opened Slope of a st line\n");
            fclose(history);
			system("clear");
			slopeq();
		}
		if (opr == 10) {
		    fputs(history, "User opened intersect points of st lines\n");
            fclose(history);
			system("clear");
			isect();
		}
		if (opr == 11) {
		    fputs(history, "User opened Maxima/Minima of a function\n");
            fclose(history);
			system("clear");
			maxima();
		}
		if (opr == 12) {
		    fputs(history, "User opened Profit diagram\n");
            fclose(history);
			system("clear");
			diff();
		}
		if (opr == 13) {
		    fputs(history, "User opened Integration of a Fucntion\n");
            fclose(history);
			system("clear");
			ntgrate();
		}
		if (opr == 14) {
		    fputs(history, "User opened Investment Analysis\n");
            fclose(history);
			system("clear");
			invelyz();
		}
		if (opr == 15) {
		    fputs(history, "User opened Differentiation of a Fucntion\n");
            fclose(history);
			system("clear");
			pdig();
		}


	}
}

}

wlcanon() {


    char sentence[1000];
	int opr;
	printf("\n\t----------------\n\t      Menu\n\t----------------\n\n");
	printf("\033[35m\t\e[1mCoordinate Geometry\033[0m\e[0m\n");
	printf("\t\033[35m\e[1m[1]\033[0m\e[0m  Distance between two points\n");
	printf("\t\033[35m\e[1m[2]\033[0m\e[0m  Polar to Cartesian Conversion\n");
	printf("\t\033[35m\e[1m[3]\033[0m\e[0m  Quadrant of a Coordinate\n");
	printf("\t\033[35m\e[1m[4]\033[0m\e[0m  Mirror of a point\n");
	printf("\t\033[35m\e[1m[5]\033[0m\e[0m  Distance of a Coordinate from O(0,0)\n");
	printf("\t\033[35m\e[1m[6]\033[0m\e[0m  Angle made by the point with respect to x & y axis.\n");
	printf("\n\n\033[36m\t\e[1mStraight Lines\033[0m\e[0m\n");
	printf("\t\033[36m\e[1m[7]\033[0m\e[0m  St. Line Equation Generator\n");
	printf("\t\033[36m\e[1m[8]\033[0m\e[0m  Distance between two st. lines\n");
	printf("\t\033[36m\e[1m[9]\033[0m\e[0m  Slope of a st. Line\n");
	printf("\t\033[36m\e[1m[10]\033[0m\e[0m Intersect Point of two st. lines\n");
	printf("\n\n\033[33m\t\e[1mCurves Analysis\033[0m\e[0m\n");
	printf("\t\033[33m\e[1m[11]\033[0m\e[0m  Maxima & Minima of a Function\n");
	printf("\t\033[33m\e[1m[12]\033[0m\e[0m  Differentiation of a Function\n");
	printf("\t\033[33m\e[1m[13]\033[0m\e[0m  Area of a Function binded by x=a,y=b\n");
	printf("\n\n\033[32m\t\e[1mBusiness Analysis\033[0m\e[0m\n");
	printf("\t\033[32m\e[1m[14]\033[0m\e[0m  Invest Analysis\n");
	printf("\t\033[32m\e[1m[15]\033[0m\e[0m  Profit Diagram\n");
	printf("\n\n");
	printf("\t\033[31m\e[1m[0]\033[0m\e[0m  Log Out / Exit\n\n");
    while ( opr > 15) {
	printf("\t---------------------\n\tChoose Operation: "); scanf("%d",&opr);
	printf("\r---------------------\n");
	if (opr > 15) {
		printf("\n\n\tINVALID OPERATION!!!\n\n");
		printf("\t---------------------\n\n\tChoose Operation: "); scanf("%d",&opr);
	printf("\t---------------------\n");

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
		if (opr == 8) {
			system("clear");
			dis_st();
		}
		if (opr == 9) {
			system("clear");
			slopeq();
		}
		if (opr == 10) {
			system("clear");
			isect();
		}
		if (opr == 11) {
			system("clear");
			maxima();
		}
		if (opr == 12) {
			system("clear");
			diff();
		}
		if (opr == 13) {
			system("clear");
			ntgrate();
		}
		if (opr == 14) {
			system("clear");
			invelyz();
		}
		if (opr == 15) {
			system("clear");
			pdig();
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
		if (opr == 8) {
			system("clear");
			dis_st();
		}
		if (opr == 9) {
			system("clear");
			slopeq();
		}
		if (opr == 10) {
			system("clear");
			isect();
		}
		if (opr == 11) {
			system("clear");
			maxima();
		}
		if (opr == 12) {
			system("clear");
			diff();
		}
		if (opr == 13) {
			system("clear");
			ntgrate();
		}
		if (opr == 14) {
			system("clear");
			invelyz();
		}
		if (opr == 15) {
			system("clear");
			pdig();
		}

	}
}

}


docs() {

    printf("\n\033[35m\t\e[1mRead Me\033[0m\e[0m\n");
    printf("\t\033[35m______________________________\033[0m\n\n");
    printf("\n\033[35m\t\e[1mIntro\033[0m\e[0m\n");
    printf("\tHello user, Thank you for using \e[1mLinear Equations & Function Analysis\e[0m\n");
    printf("\tThis is a simple calculator that solves maths related to both\n\tLinear and Continious Functions. Since the");
    printf(" beginnig of the\n\tjourney of our programming, we have been thinking of some ways\n\tto integrate programming with mathematics. We asked ");
    printf("our course\n\tinstructors about it and later found out that programming and\n");
    printf("\tMathematics are interconnected. So we started studying more about\n\tprogramming and started to solve problems on online platforms.\n\tAnd later by getting ");
    printf("motivated by our CSE100 course instructor,\n\thonorable \e[1mMuhammad Mohsin Kabir\e[0m, We chose this very fun project.\n");
    printf("\n");
    printf("\n");
    printf("\n");

}
// printf("\n");

int main() {
    int opts;
    char close;
    printf("\n\n\t\t\t\t=============\n\t\t\t\t    \e[1mLEFAN\e[0m\n\t\t\t\t=============\n\n");
    printf("\n\tHey \033[32mAnon\033[0m, Welcome to Linear Equations and Function Analysis!\n\tA coordinate geometry Calculator and Function Analyzer.\n\n");
    printf("\t   \033[36m[1] Sign in\n\t   [2] Sign up\n\t   [3] Continue as \033[32mAnon\033[36m (calculation history will not be saved)\n\t   [4] Docs\033[0m\n\n");
    printf("\tEnter the \e[1mnumber \e[0mbefore the options to operate the program: ");
    scanf("%d",&opts);
    while (opts > 4) {
        printf("INVALID OPTION!!\n");
        printf("Enter the number before the options to operate the program: ");
        scanf("%d",&opts);
    }

    if (opts == 1){
        system("clear");
        in();

    if (opts == 2) {
        system("clear");
        reg();
    }
	if (opts == 3) {
	    system("clear");
        landing();
    }
    if (opts == 4) {
	    system("clear");
        docs();
    }
    }

    if (opts == 1){
        system("clear");
        in();
    }

    if (opts == 2) {
        system("clear");
        reg();
    }
	if (opts == 3) {
	    system("clear");
        landing();
    }
    if (opts == 4) {
	    system("clear");
        docs();
    }
// sqrt(9); sqrt function doesnt work
}
