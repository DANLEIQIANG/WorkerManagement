#include<iostream>
#include<string.h>
#include <fstream>
#include <cstdlib>
using namespace std;

class Staff      
{
protected:
	char num[10];
	char name[10];
	int age;	
public:
	char *get_num()
	{
		return num;
	}
	char *get_name()
	{
		return name;
	}
	int get_age()
	{
		return age;
	}
};

class Salesman:virtual public Staff
{
protected:
	char amount[10];
public:
	Salesman * Next;
	void set_Salesman()
	{
		cout<<"请输入编号："<<endl;
        cin>>num;
       	cout<<"请输入姓名："<<endl;
       	cin>>name;
       	cout<<"请输入年龄："<<endl;
       	cin>>age;
       	cout<<"请输入销售额："<<endl;      //增加销售额
       	cin>>amount;	

	}
	void InputFromFile(istream &in)
	{
		in>>num>>name>>age>>amount;
    }
	void show_Salesman()
	{
		cout<<"编号："<<num<<endl;
       	cout<<"姓名："<<name<<endl;
        cout<<"年龄："<<age<<endl;
        cout<<"销售额："<<amount<<endl;
    }
	char *get_amount()
	{
		return amount;
	}
};

class Manager:virtual public Staff
{
protected:
	char dep[10];
public:
	Manager * Next;
	void set_Manager()
	{
		cout<<"请输入编号："<<endl;
        cin>>num;
        cout<<"请输入姓名："<<endl;
        cin>>name;
       	cout<<"请输入年龄："<<endl;
       	cin>>age;
       	cout<<"请输入部门："<<endl;   //增加所在部门
		cin>>dep; 
	}
	void show_Manager()
	{
		cout<<"编号："<<num<<endl;
       	cout<<"姓名："<<name<<endl;
       	cout<<"年龄："<<age<<endl;
        cout<<"部门："<<dep<<endl; 
	}
	char *get_dep()
    {
		return dep;
	}
	void InputFromFile(istream &in)
	{
		in>>num>>name>>age>>dep;
	}

};

class SalesManager:public Salesman,public Manager
{
public:
	 SalesManager* Next;
	void set_SalesManager()
	{
		cout<<"请输入编号："<<endl;
        cin>>num;
      	cout<<"请输入姓名："<<endl;
      	cin>>name;        	
		cout<<"请输入年龄："<<endl;
       	cin>>age;
       	cout<<"请输入部门："<<endl;
		cin>>dep; 
       	cout<<"请输入销售额："<<endl;
       	cin>>amount;

	}
	void InputFromFile(istream &in)
	{
		in>>num>>name>>age>>dep>>amount;
	}
	void show_SalesManager()
	{
		cout<<"编号："<<num<<endl;
       	cout<<"姓名："<<name<<endl;
       	cout<<"年龄："<<age<<endl;
		cout<<"部门："<<dep<<endl; 
       	cout<<"销售额："<<amount<<endl;

	}
};



class Salesman_operation
{
public:
	Salesman_operation();
	~Salesman_operation();
	void addinfo();
	void searchinfo();                   
	void save();                  
	void savedelete();
	void modifyinfo();           
	void deleteinfo();             
	int count;

private:
	Salesman * Head,* End;
	ifstream in;                      //文件输入
	ofstream out;                     //文件输出

};

Salesman_operation::Salesman_operation()                        //构造函数
{ 
	Head=new Salesman;
	Head->Next=new Salesman;
	End=Head->Next;
	count=0;
	in.open("F:\\oop_txt\\Salesman.txt");
	while(!in.eof())
	{
		count++;
		End->InputFromFile(in);
		if(End->get_num()[0]=='\0')
			break;
		End->Next=new Salesman;
		End=End->Next;
	}
	in.close();
}

Salesman_operation::~Salesman_operation()                     //析构函数
{
	for(Salesman * temp;Head->Next!=End;)
	{
		temp=Head->Next;
		Head->Next=Head->Next->Next;
		delete temp;
	}
	delete Head,End;
}

void Salesman_operation::addinfo()
{
	End->set_Salesman();
	End->Next=new Salesman;
	End=End->Next;
	save();
}
void Salesman_operation::searchinfo()                      //查找条目
{
	char num[10];
	Salesman * p=NULL,*px=NULL;
	int flag=0;
	cout<<"请输入要查找销售员号：";
	cin>>num;
	for(p=Head;p->Next!=End;p=p->Next)
	{
		if(strcmp(p->Next->get_num() ,num)==0)
		{
			flag=1;
		    px=p;
		}  
	}	   
	if(flag==1)
		px->Next->show_Salesman();
	else
		cout<<"没有找到!!"<<endl<<endl;
}

