#pragma once
class RingBuffer
{
public:
	RingBuffer(int buffer_size = 10000);
	~RingBuffer();

	int GetBufferSize() const { return _size; };
	int GetUseSize() const;
	int GetFreeSize() const;
	int GetRear() const { return _rear; };
	int GetFront() const { return _front; };

	int Enqueue(const char* data, int data_size);
	int Dequeue(char* buffer, int buffer_size);
	int Peak(char* data, int data_size);
	void ClearBuffer();

	int	DirectEnqueueSize() const;
	int	DirectDequeueSize() const;

	int	MoveRear(int move_size);
	int	MoveFront(int move_size);

	char* GetFrontBufferPtr();
	char* GetRearBufferPtr();

private:
	char* _buffer;
	int _front = 0;
	int _rear = 0;
	int _size;
};