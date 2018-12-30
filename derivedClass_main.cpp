#include "derivedClass.h"

baseDMA::baseDMA(){
    label = "default base";
    rating = -1;
}
baseDMA::baseDMA(char *L, int r){
    label = L;
    rating = r;

}
baseDMA::baseDMA(const baseDMA & rs) {
    cout<<"base copy"<<endl;
    label = new char[strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating;
}

baseDMA & baseDMA::operator=(const baseDMA & rs) {
    cout<<"base assignment"<<endl;
    if (this == &rs)
        return *this;
    delete [] label;
    label = new char[strlen(rs.label) + 1];
    cout<<rs.label<<endl;
    strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}
//
void baseDMA::display(){
    cout<<"base display"<<" "<<label<<endl;
}
//---------------------------------------------
hasDMA::hasDMA(const hasDMA & hs) : baseDMA(hs) {
    cout<<"derived copy"<<endl;
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
}

hasDMA::hasDMA(){
    style = "default derived";
}
hasDMA::hasDMA(char *M, int m): baseDMA(M, m){

}
hasDMA & hasDMA::operator=(const hasDMA & hs) {
    cout<<"derived assignment"<<endl;
    if (this == &hs)
        return *this;
    baseDMA::operator=(hs);
    delete [] style;
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
    return *this;
}
//
void hasDMA::display(){
    cout<<"derived display"<<" "<<style<<endl;
}

int main(){
    baseDMA basetest("hello", 5);
    baseDMA basetest2("hi", 1);
    basetest2 = basetest;
    cout<<"---------------------------------"<<endl;
    hasDMA hastest("derived", 0);
    basetest = hastest;
    cout<<basetest.rating<<" "<<endl;
    cout<<"---------------------------------"<<endl;
    hasDMA hastest2;
    cout<<hastest2.rating<<endl;
    baseDMA &basetest4 = hastest;
    basetest4.display();

}

