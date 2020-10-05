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
SN* copyStack(SN* originalHead){
SN* newHead=nullptr;
if(originalHead!=nullptr){
newHead=new SN;
newHead->content=originalHead->content;
newHead->aNext=copyStack(originalHead->aNext);
}
return newHead;
}
class CCAccount{ // Credit Card Account
private:
std::string cName;// Name of the customer
double balance;
SN* aHT;// address of the Head of the stack of Transactions
public:
CCAccount(const std::string& = "noNameYet");
CCAccount(const CCAccount& );
void operator=(const CCAccount& );
std::string getName() const;
double getBalance() const;
void changeName(const std::string&, const int&);
// The first argument is new name;
// The second argument is a password -
// the programmers without the correct password
// cannot change the name
void addCharge(const double&);
void printStatement() const;// prints all transactions
~CCAccount();
};
CCAccount::CCAccount(const std::string& s){
cName=s;
balance=0.0;
aHT=nullptr;
}
std::string CCAccount::getName() const{
return cName;
}
double CCAccount::getBalance() const{
return balance;
}
void CCAccount::changeName(const std::string& newName, const int & p){
if(p==123){
cName=newName;
}
}
void CCAccount::addCharge(const double& x){
balance=balance+x;
aHT=push(aHT,x);
}
void CCAccount::printStatement() const{
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
CCAccount::CCAccount(const CCAccount & copyFrom){
cName=copyFrom.cName;
balance=copyFrom.balance;
aHT=copyStack(copyFrom.aHT);
}
void CCAccount::operator=(const CCAccount & assignFrom){
if(&assignFrom != this){
deleteStack(aHT);
cName=assignFrom.cName;
balance=assignFrom.balance;
aHT=copyStack(assignFrom.aHT);
}
}
int main(){
CCAccount customerA("BSimpson");
customerA.addCharge(18.99);customerA.addCharge(5.23);customerA.addCharge(18.29);
customerA.printStatement();
int uI;
std::cout<<"Do you want to add another user? [1=yes, 0=no] ";
std::cin>>uI;
if(uI==1){
CCAccount customerB(customerA);
customerB.changeName("LisaSimpson",123);
customerB.addCharge(20.01);customerB.addCharge(19.09);customerB.addCharge(79.95);
customerB.printStatement();customerA.printStatement();
}
customerA.printStatement();
return 0;
} 
