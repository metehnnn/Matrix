/*
METEHAN COSKUN
NUMARA:365330
MATRIS,TABLO VE GORUNTU SINIFLARI OLUSTURMA YAZILIMI
metehnnncoskun@gmail.com
TEL:05340602193
*/

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include<stdio.h>
#include <ctime>
#include <math.h>

using namespace std;
template <class Tip>
class matris {
protected:
	Tip satir;
	Tip sutun;
	Tip yogunluk;
	Tip** Matris;
	string doosya;
public:
	void setSatir(Tip r) {
		satir = r;
	}
	Tip getSatir() {
		return satir;
	}
	void setSutun(Tip s) {
		sutun = s;
	}
	string getSutun() {
		return sutun;
	}
	void setYogun(Tip c) {
		yogunluk = c;
	}
	Tip getYogun() {
		return yogunluk;
	}
	void setDosya(string file) {
		doosya = file;
	}
	string getDosya() {
		return doosya;
	}
	matris();
	matris(Tip a, Tip b, Tip c);
	void print();
	void resize(Tip a, Tip b);
	void print(string file);
	//...........matris-matris........//
	matris operator+(matris other);
	matris operator-(matris other);
	matris operator*(matris);
	//...........matris-skalar........//
	matris operator+(Tip x);
	matris operator-(Tip x);
	matris operator*(Tip x);
	matris operator/(Tip x);
	matris operator%(Tip x);
	matris operator^(Tip x);
	matris T();
	void emul(matris M);
	Tip det();
	void inv();


};
template <typename Tip>
matris < Tip > ::matris() {
	setSatir(10);
	setSutun(10);
	Matris = new Tip * [10];

	for (int i = 0; i < 10; i++) {
		Matris[i] = new Tip[10];
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Matris[i][j] = 0;
		}
	}
}
template <typename Tip>
matris<Tip>::matris(Tip a, Tip b, Tip c) {
	setSatir(a);
	setSutun(b);
	setYogun(c);
	Matris = new Tip * [satir];
	for (int i = 0; i < satir; i++) {
		Matris[i] = new Tip[sutun];
	}
	for (int i = 0; i < satir; i++) {
		for (int j = 0; j < sutun; j++) {
			Matris[i][j] = yogunluk;
		}
	}
	if (c == 'e') {
		for (int i = 0; i < satir; i++) {
			for (int j = 0; j < sutun; j++) {
				if (i == j) {
					Matris[i][j] = 1;
				}
				else Matris[i][j] = 0;
			}
		}
	}
	if (c == 'r') {

		srand(time(0));
		for (int i = 0; i < satir; i++) {
			for (int j = 0; j < sutun; j++) {
				Matris[i][j] = rand() % 256;
			}
		}

	}
}
template <typename Tip>
void matris<Tip>::print()
{
	//cout << satir << "x" << sutun << " " << "Matrisiniz :" << endl << endl;
	for (int i = 0; i < satir; i++) {
		for (int j = 0; j < sutun; j++) {
			cout << Matris[i][j] << " ";

		}
		cout << endl;
		
	}
	
	cout << endl;
	

}
template <typename Tip>
void matris<Tip>::resize(Tip a, Tip b) {
	int temp;

	if (yogunluk == 'r') {
		this->Matris = new int* [a];
		for (int i = 0; i < a; i++) {
			this->Matris[i] = new int[b];
		}
		satir = a;
		sutun = b;
		srand(time(0));

		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				this->Matris[i][j] = rand() % 256;

			}
		}



	}
	else if (yogunluk == 'e') {

		this->Matris = new int* [a];
		for (int i = 0; i < a; i++) {
			this->Matris[i] = new int[b];
		}
		satir = a;
		sutun = b;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if (i == j) {
					this->Matris[i][j] = 1;
				}
				else {
					this->Matris[i][j] = 0;
				}
			}
		}

	}
	else {
		this->Matris = new int* [a];
		for (int i = 0; i < a; i++) {
			this->Matris[i] = new int[b];
		}
		satir = a;
		sutun = b;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				this->Matris[i][j] = yogunluk;

			}
		}

	}


}
template <typename Tip>
void matris<Tip>::print(string file) {
	setDosya(file);
	ofstream dosya;
	dosya.open("file.txt");
	for (int i = 0; i < satir; i++) {
		for (int j = 0; j < sutun; j++) {
			dosya << Matris[i][j] << " ";
		}

		dosya << endl;
	}
	dosya.close();
	cout << "Dosyaya yazma islemi tamamlandi lutfen dosyanizi kontrol ediniz!";


}
template<typename Tip>
matris<Tip> matris<Tip>:: operator+(matris other) {
	matris <Tip> temp(satir,sutun,yogunluk);
	
	if (temp.satir == other.satir && temp.sutun == other.sutun) {
		cout << "Toplama Islemi Sonucu :" << endl;
		for (int i = 0; i < temp.satir; i++) {
			for (int j = 0; j < temp.sutun; j++) {
				temp.Matris[i][j] = Matris[i][j] + other.Matris[i][j];

			}
		}

	}
	
	else {
		cout << "Toplama islemi icin satir ve sutun sayilari esit olmalidir!!"<<endl;
		exit(1);

	}
	
	return temp;	
}
template<typename Tip>
matris<Tip>matris<Tip>::operator-(matris other) {
	matris <Tip> temp;
	temp.satir = satir;
	temp.sutun = sutun;
	temp.yogunluk = yogunluk;
	if (temp.satir == other.satir && temp.sutun == other.sutun) {
		for (int i = 0; i < temp.satir; i++) {
			for (int j = 0; j < temp.sutun; j++) {
				temp.Matris[i][j] = Matris[i][j] - other.Matris[i][j];

			}
		}
	}
	else { 
		cout << "Cikarma islemi icin satir ve sutun sayilari esit olmalidir!!"<<endl; 
		exit(1);
	}
	return temp;
}
template<typename Tip>
matris<Tip> matris<Tip>::operator*(matris other) {
	matris<Tip> temp(satir, sutun, yogunluk);
	int sum = 0;
	if (temp.sutun == other.satir) {
		for (int i = 0; i < satir; i++) {
			for (int j = 0; j < sutun; j++) {
				for (int k = 0; k < sutun; k++) {
					sum = sum + Matris[i][k] * other.Matris[k][j];
				}
				temp.Matris[i][j] = sum;
				sum = 0;

			}
		}
	}
	else { 
		cout << "Carpma Islemi Yapmak Icin Birinci Matrisin Sutun Sayisi Ikinci Matrisin Satir Sayisina Esit Olmalidir!! "<<endl; 
		exit(1);
	}

	return temp;

}
template<typename Tip>
matris<Tip>matris<Tip>::operator+(Tip x) {
	matris <Tip> temp(satir, sutun, yogunluk);

	for (int i = 0; i < satir; i++) {
		for (int j = 0; j < sutun; j++) {
			temp.Matris[i][j] = Matris[i][j] + x;
		}
	}


	return temp;
}
template<typename Tip>
matris<Tip> matris<Tip>::operator-(Tip x) {
	matris <Tip> temp(satir,sutun,yogunluk);
	for (int i = 0; i < satir; i++) {
		for (int j = 0; j < sutun; j++) {
			temp.Matris[i][j] = Matris[i][j] - x;

		}
	}


	return temp;
}
template<typename Tip>
matris<Tip> matris<Tip>::operator*(Tip x) {
	matris<Tip> temp(satir,sutun,yogunluk);
	for (int i = 0; i < satir; i++) {
		for (int j = 0; j < sutun; j++) {
			temp.Matris[i][j] = Matris[i][j] * x;
		}
	}
	return temp;
}
template<typename Tip>
matris<Tip> matris<Tip>::operator/(Tip x) {
	matris<Tip> temp(satir,sutun,yogunluk);
	for (int i = 0; i < satir; i++) {
		for (int j = 0; j < sutun; j++) {
			temp.Matris[i][j] = Matris[i][j] / x;
		}
	}
	return temp;
}
template<typename Tip>
matris<Tip> matris<Tip>::operator%(Tip x) {
	matris<Tip> temp(satir,sutun,yogunluk);
	for (int i = 0; i < satir; i++) {
		for (int j = 0; j < sutun; j++) {
			temp.Matris[i][j] = Matris[i][j] % x;
		}
	}
	return temp;
}
template<typename Tip>
matris<Tip> matris<Tip>::operator^(Tip x) {
	matris <Tip> temp(satir, sutun, yogunluk);
	matris <Tip> other(satir, sutun, yogunluk);

	for (int i = 0; i < satir; i++) {
		for (int j = 0; j < sutun; j++) {
			other.Matris[i][j] = (i == j);
		}
	}
	for(int z=0;z<x;z++){

		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < satir; j++)
			{
				temp.Matris[i][j] = 0;
				for (int k = 0; k < satir; k++)
				{
					temp.Matris[i][j]+=  other.Matris[i][k] * Matris[k][j];
					
					
				}
			}
			
		}
	
		
		for (int i = 0; i < satir; i++) {
			for (int j = 0; j < sutun; j++)
			{
				other.Matris[i][j] = temp.Matris[i][j];
			}
		}
		
	}
	return other;

}
template<typename Tip>
matris<Tip> matris<Tip>::T() {
	matris<Tip>temp(sutun,satir,yogunluk);
	cout << sutun << "x" << satir << " " << "Transpoze Matrisiniz:" << endl;
	for (int i = 0; i < satir; i++) {
		for (int j = 0; j < sutun; j++) {
			temp.Matris[j][i] = Matris[i][j];
		}
	}
	for (int i = 0; i < satir; i++) {
		delete[] Matris[i];
	}
	delete[] Matris;
	this->Matris = temp.Matris;
	int tmp = sutun;
	satir = sutun;
	sutun = tmp;

	

	return temp;
}
template<typename Tip>
void matris<Tip>::emul(matris M) {
	if (satir == M.satir && sutun == M.sutun) {
		for (int i = 0; i < satir; i++) {
			for (int j = 0; j < sutun; j++) {
				Matris[i][j] = Matris[i][j] * M.Matris[i][j];
			}
		}
	}
	else cout << "Satir ve Sutun sayilari Esit Olmalidir!!";
}
template <typename Tip>
Tip matris<Tip>::det() {


	if (satir == 2)
		return ((Matris[0][0] * Matris[1][1]) - (Matris[1][0] * Matris[0][1]));
	else {
		Tip a = 0;
		Tip b = 0;
		Tip c = 0;
		Tip d = 0;
		Tip e = 0;
		Tip f = 0;
		Tip g = 0;
		Tip h = 0;
		Tip i = 0;

		a = Matris[0][0];
		b = Matris[0][1];
		c = Matris[0][2];
		d = Matris[1][0];
		e = Matris[1][1];
		f = Matris[1][2];
		g = Matris[2][0];
		h = Matris[2][1];
		i = Matris[2][2];

		Tip determinant = (a * e * i + d * h * c + g * b * f) - (c * e * g + f * h * a + i * b * d);
		return determinant;
		
	}

}
template<typename Tip>
void matris<Tip>::inv() {
	matris <Tip>temp(satir, sutun, this->yogunluk);

	for (int i = 0; i < satir; i++) {
		for (int j = 0; j < sutun; j++) {
			if (i == j)
				temp.Matris[i][j] = 1;
			else
				temp.Matris[i][j] = 0;
		}
	}

	Tip x, z;
	for (int i = 0; i < satir; i++) {
		x = Matris[i][i];
		for (int j = 0; j < satir; j++) {
			Matris[i][j] = Matris[i][j] / x;
			temp.Matris[i][j] = temp.Matris[i][j] / x;
		}
		for (int k = 0; k < satir; k++) {
			if (k != i) {
				z = Matris[k][i];
				for (int j = 0; j < satir; j++) {
					Matris[k][j] = Matris[k][j] - (Matris[i][j] * z);
					temp.Matris[k][j] = temp.Matris[k][j] - (temp.Matris[i][j] * z);
				}
			}
		}
	}
	for (int i = 0; i < satir; i++) {
		for (int j = 0; j < sutun; j++) {
			cout << temp.Matris[i][j] << " ";
		}
		cout << endl;
	}
}