void Salesman_operation::modifyinfo()                //修改条目
{
	char num[10];
	Salesman * p=NULL,*px=NULL;
	cout<<"已存在的销售员信息："<<endl;
	 for(p=Head->Next;p!=End;p=p->Next)
	 {
	 	cout<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_amount()<<endl;
	 }
	 cout<<endl;
	cout<<"请输入要修改销售员编号：";
	int flag=0;
	cin>>num;
	for(p=Head;p->Next!=End;p=p->Next)
	{
		if(strcmp(p->Next->get_num() ,num)==0)
		{
			flag=1;
		    px=p;
		}  
	}	   
	if(flag==1)
	{
		px->Next->show_Salesman();
		cout<<"请输入新的内容："<<endl;
		px->Next->set_Salesman();
	}
	else
		cout<<"没有找到!!"<<endl<<endl;
	save();
}

void Salesman_operation::deleteinfo()              //删除条目
{
	char num[10];
	Salesman *p=NULL,*temp=NULL,*px=NULL;
	int flag=0; 
	cout<<"已存在的销售信息："<<endl;
	 for(p=Head->Next;p!=End;p=p->Next)
	 {
	 	cout<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_amount()<<endl;
	 }
	 cout<<endl; 
	cout<<"请输入要删除销售员编号：";
	cin>>num;
	for(p=Head;p->Next!=End;p=p->Next)
	{
		if(strcmp(p->Next->get_num() ,num)==0)
		{
			flag=1;
		    px=p;
		}  
	}	   
	if(flag==1)
	{
		temp=px->Next;
		px->Next=px->Next->Next;
		delete temp;
		cout<<"删除成功!!"<<endl<<endl;
	}
	else
		cout<<"没有找到!!"<<endl<<endl;
	
	
}

void Salesman_operation::save()                    //保存
{
	out.open("F:\\oop_txt\\Salesman.txt");
	for(Salesman * p=Head->Next;p!=End;p=p->Next)
		out<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_amount()<<endl;
		
	out.close();
}
void Salesman_operation::savedelete()                    //保存删除
{
	out.open("F:\\oop_txt\\Salesman.txt");
	for(Salesman * p=Head->Next;p->Next!=End;p=p->Next)
		out<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_amount()<<endl;
		
	out.close();
}

class Manager_operation
{
public:
	Manager_operation();
	~Manager_operation();
	void addinfo();
	void searchinfo();                  
	void save();    
	void savedelete();              	
void modifyinfo();             
	void deleteinfo();            
    int count;
private:
	Manager * Head,* End;
	ifstream in;                      //文件输入
	ofstream out;                     //文件输出

};

Manager_operation::Manager_operation()                        //构造函数
{ 
	Head=new Manager;
	Head->Next=new Manager;
	End=Head->Next;
	count=0;
	in.open("F:\\oop_txt\\Manager.txt");
	while(!in.eof())
	{
		count++;
		End->InputFromFile(in);
		if(End->get_num()[0]=='\0')
			break;
		End->Next=new Manager;
		End=End->Next;
	}
	in.close();
}

Manager_operation::~Manager_operation()                     //析构函数
{
	for(Manager *temp;Head->Next!=End;)
	{
		temp=Head->Next;
		Head->Next=Head->Next->Next;
		delete temp;
	}
	delete Head,End;
}

void Manager_operation::searchinfo()                      //查找条目
{
	char num[10];
	Manager *p=NULL,*px=NULL;
	int flag=0;
	cout<<"请输入要查找经理号：";
	cin>>num;
	for(p=Head;p->Next!=End;p=p->Next)
	{
		if(strcmp(p->Next->get_num() ,num)==0)
		{
			flag=1;
		    px=p;
		}  
	}	   
	if(flag==1)
		px->Next->show_Manager();
	else
		cout<<"没有找到!!"<<endl<<endl;
}

void Manager_operation::addinfo()
{
	End->set_Manager();
	End->Next=new Manager;
	End=End->Next;
	save();
}
void Manager_operation::modifyinfo()                //修改条目
{
	char num[10];
	Manager * p=NULL,*px=NULL;
	
	cout<<"已存在经理编号："<<endl;
	 for(p=Head->Next;p->Next!=End;p=p->Next)
	 {
	 	cout<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_dep()<<endl;
	 }
	 cout<<endl; 
	 cout<<"请输入要修改经理编号：";
	int flag=0;
	cin>>num;
	for(p=Head;p->Next!=End;p=p->Next)
	{
		if(strcmp(p->Next->get_num() ,num)==0)
		{
			flag=1;
		    px=p;
		}  
	}	   
	if(flag==1)
	{
		px->Next->show_Manager();
		cout<<"请输入新的内容："<<endl;
		px->Next->set_Manager();
	}
	else
		cout<<"没有找到!!"<<endl<<endl;
	save();
}

