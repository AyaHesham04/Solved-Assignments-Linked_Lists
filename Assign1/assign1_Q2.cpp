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

void SplitList_1(CList MainL, int val, CList L1, CList L2)
{
	CNode* pTrav = MainL.pHead;
	CNode* pB = MainL.pHead;
	int ct = 0;

	while (pTrav->info != val)
	{
		pB = pTrav;
		pTrav = pTrav->pNext;
		ct++;
	}

	CNode* pTrav2 = MainL.pHead;
	for (int i = 0; i <= ct; i++)
	{
		CNode* pnn = new CNode;
		if (L1.pHead == NULL)
		{
			L1.pHead = pnn;
			L1.pTail = pnn;
			pnn->info = pTrav2->info;
			cout << pnn->info << ", ";

		}
		else
		{
			L1.pTail->pNext = pnn;
			L1.pTail = pnn;
			pnn->info = pTrav2->info;
			cout << pnn->info << ", ";


		}

		if (i == ct)
		{
			pnn->pNext = NULL;
		}

		pTrav2 = pTrav2->pNext;
	}


	ct = 0;

	while (pB->pNext != NULL)
	{
		pB = pB->pNext;
		ct++;
	}

	
	for (int i = 0; i <= ct; i++)
	{
		CNode* pnn = new CNode;
		if (L2.pHead == NULL)
		{
			L2.pHead = pnn;
			L2.pTail = pnn;
			pnn->info = pTrav->info;
			cout << pnn->info << ", ";


		}
		else
		{
			L2.pTail->pNext = pnn;
			L2.pTail = pnn;
			pnn->info = pTrav->info;
			cout << pnn->info << ", ";


		}

		if (i == ct)
		{
			pnn->pNext = NULL;
		}

		pTrav = pTrav->pNext;
	}



}

void main()
{
	CList MainL;
	CList L1;
	CList L2;
	int val;
	CNode* pnn;
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		pnn = new CNode;
		cout << "enter info\n";
		cin >> pnn->info;
		pnn->pNext = NULL;
		MainL.Attach(pnn);
	}

	

	cout << "enter val /n";
	cin >> val;
	
	SplitList_1(MainL, val, L1, L2);



}