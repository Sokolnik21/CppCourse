#ifndef DATA_H
#define DATA_H

#include <string>
#include <iostream>

namespace Cowboy {
	class Data {
	public:
		Data(int _year, int _month, int _day);
		void setYear(int _year);
		int getYear() const;
		bool write(std::ostream & os) const; /// zapisuje atrybuty do strumienia
		bool load(std::istream & is); /// wczytuje atrybuty ze strumienia
		friend std::ostream& operator<<(std::ostream& stream, const Data& d);
		friend std::istream& operator>>(std::istream& stream, Data& d);
	private:
		int year;
		int month;
		int day;
	};
}

#endif // OSOBA_H
