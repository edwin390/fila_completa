#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

class cFila
{
public:
	cFila();
	bool vacia();
	bool llena();
	void inserta(int, int);
	void eliminar(int);
	int primero();
	int ultimo();
	int recupera(int);
	void imprimir();
	void anular();
    int busqueda_li(int);
	int busqueda_bi(int,int,int);
	void bubbleSort();
	void insertionSort();
	void selectionSort();
	void shellSort();
	void merge(int iP[], int p, int q, int r);
	void mergeSort(int iP[], int l, int r);
	void swap(int* a, int* b);
    int partition(int iP[], int low, int high);
	void quickSort(int elementos[], int low, int high);
	int iP[5];
	int iTamanio;
	bool band=true;
};

int cFila::busqueda_li(int bus)
{
	for (int i = 0; i < 5; i++) {
		if (iP[i] == bus) {
			return i;
		}
	}
	return -1; 
}

int cFila::busqueda_bi(int bus, int izq, int dere)
{
	if (izq < dere)
	{
		int medio = (izq + dere) / 2;
		if (iP[medio] == bus)
		{
			return medio;
		}
		if (iP[medio] < bus)
		{
			return busqueda_bi(bus, medio + 1, dere);
		}
		else
		{
			return busqueda_bi(bus, izq, medio - 1);
		}
	}
	if (izq == dere && iP[izq] == bus)
	{
		return izq;
	}
	return -1;
}

void cFila::bubbleSort()
{
	bool bandera;
	for (int x = 1; x < iTamanio; x++) 
	{
		bandera = false;
		for (int i = iTamanio - 1; i >= x; i--) 
		{
			if (iP[i - 1] > iP[i])
			{
				int temp = iP[i - 1];
				iP[i - 1] = iP[i ];
				iP[i] = temp;
				bandera = true;
			}
		}
		if (bandera == false)
			break;
	}
	band = true;
}

void cFila::insertionSort()
{
	int aux,pos;
	for (int i = 0; i < iTamanio; i++)
	{
		pos = i;
		aux = iP[i];
		while ((i>0) && (iP[pos - 1]>aux))
		{
			iP[pos] = iP[pos - 1];
			pos--;
		}
		iP[pos] = aux;
	}
	band = true;
}

void cFila:: selectionSort()
{
	int aux;
	int pos;

	for (int i = 0; i < iTamanio; i++) 
	{
		pos = i;
		for (int j = i + 1; j < iTamanio; j++) 
		{
			if (iP[pos] > iP[j]) 
			{
				pos = j;
			}
		}
		aux = iP[i];
		iP[i] = iP[pos];
		iP[pos] = aux;
	}
	band = true;
}

void cFila::shellSort()
{
	int gap = 1, aux, j;
	while (gap < iTamanio / 3) {
		gap = gap * 3 + 1;
	}
	while (gap > 0) {
		for (int i = gap; i < iTamanio; i++) {
			aux = iP[i];
			j = i;
			while (j >= gap && iP[j - gap] > aux) {
				iP[j] = iP[j - gap];
				j -= gap;
			}
			iP[j] = aux;
		}
		gap = (gap - 1) / 3;
	}
	band = true;
}

