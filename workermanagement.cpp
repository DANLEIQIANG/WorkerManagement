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
		cout<<"�������ţ�"<<endl;
        cin>>num;
       	cout<<"������������"<<endl;
       	cin>>name;
       	cout<<"���������䣺"<<endl;
       	cin>>age;
       	cout<<"���������۶"<<endl;      //�������۶�
       	cin>>amount;	

	}
	void InputFromFile(istream &in)
	{
		in>>num>>name>>age>>amount;
    }
	void show_Salesman()
	{
		cout<<"��ţ�"<<num<<endl;
       	cout<<"������"<<name<<endl;
        cout<<"���䣺"<<age<<endl;
        cout<<"���۶"<<amount<<endl;
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
		cout<<"�������ţ�"<<endl;
        cin>>num;
        cout<<"������������"<<endl;
        cin>>name;
       	cout<<"���������䣺"<<endl;
       	cin>>age;
       	cout<<"�����벿�ţ�"<<endl;   //�������ڲ���
		cin>>dep; 
	}
	void show_Manager()
	{
		cout<<"��ţ�"<<num<<endl;
       	cout<<"������"<<name<<endl;
       	cout<<"���䣺"<<age<<endl;
        cout<<"���ţ�"<<dep<<endl; 
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
		cout<<"�������ţ�"<<endl;
        cin>>num;
      	cout<<"������������"<<endl;
      	cin>>name;        	
		cout<<"���������䣺"<<endl;
       	cin>>age;
       	cout<<"�����벿�ţ�"<<endl;
		cin>>dep; 
       	cout<<"���������۶"<<endl;
       	cin>>amount;

	}
	void InputFromFile(istream &in)
	{
		in>>num>>name>>age>>dep>>amount;
	}
	void show_SalesManager()
	{
		cout<<"��ţ�"<<num<<endl;
       	cout<<"������"<<name<<endl;
       	cout<<"���䣺"<<age<<endl;
		cout<<"���ţ�"<<dep<<endl; 
       	cout<<"���۶"<<amount<<endl;

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
	ifstream in;                      //�ļ�����
	ofstream out;                     //�ļ����

};

Salesman_operation::Salesman_operation()                        //���캯��
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

Salesman_operation::~Salesman_operation()                     //��������
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
void Salesman_operation::searchinfo()                      //������Ŀ
{
	char num[10];
	Salesman * p=NULL,*px=NULL;
	int flag=0;
	cout<<"������Ҫ��������Ա�ţ�";
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
		cout<<"û���ҵ�!!"<<endl<<endl;
}

void Salesman_operation::modifyinfo()                //�޸���Ŀ
{
	char num[10];
	Salesman * p=NULL,*px=NULL;
	cout<<"�Ѵ��ڵ�����Ա��Ϣ��"<<endl;
	 for(p=Head->Next;p!=End;p=p->Next)
	 {
	 	cout<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_amount()<<endl;
	 }
	 cout<<endl;
	cout<<"������Ҫ�޸�����Ա��ţ�";
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
		cout<<"�������µ����ݣ�"<<endl;
		px->Next->set_Salesman();
	}
	else
		cout<<"û���ҵ�!!"<<endl<<endl;
	save();
}

void Salesman_operation::deleteinfo()              //ɾ����Ŀ
{
	char num[10];
	Salesman *p=NULL,*temp=NULL,*px=NULL;
	int flag=0; 
	cout<<"�Ѵ��ڵ�������Ϣ��"<<endl;
	 for(p=Head->Next;p!=End;p=p->Next)
	 {
	 	cout<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_amount()<<endl;
	 }
	 cout<<endl; 
	cout<<"������Ҫɾ������Ա��ţ�";
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
		cout<<"ɾ���ɹ�!!"<<endl<<endl;
	}
	else
		cout<<"û���ҵ�!!"<<endl<<endl;
	
	
}

void Salesman_operation::save()                    //����
{
	out.open("F:\\oop_txt\\Salesman.txt");
	for(Salesman * p=Head->Next;p!=End;p=p->Next)
		out<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_amount()<<endl;
		
	out.close();
}
void Salesman_operation::savedelete()                    //����ɾ��
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
	ifstream in;                      //�ļ�����
	ofstream out;                     //�ļ����

};

