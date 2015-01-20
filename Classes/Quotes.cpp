//
//  Quotes.cpp
//  quotes
//
//  Created by Vlad on 20.01.15.
//
//

#include "Quotes.h"
#include "json/document.h"

using namespace cocos2d;
using namespace std;

Quotes *Quotes::__sharedInstance = nullptr;
int Quotes::_currentIndex = 0;
vector<string> Quotes::_quotes;

Quotes::~Quotes(){
    
}

Quotes::Quotes(){
    
}


void Quotes::load(){
    if(__sharedInstance == nullptr) {
        __sharedInstance = new Quotes();
    } else {
        return;
    }
    
    unsigned char *t = nullptr;
    ssize_t stringsDataSize = 0;
    t = (FileUtils::getInstance()->getFileData("quotes.json", "r", &stringsDataSize));
    
    char *stringsData = new char[stringsDataSize + 1];
    memcpy(stringsData, t, stringsDataSize);
    stringsData[stringsDataSize] = NULL;
    
    delete[] t;
    t = NULL;
    
    rapidjson::Document stringsDoc;
    stringsDoc.Parse<0>(stringsData);
    
    const auto &strArray = stringsDoc["quotes"];
    
    if(strArray.IsArray()) {
        for(auto it = strArray.onBegin(); it != strArray.onEnd(); ++it) {
            _quotes.push_back(it->GetString());
        }
    }
    
    delete[] stringsData;

}

string Quotes::getNext(){
    __sharedInstance->increaseIndex();
    return _quotes[_currentIndex];
}

string Quotes::getPrev(){
    __sharedInstance->decreaseIndex();
    return _quotes[_currentIndex];
}

string Quotes::getCurrent(){
    return _quotes[_currentIndex];
}

void Quotes::increaseIndex(){
    _currentIndex++;
    if(_currentIndex > _quotes.size() - 1){
        _currentIndex = 0;
    }
}

void Quotes::decreaseIndex(){
    _currentIndex--;
    if(_currentIndex < 0){
        _currentIndex = _quotes.size() - 1;
    }
}