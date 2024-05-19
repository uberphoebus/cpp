#include <future>
#include <iostream>
#include <string>
#include <vector>

void worker(std::promise<std::string> *p) { p->set_value("Hello, World!"); }

int main(void) {
  std::promise<std::string> p;
  std::future<std::string> data =
      p.get_future(); // future is a read-only promise

  std::thread t(worker, &p);
  data.wait(); // wait until the promise is set

  std::cout << data.get() << std::endl; // get the value from the promise
  t.join();
}