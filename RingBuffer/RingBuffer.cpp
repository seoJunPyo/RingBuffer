#include "RingBuffer.h"
#include <memory>

RingBuffer::RingBuffer(int buffer_size) : _size(buffer_size)
{
    _buffer = (char*)malloc(sizeof(char) * _size + 1);
}

RingBuffer::~RingBuffer()
{
    free(_buffer);
}

int RingBuffer::GetUseSize() const
{
    if (_front <= _rear)
        return _rear - _front;

    else
        return (_size - _front) + _rear + 1;
}

int RingBuffer::GetFreeSize() const
{
    if (_front <= _rear)
        return (_size - _rear) + _front;

    else
        return _front - _rear - 1;
}

int RingBuffer::Enqueue(const char* data, int data_size)
{
    int free_size = GetFreeSize();

    if (data_size > free_size)
        data_size = free_size;

    for (int i = 0; i < data_size; i++)
    {
        _buffer[_rear] = data[i];

        if (_rear == _size)
            _rear = 0;
        else
            ++_rear;
    }

    return data_size;
}

int RingBuffer::Dequeue(char* data, int data_size)
{
    int use_size = GetUseSize();

    if (data_size > use_size)
        data_size = use_size;

    for (int i = 0; i < data_size; i++)
    {
        data[i] = _buffer[_front];

        if (_front == _size)
            _front = 0;
        else
            _front++;
    }

    return data_size;
}

int RingBuffer::Peak(char* data, int data_size)
{
    int use_size = GetUseSize();
    int readPos = _front;

    if (data_size > use_size)
        data_size = use_size;

    for (int i = 0; i < data_size; i++)
    {
        data[i] = _buffer[readPos];

        if (readPos == _size)
            readPos = 0;
        else
            readPos++;
    }

    return data_size;
}

void RingBuffer::ClearBuffer()
{
    _front = 0;
    _rear = 0;
}

int RingBuffer::DirectEnqueueSize() const
{
    int diff = _size - _rear;
    int free_size = GetFreeSize();

    if (free_size >= diff)
        return diff;
    else
        return free_size;
}

int RingBuffer::DirectDequeueSize() const
{
    int diff = _size - _front;
    int use_size = GetUseSize();

    if (use_size >= diff)
        return diff;
    else
        return use_size;
}

int RingBuffer::MoveRear(int move_size)
{
    int free_size = GetFreeSize();

    if (free_size < move_size)
        move_size = free_size;

    _rear += move_size;
    if (_rear >= _size)
        _rear -= (_size + 1);

    return move_size;
}

int RingBuffer::MoveFront(int move_size)
{
    int use_size = GetUseSize();

    if (use_size < move_size)
        move_size = use_size;

    _front += move_size;
    if (_front > _size)
        _front -= (_size + 1);

    return move_size;
}

char* RingBuffer::GetFrontBufferPtr()
{
    return &_buffer[_front];
}

char* RingBuffer::GetRearBufferPtr()
{
    return &_buffer[_rear];
}