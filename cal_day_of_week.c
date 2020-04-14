// This program can take a date format like 2-aug-2020 etc and tell the exact day of week like monday,tuesday etc on that day ...

#include<stdio.h>
#include<stdlib.h>
#include<string.h>	
#include<unistd.h>

// Terminal color codes ...

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

// codes for making terminal font BOLD

#define BOLDRED     "\033[1m\033[31m"   
#define BOLDGREEN   "\033[1m\033[32m" 

// Resetting the terminal colors and font to as original ...
#define RESET   "\033[0m"

// Month_ codes
# define jan  0
# define feb  3
# define mar  3
# define apr  6
# define may  1
# define jun  4
# define jul  6
# define aug  2
# define sep  5
# define oct  0
# define nov  3
# define dec  5

// Function prototypes ...

void caldayofmonth(char[]);
void calweekdayafterspecified(char*, int);
void loadingCursor();


	// Temp variable to split the date into day - month - year and store it locally 	
	char day[3];
	char month[4];
	char year[5];
	int counter = 0;


// Entry point Function ....	
int main(void){


	int choice;
	char date[20];
	char con;
	int interval;

	do{
		printf(KCYN"MENU : >");
		printf(KBLU"\n\n\t1} TYPE I : Find day of week from DD-MM-YYYY (i.e 10-aug-2010) ?");
		printf("\n\t2} TYPE III : Find weekday from previously given weekday (i.e monday) ?");
		printf("\n\t3} Exit now !");
		printf(KGRN"\n\n\tPlease select one option :");

		scanf("%d", &choice);

		printf(BOLDRED"\n\t\tALL THE DAY, MONTH FORMAT ARE IN THREE LETTER WORDS \n\t\te.g. tue,thu,sat | jan,mar,jul"RESET);

		if (choice >= 1 && choice <= 3){

			
			switch(choice){

				case 1:	printf(KCYN"\n|\n|--------You have selected Type I : welcome");
					printf("\n|--------Please enter a day as specified : 10-aug-2000\n\t\t>"KGRN);
					scanf("%s",date);
					caldayofmonth(date);	
					break;
				case 2:	printf(KCYN"\n|\n|--------You have selected Type II : welcome");
					printf("\n\tPlease enter a day as specified : tue\n|\t-------->"KGRN);
					scanf("%s",date);
					printf(KCYN"\n\tPlease enter interval : 2134\n|\n|\t-------->"KGRN);
					scanf("%d",&interval);
					calweekdayafterspecified(date, interval);	
					break;
				case 3: printf(KGRN"\n|\n|--------You have selected Type III : Good bye exiting Now ... "RESET);
					exit(0);
					
					break;
			}
		}else{
			printf(BOLDRED"\n\t\tChoice should be 1 - 2 - 3 - 4 only, Please try again ?"RESET);
		}

		printf(BOLDRED"\n|\n|----------------WANT TO TRY AGAIN PRESS Y or y :"RESET);
		//scanf("%c", &con);
	}while(((con = getchar()) == 'Y') || ((con = getchar()) == 'y'));
}

/**
 * 
 * function name : splitdate()
 * 
 * in parameters : date - char*
 * out parameters : nothing - void
 * 
 * desc : This function takes a date format like 23-aug-1999 and tokenises it in day, month, year ...
 * 		  and stores the day, month, year inside the global character arrays ...
 * 
 * in calls : nothing PURE LOGIC :)
 * 
 */ 


void splitdate(char* date){


	// Variables for traversing the temporary variable to store day - month - year
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;

	// While loop for spliting the string of Date into day - month - year ...
	while( date[i] != '\0'){

		if (date[i] == '-')
			counter ++;

		if (date[i] == '-'){
			i++;
			continue;
		}

		if (counter == 0)
			day[j++] = date[i];
		else if (counter == 1)
			month[k++] = date[i];
		else
			year[l++] = date[i];

		i++;
	}

	// Terminating the copied string with null characters...
	day[j] = '\0';
	month[k] = '\0';
	year[l] = '\0';

	if((atoi(day)>=1 && atoi(day)<=31) && (strcmp(month,"jan")==0 || strcmp(month,"mar")==0 || 
		strcmp(month,"may")==0 || strcmp(month,"jul")==0 || strcmp(month,"aug")==0 || strcmp(month,"oct")==0 || 
		strcmp(month,"dec")==0))

                printf(KCYN"\n\t--------Date is valid.\n");
            else if((atoi(day)>=1 && atoi(day)<=30) && (strcmp(month,"apr")==0 || strcmp(month,"jun")==0 || 
				strcmp(month,"sep")==0 || strcmp(month,"nov")==0))
                printf(KCYN"\n\t--------Date is valid.\n");
            else if((atoi(day)>=1 && atoi(day)<=28) && (strcmp(month,"feb")==0))
                printf(KCYN"\n\t--------Date is valid.\n");
            else if(atoi(day)==29 && strcmp(month,"feb")==0 && (atoi(year)%400==0 ||(atoi(year)%4==0 && atoi(year)%100!=0)))
                printf(KCYN"\n\t--------Date is valid.\n");
            else{
                printf(BOLDRED"\n\n\t--------Day is invalid.\n");
				exit(0);
			}

}

