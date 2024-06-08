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
	CNode* pnn;
	int N, num, ct=0;


	cout << "Enter N \n";
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		pnn = new CNode;
		cout << "enter info\n";
		cin >> pnn->info;
		pnn->pNext = NULL;
		L1.Attach(pnn);
	}
	
	cout << "enter num\n";
	cin >> num;

	CNode* pTrav = L1.pHead;  //to point at target node
	CNode* pB = L1.pHead;   //to point at node before target


	while (pTrav != NULL)
	{
		if (ct == num)
		{
			pB->pNext = NULL;   //to make it last node
			L1.pTail->pNext = L1.pHead;   //to make last point to start node
			L1.pHead = pTrav;   //head points at target
			L1.pTail = pB;   //tail points at node before target
			break;

		}

		ct++;
		pB = pTrav;
		pTrav = pTrav->pNext;
	}

	//output
	pTrav = L1.pHead;
	while (pTrav != NULL)
	{
		cout << pTrav->info << " ";
		pTrav = pTrav->pNext;
	}

	
}