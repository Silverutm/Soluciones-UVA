#include <iostream>
#include <cstdio>
#include <vector>

#define For(i, a, b) for(int i = (a); i < (b); ++i)

using namespace std;

typedef vector <int> vi;

// Segment Tree para RMQ usando Lazy Updates

class SegTreeLazyRMQ
{
private:
	vi st, lazy, acum, A;
	int n;
	int left(int nodo) { return (nodo << 1) + 1; }
	int right(int nodo) { return (nodo << 1) + 2; }

	void init(int i, int j, int nodo)
	{
		if (i == j)
		{
			st[nodo] = i;
			return;
		}

		int m = (i + j) >> 1;
		init(i, m, left(nodo));
		init(m + 1, j, right(nodo));

		if (A[st[left(nodo)]] <= A[st[right(nodo)]])
			st[nodo] = st[left(nodo)];
		else
			st[nodo] = st[right(nodo)];
	}

public:
	SegTreeLazyRMQ(const vi & _A)
	{
		A = _A;
		n = A.size();
		st.assign(n << 2, 0);
		lazy.assign(n << 2, 0);
		acum.assign(n << 2, 0);

		init(0, n-1, 0);

		cout << "Construido" << endl;
	}

	void update(int i, int j, int a, int b, int val, int nodo)
	{
		if (i == a and j == b)
		{
			acum[nodo] += val;
			printf("se actualizó i: %d j: %d val: %d\n", i, j, acum[nodo]);
			if (i != j)
			{
				lazy[left(nodo)]  += val;
				lazy[right(nodo)] += val;
			}

			return;
		}

		lazy[left(nodo)]  += lazy[nodo];
		lazy[right(nodo)] += lazy[nodo];
		acum[nodo]        += lazy[nodo];
		lazy[nodo]         = 0;

		int m = (i + j) >> 1;
		if (b <= m)
			update(i, m, a, b, val, left(nodo));
		else if (a > m)
			update(m+1, j, a, b, val, right(nodo));
		else
		{
			update(i, m, a, m, val, left(nodo));
			update(m+1, j, m+1, b, val, right(nodo));
		}

		if (A[st[left(nodo)]] + acum[left(nodo)] <= A[st[right(nodo)]] + acum[right(nodo)])
			st[nodo] = st[left(nodo)];
		else
			st[nodo] = st[right(nodo)];
	}

	int query(int i, int j, int a, int b, int nodo)
	{
		if (i == a and j == b)
			return st[nodo];

		lazy[left(nodo)]  += lazy[nodo];
		lazy[right(nodo)] += lazy[nodo];
		acum[nodo]        += lazy[nodo];
		lazy[nodo]         = 0;

		int aux;
		int m = (i + j) >> 1;
		if (b <= m)
		{			
			aux = query(i, m, a, b, left(nodo));
			printf("i: %d j: %d a: %d b: %d res: %d\n", i, j, a, b, aux);
			return aux; //query(i, m, a, b, left(nodo));
		}
		else if (a > m)
		{
			aux = query(m+1, j, a, b, right(nodo));
			printf("i: %d j: %d a: %d b: %d res: %d\n", i, j, a, b, aux);
			return aux; //query(m+1, j, a, b, right(nodo));
		}
		else
		{
			int izq = query(i, m, a, m, left(nodo));
			int der = query(m+1, j, m+1, b, right(nodo));



			printf("aizq: %d acumizq: %d ader: %d acumder: %d\n", A[izq], acum[left(nodo)], A[der], acum[right(nodo)]);
			if (A[izq] + acum[left(nodo)] <= A[der] + acum[right(nodo)]) 
			{
				printf("i: %d j: %d a: %d b: %d res: %d\n", i, j, a, b, izq);
				return izq;
			}
			else
			{
				printf("i: %d j: %d a: %d b: %d res: %d\n", i, j, a, b, der);
				return der;
			}
		}
	}
};

int main()
{
	vector <int> A;
	int n;

	scanf("%d", &n);
	A.resize(n);
	For(i, 0, n)
		scanf("%d", &A[i]);

	SegTreeLazyRMQ tree(A);
	char c;
	while (cin >> c)
	{
		int a, b, w;

		cin >> a >> b;
		if (c == 'u')
		{
			cin >> w;
			tree.update(0, n-1, a, b, w, 0);
		}
		else
			cout << tree.query(0, n-1, a, b, 0) << endl;
	}

	return 0;
}