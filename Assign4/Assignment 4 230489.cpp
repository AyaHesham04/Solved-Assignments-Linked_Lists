#include <iostream>
using namespace std;


class CNode {

public:
    char X[8][8];
    int r;
    CNode* pNext;

};

class CStack {

public:
    CNode* PHead;


    CStack() {

        PHead = NULL;

    }

    ~CStack()
    {
        CNode* pTrav;
        pTrav = PHead;
        while (PHead != NULL)
        {
            PHead = pTrav->pNext;
            pTrav->pNext = NULL;
            delete pTrav;
            pTrav = PHead;
        }

    }

    void Push(CNode* pnn)
    {
        pnn->pNext = PHead;
        PHead = pnn;
    }

    CNode* Pop()
    {
        if (PHead == NULL)
        {
            return NULL;
        }

        CNode* pTrav = PHead;
        PHead = PHead->pNext;
        pTrav->pNext = NULL;
        return pTrav;
    }

};

void Copy(CNode* pnn, CNode* pCurr)
{

    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            pnn->X[r][c] = pCurr->X[r][c];
        }
    }

    pnn->r = pCurr->r;
}


CNode* initialize()
{
    CNode* pnn = new CNode;
    pnn->pNext = NULL;
    pnn->r = 0;

    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            pnn->X[r][c] = ' ';
        }
    }


    return pnn;
}

void FlagRow(CNode* pnn, int& Flag, int i)
{
    for (int r = 0; r < 8; r++)
    {
        if ((pnn->r) != r)
        {
            if (pnn->X[r][i] == 'Q')
            {
                Flag = 1;

            }
        }
    }
}

void FlagDLeft(CNode* pnn, int& Flag, int i)
{
    for (int r = (pnn->r) - 1, c = i - 1; r >= 0 && Flag == 0 && c >= 0; r--, c--)
    {
        if (pnn->X[r][c] == 'Q')
        {
            Flag = 1;
        }
    }
}

void FlagDRight(CNode* pnn, int& Flag, int i)
{
    for (int r = (pnn->r) - 1, c = i + 1; r >= 0 && Flag == 0 && c < 8; r--, c++)
    {
        if (pnn->X[r][c] == 'Q')
        {
            Flag = 1;

        }
    }
}

void Expand(CNode* pCurr, CStack& S)
{
    CNode* pnn;

    int Flag = 0, ct = 0;

    for (int i = 0; i < 8; i++)
    {
        pnn = new CNode;
        Copy(pnn, pCurr);
        pnn->X[pnn->r][i] = 'Q';

        Flag = 0;
        FlagRow(pnn, Flag, i);
        FlagDLeft(pnn, Flag, i);
        FlagDRight(pnn, Flag, i);

        if (Flag == 0)
        {
            if (pnn->r < 8)
            {
                (pnn->r)++;
                S.Push(pnn);
            }
        }
    }

}

void BackTrack(CStack& S)
{
    int results = 0;

    CNode* pCurr;
    pCurr = initialize();
    S.Push(pCurr);

    while (S.PHead != NULL)
    {
        pCurr = S.Pop();

        if (pCurr->r == 8)
        {
            results++;

            for (int r = 0; r < 8; r++)
            {
                for (int c = 0; c < 8; c++)
                {
                    cout << pCurr->X[r][c] << " | ";

                }
                cout << endl;
                cout << "*******************************" << endl;

            }

            cout << endl;

        }


        Expand(pCurr, S);
    }

    cout << results << endl;
}

void main()
{
    CStack S;

    BackTrack(S);

}