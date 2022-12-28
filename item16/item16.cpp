#include <iostream>
#include <memory>

class numberList
{
public:
    numberList(int size)
    :size(size)
    {
        if(size == 1)
        {
            std::cout << "Constructed one number" << std::endl;
            number = new int;
        }
        else
        {
            std::cout << "Constructed several numbers" << std::endl;
            numberlist = new int[size] ;
        }
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

numberList* createNumberList(int size)
{
    return new numberList(size);
}

int main(void)
{
    
    std::shared_ptr<numberList> one_num(createNumberList(1));
    std::shared_ptr<numberList> two_num(createNumberList(2));

    return 0;
}