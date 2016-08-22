#include "MyString.h"
#include <string.h>
#include <stdio.h>

MyString::MyString()
{
	m_pdata = NULL;
}

MyString::MyString(const char* c)
{
	char* tmp = new char[strlen(c)+1];
	strcpy(tmp, c);
	m_pdata = tmp;
}

MyString::MyString(const MyString& ms)
{
	char* tmp = new char[strlen(ms.m_pdata)+1];
	strcpy(tmp, ms.m_pdata);
	m_pdata = tmp;
}

MyString& MyString::operator = (const MyString& ms)
{
	if (this != &ms)
	{
		MyString ms_tmp(ms);

		char* tmp = ms_tmp.m_pdata;
		ms_tmp.m_pdata = m_pdata;
		m_pdata = tmp;
	}
	return *this;
}

void MyString::myPrint()
{
	if (m_pdata == NULL)
	{
		printf("m_pdata == NULL\n");
		return;
	}
	printf("MyString = %s\n", m_pdata);
}