void loadingCursor() {

		printf("\nLoading ...  ");
        int j = 0;
        while (j < 3) {
            for (int i = 0; i < 3; i++) {

                

                    int g = 0;
					while (g < 30000)
						g++;

                    if (i == 0)
                        printf(BOLDRED"\r-");
                    else if (i == 1)
                        printf(BOLDRED"\r\\");
                    else if (i == 2)
                        printf(BOLDRED"\r|");
                    else
                        printf(BOLDRED"\r/");

                

            }
            j++;
        }

        printf("\n");
    }

/*
* function name : getmcode()
* 
* in parameters : month - char*
* out parameters : month_code - int
*
* in calls : strcmp()
* 
* desc : this function takes year as int and returns back the month code which futher 
*		 will be used ...
*
*/

int getmcode(char* month){

	if(strcmp(month,"jan")==0)
		return jan;
	else if(strcmp(month,"feb")==0)
		return feb;
	else if(strcmp(month,"mar")==0)
		return mar;
	else if(strcmp(month,"apr")==0)
		return apr;
	else if(strcmp(month,"may")==0)
		return may;
	else if(strcmp(month,"jun")==0)
		return jun;
	else if(strcmp(month,"jul")==0)
		return jul;
	else if(strcmp(month,"aug")==0)
		return aug;
	else if(strcmp(month,"sep")==0)
		return sep;
	else if(strcmp(month,"oct")==0)
		return oct;
	else if(strcmp(month,"nov")==0)
		return nov;
	else
		return dec;
}

/**
 *
 * function name : getdayfromtypeone()
 * 
 * in parameters : day - int
 * out parameters : day - char*
 * 
 * desc : This function returns the day from the index specified
 *  
 */

char* getdayfromtypeone(int day){

	char *days[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursdat","Friday","Saturday"};
	return days[day];	
}

/*
* function name : getycode()
* 
* in parameters : year - int
* out parameters : year_code - int
* 
* desc : this function takes year as int and returns back the year code which futher 
*		 will be used ...
*
*/

int getycode(int year){

	if (year >= 1600 && year <= 1699)
		return 6;
	else if (year >= 1700 && year <= 1799)
		return 4;
	else if (year >= 1800 && year <= 1899)
		return 2;
	else if (year >= 1900 && year <= 1999)
		return 0;
	else if (year >= 2000 && year <= 2099)
		return 6;
	else{
		printf(BOLDRED"\n\n\t\tWRONG YEAR ENTERED : YEAR MUST BE BETWEEN 1600 --> 2099 "RESET);
		return -1;
	}	
}



/*
 * function name : caldayofmonth
 * in parameters : date format - string
 * out parameters : nothing - void
 *
 * desc : This function calculates the day of week i.e. sunday, monday, Tuesday, Wednesday etc...
 * from the Date format i.e. 15-may-2020, 2-aug- 1990 etc...
 *
 * incalls : getycode(int)
 * 	     getmcode(char*)
 * 	     getdayfromtypeone(int)		
 * 	     splitdate(char*)
 *
 */
void caldayofmonth(char* date){

	// Spliting date into day - month - year ...
	splitdate(date);
	loadingCursor();

	// Variables for storing the intermidiate values while finding out the day of the week i.e. sunday, monday etc... 
        int yrint;	
	char yr_lst_two[3];
	int yrlsttwo;
	int quo_year;
	int m_code;
	int y_code;
	int total;
	int remainder;
	
	// Copying the last 2 digits from the year i.e. if 2020 then last two digits = 20
	yr_lst_two[0] = year[2];
	yr_lst_two[1] = year[3];
	yr_lst_two[2] = year[4];

	// Converting the string to integers type...
	yrlsttwo = atoi(yr_lst_two);
	yrint = atoi(year);
	quo_year = yrlsttwo / 4;
	m_code = getmcode(month);
	y_code = getycode(atoi(year));

	// If wrong year entered terminate program ...
	if (y_code == -1)
		exit(0);

	// Adding last 2 digits of yr + day + quotient on mod 4 + month code + year code ...
	total = yrlsttwo + atoi(day) + quo_year + m_code + y_code;
	remainder = (int)(total % 7);

	// Test case handled if the year is leap and the month entered is january or february ...
	if ((strcmp(month,"jan") || strcmp(month,"feb")) && atoi(year) % 4 == 0)
		remainder -= 1;
	
	// Printing the day ...
	printf(BOLDGREEN"\n\n\t\t%s was the day on Date : %s\n",getdayfromtypeone(remainder), date);
}

/**
 *
 * function name : calweekdayafterspecified()
 * in parameters : day - string
 * 				   interval - int
 * out parameters : nothing - void
 * 
 * desc : This function takes the day i.e. mon, tue, fri etc.. 
 * 		  and interval i.e. 455, 555 etc.. and calculates the day 
 * 		  that will come after the rentered interval
 * 
 * in calls : strcasecmp(const char*, const char*) 
 * 
 */



void calweekdayafterspecified(char* day, int interval){

	loadingCursor();

	char *days[7] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	int i = 0;
	int num;
	int index = -1;	
	while (i < 7){

		if (strcasecmp(days[i], day) == 0)
			index = i;

		i++;
	}
	// Test case if format of day entered is Wrong ...
	if (index == -1){
		printf(BOLDRED"\n|\t--------WRONG FORMAT PROVIDED : PLEASE SPECIFY AS i.e. mon, tue, Wed etc..."RESET);
		exit(0);
	}

	// Calculating remainder ...	
	int rem = (int)(interval % 7);
	num = rem+index;

	if (num > 7)
		num = rem+index - 7;
		
	printf(KGRN"\n|\n|--------Day after %d will be %s\n|",interval, getdayfromtypeone(num));	        	

}
