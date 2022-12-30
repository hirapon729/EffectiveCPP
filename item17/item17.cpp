#include <iostream>
#include <memory>

class Widget
{
public:
    Widget()
    {
        std::cout << "Widget is created" << std::endl;
    }
};

int priority()
{
    std::cout << "priority is called" << std::endl;
    return 0;
}

void processWidget(std::shared_ptr<Widget> pw, int priority)
{
}

int main()
{
    processWidget(std::shared_ptr<Widget>(new Widget),priority());
    return 0;
}