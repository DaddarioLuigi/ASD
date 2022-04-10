/*

matrice_header.h

*/
#ifndef MATRICE_H
#define MATRICE_H


template <typename T>

class matrice {
 public:
 	matrice()
 	{
 		return;
	}
	init(int, int); // costruttore
	int getRighe();
	int getColonne();
	void modificaDimMatrice(int, int);
	~matrice();
	matrice & operator=(const matrice &); //definizione dell'operatore di uguaglianza tra 2 matrici
	T leggimatrice(int, int);
	//void aggiungiRiga();
	void scrivimatrice(int, int, T);
	void prodottoScalare(double);
	matrice trasposta();
	void stampa();
	void riempiRandom();
 private:
	int righe;
	int colonne;
	T **elementi; 
};

#endif
