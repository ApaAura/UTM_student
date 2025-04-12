#include "Queue.h"

int main()
{
	Queue q(5);
	for (size_t i = 0; i < 5; i++)
	{
		q.Enqueue(i);
	}
	Queue q2(5);
	for (size_t i = 0; i < 5; i++)
	{
		cout << "q[" << i << "] = ";
		cin >> q2;
	}
	cout << "q1: " << q << endl;
	cout << "q2: " << q2 << endl;
	if (q == q2)
	{
		cout << "q1 == q2" << endl;
	}
	else
	{
		cout << "q1 != q2" << endl;
	}
	Queue q3 = q + q2;
	cout << "q3: " << q3 << endl;
}
