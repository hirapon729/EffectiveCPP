#include <iostream>

class FontHandle{
public:

    int size; 

    FontHandle()
    :size(1)
    {}

};

void changeFontSize(FontHandle *fh, int newSize)
{
    fh->size = newSize;
}

void releaseFont(FontHandle *fh)
{
    fh->size = 0;
    std::cout << " is released!" << std::endl;
};

class Font{
public:
    explicit Font(FontHandle* fh, int number)
    :f(fh),id(number)
    {}
    ~Font() { std::cout << "f" << id; releaseFont(f); }

    FontHandle* get() const { return f; }
    operator FontHandle*() const { return f; }
    FontHandle* operator->() const {return f;}

private:
    FontHandle* f;
    int id;
};

int main(void)
{
    
    // Bad use
    FontHandle* main_fh;
    changeFontSize( main_fh, 11);
    std::cout << "main_fh font size:" << main_fh->size << std::endl; 

    // Good use
    Font f1(main_fh, 1);
    changeFontSize( f1.get(), 15);
    std::cout << "f1 font size:" << f1.get()->size << std::endl; 

    // Good use
    Font f2(main_fh, 2);
    changeFontSize( f2, 18 );
    std::cout << "f2 font size:" << f2->size << std::endl;

    // Bad use
    FontHandle* main_fh2;
    main_fh2 = f2;
    f2.~Font(); // main_f2 is released
    std::cout << "main_fh font size: " << main_fh->size << std::endl; 

}