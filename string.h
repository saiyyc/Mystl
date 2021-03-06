#include<iostream>
using namespace std;

class String
{
public:
	String(const char *str = NULL);
	String(const String &other);
	~String(void);
	String & operator=(const String &other);
	bool operator==(const String &str);
	friend ostream & operator<<(ostream& o, const String &str);
private:
	char *m_data;
};

/*
构造、析构、拷贝构造、赋值运、流输出运算
*/

String::String(const char *str)
{
	if (str == NULL){
		m_data = new char[1];
		*m_data = '\0';
	}
	else{
		int len = strlen(str);
		m_data = new char[len + 1];
		strcpy(m_data, str);
	}
}
String::~String(void)
{
	delete[] m_data;
}

String::String(const String &other)
{
	int len = strlen(other.m_data);
	m_data = new char[len + 1];
	strcpy(m_data, other.m_data);
}

String & String::operator=(const String &other)
{
	if (this == &other)
		return *this;

	delete[]m_data;

	int len = strlen(other.m_data);
	m_data = new char[len + 1];
	strcpy(m_data, other.m_data);

	return *this;
}

bool String::operator==(const String &str)
{
	return strcmp(m_data, str.m_data) == 0;
}

ostream & operator<<(ostream &o, const String &str)
{
	o << str.m_data;
	return o;