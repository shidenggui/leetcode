#include <iostream.h>

char * AddDate(char * pDate, int M){
	char *ph = pDate;
	int y = M/12;
	int m = M%12;
	ph += 4;
	char *t = new char[3];
	char *th = t;
	for(int i = 0; i < 2; i++){
		*th++ = *ph++;
	}
	*th = '\0';
	int pm = atoi(t);
	y += (pm + m) / 12;
	m = (pm + m) % 12;
	ph -= 2;
	*ph++ = '0';
	*ph++ = '0';
	ph += 2;
	while(*ph != '\0' && (*ph++ = '0'));
	long long int date = atoll(pDate);
	date += y * 10000000000LL;
	date += m * 100000000LL;
	char *tmp = new char[17];
	lltoa(date, tmp, 10);
	
	delete [] t;
	delete [] tmp;
	delete ph;
	
}


char * AddDate2(char * pDate, int M){
	char *ph = pDate;
	int y = M/12;
	int m = M%12;
	int py = 0;
	for(int i = 0,t = 1000; i < 4; i++, t /= 10){
		py += (int)(*ph++ - '0') * t; 
	}
	int pm = 0;
	for(int i = 0, t = 10; i < 2; i++, t /= 10){
		pm += (int)(*ph++ - '0') * t; 
	} 
	y += (pm + m) / 12;
	m = (pm + m) % 12;
	y += py;
	ph = pDate;
	for(int i = 0,t = 1000; i < 4; i++, t /= 10){
		*ph++ = y / t + '0';
		 y = y % t;
	}
	for(int i = 0,t = 10; i < 2; i++, t /= 10){
		*ph++ = m / t + '0';
		 m = m % t;
	}
	ph += 2;
	while(*ph != '\0' && (*ph++ = '0'));


}

char * AddDate3(char * pDate, int M){
	char *ph = pDate;
	int y = M/12;
	int m = M%12;
	int py = 0;
	char *ty = new char[5];
	for(int i = 0; i < 4; i++){
		*ty++ = *ph++;
	}
	*ty = '\0';
	py = atoi(ty);
	int pm = 0;
	char *tm = new char[3];
	for(int i = 0; i < 2; i++){
		*tm++ = *ph++; 
	}
	*tm = '\0';
	pm = atoi(tm);
	y += (pm + m) / 12;
	m = (pm + m) % 12;
	y += py;
	ph = pDate;
	for(int i = 0,t = 1000; i < 4; i++, t /= 10){
		*ph++ = y / t + '0';
		 y = y % t;
	}
	for(int i = 0,t = 10; i < 2; i++, t /= 10){
		*ph++ = m / t + '0';
		 m = m % t;
	}
	ph += 2;
	while(*ph != '\0' && (*ph++ = '0'));


}



int main(int argc, char *argv[])
{
	const char * ex = "20140401010101";
	char a[] = "20140401010101";
	
	clock_t start_time=clock();

	{
		//被测试代码
		int i = 0;
		while(i++ != 1000000){
			AddDate(a , 10);
			strcpy(a, ex);
		} 
	}

	clock_t end_time=clock();
	cout<< "Add1 Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;//输出运行时间
	
	
	start_time=clock();

	{
		//被测试代码
		int i = 0;
		while(i++ != 1000000){
			AddDate2(a , 10);
			strcpy(a, ex);
		} 
	}

	end_time=clock();
	cout<< "Add2 Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;//输出运行时间
	
	start_time=clock();

	{
		//被测试代码
		int i = 0;
		while(i++ != 1000000){
			AddDate3(a , 10);
			strcpy(a, ex);
		} 
	}

	end_time=clock();
	cout<< "Add3 Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;//输出运行时间
	return 0;
}