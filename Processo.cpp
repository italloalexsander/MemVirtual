#include "Processo.h"

Processo::Processo(){
    this->tInfo = 0;
	this->tPriori = 0;
}

Processo::Processo(int tInfo)
{
    this->tInfo = tInfo;
}

Processo::~Processo(){}
