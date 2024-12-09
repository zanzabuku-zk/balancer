
#pragma once

class BalancingBot
{
public:
	void run();

private:
	//RingBuffer<int> ringBuffer;
	std::shared_ptr<RingBuffer<float>> rb;

	//	std::shared_ptr<ClientOkex> clientOkex;

};