Manager_operation::Manager_operation()                        //���캯��
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

Manager_operation::~Manager_operation()                     //��������
{
	for(Manager *temp;Head->Next!=End;)
	{
		temp=Head->Next;
		Head->Next=Head->Next->Next;
		delete temp;
	}
	delete Head,End;
}

void Manager_operation::searchinfo()                      //������Ŀ
{
	char num[10];
	Manager *p=NULL,*px=NULL;
	int flag=0;
	cout<<"������Ҫ���Ҿ���ţ�";
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
		cout<<"û���ҵ�!!"<<endl<<endl;
}

void Manager_operation::addinfo()
{
	End->set_Manager();
	End->Next=new Manager;
	End=End->Next;
	save();
}
void Manager_operation::modifyinfo()                //�޸���Ŀ
{
	char num[10];
	Manager * p=NULL,*px=NULL;
	
	cout<<"�Ѵ��ھ����ţ�"<<endl;
	 for(p=Head->Next;p->Next!=End;p=p->Next)
	 {
	 	cout<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_dep()<<endl;
	 }
	 cout<<endl; 
	 cout<<"������Ҫ�޸ľ����ţ�";
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
		cout<<"�������µ����ݣ�"<<endl;
		px->Next->set_Manager();
	}
	else
		cout<<"û���ҵ�!!"<<endl<<endl;
	save();
}

void Manager_operation::deleteinfo()              //ɾ����Ŀ
{
	char num[10];
	Manager *p=NULL,*temp=NULL,*px=NULL;
	int flag=0; 
	cout<<"�Ѵ��ڵľ����ţ�"<<endl;
	 for(p=Head->Next;p->Next!=End;p=p->Next)
	 {
	 	cout<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_dep()<<endl;
	 }
	 cout<<endl; 
	cout<<"������Ҫɾ�������ţ�";
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
		cout<<"ɾ���ɹ�!!"<<endl<<endl;
	}
	else
		cout<<"û���ҵ�!!"<<endl<<endl;
	
	
}

void Manager_operation::save()                    //����
{
	out.open("F:\\oop_txt\\Manager.txt");
	for(Manager * p=Head->Next;p!=End;p=p->Next)
		out<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_dep()<<endl;
	out.close();
}
void Manager_operation::savedelete()                    //����
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
	ifstream in;                      //�ļ�����
	ofstream out;                     //�ļ����
};

SalesManager_operation::SalesManager_operation()                 //���캯��
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

SalesManager_operation::~SalesManager_operation()              //��������
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
void SalesManager_operation::searchinfo()                      //������Ŀ
{
	char num[10];
	SalesManager *p=NULL,*px=NULL;
	int flag=0;
	cout<<"������Ҫ�������۾���ţ�";
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
		cout<<"û���ҵ�!!"<<endl<<endl;
}

void SalesManager_operation::modifyinfo()                //�޸���Ŀ
{
	char num[10];
	SalesManager *p=NULL,*px=NULL;
	cout<<"�Ѵ��ڵ����۾����ţ�"<<endl;
	 for(p=Head->Next;p!=End;p=p->Next)
	 {
	 	cout<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_dep()<<" "<<p->get_amount()<<endl;
	 }
	 cout<<endl; 
	cout<<"������Ҫ�޸����۾����ţ�";
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
		cout<<"�������µ����ݣ�"<<endl;
		px->Next->set_SalesManager();
	}
	else
		cout<<"û���ҵ�!!"<<endl<<endl;
	save();
}


void SalesManager_operation::deleteinfo()              //ɾ����Ŀ
{
	char num[10];
	SalesManager *p=NULL,*temp=NULL,*px=NULL;
	int flag=0; 
	cout<<"�Ѵ��ڵ����۾����ţ�"<<endl;
	 for(p=Head->Next;p!=End;p=p->Next)
	 {
	 	cout<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_dep()<<" "<<p->get_amount()<<endl;
	 }
	 cout<<endl; 
	cout<<"������Ҫɾ�����۾����ţ�";
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
		cout<<"ɾ���ɹ�!!"<<endl<<endl;
	}
	else
		cout<<"û���ҵ�!!"<<endl<<endl;
	
}