template <class Tip>
class table :public matris<Tip> {
public:
	void setSatir(Tip a) {
		this->satir = a;
	}
	Tip getSatir() {
		return this->satir;
	}
	void setSutun(Tip b) {
		this->sutun = b;
	}
	Tip getSutun() {
		return this->sutun;
	}
	void setYogun(Tip c) {
		this->yogunluk = c;
	}
	Tip getYogun() {
		return this->yogunluk;
	}
	table();
	table(Tip a, Tip b, Tip c);
	Tip itemAt(Tip a, Tip b);
	Tip itemAt(string s);
	Tip itemAt(string rs, string cs);
	void setRowNames(string s[], Tip n);
	void setColNames(string s[], Tip n);
	void print();

};
template<typename Tip>
table<Tip>::table() {
	this->Matris = new Tip * [10];
	for (int i = 0; i < 10; i++) {
		this->Matris[i] = new Tip[10];
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			this->Matris[i][j] = 0;
		}
	}

	for (int i = 0; i < 10; i++) {
		cout << "\t" << char(i + 65);
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << i << "\t";
		for (int j = 0; j < 10; j++) {
			cout << this->Matris[i][j] << "\t";
		}
		cout << endl;
	}
}
template<typename Tip>
table<Tip>::table(Tip a, Tip b, Tip c) {
	setSatir(a);
	setSutun(b);
	setYogun(c);
	this->Matris = new Tip * [this->satir];
	for (int i = 0; i < this->satir; i++) {
		this->Matris[i] = new Tip[this->sutun];
	}
	for (int i = 0; i < this->satir; i++) {
		for (int j = 0; j < this->sutun; j++) {
			this->Matris[i][j] = this->yogunluk;
		}
	}
	if (c == 'r') {
		srand(time(0));
		for (int i = 0; i < this->satir; i++) {
			for (int j = 0; j < this->sutun; j++) {
				this->Matris[i][j] = rand() % 256;
			}
		}
	}
	for (int i = 0; i < this->sutun; i++) {
		cout << "\t\t" << char(i + 65);
	}
	cout << endl;

	for (int i = 0; i < this->satir; i++) {
		cout << i << "\t\t";
		for (int j = 0; j < this->sutun; j++) {
			cout << this->Matris[i][j] << "\t\t";
		}
		cout << endl;
	}


}
template<typename Tip>
Tip table<Tip>::itemAt(Tip a, Tip b) {
	setSatir(a);
	setSutun(b);
	return this->Matris[a][b];
}
template<typename Tip>
Tip table<Tip>::itemAt(string s) {
	Tip t1;
	int t2, t3, t7;
	t1 = int(s[0]) - 65;
	t2 = s[1] - 48;
	t3 = s[2] - 48;
	string t4 = to_string(t2);
	string t5 = to_string(t3);
	string t6 = t4 + t5;
	t7 = stoi(t6);

	return this->Matris[t7][t1];
}
template<typename Tip>
Tip table<Tip>::itemAt(string rs, string cs) {
	string tutucu;
	int t;
	int t2;
	int i = 0;
	while (rs[i] != '\0') {
		tutucu = tutucu + rs[i];
		i++;
	}
	t = stoi(tutucu);

	if (cs[1] == '\0') {
		t2 = int(cs[0]) - 65;
	}
	else
	{
		while (cs[i] != '\0') {
			tutucu = tutucu + cs[i];
			i++;
		}
		t2 = stoi(tutucu);
	}

	return this->Matris[t][t2];
}
template <typename Tip>
void table<Tip>::setRowNames(string s[], Tip n) {
	string tutucu;
	cout << endl << "Row Names Updated Table : " << endl << endl;

	for (int i = 0; i < this->sutun; i++) {
		cout << "\t\t" << char(i + 65);
	}

	cout << endl;
	for (int i = 0; i < this->satir; i++) {

		if (i < n) {

			tutucu = s[i];
			cout << tutucu;
			for (int j = 0; j < this->sutun; j++) {
				cout << "\t" << this->Matris[i][j] << "\t";
			}
			cout << endl;
		}
		else {
			cout << i << "\t";
			for (int j = 0; j < this->sutun; j++) {
				cout << "\t" << this->Matris[i][j] << "\t";
			}
			cout << endl;

		}
	}



}
template <typename Tip>
void table<Tip>::setColNames(string s[], Tip n) {
	string tutucu;
	cout << endl;
	cout << "Column Names Updated Table :" << endl;
	cout << endl;

	for (int i = 0; i < this->sutun; i++) {
		if (i < n) {
			tutucu = char(i + 65);
			tutucu = s[i];
			cout << "\t" << tutucu;
		}
		else {
			cout << "\t" << char(i + 65) << "\t";


		}
	}
	cout << endl;
	for (int i = 0; i < this->satir; i++) {
		cout << i << "\t";
		for (int j = 0; j < this->sutun; j++) {
			cout << this->Matris[i][j] << "\t\t";
		}
		cout << endl;
	}


}
template <typename Tip>
void table<Tip>::print() {
	for (int i = 0; i < this->satir; i++) {
		for (int j = 0; j < this->sutun; j++) {
			int tutucu = j + 65;
			cout << "Table" << "[" << i << "]" << "[" << char(tutucu) << "]" << ":" << this->Matris[i][j] << endl;
		}
	}
}

