#include <iostream>
#include <memory>

class numberList
{
public:
    numberList(void)
    {
            std::cout << "Constructed one number" << std::endl;
            number = new int;
    }
    
    numberList(int size)
    :size(size)
    {
        std::cout << "Constructed several numbers" << std::endl;
        numberlist = new int[size] ;
    }

    ~numberList()
    {
        if(size == 1)
        {
            std::cout << "Destructed one number" << std::endl;
            delete number;
        }
        else
        {
            std::cout << "Destructed several numbers" << std::endl;
            delete [] numberlist;
        }

    }

private:
    int *numberlist;
    int *number;
    int size;
};

numberList* createNumberList()
{
    return new numberList();
}

numberList* createNumberList(int size)
{
    return new numberList(size);
}

int main(void)
{
    std::shared_ptr<numberList> one_num(createNumberList());
    std::shared_ptr<numberList> two_num(createNumberList(2));

    return 0;
}