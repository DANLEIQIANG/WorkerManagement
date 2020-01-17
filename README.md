# WorkerManagement-公司员工管理
1 Description  
----

设计一个虚基类Staff（员工），包含编号、姓名和年龄保护数据成员以及相关的成员函数；由Staff派生出销售员类Salesman，包含销售额保护数据成员以及相关的成员函数；再由Staff派生出经理类Manager；然后由Salesman和Manager类派生出销售经理类SalesManager。
设计一个利用文件处理方式实现对公司人员（包括销售员、经理和销售经理）进行管理，具有增加数据、更新数据、查询数据、删除数据以及重组文件的功能。（删除数据在记录中做删除标志，重组文件指在物理上删除有删除标志的记录。）另外要求分别统计这三类员工的人数以及所有员工的总数。

2 思想及功能 
---- 

先定义一个虚基类Staffy（员工），包含编号、姓名和年龄保护数据成员以及相关的成员函数；由Staff派生出销售员类Salesman，包含销售额保护数据成员以及相关的成员函数；再由Staff派生出经理类Manager，包含经理所在部门保护数据成员以及相关的成员函数；然后由Salesman和Manager类派生出销售经理类SalesManager。对Salesman，Manager以及SalesManager分别定义一个操作类，名为Salesman_operation，Manage_operationr以及SalesManager_operation，在这三个类中，实现addinfo()，deleteinfo()，modifyinfo()，searchinfo()等函数，用于文件的增加数据、更新数据、查询数据、删除数据以及重组文件的功能，在实现方面，我主要通过对于链表和文件的操作实现。在统计人数方面，我在建立每个operaton类的构造函数中用count实现。
