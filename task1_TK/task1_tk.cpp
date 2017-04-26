#include "task1_tk.h"

task1_TK::task1_TK(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

task1_TK::~task1_TK()
{

}

void task1_TK::ASCIIToBin(QChar znak, int znakASCII)
{
	bool tmp;                //zmienna typu bool ktora pozwoli nam przekształcić dany znak w jego reprezentacje w postac binarną
	for (int i = 7; i != 0; i--)
	{
		tmp = znakASCII % 2; // dzielenie modulo przez dwa by określić czy na danej pozycji ma być wartość 0 lub 1
		T[i] = tmp;          //przypisanie wczesniej otrzymanej cyfry (0 lub 1) do tablicy
		znakASCII /= 2;

		if (i == 1) T[0] = false; //najstarszy bit musi wynosiæ zero
	}
}


void task1_TK::mnozenie(int wektor[], int Wwynikowy[])
{
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Wwynikowy[i] += wektor[j] * H[i][j]; //mnozymy nasz znak w postaci binarnej przez macierz H
		}
		Wwynikowy[i] %= 2;                       //dzielenie modulo przez 2 by uzyskac wynik w postaci binarnej
	}
}



void task1_TK::kodowanie(QChar znak)
{
	static int AC[wiersze];              // tablica w której bedziemy przechowywac mnożenie binarnej wartości znaku przez macierz H

	int znakASCII = znak.toLatin1();     // funkcja zamieniająca Qchar na jego reprezentacje dziesiętną
	
                                         //przeksztalcenie na kod ASCII
         ASCIIToBin(znak, znakASCII);
            //polskie znaki mają swoją reprezentacje liczbową w postaci liczb ujemnych


	mnozenie(T, AC);                     //obliczanie sumy kontrolnej na podstawie kodu ASCII


	for (int i = 8, j = 0; i < n; i++, j++)
		T[i] = AC[j];                    //uzupelnij tablice o bity kontrolne


}


void task1_TK::on_buttonK_clicked() {

	ui.textBrowser->clear();
	QFile plik_in("wysylana.txt");       //zmienne typu qfile na plik
	QFile plik_out("odebrana.txt");
	
	QString wiadomosc;
	wiadomosc.clear();


	if (!plik_in.open(QIODevice::ReadOnly | QIODevice::Text)) //warunek otwarcia pliku, jesli messagebox
	{
		QMessageBox w(this);
		w.setText("BLAD!  Niepowodzenie przy odczycie pliku wysylana.txt");
		w.exec();
		plik_in.error();
		//exit;
	}

	QTextStream stream(&plik_in);
	wiadomosc = stream.readAll(); //przekształcamy nasze slowo na qstringa

	if (!plik_out.open(QIODevice::ReadWrite | QIODevice::Text))
	{
		QMessageBox w(this);
		w.setText("BLAD!  Niepowodzenie przy odczycie pliku odebrana.txt");
		w.exec();
		plik_out.error();
		//exit;
	}


	


	QTextStream stream1(&plik_out);
	


//KODOWANIE--------------
	QByteArray bytearray;
	
	ui.textBrowser_3->setText(wiadomosc);
	for (QString::iterator it = wiadomosc.begin(); it != wiadomosc.end(); ++it)
	{
			kodowanie(*it);                                 //przekształcamy nasze słowo na jego reprezentacje w kodzie binarnym
			ui.textBrowser->insertPlainText(*it);           //wypisanie znaku w kodzie ASCII na ekran
			ui.textBrowser->insertPlainText(":  ");
			for (int i = 0; i < n; i++)
			{
				stream1 << T[i];                            //zapisanie znaku w postaci binarnej do pliku
				if (i == n - 1) stream1 << "\n";            //przejście do nowej lini tak by każdy wiersz przedstawiał jeden znak
				QString change = QString::number(T[i]);     //Textbrowser odczytuje tylko Qstring, metoda zamienia int to QString
				ui.textBrowser->insertPlainText(change);    //wypisanie naszego znaku w postaci binarnej
				if (i == 7) ui.textBrowser->insertPlainText(" | ");
			}
			ui.textBrowser->insertPlainText("\n");

	}

	plik_out.close();
	plik_in.close();

}




int task1_TK::naASCII()
{
	double kodASCII = 0.0;

	for (int i = 0, j = 7; i < 8; i++, j--)
		kodASCII += (ASCII[i] * pow(2.0, j)); // podnies do potegi każdy bit by uzyskać liczbe w postaci dziesiętnej

	return (int)kodASCII;
}

void task1_TK::naprawBit(int pozycjaBledu)
{
	ASCII[pozycjaBledu] += 1;                 //dodaj 1 w miejscu gdzie wystapil blad
	ASCII[pozycjaBledu] %= 2;                 //dzielenie modulo przez 2 tak by otrzymac wartość 0 lub 1
}

int* task1_TK::szukaj2Bledy() throw(QString)
{
	bool found;
	int *k = new int[2];
	QString e = "  Zbyt duza liczba bledow!";

	for (int i = 0; i < n - 1; i++)
	{
		for (int l = i + 1; l < n; l++)
		{
			found = true;

			for (int j = 0; j < wiersze; j++)
			{
				if (((H[j][i] + H[j][l]) % 2) != Decode[j])
				{
					found = false;
					break;
				}
			}
			if (found)              //jesli wystapil blad wtedy znajduje sie on na i-tej i l-tej pozycji
			{
				k[0] = i;
				k[1] = l;
				return k;
			}
		}
	}
	if (!found) throw e;
}