void Manager_operation::deleteinfo()              //删除条目
{
	char num[10];
	Manager *p=NULL,*temp=NULL,*px=NULL;
	int flag=0; 
	cout<<"已存在的经理编号："<<endl;
	 for(p=Head->Next;p->Next!=End;p=p->Next)
	 {
	 	cout<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_dep()<<endl;
	 }
	 cout<<endl; 
	cout<<"请输入要删除经理编号：";
	cin>>num;
	for(p=Head;p->Next!=End;p=p->Next)
	{
		if(strcmp(p->Next->get_num() ,num)==0)
		{
			flag=1;
		    px=p;
		}  
	}	   
	if(flag==1)
	{
		temp=px->Next;
		px->Next=px->Next->Next;
		delete temp;
		cout<<"删除成功!!"<<endl<<endl;
	}
	else
		cout<<"没有找到!!"<<endl<<endl;
	
	
}

void Manager_operation::save()                    //保存
{
	out.open("F:\\oop_txt\\Manager.txt");
	for(Manager * p=Head->Next;p!=End;p=p->Next)
		out<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_dep()<<endl;
	out.close();
}
void Manager_operation::savedelete()                    //保存
{
	out.open("F:\\oop_txt\\Manager.txt");
	for(Manager * p=Head->Next;p->Next!=End;p=p->Next)
		out<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_dep()<<endl;
		
	out.close();
}

class SalesManager_operation
{
public:
	SalesManager_operation();
	~SalesManager_operation();
	void addinfo();
	void searchinfo();                   
	void save();                   
	void savedelete(); 
	void modifyinfo();            
	void deleteinfo(); 
	int count;  

	
private:
	SalesManager *Head,*End;
	ifstream in;                      //文件输入
	ofstream out;                     //文件输出
};

SalesManager_operation::SalesManager_operation()                 //构造函数
{ 
	Head=new SalesManager;
	Head->Next=new SalesManager;
	End=Head->Next;
	count=0;
	in.open("F:\\oop_txt\\SalesManager.txt");
	while(!in.eof())
	{
		count++;
		End->InputFromFile(in);
		if(End->get_num()[0]=='\0')
			break;
		End->Next=new SalesManager;
		End=End->Next;
	}
	in.close();
}

SalesManager_operation::~SalesManager_operation()              //析构函数
{
	for(SalesManager *temp;Head->Next!=End;)
	{
		temp=Head->Next;
		Head->Next=Head->Next->Next;
		delete temp;
	}
	delete Head,End;
}
void SalesManager_operation::addinfo()
{
	End->set_SalesManager();
	End->Next=new SalesManager;
	End=End->Next;
	save();
}
void SalesManager_operation::searchinfo()                      //查找条目
{
	char num[10];
	SalesManager *p=NULL,*px=NULL;
	int flag=0;
	cout<<"请输入要查找销售经理号：";
	cin>>num;
	for(p=Head;p->Next!=End;p=p->Next)
	{
		if(strcmp(p->Next->get_num() ,num)==0)
		{
			flag=1;
		    px=p;
		}  
	}	   
	if(flag==1)
		px->Next->show_SalesManager();
	else
		cout<<"没有找到!!"<<endl<<endl;
}

void SalesManager_operation::modifyinfo()                //修改条目
{
	char num[10];
	SalesManager *p=NULL,*px=NULL;
	cout<<"已存在的销售经理编号："<<endl;
	 for(p=Head->Next;p!=End;p=p->Next)
	 {
	 	cout<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_dep()<<" "<<p->get_amount()<<endl;
	 }
	 cout<<endl; 
	cout<<"请输入要修改销售经理编号：";
	int flag=0;
	cin>>num;
	for(p=Head;p->Next!=End;p=p->Next)
	{
		if(strcmp(p->Next->get_num() ,num)==0)
		{
			flag=1;
		    px=p;
		}  
	}	   
	if(flag==1)
	{
		px->Next->show_SalesManager();
		cout<<"请输入新的内容："<<endl;
		px->Next->set_SalesManager();
	}
	else
		cout<<"没有找到!!"<<endl<<endl;
	save();
}


void SalesManager_operation::deleteinfo()              //删除条目
{
	char num[10];
	SalesManager *p=NULL,*temp=NULL,*px=NULL;
	int flag=0; 
	cout<<"已存在的销售经理编号："<<endl;
	 for(p=Head->Next;p!=End;p=p->Next)
	 {
	 	cout<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_dep()<<" "<<p->get_amount()<<endl;
	 }
	 cout<<endl; 
	cout<<"请输入要删除销售经理编号：";
	cin>>num;
	for(p=Head;p->Next!=End;p=p->Next)
	{
		if(strcmp(p->Next->get_num() ,num)==0)
		{
			flag=1;
		    px=p;
		}  
	}	   
	if(flag==1)
	{
		temp=px->Next;
		px->Next=px->Next->Next;
		delete temp;
		cout<<"删除成功!!"<<endl<<endl;
	}
	else
		cout<<"没有找到!!"<<endl<<endl;
	
}

