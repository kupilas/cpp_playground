#ifndef GUITAR_H_
#define GUITAR_H_

class Guitar
{
  public:
    static int n;
  private:
    int numberOfStrings;

  public:
    Guitar();
    ~Guitar(); // destructor
    
    int getNumberOfStrings();
};

#endif