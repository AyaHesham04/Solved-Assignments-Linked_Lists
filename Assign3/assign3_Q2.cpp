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
	int N,check=0,tot=0;
	CNode* pnn1;
	CNode* pnn2;

	cout << "Enter N L1\n";
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		pnn1 = new CNode;
		cout << "enter info list 1\n";
		cin >> pnn1->info;
		pnn1->pNext = NULL;
		L1.Attach(pnn1);
	}
	cout << "Enter N L2\n";
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		pnn2 = new CNode;
		cout << "enter info list 2\n";
		cin >> pnn2->info;
		pnn2->pNext = NULL;
		L2.Attach(pnn2);

	}

	CNode* pTrav1 = L1.pHead, * pTrav2 = L1.pHead->pNext, * pTrav3 = L2.pHead, * pTrav4 = L2.pHead->pNext;

	while (pTrav1 != NULL && pTrav2 != NULL && pTrav3 != NULL && pTrav4 != NULL)
	{
		if (pTrav3->info == pTrav1->info && check==0)
		{
			check = 1;
			tot += pTrav3->info;
		}
		else
		{
			if (check == 0) //here so it doesnt move tr3 again once start of range is met
			{
				pTrav3 = pTrav3->pNext;
				pTrav4 = pTrav4->pNext;

			}

		}
	

		if (pTrav4->info != pTrav2->info)
		{
			if (check == 1) //here so it doesnt enter else now & ensure tr3 reached start of range first
			{
				tot += pTrav4->info;
				pTrav4 = pTrav4->pNext;
			}
		}
		else
		{
			tot += pTrav4->info;
			cout << "Total between " << pTrav1->info << " and " << pTrav2->info << ": " << tot<<"\n";
			pTrav3 = pTrav3->pNext;
			pTrav4 = pTrav3->pNext;
			pTrav1 = pTrav2->pNext;
			pTrav2 = pTrav1->pNext;
			tot = 0;
			check = 0;

		}
	}

}