void SalesManager_operation::save()                    //保存
{
	out.open("F:\\oop_txt\\SalesManager.txt");
	for(SalesManager * p=Head->Next;p!=End;p=p->Next)
		out<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_dep()<<" "<<p->get_amount()<<endl;
	out.close();
}
void SalesManager_operation::savedelete()                    //保存删除
{
	out.open("F:\\oop_txt\\SalesManager.txt");
	for(SalesManager * p=Head->Next;p->Next!=End;p=p->Next)
		out<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_dep()<<" "<<p->get_amount()<<endl;
		
	out.close();
}
int main()
{
	Salesman_operation salesman;
	Manager_operation manager;
	SalesManager_operation salesmanager;
	char choice,choiceit;
    cout<<"                  C++大作业                 "<<endl;
    cout<<"******************MyCompany*******************"<<endl;
    cout<<"请选择操作："<<endl;
    cout<<"[1]增加数据             ";
    cout<<"[2]更新数据"<<endl;
    cout<<"[3]查询数据             ";
    cout<<"[4]删除数据"<<endl;
    cout<<"[5]保存删除             ";
    cout<<"[6]查询人数"<<endl; 
    cout<<"[7]退出系统"<<endl<<endl;
    while(cin>>choice)                
    {
        if(choice=='1')
        {
        	
        	cout<<"[1]增加销售员：";             
    		cout<<"[2]增加经理：";
   			cout<<"[3]增加销售经理：";
    		cout<<"[4]返回"<<endl;
			cin>>choiceit;
    		if(choiceit=='1')
    		    salesman.addinfo();
    		if(choiceit=='2')    
                 manager.addinfo();
            if(choiceit=='3')
            	salesmanager.addinfo();
            else if(choiceit=='4')
           	{
        		cout<<"已返回"<<endl;
        		continue;
    		}
        }
        else if(choice=='2')
        {
        	
            cout<<"[1]修改销售员：";              
            cout<<"[2]修改经理：";
    		cout<<"[3]修改销售经理：";
    		cout<<"[4]返回"<<endl;cin>>choiceit;
            if(choiceit=='1')
    		    salesman.modifyinfo();
    		if(choiceit=='2')    
                 manager.modifyinfo();
            if(choiceit=='3')
            	salesmanager.modifyinfo();
            else if(choiceit=='4')
           	{
        		cout<<"已返回"<<endl;
        		continue;
    		}
        } 
        else if(choice=='3')
        {
        	
            cout<<"[1]查看销售员：";            
    		cout<<"[2]查看经理：";
    		cout<<"[3]查看销售经理：";
    		cout<<"[4]返回"<<endl;cin>>choiceit;
    		if(choiceit=='1')
    		    salesman.searchinfo();
    		if(choiceit=='2')    
                 manager.searchinfo();
            if(choiceit=='3')
            	salesmanager.searchinfo();
            else if(choiceit=='4')
           	{
        		cout<<"已返回"<<endl;
        		continue;
    		}
        }
       else if(choice=='4')
        {
            
            cout<<"[1]删除销售员：";             
            cout<<"[2]删除经理：";
    		cout<<"[3]删除销售经理：";
    		cout<<"[4]返回"<<endl;cin>>choiceit;
            if(choiceit=='1')
    		    salesman.deleteinfo();
    		if(choiceit=='2')    
                 manager.deleteinfo();
            if(choiceit=='3')
            	salesmanager.deleteinfo();
            else if(choiceit=='4')
           	{
        		cout<<"已返回"<<endl;
        		continue;
    	    }
        }
        if(choice=='5')
		{
			salesman.savedelete();
			manager.savedelete();
			salesmanager.savedelete();
		 } 
		 if(choice=='6')
		 {
		 	cout<<"售货员人数："<<(salesman.count)<<endl;
		 	cout<<"经理人数："<<(manager.count)<<endl;
		 	cout<<"销售经理人数："<<(salesmanager.count)<<endl;
		 	cout<<"总人数："<< (salesman.count+manager.count+salesmanager.count)<<endl<<endl;
		 	
		 }
        else if(choice=='7')
        {
            break;
        }
        cout<<"本次操作执行完毕"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"请选择操作"<<endl;
        cout<<"[1]增加数据             ";
    	cout<<"[2]更新数据"<<endl;
    	cout<<"[3]查询数据             ";
    	cout<<"[4]删除数据"<<endl;
    	cout<<"[5]保存删除             ";
    	cout<<"[6]查询人数"<<endl; 
        cout<<"[7]退出系统"<<endl<<endl;
    }
	return 0;
}

 

