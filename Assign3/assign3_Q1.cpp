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
	int N;
	CNode* pnn1;
	CNode* pnn2;

	cout << "Enter N \n";
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		pnn1 = new CNode;
		cout << "enter info list 1\n";
		cin >> pnn1->info;
		pnn1->pNext = NULL;
		L1.Attach(pnn1);

		pnn2 = new CNode;
		cout << "enter info list 2\n";
		cin >> pnn2->info;
		pnn2->pNext = NULL;
		L2.Attach(pnn2);

	}

	CNode* pTrav1 = L1.pHead; 
	CNode* pTrav2 = L2.pHead;
	CNode* pB = L2.pHead;

	while (pTrav1->pNext!= NULL)
	{
		if (pTrav1->info == pTrav2->info)
		{
			pB->pNext = pTrav2->pNext;
			pTrav2->pNext = NULL;
			delete pTrav2;
			pTrav2 = pB->pNext;

		}

		pTrav1 = pTrav1->pNext;
		if (pTrav1->info != pTrav2->info)
		{
			pB = pTrav2;
			pTrav2 = pTrav2->pNext;
		}

	}

	//output
	pTrav2 = L2.pHead;
	while (pTrav2 != NULL)
	{
		cout << pTrav2->info << " ";
		pTrav2 = pTrav2->pNext;
	}

}