#include<iostream>
class SN{// Stack Node
public:
double content;
SN* aNext;
};
SN* push(SN* oH, double x){
SN* nN;
nN=new SN;
nN->content=x;
nN->aNext=oH;
return nN;
}
SN* pop(SN* oH){
if(oH==nullptr){
return nullptr;
}
SN* nextNode;
nextNode=oH->aNext;
delete oH;
return nextNode;
}
double readTop(SN* aH){
if(aH==nullptr){
return 0.0;
}
return aH->content;
}
int isEmpty(SN* aH){
if(aH==nullptr){
return 1;
}
return 0;
}
void deleteStack(SN* aH){
while(aH!=nullptr){
aH=pop(aH);
}
}
class CCAccount{ // Credit Card Account
private:
std::string cName;// Name of the customer
double balance;
SN* aHT;// address of the Head of the stack of Transactions
public:
CCAccount(std::string );
std::string getName() ;
double getBalance() ;
void changeName(std::string, int);
// The first argument is new name;
// The second argument is a password -
// the programmers without the correct password
// cannot change the name
void addCharge(double);
void printStatement() ;// prints all transactions
~CCAccount();
};
CCAccount::CCAccount(std::string s){
cName=s;
balance=0.0;
aHT=nullptr;
}
std::string CCAccount::getName(){
return cName;
}
double CCAccount::getBalance(){
return balance;
}
void CCAccount::changeName(std::string newName, int p){
if(p==123){
cName=newName;
}
}
void CCAccount::addCharge(double x){
balance=balance+x;
aHT=push(aHT,x);
}
void CCAccount::printStatement(){
std::cout<<"The account holder "<<cName<<" has balance ";
std::cout<<balance<<".\n";
std::cout<<"The transactions are: ";
SN* runner;
runner=aHT;
while(runner!=nullptr){
std::cout<<runner->content<<"\t";
runner=runner->aNext;
}
std::cout<<"\n";
}
CCAccount::~CCAccount(){
std::cout<<"Deleting the account for "<<cName<<".\n";
deleteStack(aHT);
}
int main(){
CCAccount customerA("BSimpson");
customerA.addCharge(18.99);customerA.addCharge(5.23);customerA.addCharge(18.29);
customerA.printStatement();
int uI;
std::cout<<"Do you want to add another user? [1=yes, 0=no] ";
std::cin>>uI;
if(uI==1){
CCAccount customerB("LSimpson");
customerB.addCharge(20.01);customerB.addCharge(19.09);customerB.addCharge(79.95);
customerB.printStatement();customerA.printStatement();
}
customerA.printStatement();
return 0;
} 
