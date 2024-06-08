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

void ReverseList(CList MainL)
{
	CNode* pB = MainL.pHead;    //current node to change arrow of
	CNode* pTrav = MainL.pHead;   //node after (next)
	CNode* pArrow = NULL;    //node to redirect the arrows(next) of nodes
	CNode* pLast = MainL.pTail;   //to store the pTail for reverse at the end

	while (pB != NULL)  //NULL is reaching after end of list
	{
		pTrav = pTrav->pNext;  //travserse
		pB->pNext = pArrow;  
		pArrow = pB;   //redirects arrow to prev node 
		pB = pTrav;
	}

	MainL.pTail = MainL.pHead;
	MainL.pHead = pLast;


	//output
	pTrav = MainL.pHead; 
	while (pTrav != NULL)
	{
		cout << pTrav->info << " ";
		pTrav = pTrav->pNext;
	}
}

void ReverseList(CList MainL, CList L)
{
	CNode* pTrav = MainL.pHead;
	CNode* pB = L.pTail;

	while (pTrav != NULL)
	{
		CNode* pnn = new CNode;

		if (L.pHead == NULL)
		{
			pnn->info = pTrav->info;
			L.pHead = pnn;
			L.pTail = pnn;
			pB = L.pTail;  //to keep track of the node that each new node will point to

		}
		else
		{
			pnn->info = pTrav->info;
			L.pHead = pnn;
			pnn->pNext = pB;
			pB = pnn;
		}

		pTrav = pTrav->pNext;
	}


	//output
	pTrav = L.pHead;
	while (pTrav != NULL)
	{
		cout << pTrav->info << " ";
		pTrav = pTrav->pNext;
	}

}



void main()
{
	CList MainL;
	CList L;
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
		MainL.Attach(pnn);
	}

	ReverseList(MainL,L);

}