template<class RGB>
class image :public matris <RGB> {
protected:
	RGB yukseklik;
	RGB genislik;
	RGB pixels;
	RGB size;
public:
	void setY(RGB y) {
		yukseklik = y;
	}
	RGB getY() {
		return yukseklik;
	}
	void setG(RGB g) {
		genislik = g;
	}
	RGB getG() {
		return genislik;
	}
	struct Image {
		string yesil;
		string mavi;
		string kirmizi;
	};
	image<RGB>();
	image<RGB>(string filename, string format);
	void  imread(string filename, string format);
	image<RGB>(int width, int height);
	void imwrite(string filename, string format);



};
template<typename RGB>
image<RGB>::image() {
	RGB Matris[255][255];
	for (int i = 0; i < 255; i++) {
		for (int j = 0; j < 255; j++) {
			Matris[i][j] = 0;
			cout << Matris[i][j] << " ";
		}
		cout << endl;
	}

}
template<typename RGB>
image<RGB>::image(string filename, string format) {
	ifstream file(filename, ios::binary);
	file.seekg(2, ios::beg);
	file.read((char*)&size, sizeof(int));
	file.seekg(10, ios::beg);
	file.read((char*)&pixels, sizeof(int));
	file.seekg(18, ios::beg);
	file.read((char*)&genislik, sizeof(int));
	file.read((char*)&yukseklik, sizeof(int));
	file.seekg(28, ios::beg);
	file.read((char*)&pixels, sizeof(short int));
	file.seekg(pixels, ios::beg);
	cout << "Size: " << size << endl;
	cout << "pixels_adress: " << pixels << endl;
	cout << "bits per pixel: " << pixels << endl;
	cout << "Width: " << genislik << endl;
	cout << "Height: " << yukseklik << endl;


}
template<typename RGB>
void  image<RGB>::imread(string filename, string format) {
	ifstream myfile(filename, ios::binary);
	char* arr;
	arr = new char[2];
	myfile.read(arr, 2);

	int n = int((arr[0] + 256) % 256);
	int m = int((arr[1] + 256) % 256);
	int imgSize = n * m;
	delete arr;

	myfile.seekg(2, ios::beg);
	arr = new char[imgSize];
	myfile.read(arr, imgSize);
	cout << n << " " << m << endl;

	this->satir = n;
	this->sutun = m;

	this->Matris = new RGB * [n];
	for (int i = 0; i < n; i++) {
		this->Matris[i] = new RGB[m];
	}

	int k = 0;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {
			this->Matris[i][j] = int((arr[k] + 256) % 256);
			k++;
		}
	}
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {
			cout << this->Matris[i][j] << " ";
			
		}
		cout << endl;
	}

}
template<typename RGB>
image<RGB>::image(int width, int height) {

	setY(height);
	setG(width);
	this->Matris = new RGB * [yukseklik];
	for (int i = 0; i < yukseklik; i++) {
		this->Matris[i] = new RGB[genislik];
	}
	for (int i = 0; i < yukseklik; i++) {
		for (int j = 0; j < genislik; j++) {
			this->Matris[i][j] = 0;
		}
	}
	for (int i = 0; i < yukseklik; i++) {
		for (int j = 0; j < genislik; j++) {
			cout << this->Matris[i][j] << " ";
		}
	}
}
template<typename RGB>
void image<RGB>::imwrite(string filename, string format) {
	ofstream file_to_write;
	file_to_write.open(filename);

	for (int i = 0; i < this->satir; i++) {
		for (int j = 0; j < this->sutun; j++) {
			file_to_write << this->Matris[i][j];
			file_to_write << " ";
		}
	}

}
int main()
{
	//-----------Matris----------//
	/*matris<int>* m1 = new matris<int>();
	matris<int>* m2 = new matris<int>(3,2,1);
	matris<int>* m3 = new matris<int>(5,5,'e');
	matris<int>* m4 = new matris<int>(15, 15, 'r');*/

	matris<int> m1 = matris<int>();
	matris<int> m2(3, 2, 2);
	matris<int> m3(1, 5, 'e');
	matris<int> m4(5, 10, 'r');
	m2=m2.T();
	m2.print();
	
	
	
	
	//------------Table----------//
	string s[] = { "0. satir","1. satir","2. satir" };
	//table<int>();
	//table<int>t1(3, 2, 1);
	//table<int>t2(3, 3, 'r');

	//------------Ýmage----------//
	//image<int>();
	//image <int>a("image_file1.bmp", "bmp");
	//a.imread("image_file1.bmp", "bmp");
	

	return 0;
}


