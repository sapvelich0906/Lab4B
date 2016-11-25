// Struct.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;



struct release
{
	char country[20];
	char company[30];
	int year;
};

struct film
{
	char name[30];
	char genre[30];
	char director[50];
	release rel;
	int duration;
	int rating;
};

int main(int argc, char* argv[])
{
	film *f;
	int n;
	cout << "n=";
	cin >> n;
	f = (film *)malloc(n * sizeof(film));
	for (int i = 0; i < n; i++)
	{
		cout << "Film " << i+1 << endl;
		cin.get();
		cout << "Name: ";
		_flushall();
		cin.getline(f[i].name, 29);
		fflush(stdin);
		cout << endl;
		cout << "Genre: ";
		cin.getline(f[i].genre, 29);
		fflush(stdin);
		cout << endl;
		cout << "Director: ";
		cin.getline(f[i].director, 49);
		fflush(stdin);
		cout << endl;
		cout << "Release: " << endl;
		cout << "Country: ";
		cin.getline(f[i].rel.country, 19);
		cout << endl;
		cout << "Company: ";
		cin.getline(f[i].rel.company, 29);
		cout << endl;
		cout << "Year: ";
		cin >> f[i].rel.year;
		fflush(stdin);
		cout << endl;
		cout << "Rating: ";
		cin >> f[i].rating;
		fflush(stdin);
		cout << endl;
		cout << "Duration, min: ";
		cin >> f[i].duration;
		fflush(stdin);
		cout << endl;
	}
	for (int i = 0; i < n; i++)
		cout << f[i].name << " " << f[i].genre << " " << f[i].director 
		     << " " << f[i].rel.country << " " << f[i].rel.company << " " << f[i].rel.year
		     << " " << f[i].rating << " " << f[i].duration;
	cout << endl;
	char FilmGenre[40];
	cout << "Film genre: "; 
	cin.get();
	cin.getline(FilmGenre, 39);
	cout << endl;
	int k = 0;
	for (int i = 0; i<n; i++)
		if (strcmp(FilmGenre, f[i].genre) == 0) 
			if (f[i].rating>=7) 
				if (f[i].rel.year>2002)
					k++; 
	if (k!=0) 
		cout <<"k=" << k << endl; 
	else cout << "Not found" << endl;
	free(f);

	return 0;
}

