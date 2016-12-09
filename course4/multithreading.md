#Multithreading


## Thread vs Process

- Threads share the same memory space. Pointers are valid in all the threads
- Processes are isolated, requires specific technique to communicate
- In game, only use threads


## Thread vs Fiber

- Fibers are threads you manage
- The os will not switch to and from them automatically
- You need to yield to give hand back to the system
- Threads are standardized in C++11, not fibers (Boost.Fiber)


<!-- .slide: class="smaller_text" -->
## Thread creation

```
#include <thread>
#include <mutex>
#include <iostream>

static const int num_threads = 20;

int main() {
     std::thread t[num_threads];
     int result = 0;

      for (int i = 0; i < num_threads; ++i) {
          t[i] = std::thread([&result, i]{

            for( int j = 0; j < i; ++j )
            {
                result ++;
            }
          });
     }

     //Join the threads with the main thread
     for (int i = 0; i < num_threads; ++i) {
         t[i].join();
     }

     std::cout << "Result : " << result << "\n";

     return 0;
 }
```


## What happens

| Thread 1 | Thread 2 |
|----------|----------|
| mov eax, [result] | |
| inc eax | mov eax, [result]|
|mov [result], eax | inc eax |
| | mov [result], eax |


<!-- .slide: class="smaller_text" -->
##Mutex

```
#include <mutex>

int main() {

     std::mutex result_mutex;

      for (int i = 0; i < num_threads; ++i) {
          t[i] = std::thread([&result, i, &result_mutex]{

            for( int j = 0; j < i; ++j )
            {
                result_mutex.lock();
                result ++;
                result_mutex.unlock();
            }
          });
     }

```


<!-- .slide: class="smaller_text" -->
##Mutex

```
#include <mutex>

int main() {

     std::mutex result_mutex;

      for (int i = 0; i < num_threads; ++i) {
          t[i] = std::thread([&result, i, &result_mutex]{

            for( int j = 0; j < i; ++j )
            {
                std::lock_guard<std::mutex> guard(result_mutex);
                result ++;
            }
          });
     }

```


##Monitor Object

```
template< typename T>
class lock_guard
{
    lock_guard(T & mutex) : mMutex(mutex){
        mMutex.lock();
    }

    ~lock_guard(){
        mMutex.unlock();
    }

    T & mMutex;
}
```


##Lock free

- Mutex are still expensive
- Most of the time it's not needed
- Algorithm and libraries can be found online


## Lock free / atomic operation

```
int main() {
     std::thread t[num_threads];
     int result = 0;

     for (int i = 0; i < num_threads; ++i) {
         t[i] = std::thread([&result, i, &result_mutex]{

            for( int j = 0; j < i; ++j )
            {
                InterlockedIncrement( &result );
            }
        });
    }

```


##Interlock

- Increment, Decrement, Add
- And, Or, Xor
- CompareExchange


##CompareExchange

```
new_node = ( NODE * ) byte_array;
next_tag.FirstFreeNodeIndex = GetNodeIndex( new_node );

do
{
    old_tag = Tag;
    next_tag.Identifier = old_tag.Identifier + 1;
    new_node->NextNodeIndex = old_tag.FirstFreeNodeIndex;
}
while ( !PARALLEL_CompareExchange( Tag, next_tag, old_tag ) );
```


##CompareExchange

```
do
{
    old_tag = Tag;
    next_tag = old_tag;

    if ( old_tag.FirstFreeNodeIndex == INDEX_None )
    {
        return VOID_Null;
    }

    next_tag.FirstFreeNodeIndex = GetNode( old_tag.FirstFreeNodeIndex )->NextNodeIndex;
    ++next_tag.Identifier;
}
while ( !PARALLEL_CompareExchange( Tag, next_tag, old_tag ) );
```


## Thread pool and task

- Thread creation is expensive
- Create thread once, used several times
- Task system (std::async in C++11)


<!-- .slide: class="smaller_text" -->
## C++11 task model

```
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>

template <typename Iter>
int parallel_sum(Iter beg, Iter end)
{
    auto len = end - beg;
    if(len < 1000)
    {
        return std::accumulate(beg, end, 0);
    }

    Iter mid = beg + len/2;
    auto handle = std::async(std::launch::async,
                             parallel_sum<RAIter>, mid, end);
    int sum = parallel_sum(beg, mid);
    return sum + handle.get();
}

int main()
{
    std::vector<int> v(10000, 1);
    std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << '\n';
}
```


##std::async behavior

- The future destructor wait for task completion

```
std::async(std::launch::async, []{ f(); }); // temporary's dtor waits for f()
std::async(std::launch::async, []{ g(); }); // does not start until f() completes
```


##Thread local storage

- Thread specific variable
- Managed by the os
- Used to be platform specific (TLSCreate, ...)
- Default in C++11


##TLS C++11

```
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

thread_local unsigned int rage = 1;
std::mutex cout_mutex;

void increase_rage(const std::string& thread_name)
{
    ++rage; // modifying outside a lock is okay; this is a thread-local variable
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "Rage counter for " << thread_name << ": " << rage << '\n';
}

int main()
{
    std::thread a(increase_rage, "a"), b(increase_rage, "b");

    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Rage counter for main: " << rage << '\n';
    }

    a.join();
    b.join();
}
```
