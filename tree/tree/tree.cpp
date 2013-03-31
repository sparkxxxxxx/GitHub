#include<iostream>
using namespace std;
#include<stack>
#include<string>
#include<queue>

template<typename T> class BinaryTree;
template <class T>
class BinaryTreeNode{
	friend class BinaryTree<T>;
private:
	T info;
	BinaryTreeNode<T> *leftchild;
	BinaryTreeNode<T> *rightchild;
	bool border;
public:
	BinaryTreeNode(){leftchild=NULL;rightchild=NULL;border=false;}
	BinaryTreeNode(const T& ele){info=ele;leftchild=NULL;rightchild=NULL;border=false;}
	BinaryTreeNode(const T& ele,BinaryTreeNode<T> *l,BinaryTreeNode<T> *r){info=ele;leftchild=l;rightchild=r;border=false;} 
	BinaryTreeNode<T> *getleftchild() const {return leftchild;}
	BinaryTreeNode<T> *getrightchild() const {return rightchild;}
	//void setbordertrue(){border=true;}
	//int  getborder(){return border;}
	T value() const {return info;}  
	void setLeftchild( BinaryTreeNode<T> *l){ leftchild=l;}
	void setRightchild( BinaryTreeNode<T> *r){ rightchild=r;}
	void setValue(const T& val){info= val;}
	 int Height();
	 int size();

	};
  enum Tags{Left,Right};
  template<class T>
  class StackElement{
  public:
    BinaryTreeNode<T> *pointer;
	Tags tag;
  };


template<class T>
class BinaryTree{
private:
	
	BinaryTreeNode<T> *root;

public:
	BinaryTree(){root=NULL;}
	void setBinaryTreeroot(BinaryTreeNode<T> *ele){root=ele;}
	//~BinaryTree();
	bool isEmpty() const{return root==NULL;}
	BinaryTreeNode<T>* getRoot(){return root;}
	BinaryTreeNode<T>* getParent(BinaryTreeNode<T> *current);
	BinaryTreeNode<T>* getLeftSibling(BinaryTreeNode<T> *current);
	BinaryTreeNode<T>* getRightSibling(BinaryTreeNode<T> *current);

	 void PreOrder(BinaryTreeNode<T> *root);   //前序遍历
	 void InOrder(BinaryTreeNode<T> *root);     //中序遍历
	 void PostOrder(BinaryTreeNode<T> *root);    //后序遍历
     void preexpressiontoTree(string str);    //前缀表达式转二叉树
	 void postexpressiontoTree(string str); 
	 void inexpressiontoTree(string str);
	void print(BinaryTreeNode<T> *root);
	};
template<class T> BinaryTreeNode<T>* BinaryTree<T>::getLeftSibling(BinaryTreeNode<T> *current){
	return root&&current?current->leftchild:NULL;
   }
template<class T> BinaryTreeNode<T>* BinaryTree<T>::getRightSibling(BinaryTreeNode<T> *current){
	return root&&current?current->rightchild:NULL;
  }

template<class T>int BinaryTreeNode<T>::Height(){
	if(this==NULL){
		return -1;
	}
	int lheight,rheight;
	lheight=this->leftchild->Height();
	rheight=this->rightchild->Height();
	return 1+(lheight>rheight?lheight:rheight);

}

template<class T> int BinaryTreeNode<T>::size(){
	if(this==NULL){
		return 0;
	}
	return 1+this->leftchild->size()+this->rightchild->size();
}



template<class T>void BinaryTree<T>::print(BinaryTreeNode<T> *root){
	   BinaryTreeNode<T> *pointer=root,*temp;
	   queue<BinaryTreeNode<T> *> Nodeque, infoque;
	    BinaryTreeNode<T> *point=root;
	   int p=1,leftN=0,RightN=0;
	   cout<<pointer->size();
	  
	   if(pointer){
		   Nodeque.push(pointer);
           infoque.push(pointer);
       while(1){
			   pointer=Nodeque.front();
			   Nodeque.pop();
			 
			   if(pointer->getleftchild()==NULL) {
			   infoque.push(new BinaryTreeNode<T> (' '));
			   Nodeque.push(new BinaryTreeNode<T> (' '));
			   }
		
			   else{  
				   Nodeque.push(pointer->getleftchild());
				   infoque.push(pointer->getleftchild());
				 p++;
			   }
			
			    if(pointer->getleftchild()==NULL) {
					infoque.push(new BinaryTreeNode<T> (' '));
			   Nodeque.push(new BinaryTreeNode<T> (' '));
				}
			
				else {
				   Nodeque.push(pointer->getrightchild());
				   infoque.push(pointer->getrightchild());
				   p++;
				}
			
	     if(p==point->size()) {break;}
			 
	   }
			 
 	   }
 
	   int n=point->Height()+1;
	   int k,a,r=1;
	
	   cout<<endl;
	   cout<<"二叉树树形表示"<<endl;
	   
	  while(!infoque.empty())//控制输出
  { for(int i=0;i<pow(2.0,n-r);i++) cout<<" ";          //控制每行开头的空格
	   for(int j=0;j<pow(2.0,r-1);j++)           //控制每行输出个数
	   { 
		   temp=infoque.front();
		   //if(temp->value()!=' '){
			   cout<<temp->value();
	      infoque.pop();
		//}
		 //  else
       //  {  cout<<" ";
		//infoque.pop();}
       for(int k=0;k<pow(2.0,n-r+1)-1;k++)
             cout<<" ";                     //每行内部空格控制
   
	  if(infoque.empty()) break;
	    }
     cout<<endl;
     r++;
	 // if(infoque.empty()) break;
}//while

}

