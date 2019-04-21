#pragma once
class Plex
{
public:
	int m;//ÊµÊý
	int n;//ÐéÊý
public:
	Plex();
	Plex(int m, int n);
	Plex& operator=(const Plex& src);
	Plex operator+( const Plex& src);
	Plex operator+(int m);
	Plex operator-(const Plex& src);
	bool operator==(const Plex& src);
	bool operator<(const Plex& src);
	bool operator>(const Plex& src);
	void show();

};

