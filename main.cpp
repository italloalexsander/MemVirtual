#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Processo.h"

using namespace std;

int contem(Processo x, vector <Processo> y, int offset)
{
    for(int i = offset; i < y.size(); i++){
        if(y[i].tInfo==x.tInfo)
        {
            return i + 1;
        }
    }

    return 0;
}	

vector <Processo> LeArquivo(const char *arq){
    ifstream arquivo;
    arquivo.open(arq, ios::in);
    int tInfo;

    vector <Processo> a;

    while(arquivo.good()){
        arquivo >> tInfo;

        Processo aux(tInfo);

        a.push_back(aux);

    }
    arquivo.close();
    return a;
}

void FIFO(vector <Processo> listaProcesso)
{
    int tamQuadros = listaProcesso[0].tInfo;
    int cont = 0;
    listaProcesso.erase(listaProcesso.begin());
    vector <Processo> aux;
    for(int i = 0; i < tamQuadros; i++){
        aux.push_back(listaProcesso[0]);
        listaProcesso.erase(listaProcesso.begin());
        cont++;
    }
    int tamLista = listaProcesso.size();
    for(int j = 0; j < tamLista; j++){
        if(contem(listaProcesso[j], aux, 0)>0){
            //nada acontece
        }else{
            aux.erase(aux.begin());
            aux.push_back(listaProcesso[j]);
            cont++;
        }
    }
    cout << "FIFO " << cont << endl;

}

void OTM(vector <Processo> listaProcesso){
	int tamQuadros = listaProcesso[0].tInfo;
	int cont = 0, cont2 = 0;
	int quanto = 0;
	int posicao = -1;
	int out = -1;
	listaProcesso.erase(listaProcesso.begin());
    vector <Processo> aux;
	Processo p;
    for(int i = 0; i < tamQuadros; i++){
        aux.push_back(listaProcesso[0]);
        listaProcesso.erase(listaProcesso.begin());
        cont++;
    }
	int tamLista = listaProcesso.size();
	for(int j = 0; j < tamLista; j++){
		//cout << "tInfo ? : "<< listaProcesso.begin().tInfo << endl;
		if(contem(listaProcesso[0], aux, 0)>0){
			Processo aux2 = listaProcesso[0];
			listaProcesso.erase(listaProcesso.begin());
			
		}else{
			for(int k = 0; k < tamQuadros; k++){
			out = contem(aux[k], listaProcesso, 0);
				if(out == 0){
					aux.erase(aux.begin()+k);
					aux.push_back(listaProcesso[0]);
					listaProcesso.erase(listaProcesso.begin());
					cont++;
					break;
				}else{
					if(out > quanto){
						posicao = k;
						quanto = out;
					}
				}
			}
			if(out > 0){
				aux.erase(aux.begin()+posicao);
				aux.push_back(listaProcesso[0]);
				cont++;
			}
		}
	}
	cout << "OTM " << cont << endl;
}
	



void LRU(vector <Processo> listaProcesso)
{
	int tamQuadros = listaProcesso[0].tInfo;
	int cont = 0;
	int out = 0;
	listaProcesso.erase(listaProcesso.begin());
    vector <Processo> aux;
    for(int i = 0; i < tamQuadros; i++){
        aux.push_back(listaProcesso[0]);
        listaProcesso.erase(listaProcesso.begin());
        cont++;
    }
	int tamLista = listaProcesso.size();
	for(int j = 0; j < tamLista; j++){
		out = contem(listaProcesso[j], aux, 0);
		if(out!=0){
			Processo aux2 = aux[out - 1];
			aux.erase(aux.begin()+ out - 1);
			aux.push_back(aux2);
		}else{
			aux.erase(aux.begin());
			aux.push_back(listaProcesso[j]);
			cont++;
		}
	}
	cout << "LRU " << cont << endl;
}
int main(){
    vector <Processo> p, q, r;
    p = q = r = LeArquivo("arquivo.txt");
    FIFO(p);
	OTM(r);
	LRU(q);
	
}