template<class T> void BinaryTree<T>::PreOrder(BinaryTreeNode<T> *root){
	using std::stack;
	stack<BinaryTreeNode<T> *> stk;
	BinaryTreeNode<T> *pointer=root;
	stk.push(NULL);
	while(pointer){
		cout<<pointer->value();
		if(pointer->getrightchild()!=NULL)
			stk.push(pointer->getrightchild());
		if(pointer->getleftchild()!=NULL)
			pointer=pointer->getleftchild();
		else{
			pointer=stk.top();
				stk.pop();
		}
	}
	cout<<endl;
}



template<class T> void BinaryTree<T>::InOrder(BinaryTreeNode<T> *root){
     stack<BinaryTreeNode<T> *> stk;
	 int num=0;
     BinaryTreeNode<T> *pointer =root;
	BinaryTreeNode<T> *temp,*temp2=NULL;
while(!stk.empty()||pointer){
if(pointer){
	stk.push(pointer);
	pointer=pointer->getleftchild();
	temp=stk.top();
   if(pointer!=NULL){
      if((pointer->value()=='+'||pointer->value()=='-')&&(temp->value()=='*'||temp->value()=='/'))  
	  {cout<<"(";
	   num++;
	    temp2=pointer;
       }	
                     }

}
 else { 
		 pointer=stk.top();
	  temp=stk.top();
		 stk.pop();
	
		
		 cout<<pointer->value();
		 pointer=pointer->getrightchild();
		
		 
		 if(pointer!=NULL){
       if((pointer->value()=='+'||pointer->value()=='-')&&(temp->value()=='*'||temp->value()=='/'))  
	  {cout<<"(";
	   num++;
	    temp2=pointer;
       }	
                          }
		 if(temp2!=NULL){
	   if(temp2->getrightchild()==temp&&temp2->getrightchild()!=NULL) {
	 	 cout<<")";
	     num--;
	
	 //while(num>0){
	     //cout<<")";
	      // num--; }
 }
	                     }

 }
	 

}
	
	
	cout<<endl;
}




template<class T> void BinaryTree<T>::PostOrder(BinaryTreeNode<T> *root){
	 StackElement<T> element;
	 stack<StackElement<T>> stk; 
	 BinaryTreeNode<T> *pointer;
	 if(root==NULL) return;
	 else pointer=root;
	 while(!stk.empty()||pointer){
		 while(pointer!=NULL){
			 element.pointer=pointer;
			 element.tag=Left;
			 stk.push(element);
			 pointer=pointer->getleftchild();
		 }
		 element=stk.top();
		 stk.pop();
		 pointer=element.pointer;
		 if(element.tag==Left){
			 element.tag=Right;
			 stk.push(element);
			 pointer=pointer->getrightchild();

		 }
		 else{		 
			 cout<<pointer->value();
			 pointer=NULL;
		 }
	 }
	cout<<endl;
}

template<class T> void BinaryTree<T>::preexpressiontoTree(string str){
	   stack<BinaryTreeNode<T>*> nodeStack; 
	   BinaryTreeNode<T> *tempNode,*tempNode2;
	   for (int i=str.length()-1;i>=0;i--) {
    switch (str[i]) {
        case '+':
		case '-':
		case '*': 
		case '/':
               tempNode = nodeStack.top();
			   nodeStack.pop();
			   tempNode2=nodeStack.top();
               nodeStack.pop();
			 nodeStack.push(new BinaryTreeNode<T>(str[i],tempNode, tempNode2));
			   
            break;
        default:
            nodeStack.push(new BinaryTreeNode<T>(str[i]));
            break;
        }   
	 }
	 root=nodeStack.top();
	 nodeStack.pop();
}

