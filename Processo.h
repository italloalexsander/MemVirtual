#ifndef PROCESSO_H
#define PROCESSO_H


class Processo
{
    public:
        Processo();
        Processo(int tInfo);
        int tInfo;
		int tPriori;
        virtual ~Processo();
    protected:
    private:
};

#endif // PROCESSO_H
