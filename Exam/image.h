#ifndef image_h
#define image_h
#define Max 100

typedef struct _date{
	int year;
	char ch1;
	int month;
	char ch2;
	int day;
} Date ;

typedef struct _library{
	char bookId[20];
	char bookName[100];
	float bookPrice;
	int bookNum;
	int bookRent;
} Library ;

typedef struct _member{
	char memberName[100];
	char memberId[20];
	Date borrow;
	Date back;
	float rent;
} Member ;

#endif
