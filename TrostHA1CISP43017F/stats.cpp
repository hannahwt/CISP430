//  Hannah Trost
//  CISP 430 A1 Fall 2017
//  stats.cpp
//  TrostHA1CISP43017F
//  Implementation file for statistician class, designed to keep track
//  of simple statistics about a sequence of real numbers

#include "stats.h"
using namespace CISP430_A1;
using namespace std;

statistician::statistician(){
    count=0;
    total=0;
    tiniest=0;
    largest=0;
}

void statistician::next(double r){
    count++;
    total += r;
    if(count == 1){
        tiniest = r;
        largest = r;
    }else if(r < tiniest){
        tiniest = r;
    }else if(r > largest){
        largest = r;
    }
}

void statistician::reset(){
    count = 0;
    total = 0;
    tiniest = 0;
    largest = 0;
}

double statistician::mean() const{
    return total / count;
}

double statistician::minimum() const{
    return tiniest;
}

double statistician::maximum() const{
    return largest;
}

statistician CISP430_A1::operator +(const statistician& s1, const statistician& s2)
{
    statistician s3;
    s3.count = s1.count + s2.count;
    s3.total = s1.total + s2.total;
    if(s2.count == 0 || s1.tiniest < s2.tiniest){
        s3.tiniest = s1.tiniest;
    }else{
        s3.tiniest = s2.tiniest;
    }
    if(s1.largest > s2.largest){
        s3.largest = s1.largest;
    }else{
        s3.largest = s2.largest;
    }
    return s3;
}

statistician CISP430_A1::operator *(double scale, const statistician& s)
{
    statistician s2;
    s2.total = s.total * scale;
    if(scale > 0){
        s2.tiniest = s.tiniest*scale;
        s2.largest = s.largest*scale;
    }else{
        s2.tiniest = s.largest*scale;
        s2.largest = s.tiniest*scale;
    }
    s2.count = s.count;
    return s2;
}

bool CISP430_A1::operator ==(const statistician& s1, const statistician& s2)
{
    if(s1.length() == s2.length() && s1.sum() == s2.sum() && s1.minimum() == s2.minimum() && s1.maximum() == s2.maximum()){
        return true;
    } else{
        return false;
    }
}

