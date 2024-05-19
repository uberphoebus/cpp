#include <iostream>
#include <thread>
#include <vector>

void worker(std::vector<int>::iterator start, std::vector<int>::iterator end,
            int *result) {
  int sum = 0;
  for (auto itr = start; itr != end; itr++) {
    sum += *itr;
  }
  *result = sum;

  std::thread::id this_id = std::this_thread::get_id();
  std::cout << "thread id: " << this_id << " | " << *start << " ~ "
            << *(end - 1) << " = " << sum << std::endl;
}

int main(void) {
  std::vector<int> data(10000);

  for (int i = 0; i < 10000; i++) {
    data[i] = i;
  }

  std::vector<int> partial_sums(4);

  std::vector<std::thread> workers;
  for (int i = 0; i < 4; i++) {
    workers.push_back(std::thread(worker, data.begin() + i * 2500,
                                  data.begin() + (i + 1) * 2500,
                                  &partial_sums[i]));
  }

  for (int i = 0; i < 4; i++) {
    workers[i].join();
  }

  int total = 0;
  for (int i = 0; i < 4; i++) {
    total += partial_sums[i];
  }
  std::cout << "total: " << total << std::endl;
}