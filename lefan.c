#include <stdio.h>
#include <stdlib.h>
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
	printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out\n");
	
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

	printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out\n");
	
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
	printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out\n");
	
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
	printf("\nPress 1 to Calculate another, 2 to go back to options page and 0 to log out\n");
	
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
	printf("0. Log Out\n\n");
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
		if (opr == 4) {
			system("clear");
			mircor();
		}
		if (opr == 7) {
			system("clear");
			eqgen();
		}
	}
	else {


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
		if (opr == 4) {
			system("clear");
			mircor();
		}
		if (opr == 7) {
			system("clear");
			eqgen();
		}

	}
}
}





int main() {
    int opts;
    char close;
    printf("Press 1 to Sign in and 2 to Sign up\n");
    scanf("%d",&opts);

    if (opts == 1){
        in();
    }

    if (opts == 2) {
        reg();
    }
// sqrt(9); sqrt function doesnt work
}
