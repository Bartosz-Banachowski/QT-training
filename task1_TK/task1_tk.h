#ifndef TASK1_TK_H
#define TASK1_TK_H

#include <QtWidgets/QMainWindow>
#include "ui_task1_tk.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessagebox.h>
#include <QProcess.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <math.h>
#include <locale.h>

const int wiersze = 8;
const int n = 16;

class task1_TK : public QMainWindow
{
	Q_OBJECT

public:
	

	bool H[wiersze][n] = {
		{ 1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0 },
		{ 0,1,1,1,1,0,1,1,0,1,0,0,0,0,0,0 },
		{ 1,0,0,1,0,1,0,1,0,0,1,0,0,0,0,0 },
		{ 1,1,1,0,1,0,0,1,0,0,0,1,0,0,0,0 },
		{ 0,1,0,1,0,1,1,0,0,0,0,0,1,0,0,0 },
		{ 1,0,1,0,1,0,1,0,0,0,0,0,0,1,0,0 },
		{ 1,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0 },
		{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1 } };

	int *Decode = new int[wiersze];       //wektor otrzymany przy dekodowaniu
	int ASCII[n];
	int T[n];


	void mnozenie(int wektor[], int Wwynikowy[]);
	void ASCIIToBin(QChar znak, int znakASCII);
	void kodowanie(QChar znak);
	int naASCII();
	bool czyBlad();
	int szukaj1Blad();
	int *szukaj2Bledy();
	void naprawBit(int pozycjaBledu);
	void napraw2Bledy();
	void napraw1Blad();
	QChar dekodowanie();
	

	task1_TK(QWidget *parent = 0);
	~task1_TK();

	private slots:
		void on_buttonK_clicked();
		void on_buttonD_clicked();
		void on_buttonB_clicked();

private:
	
	Ui::task1_TKClass ui;
};

#endif // TASK1_TK_H