void cFila::merge(int iP[], int p, int q, int r) 
{
	int n1 = q - p + 1;
	int n2 = r - q;

	int* L = new int[n1];
	int* M = new int[n2];


	for (int i = 0; i < n1; i++)
		L[i] = iP[p + i];
	for (int j = 0; j < n2; j++)
		M[j] = iP[q + 1 + j];


	int i, j, k;
	i = 0;
	j = 0;
	k = p;

	while (i < n1 && j < n2)
	{
		if (L[i] <= M[j]) 
		{
			iP[k] = L[i];
			i++;
		}
		else 
		{
			iP[k] = M[j];
			j++;
		}
		k++;
	}


	while (i < n1) 
	{
		iP[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) 
	{
		iP[k] = M[j];
		j++;
		k++;
	}
}

void cFila::mergeSort(int iP[], int l, int r)
{
	if (l < r) 
	{

		int m = l + (r - l) / 2;

		mergeSort(iP, l, m);
		mergeSort(iP, m + 1, r);
		merge(iP, l, m, r);
	}
	band = true;
}

void cFila::swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int cFila::partition(int iP[], int low, int high)
{
	int pivot = iP[high];
	int i = (low - 1);


	for (int j = low; j < high; j++) 
	{
		if (iP[j] <= pivot) 
		{
			i++;
			swap(&iP[i], &iP[j]);
		}
	}


	swap(&iP[i + 1], &iP[high]);

	return (i + 1);
}

void cFila::quickSort(int iP[], int low, int high) 
{
	if (low < high) {


		int pi = partition(iP, low, high);
		quickSort(iP, low, pi - 1);
		quickSort(iP, pi + 1, high);
	}	
	band = true;
}

cFila::cFila()
{
	iTamanio = 0;
}

bool cFila::vacia()
{
	return iTamanio == 0;
}

bool cFila::llena()
{
	return iTamanio == 5;
}

void cFila::inserta(int nd, int ind)
{
	if (iTamanio == 0)
		band = true;
	else
		band = false;

	if (not llena() && ind > -1 && ind <= iTamanio)
	{
		for (int i = iTamanio; i > ind; i--) {
			iP[i] = iP[i - 1];
		}
		iP[ind] = nd;
		iTamanio++;
		cout << "elemento agrado con exito" << endl;
	}
	else
		cout << endl << "error" << endl;
}

void cFila::eliminar(int ind)
{
	if (not vacia() && ind >- 1 && ind <= iTamanio)
	{
		for (int i = ind; i < iTamanio - 1; i++) {
			iP[i] = iP[i + 1];
		}
		iTamanio--;
		cout << "elemento eliminado con exito" << endl;
	}
}

int cFila::primero()
{
	if (not vacia())
		return iP[0];
	else
		cout << "la lista esta vacia";
}

int cFila::ultimo()
{
	if( not vacia())
		return iP[iTamanio-1];
	else
		cout << "la lista esta vacia";
}

int cFila::recupera(int ind)
{
	if(not vacia())
		return iP[ind];
	else
		cout << "la lista esta vacia";
}

void cFila::imprimir()
{
	if (not vacia())
	{
		int o = 1;
		for (int i = 0;i < iTamanio;i++)
		{
			cout << "el elemento:" << o << "  es:" << iP[i] << endl;
			o++;
		}
	}
	else
		cout << "la lista esta vacia" << endl;
}

void cFila::anular()
{
	iTamanio = 0;
}

int main()
{
	cFila p1;
	int iOp, iNd, iPoc, iFren, iUltimo, iRecu, iOp2, iBus, iEle;
	bool op = true;
	while (op == true)
	{
		cout << "   ------MENU------";
		cout << endl << "1) -----VACIA------" << endl << "2) -----LLENA------" << endl << "3) ----INSERTA-----" << endl << "4) ----ELIMINA-----" << endl << "5) -----FRENTE-----" << endl << "6) -----ULTIMO-----" << endl << "7) ----RECUPERA----" << endl << "8) ----IMPRIMIR----" << endl << "9) -----ANULAR-----" << endl << "10) ----BUSCAR-----" << endl << "11) ----ORDENAR----"<< endl << "12)-----SALIR-----" << endl;
		cin >> iOp;
		switch (iOp)
		{
		case 1:
			if (p1.vacia())
				cout << endl << "la lista esta vacia" << endl;
			else
				cout << endl << "la lista no esta vacia" << endl;
			break;
		case 2:
			if (p1.llena())
				cout << endl << "la lista esta llena" << endl;
			else
				cout << "la lista no esta llena" << endl;
			break;
		case 3:
			cout << endl << "dime que dato desea hagregar " << endl;
			cin >> iNd;
			cout << endl << "dime la posicion menor o igual que:" << p1.iTamanio << endl;
			cin >> iPoc;
			p1.inserta(iNd, iPoc);
			break;
		case 4:
			cout << endl << "dime la posicion menor o igual que:" << p1.iTamanio << endl;
			cin >> iPoc;
			p1.eliminar(iPoc);
			break;
		case 5:
			iFren = p1.primero();
			cout << endl << "dato:" << iFren << endl;
			break;
		case 6:
			iUltimo = p1.ultimo();
			cout << endl << "dato:" << iUltimo << endl;
			break;
		case 7:
			cout << endl << "dime la posicion menor o igual que:" << p1.iTamanio << endl;
			cin >> iPoc;
			iRecu = p1.recupera(iPoc);
			cout << endl << "dato:" << iRecu << endl;
			break;
		case 8:
			if (not p1.vacia())
				p1.imprimir();
			else
				cout << endl << "error" << endl;
			break;
		case 9:
			if (not p1.vacia())
			{
				p1.anular();
				cout << endl << "lista anulada" << endl;
			}
			else
				cout << endl << "error" << endl;
			break;
		case 10:
			cout << "por que metodo desea ordenar" << endl << "1) lineal" << endl << "2) binaria" << endl;
			cin >> iOp2;
			switch (iOp2)
			{
			case 1:
				cout << "dime el numero que deseas buscar" << endl;
				cin >> iBus;
				iEle=p1.busqueda_li(iBus);
				if (iEle == -1)
					cout << "el numero no se encontro" << endl;
				else
					cout << "el numero se encontro" << endl;
				break;
			case 2:
				if (p1.band == true)
				{
					cout << "dime el numero que deseas buscar" << endl;
					cin >> iBus;
					iEle=p1.busqueda_bi(iBus, 0, p1.iTamanio);
					if (iEle == -1)
						cout << "el numero no se encontro" << endl;
					else
						cout << "el numero se encontro" << endl;
				}
				else
					cout << "primero tiene que ordenar los elementos" << endl;
				break;
			default:
				cout << "error" << endl;
				break;
			}
			break;
		case 11:
			cout << "por que metodo desea ordenar" << endl << "1) burbuja" << endl << "2) insercion" << endl << "3) shell" << endl << "4) salecccion" << endl << "5) mezcla" << endl << "6) quickshort" << endl;
			cin >> iOp2;
			switch (iOp2)
			{
			case 1:
				p1.bubbleSort();
				cout << "elementos ordenados" << endl;
				break;
			case 2: 
				p1.insertionSort();
				cout << "elementos ordenados" << endl;
				break;
			case 3:
				p1.shellSort();
				cout << "elementos ordenados" << endl;
				break;
			case 4:
				p1.selectionSort();
				cout << "elementos ordenados" << endl;
				break;
			case 5:
				p1.mergeSort(p1.iP, 0, p1.iTamanio-1);
				cout << "elementos ordenados" << endl;
				break;
			case 6:
				p1.quickSort(p1.iP, 0, p1.iTamanio-1);
				cout << "elementos ordenados" << endl;
				break;
			default:
				cout << "error" << endl;
				break;
			}
			break;
		case 12:
			op = false;
			break;
		default:
			cout << endl << "error" << endl;
			break;
		}

	}
}

