#include <iostream>
#include "RingBuffer.h"

using namespace std;

char test_str[] = "1234567890 abcdefghijklmnopqrstuvwxyz 1234567890 abcdefghijklmnopqrstuvwxyz";

char de_buffer[100];
char peak_buffer[100];

int main()
{
	RingBuffer ring_buffer{ 100 };

	ring_buffer.Enqueue("AAAAAAAAAAAAAAAAAAAAAAA", sizeof("AAAAAAAAAAAAAAAAAAAAAAA"));
	ring_buffer.Enqueue("AAAAAAAAAAAAAAAAAAAAAAA", sizeof("AAAAAAAAAAAAAAAAAAAAAAA"));
	ring_buffer.Enqueue("AAAAAAAAAAAAAAAAAAAAAAA", sizeof("AAAAAAAAAAAAAAAAAAAAAAA"));
	ring_buffer.Enqueue("AAAAAAAAAAAAAAAAAAAAAAA", sizeof("AAAAAAAAAAAAAAAAAAAAAAA"));
	cout << "front : " << ring_buffer.GetFront() << ", rear : " << ring_buffer.GetRear() << '\n';
	cout << "free size : " << ring_buffer.GetFreeSize() << ", use size : " << ring_buffer.GetUseSize() << '\n';
	cout << "DirectDequeueSize : " << ring_buffer.DirectDequeueSize() << ", DirectEnqueueSize : " << ring_buffer.DirectEnqueueSize() << '\n' << '\n';

	char buffer[1000];	

	ring_buffer.Dequeue(buffer, 30);
	cout << "front : " << ring_buffer.GetFront() << ", rear : " << ring_buffer.GetRear() << '\n';
	cout << "free size : " << ring_buffer.GetFreeSize() << ", use size : " << ring_buffer.GetUseSize() << '\n';
	cout << "DirectDequeueSize : " << ring_buffer.DirectDequeueSize() << ", DirectEnqueueSize : " << ring_buffer.DirectEnqueueSize() << '\n' << '\n';

	ring_buffer.Enqueue("AAAAAAAAAAAAAAAAAAAAAAA", sizeof("AAAAAAAAAAAAAAAAAAAAAAA"));
	cout << "front : " << ring_buffer.GetFront() << ", rear : " << ring_buffer.GetRear() << '\n';
	cout << "free size : " << ring_buffer.GetFreeSize() << ", use size : " << ring_buffer.GetUseSize() << '\n';
	cout << "DirectDequeueSize : " << ring_buffer.DirectDequeueSize() << ", DirectEnqueueSize : " << ring_buffer.DirectEnqueueSize() << '\n' << '\n';


	ring_buffer.MoveFront(10);
	cout << "front : " << ring_buffer.GetFront() << ", rear : " << ring_buffer.GetRear() << '\n';
	cout << "free size : " << ring_buffer.GetFreeSize() << ", use size : " << ring_buffer.GetUseSize() << '\n';
	cout << "DirectDequeueSize : " << ring_buffer.DirectDequeueSize() << ", DirectEnqueueSize : " << ring_buffer.DirectEnqueueSize() << '\n' << '\n';

	/*
	char* buffer = (char*)malloc(sizeof(char) * 100000);


	int enqueue_pos = 0;
	int dequeue_pos = 0;

	while (1)
	{
		int EnOrDe = rand() % 2;
		
		if (EnOrDe == 0)
		{
			int data_size = rand() % 75;

			if (data_size + enqueue_pos > 100000)
			{
				ring_buffer.ClearBuffer();
				enqueue_pos = 0;
				dequeue_pos = 0;
			}

			int result = ring_buffer.Enqueue(test_str, data_size);
			for (int i = 0; i < result; i++)
			{
				buffer[enqueue_pos++] = test_str[i];
			}
		}
		else
		{
			int data_size = (rand() % 100) + 1;

			int peak_result = ring_buffer.Peak(peak_buffer, data_size);


			int result = ring_buffer.Dequeue(de_buffer, data_size);
			for (int i = 0; i < result; i++)
			{
				if (buffer[dequeue_pos] != de_buffer[i])
					__debugbreak();

				dequeue_pos++;
			}

			if (peak_result != result)
			{
				cout << "peak diff dequeue result!\n";
				__debugbreak();
			}

			for (int i = 0; i < result; i++)
			{
				if (de_buffer[i] != peak_buffer[i])
				{
					cout << "peak diff dequeue result!\n";
					__debugbreak();
				}
			}
		}

		cout << "front : " << ring_buffer.GetFront() << ", rear : " << ring_buffer.GetRear() << '\n';
		cout << "free size : " << ring_buffer.GetFreeSize() << ", use size : " << ring_buffer.GetUseSize() << '\n';

		if (ring_buffer.GetFreeSize() + ring_buffer.GetUseSize() != ring_buffer.GetBufferSize())
		{
			cout << "diff size!\n";
			__debugbreak();
		}
	}
	*/

	return 0;
}