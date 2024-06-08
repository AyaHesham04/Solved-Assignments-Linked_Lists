#include <iostream>
using namespace std;

class CNode
{
public:
	int info;
	CNode* pNext;
};

class CList
{
public:
	CNode* pHead;
	CNode* pTail;

	CList()
	{
		pHead = NULL;
		pTail = NULL;
	}

	void Attach(CNode* pnn)
	{
		if (pHead == NULL)
		{
			pHead = pnn;
			pTail = pnn;
		}
		else
		{
			pTail->pNext = pnn;
			pTail = pnn;
		}
	}

	~CList()
	{
		CNode* pTrav = pHead;
		while (pHead != NULL)
		{
			pHead = pTrav->pNext;
			pTrav->pNext = NULL;
			delete pTrav;
			pTrav = pHead;
		}
	}
};



int main()
{
	CList L[20];
	CList newL;
	CNode* pnn;
	CNode* pTrav1, * pB1, * pF1, * pF2;
	CNode* pTrav2, * pB2;
	int N, check1 = 0, check2 = 0;

	for (int j = 0; j < 20; j++)
	{
		cout << "Enter N for list " << j + 1 << "\n";
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			pnn = new CNode;
			cout << "enter info list\n";
			cin >> pnn->info;
			pnn->pNext = NULL;
			L[j].Attach(pnn);
		}
	}


	for (int j = 0; j < 10; j++)
	{
		pTrav1 = L[j].pHead, pB1 = L[j].pHead, pF1 = L[j].pHead;
		pTrav2 = L[19 - j].pHead, pB2 = L[19 - j].pHead, pF2 = L[19 - j].pHead;
		check1 = 0, check2 = 0;

		while (pF1->pNext != NULL)
		{
			if (pTrav1->info > 0)
			{
				pB1 = pTrav1;
				pTrav1 = pTrav1->pNext;
				pF1 = pTrav1->pNext;

			}
			else
			{
				check1 = 1;
			}

			if (pF1->info > 0 && check1 == 1)
			{
				pF1 = pF1->pNext;
			}
			else if (check1 == 1)
			{
				break;
			}

		}

		while (pF2->pNext != NULL)
		{
			if (pTrav2->info > 0)
			{
				pB2 = pTrav2;
				pTrav2 = pTrav2->pNext;
				pF2 = pTrav2->pNext;

			}
			else
			{
				check2 = 1;
			}

			if (pF2->info > 0 && check2 == 1)
			{
				pF2 = pF2->pNext;
			}
			else if (check2 == 1)
			{
				break;
			}


		}

		if (newL.pHead == NULL)
		{
			newL.pHead = pTrav1;
			pB1->pNext = pF1->pNext;
			pF1->pNext = pTrav2;
			pB2->pNext = pF2->pNext;
			pF2->pNext = NULL;
			newL.pTail = pF2;

		}
		else
		{
			newL.pTail->pNext = pTrav1;
			pB1->pNext = pF1->pNext;
			pF1->pNext = pTrav2;
			pB2->pNext = pF2->pNext;
			pF2->pNext = NULL;
			newL.pTail = pF2;
		}


	}

	//output
	CNode* pOut = newL.pHead;
	while (pOut != NULL)
	{
		cout << pOut->info << " ";
		pOut = pOut->pNext;
	}


}
