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
	CList L1;
	CList L2;
	CNode* pnn;

	cout << "Enter N \n";
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		pnn = new CNode;
		cout << "enter info\n";
		cin >> pnn->info;
		pnn->pNext = NULL;
		L1.Attach(pnn);
	}

	CNode* pTrav = L1.pHead;
	CNode* pMin = L1.pHead;
	CNode* pMax = L1.pHead;
	int min = 9999, max = -9999, i = 0, imin = 0, imax = 0;

	while (pTrav != NULL)
	{
		if (pTrav->info < min)
		{
			min = pTrav->info;
			pMin = pTrav;
			imin = i;
		}
		if (pTrav->info > max)
		{
			max = pTrav->info;
			pMax = pTrav;
			imax = i;
		}

		pTrav = pTrav->pNext;
		i++;
	}

	for (int i = 0; i < 2; i++) //add min and max into new list
	{
		CNode* pnn = new CNode;

		if (L2.pHead == NULL)
		{
			pnn->info = min;
			L2.pHead = pnn;
			L2.pTail = pnn;
		}
		else
		{
			pnn->info = max;
			L2.pTail->pNext = pnn;
			L2.pTail = pnn;
		}
	}

	if (imin < imax)
	{
		pTrav = pMin->pNext;

		while (pTrav != NULL && pTrav != pMax)
		{
			CNode* pnn = new CNode;
			pnn->info = pTrav->info;
			L2.pTail->pNext = pnn;
			L2.pTail = pnn;

			pTrav = pTrav->pNext;
		}
	}
	else
	{
		pTrav = pMax->pNext;

		while (pTrav != NULL && pTrav != pMin)
		{
			CNode* pnn = new CNode;
			pnn->info = pTrav->info;
			L2.pTail->pNext = pnn;
			L2.pTail = pnn;

			pTrav = pTrav->pNext;
		}
	}

	//output
	pTrav = L2.pHead;
	while (pTrav != NULL)
	{
		cout << pTrav->info << " ";
		pTrav = pTrav->pNext;
	}


}