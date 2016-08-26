#include "MyString.h"


int main()
{
	char* tmp = "hello cpp";
	MyString ms(tmp);
	MyString ms1(ms);
	MyString ms2, ms3;
	ms2 = ms3 = ms1;
	ms.myPrint();
	ms1.myPrint();
	ms2.myPrint();
	ms3.myPrint();
	MyString nullms;
	nullms.myPrint();
	return 0;
}
