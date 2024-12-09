


#include <iostream>
#include <chrono>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>



void tf(std::thread& t)
{
    std::cout << t.get_id() << std::endl;
}

std::mutex mut;
std::condition_variable cond;
std::queue<int> q;





#include <cassert>
#include <list>
#include <string>
#include <unordered_map>


const size_t n = 100;

struct Order {
    int id;
    std::string data;
};


std::list<Order> orders_list;
std::unordered_map<int, std::list<Order>::iterator> orders_map;

bool get_data(std::list<Order>& orders_list, std::unordered_map<int, std::list<Order>::iterator>& orders_map, Order& order, int order_id)
{
    if (orders_map.find(order_id) == orders_map.end()) {
        return false;
    }

    std::list<Order>::iterator it = orders_map[order_id];
    orders_list.splice(orders_list.begin(), orders_list, it);
    order = *it;
    return true;
}

void add_data(std::list<Order>& orders_list, std::unordered_map<int, Order>& orders_map, const Order& order)
{
    assert(orders_map.find(order.id) != orders_map.end());

    orders_list.push_front(order);
    const auto f = orders_list.front();
    orders_map[order.id] = f;

    if (orders_list.size() > n) {
        Order o = orders_list.back();
        orders_list.pop_back();
        orders_map.erase(o.id);
    }
}






void producer() {
    int counter = 0;
    while (counter < 1000) {
        std::lock_guard<std::mutex> lock(mut);
        q.push(counter++);
        cond.notify_one();
    }

}

void consumer()
{
    while (true) {
        std::unique_lock<std::mutex> lk(mut);
        cond.wait(lk, [] {return !q.empty(); });
        int val = q.front();
        q.pop(); lk.unlock();
        std::cout << val << std::endl;
    }
}


int main() {

    std::thread t1(producer);
    std::thread t2(consumer);

    tf(t1);

    t1.join();
    t2.join();
    return 0;
}