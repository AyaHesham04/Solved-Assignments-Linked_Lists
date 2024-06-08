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



void main()
{
	CList L[30];
	CNode* pnn;
	CNode* pTrav1, * pB1;
	CNode* pTrav2, * pB2;
	int N;

	for (int j = 0; j < 30; j++)
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


	for (int j = 0; j < 30; j += 2)
	{
		pTrav1 = L[j].pHead, pB1 = L[j].pHead;
		pTrav2 = L[j + 1].pHead, pB2 = L[j + 1].pHead;

		while (pTrav1 != NULL)
		{
			if (pTrav1->info != -1)
			{
				pB1 = pTrav1;
				pB2 = pTrav2;
				pTrav1 = pTrav1->pNext;
				pTrav2 = pTrav2->pNext;
			}
			else
			{
				break;
			}
		}

		pB2 = pTrav2->pNext;
		pTrav2->pNext = pTrav1->pNext;
		pTrav1->pNext = pTrav2;

	}

	//output
	CNode* pOut = L[0].pHead;
	while (pOut != NULL)
	{
		cout << pOut->info << " ";
		pOut = pOut->pNext;
	}


}