void SalesManager_operation::save()                    //����
{
	out.open("F:\\oop_txt\\SalesManager.txt");
	for(SalesManager * p=Head->Next;p!=End;p=p->Next)
		out<<p->get_num()<<" "<<p->get_name()<<" "<<p->get_age()<<" "<<p->get_dep()<<" "<<p->get_amount()<<endl;
	out.close();
}
void SalesManager_operation::savedelete()                    //����ɾ��
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
    cout<<"                  C++����ҵ                 "<<endl;
    cout<<"******************MyCompany*******************"<<endl;
    cout<<"��ѡ�������"<<endl;
    cout<<"[1]��������             ";
    cout<<"[2]��������"<<endl;
    cout<<"[3]��ѯ����             ";
    cout<<"[4]ɾ������"<<endl;
    cout<<"[5]����ɾ��             ";
    cout<<"[6]��ѯ����"<<endl; 
    cout<<"[7]�˳�ϵͳ"<<endl<<endl;
    while(cin>>choice)                
    {
        if(choice=='1')
        {
        	
        	cout<<"[1]��������Ա��";             
    		cout<<"[2]���Ӿ���";
   			cout<<"[3]�������۾���";
    		cout<<"[4]����"<<endl;
			cin>>choiceit;
    		if(choiceit=='1')
    		    salesman.addinfo();
    		if(choiceit=='2')    
                 manager.addinfo();
            if(choiceit=='3')
            	salesmanager.addinfo();
            else if(choiceit=='4')
           	{
        		cout<<"�ѷ���"<<endl;
        		continue;
    		}
        }
        else if(choice=='2')
        {
        	
            cout<<"[1]�޸�����Ա��";              
            cout<<"[2]�޸ľ���";
    		cout<<"[3]�޸����۾���";
    		cout<<"[4]����"<<endl;cin>>choiceit;
            if(choiceit=='1')
    		    salesman.modifyinfo();
    		if(choiceit=='2')    
                 manager.modifyinfo();
            if(choiceit=='3')
            	salesmanager.modifyinfo();
            else if(choiceit=='4')
           	{
        		cout<<"�ѷ���"<<endl;
        		continue;
    		}
        } 
        else if(choice=='3')
        {
        	
            cout<<"[1]�鿴����Ա��";            
    		cout<<"[2]�鿴����";
    		cout<<"[3]�鿴���۾���";
    		cout<<"[4]����"<<endl;cin>>choiceit;
    		if(choiceit=='1')
    		    salesman.searchinfo();
    		if(choiceit=='2')    
                 manager.searchinfo();
            if(choiceit=='3')
            	salesmanager.searchinfo();
            else if(choiceit=='4')
           	{
        		cout<<"�ѷ���"<<endl;
        		continue;
    		}
        }
       else if(choice=='4')
        {
            
            cout<<"[1]ɾ������Ա��";             
            cout<<"[2]ɾ������";
    		cout<<"[3]ɾ�����۾���";
    		cout<<"[4]����"<<endl;cin>>choiceit;
            if(choiceit=='1')
    		    salesman.deleteinfo();
    		if(choiceit=='2')    
                 manager.deleteinfo();
            if(choiceit=='3')
            	salesmanager.deleteinfo();
            else if(choiceit=='4')
           	{
        		cout<<"�ѷ���"<<endl;
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
		 	cout<<"�ۻ�Ա������"<<(salesman.count)<<endl;
		 	cout<<"����������"<<(manager.count)<<endl;
		 	cout<<"���۾���������"<<(salesmanager.count)<<endl;
		 	cout<<"��������"<< (salesman.count+manager.count+salesmanager.count)<<endl<<endl;
		 	
		 }
        else if(choice=='7')
        {
            break;
        }
        cout<<"���β���ִ�����"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"��ѡ�����"<<endl;
        cout<<"[1]��������             ";
    	cout<<"[2]��������"<<endl;
    	cout<<"[3]��ѯ����             ";
    	cout<<"[4]ɾ������"<<endl;
    	cout<<"[5]����ɾ��             ";
    	cout<<"[6]��ѯ����"<<endl; 
        cout<<"[7]�˳�ϵͳ"<<endl<<endl;
    }
	return 0;
}

 