void task1_TK::napraw2Bledy()
{
	try
	{
		int *pozycjeBledow = new int[2]; //tworzymy dynamiczna tablice 2-elementowa by przechowac w niej pozycje bledów
		pozycjeBledow = szukaj2Bledy();  //szukamy pozycji na których występują błędy


		//NAPRAWIANIE
		naprawBit(pozycjeBledow[0]);
		naprawBit(pozycjeBledow[1]);
		ui.textBrowser_2->insertPlainText("   Pozycje bledow: " + QString::number(pozycjeBledow[0])+" "+ QString::number(pozycjeBledow[1]) +": ");
	}
	catch (QString e)
	{
		ui.textBrowser_2->insertPlainText(e);
	}
}

int task1_TK::szukaj1Blad() throw(QString)
{
	bool found;
	QString e = "  wyktyto wiecej bledow!";


	for (int i = 0; i < n; i++)
	{
		found = true;
		for (int j = 0; j < wiersze; j++)
		{
			if (H[j][i] != Decode[j])
			{
				found = false;
				break;
			}
		}
		if (found) return i;            //zwraca pozycje, na ktorej znajduje sie blad
	}
	if (!found) throw e;                //jesli jest wiecej niz 1 blad to rzuc wyjatek
}

void task1_TK::napraw1Blad()
{
	try
	{

		int pozycjaBledu;
		pozycjaBledu = szukaj1Blad();   //szukamy pozycji na której wystąpił błąd

		//NAPRAWIANIE
		naprawBit(pozycjaBledu);        //zamiana błędnego bitu na poprawną wartość
		ui.textBrowser_2->insertPlainText("   Pozycje bledu: " + QString::number(pozycjaBledu) + ". "+ pozycjaBledu);
	}
	catch (QString e)
	{
		napraw2Bledy();
	}
}

bool task1_TK::czyBlad()
{
	for (int i = 0; i < wiersze; i++)
		if (Decode[i] != 0) return true; // iloczyn odebranego słowa kodowego z macierzą H powinien być równy 0 jesli tak nie jest znaczy ze wystapil blad

	return false;
}

QChar task1_TK::dekodowanie()
{
	for (int i = 0; i < wiersze; i++)
		Decode[i] = 0;                  //iloczyn odebranego słowa kodowego z macierzą H powinien być równy 0
	mnozenie(ASCII, Decode);

	if (czyBlad()) napraw1Blad();
	int kodZnaku = naASCII();           //zamien postac binarną znaku na postać dziesiętną
	return QChar(kodZnaku);             // zamien postać dziesiętną na jego reprezentacje w kodzie ASCII
}

void task1_TK::on_buttonD_clicked() {

	ui.textBrowser_2->clear();
	QFile plik_in("wysylana.txt");      //zmienne typu qfile na plik
	QFile plik_out("odebrana.txt");
	QFile pliczek("wiadomosc.txt");
	QString wiadomosc;
	wiadomosc.clear();


	if (!plik_in.open(QIODevice::ReadOnly | QIODevice::Text)) //warunek otwarcia pliku, jesli messagebox
	{
		QMessageBox w(this);
		w.setText("BLAD!  Niepowodzenie przy odczycie pliku wysylana.txt");
		w.exec();
		plik_in.error();
		exit;
	}


	QTextStream stream(&plik_in);
	wiadomosc = stream.readAll();           //zapisanie naszego slowa do zmiennej qstring

	if (!plik_out.open(QIODevice::ReadWrite | QIODevice::Text))
	{
		QMessageBox w(this);
		w.setText("BLAD!  Niepowodzenie przy odczycie pliku odebrana.txt");
		w.exec();
		plik_out.error();
		exit;
	}

	if (!pliczek.open(QIODevice::ReadWrite | QIODevice::Text)) //warunek otwarcia pliku, jesli messagebox
	{
		QMessageBox w(this);
		w.setText("BLAD!  Niepowodzenie przy odczycie pliku wiadomosc.txt");
		w.exec();
		pliczek.error();
		//exit;
	}

	QTextStream stream1(&plik_out);
	QTextStream str(&pliczek);
	QString kod_binarny;
	int zmienna = 0;
	QChar znaczek;

	for (int i = 0; i < wiadomosc.length(); i++)
	{
		kod_binarny = stream1.readLine();               //przypisanie do zmiennej qstring naszego slowa w postaci binarnej
		for (int j = 0; j < n; j++)
		{
			ASCII[j] = kod_binarny[j].digitValue();
			QString change = QString::number(ASCII[j]); //Textbrowser odczytuje tylko Qstring, metoda zamienia int to QString
			ui.textBrowser_2->insertPlainText(change);
			if (j == 7) ui.textBrowser_2->insertPlainText(" | ");

		}
		for (int l = 0; l < wiersze; l++)
			Decode[l] = 0;
		ui.textBrowser_2->insertPlainText(" : ");
		znaczek = dekodowanie();
		ui.textBrowser_2->insertPlainText(znaczek); //wypisanie znaku odpowiadającemu danemu kodowi binarnemu
		for (int i = 15, j = 0; i > 7; i--, j++)
		{
			if (T[i] == 1)
			{
				zmienna += pow(2, j);				//dekodowanie bitow na int
			}
		}

		str << znaczek;								// wypisanie bitow kontronlych w wiadomosci zdekonwaej
		str << (char)zmienna;						//wypisanie zdekodowanej wiadomosci
		ui.textBrowser_2->insertPlainText("\n");
	}

	plik_out.close();
	plik_in.close();
	pliczek.close();


}

void task1_TK::on_buttonB_clicked()
{
	 QProcess *proc = new QProcess(this);
    proc->start("notepad.exe C:/Users/Bartosz/Desktop/task1_TKedited/task1_TK/task1_TK/odebrana.txt"); // trzeba podac wlasna sciezke do pliku

}
