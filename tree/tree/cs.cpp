#include<iostream>
using namespace std;
#include<stack>
#include<string>
#include<stdlib.h>


class ZZH
{
public:
double N1,N2,num,ns;
 char *data[2];
char post[100];
 int i,p,l;
string infix;
stack<char> stk;
stack<double> sum;
 ZZH(){;}
void  Run(string a);
};


void ZZH::Run(string a){
char post[100]={' '};
infix=a;
bool isnum1=false;
p=0;
for(i=0;i<infix.length();i++){ // for
 
if(infix[i]=='(') {
	stk.push(infix[i]);
}   // ÊÇ¿ªÀ¨ºÅ


if(infix[i]<='9'&& infix[i]>='0') {
	post[p]=infix[i]; p++;
	isnum1=true;
}  //ÊÇÊý×Ö
if(infix[i]==')'){ // if    ±ÕÀ¨ºÅ

if(!stk.empty()){	 //if 1 
do{
  post[p]='\40';
p++;
	post[p]=stk.top();
  stk.pop();  
  p++;
}while(stk.top()!='(');
} //if 1
if(stk.empty()) {
cout<<"error"<<endl; 


exit(0);}
if(stk.top()=='(') {stk.pop();}


}  // if

if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'){ //if2   ÔËËã·û
	
while(!stk.empty()&&stk.top()!='('){
if(((infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/')&&(stk.top()=='*'||stk.top()=='/'))|| (infix[i]=='+'||infix[i]=='-')&&(stk.top()=='+'||stk.top()=='-') ){
    if(isnum1=true){
	post[p]='\40';
	p++;}
	post[p]=stk.top();
	stk.pop();
	p++;
	
		}
   
	break;
	}   // while
  stk.push(infix[i]);
  post[p]='\40';
  p++;
 isnum1=false;
}  // if2
}  // for

while(!stk.empty()){
	if(stk.top()=='('){
	cout<<"error"<<endl; 
	
	exit(0);}
post[p]='\40';
p++;
post[p]=stk.top();
stk.pop();
p++;

}

for(i=0;i<p;i++){
cout<<post[i];
}
for(i=0;i<p;i++){
if(post[i]<='9'&&post[i]>='0'){
	if(i==0){ 
		if(post[i+1]!=' ')  {}
		else
         sum.push(post[i]-'0');
	}
if((post[i-1]==' '||i==0)&&post[i+1]!=' '&&post[i]<'9'&&post[i]>'0'){
    data[0]=&post[i];
    data[1]=&post[i+1];
    ns=atol(*data);
	sum.push(ns);
  }
if((post[i-1]==' '&&post[i+1]==' ')) sum.push(post[i]-'0');

}
  
if(post[i]=='+'||post[i]=='-'||post[i]=='*'||post[i]=='/'){
	
	N1=(double)sum.top();
	sum.pop();
	N2=(double)sum.top();
	sum.pop();
	if(post[i]=='+')
	{   
		num=N1+N2;
		sum.push(num);
		  }
   if(post[i]=='-')
	   {
		   num=N2-N1;
		   sum.push(num);
   }
	if(post[i]=='*')
		{
			num=N1*N2;
		   sum.push(num);
	} 
if(post[i]=='/') 
	{
      num=N2/N1;
     sum.push(num);
}	
}
}
cout<<endl<<sum.top()<<endl;
cin>>l;
 }



void main()
{
string str;
 
cin>>str;

ZZH zzh;
zzh.Run(str);

} //main