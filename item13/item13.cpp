#include <iostream>
#include <memory>

class Investment
{
    public:
    std::string _caller;

    Investment(std::string caller)
    :_caller(caller)
    {
         std::cout << "constructed Investment " << _caller << std::endl; 
    };

    ~Investment()
    {
         std::cout << "destructed Investment " << _caller << std::endl; 
    };
};




Investment* createInvestment(std::string callerfunc)
{
    return new Investment(callerfunc) ;
};

void f_NoAutoPtr()
{
    Investment *plnv = createInvestment(__func__);
}

void f_UseAutoPtr()
{
    std::auto_ptr<Investment> plnv(createInvestment(__func__));    
}

int main(void)
{
    f_NoAutoPtr();

    f_UseAutoPtr();

    return 0;
}