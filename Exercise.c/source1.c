#include <stdio.h>
#include <stdlib.h> // rand() contain library
#include <time.h> // time() contain library


int main()

{
	srand(time(NULL)); // Random seed

	//////////////////////////////////////////

	// Variable
	float random_interest = 0; // random 

	int money;	// money
	int max_interest;	// maximum interest

	float final_money;	// All thing complete!

	//////////////////////////////////////////
	// Money 
	printf("금액을 입력해주세요! : ");
	scanf_s("%d", &money);

	// Max interest
    time_t start, end;
    struct tm user_stime;
    int tm_day, tm_hour, tm_min, tm_sec;
    double diff;
    int my_year, my_month, my_day;

    printf("\n 년도, 월, 일을 입력해 주세요! \n Ex) 2222 5 28 : ");
    scanf_s("%d %d %d", &my_year, &my_month, &my_day);

    user_stime.tm_year = my_year - 1900; // 년도가 1900년부터 시작하기 때문
    user_stime.tm_mon = my_month - 1; //월이 0부터 시작하기 때문
    user_stime.tm_mday = my_day;
    user_stime.tm_hour = 0;
    user_stime.tm_min = 0;
    user_stime.tm_sec = 0;
    user_stime.tm_isdst = 0; //썸머타임 사용안함

    start = mktime(&user_stime);
    time(&end);

    diff = difftime(end, start);

    tm_day = diff / (60 * 60 * 24);
    diff = diff - (tm_day * 60 * 60 * 24);

    tm_hour = diff / (60 * 60);
    diff = diff - (tm_hour * 60 * 60);

    tm_min = diff / 60;
    diff = diff - (tm_min * 60);

    tm_sec = diff;

    printf("\n 최대 이자율은 %d입니다!\n", tm_day);


	// random interest
	random_interest = (float)(rand() % (tm_day * 10)) / 10;
	printf(" \n 이자는 : %.1f %%입니다! \n", random_interest);



	// Final Money
	final_money = money + (money * random_interest / 100);
	printf("최종 금액은 %.1f원! \n \n", final_money);


    int useless = 0;

    printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★");
    scanf_s("%d", &useless);
}