//-----------------------------------------------------------------------------------
template<class T> void BinaryTree<T>::postexpressiontoTree(string str){
	 stack<BinaryTreeNode<T>*> nodeStack;
	  BinaryTreeNode<T> *tempNode,*tempNode2;
	  for (int i=0;i<str.length();i++) {
		  if(str[i]==' ') continue;
          switch (str[i]) {
        case '+':
		case '-':
		case '*':
		case '/':
			tempNode=nodeStack.top();
			nodeStack.pop();
			tempNode2=nodeStack.top();
			nodeStack.pop();
			nodeStack.push(new BinaryTreeNode<T>(str[i], tempNode2, tempNode));
            break;
        default:
            nodeStack.push(new BinaryTreeNode<T>(str[i]));
            break;
        }
    }
      root = nodeStack.top();
	  nodeStack.pop();
}


template<class T> void BinaryTree<T>::inexpressiontoTree(string str){
	int p=0; 
	string str2="                                    ";
	stack<char> stk;
	bool isnum1=false;
	for(int i=0;i<str.length();i++){ // for
 
if(str[i]=='(') {
	stk.push(str[i]);
}   // 是开括号


if(str[i]<='9'&& str[i]>='0') {
	str2[p]=str[i]; p++;
	isnum1=true;
}  //是数字
if(str[i]==')'){ // if    闭括号

if(!stk.empty()){	 //if 1 
do{
  str2[p]='\40';
p++;
	str2[p]=stk.top();
  stk.pop();  
  p++;
}while(stk.top()!='(');
} //if 1
if(stk.empty()) {
cout<<"error"<<endl; 


exit(0);}
if(stk.top()=='(') {stk.pop();}


}  // if

if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){ //if2   运算符
	
while(!stk.empty()&&stk.top()!='('){
if(((str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')&&(stk.top()=='*'||stk.top()=='/'))|| (str[i]=='+'||str[i]=='-')&&(stk.top()=='+'||stk.top()=='-') ){
    if(isnum1=true){
	str2[p]='\40';
	p++;}
	str2[p]=stk.top();
	stk.pop();
	p++;
	
		}
   
	break;
	}   // while
  stk.push(str[i]);
  str2[p]='\40';
  p++;
 isnum1=false;
}  // if2
}  // for

while(!stk.empty()){
	if(stk.top()=='('){
	cout<<"error"<<endl; 
	
	exit(0);}
str2[p]='\40';
p++;
str2[p]=stk.top();
stk.pop();
p++;

}
BinaryTree<T>::postexpressiontoTree(str2);


}





int main()
{
	int zx,swi,k=1;
	string str;
	BinaryTree<char> pretotree,intotree,posttotree;;
	cout<<"-----------------------------------------------------------------"<<endl;;
	cout<<"前缀表达式转二叉树...............................................1"<<endl;;
	cout<<"中缀表达式转二叉树...............................................2"<<endl;;
	cout<<"后缀表达式转二叉树...............................................3"<<endl;;
	cout<<"------------------------------------------------------------------"<<endl;;
	cin>>swi;
	switch(swi){
	case 1:
	cout<<"请输入前缀表达式"<<endl;
		cin>>str;
	pretotree.preexpressiontoTree(str);
	pretotree.print(pretotree.getRoot());
	//pretotree.setborderT(pretotree.getRoot());
	cout<<"输出前序遍历的结果"<<endl;
	pretotree.PreOrder(pretotree.getRoot());
	cout<<"输出中序遍历的结果"<<endl;
	pretotree.InOrder(pretotree.getRoot());
	cout<<"输出后序遍历的结果"<<endl;
	pretotree.PostOrder(pretotree.getRoot());
	
	break;
	case 2:
	cout<<"请输入中缀表达式"<<endl;
	cin>>str;
intotree.inexpressiontoTree(str);
	intotree.print(intotree.getRoot());
	cout<<"输出前序遍历的结果"<<endl;	
	intotree.PreOrder(intotree.getRoot());
	cout<<"输出中序遍历的结果"<<endl;
	intotree.InOrder(intotree.getRoot());
	cout<<"输出后序遍历的结果"<<endl;
	intotree.PostOrder(intotree.getRoot());
	
	break;
	case 3:
	cout<<"请输入后缀表达式"<<endl;
	cin>>str;
	posttotree.postexpressiontoTree(str);
	posttotree.print(posttotree.getRoot());
	cout<<"输出前序遍历的结果"<<endl;
	posttotree.PreOrder(posttotree.getRoot());
	cout<<"输出中序遍历的结果"<<endl;
	posttotree.InOrder(posttotree.getRoot());
    cout<<"输出后序遍历的结果"<<endl;
	posttotree.PostOrder(posttotree.getRoot());
	break;
	
	default:
		
		break;
	}
   	
cin>>zx;
return 0;
}