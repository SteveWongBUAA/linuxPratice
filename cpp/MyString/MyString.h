#ifndef _MYSTRING_H_
#define _MYSTRING_H_ 

class MyString
{
private:
	char* m_pdata;
public:
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	MyString& operator = (const MyString&);
	void myPrint();
};

#endif
