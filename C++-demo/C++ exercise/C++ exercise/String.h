#pragma once
class String
{
private:
	char *_str;
	int _len;
public:
	String(const char* str);
	String(const String& src);
	//=(const String&)(const char*)    +(const String&)(const char)(const char*)
	//< >(const String&)(const char*)  ==(const String&)(const char)(const char*)
	// >> << 

	//大数 + - > < = == << >>  了解 ++ --
	~String();
};

