#include <iostream>
#include <thread>
#include <future>

void produce(std::promise<int>& px)
{
    try 
    {
        int x = 42;
        px.set_value(x);
    } 
    catch(const std::exception& e) 
    {
        std::cerr << "Producer error: " << e.what() << std::endl;
    }
}

void consume(std::future<int>& fx)
{
    try 
    {
        int x = fx.get();
        std::cout << "Consumed: " << x << std::endl;
    } 
    catch(const std::exception& e) 
    {
        std::cerr << "Consumer error: " << e.what() << std::endl;
    }
}

int main() 
{
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();

    std::thread thr_producer(produce, std::ref(prom));
    std::thread thr_consumer(consume, std::ref(fut));

    thr_producer.join();
    thr_consumer.join();

    return 0;
}
