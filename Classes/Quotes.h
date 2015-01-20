//
//  Quotes.h
//  quotes
//
//  Created by Vlad on 20.01.15.
//
//

#ifndef __quotes__Quotes__
#define __quotes__Quotes__

#include <cocos2d.h>

#include <string>
#include <vector>

USING_NS_CC;

using namespace std;

class Quotes: public cocos2d::Node {
    
private:
    virtual ~Quotes();
    Quotes();
public:
    
    static string getNext();
    static string getPrev();
    static string getCurrent();
    
    static void load();
    
    
    
    void increaseIndex();
    void decreaseIndex();
    

private:
    
    static vector<string> _quotes;
    
    static Quotes *__sharedInstance;
    
    static int _currentIndex;
};

#endif /* defined(__quotes__Quotes__) */
