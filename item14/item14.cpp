#include <iostream>
#include <memory>
#include <mutex>

class myMutex{
    public:
        int counter;

        myMutex()
        :counter(0)
        {
            std::cout << "myMutex is constructed" << std::endl;
        }
        ~myMutex()
        {}
};

void lock(myMutex *pm)
{
    pm->counter++;
}

void unlock(myMutex *pm)
{
    pm->counter--;
    std::cout << "counter status " << pm->counter << std::endl;
}

class Lock{
    public:
        explicit Lock(myMutex *pm)
        :mutexPtr(pm, unlock)
        {
            lock(pm);
        }
    private:
        std::shared_ptr<myMutex> mutexPtr;
};

int main(void)
{
    myMutex *main_pm;

    main_pm = new myMutex();

    Lock lock1(main_pm);
    std::cout << "lock1 " << main_pm->counter << std::endl;

    Lock lock2(main_pm);
    std::cout << "lock2 " << main_pm->counter << std::endl;

    return 0;
}
