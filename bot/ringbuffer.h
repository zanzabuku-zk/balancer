

template<typename T>
class RingBuffer {

public:
    explicit RingBuffer(size_t bufferSize) :
        bufferSize(bufferSize),
        backingBuffer(new T[bufferSize]),
        mask(bufferSize - 1),
        head(0),
        tail(0) {
    }

    RingBuffer(RingBuffer& other) = delete;
    RingBuffer& operator = (RingBuffer& other) = delete;

    RingBuffer(RingBuffer&& other)
    {
        delete[] backingBuffer;
        backingBuffer = other->backingBuffer;
        head = other->head;
        tail = other->tail;
    }

    virtual ~RingBuffer() {
        delete[] backingBuffer;
    }

    bool push(T& value) {
        using namespace std;

        size_t curHead = head.load(memory_order_relaxed);
        size_t nextHead = (curHead + 1) & mask;

        if (nextHead != tail.load(memory_order_acquire)) {
            backingBuffer[curHead] = value;
            head.store(nextHead, memory_order_release);
            return true;
        }
        else
            return false;
    }

    bool pop(T& value) {
        using namespace std;

        size_t curTail = tail.load(memory_order_relaxed);

        if (curTail != head.load(memory_order_acquire)) {
            value = backingBuffer[curTail];
            tail.store((curTail + 1) & mask, memory_order_release);
            return true;
        }
        else
            return false;
    }

    size_t size() {
        return head.load(std::memory_order_relaxed) - tail.load(std::memory_order_acquire);
    }

private:
    size_t bufferSize;
    T* backingBuffer;
    std::atomic <size_t> head;
    std::atomic <size_t> tail;
    size_t mask;
};wwwwwwwwwwww