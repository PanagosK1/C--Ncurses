#include "HiScore.h"
#include <iostream>
#include <string.h>

HiScore::HiScore(const string na,const int scor){
    name=na;
    score=scor;
}

HiScore::HiScore(){
}

HiScore::~HiScore(){
}

string HiScore::getName(){
    return name;
}

int HiScore::getScore() const{
    return score;
}

HiScore & HiScore::operator<<(const string na){
    this->name = na;
    return *this;
}


HiScore & HiScore::operator<<(const int scor){
    this->score = scor;
}


void HiScore::addScore(){
    if (scores.size()<5)
    {
        scores.push_back(this);
    }else if(scores.size()==5)
    {
        for(int i=0;i>5;i++){
            if (scores[i]->getScore() < this->getScore())
            {
                scores.at(i)= this;
            }
        }
    }
}


void HiScore::Score2binary(const string str){
    ofstream myfile (str,  std::ios::out | std::ios::binary | std::ios::app);
    if (!myfile.is_open()) {
        throw std::ios::failure("Error opening file");
    }
    int sc=0;

    for(int i = 0; i < scores.size(); i++){ 
        myfile.write(scores[i]->getName().c_str(),scores[i]->getName().size());
        //myfile.write(reinterpret_cast<const char *>(scores[i]->getScore()),sizeof(scores[i]->getScore()));
    }
    myfile.close();
}

void HiScore::Print(){
    for (int i = 0; i < scores.size(); i++)
    {
        cout<<"Score : " << scores[i]->getScore() << " Name : " <<  scores[i]->getName() << endl ;
    }
    
}

