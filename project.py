import sqlite3
import random
import cgi
TRANSACTION = """
<head>
		<meta http-equiv="content-language" content="ua, en" charset="UTF-8">
</head>

<html >
    <title>Перерахування</title>
<body>
    <h3><i> Усі перерахування </i></h3>
    {}
</body>
</html>
"""
OUTPUT_PAGE="""
<head>
		<meta http-equiv="content-language" content="ua, en" charset="UTF-8">
</head>

<html >
    <title>Project</title>
<body>
    <h3>Вітаємо, зміни збережено!</h3>
</body>
</html>
"""

class Object():

    def add(self):
        print("Метод ADD на етапі розробки\nі поки не реалізований у класі: "+str(type(self).__name__))

    def change(self):
        print("Метод CHANGE на етапі розробки\nі поки не реалізований у класі: "+str(type(self).__name__))

    def delete(self):
        print("Метод DELETE на етапі розробки\nі поки не реалізований у класі: "+str(type(self).__name__))

    #знаходження номера посади за назвою у таблиці position_list2 ( повертає у форматі [(number,)] )
    def find_position(self,pos):
        cursor.execute('''SELECT positionID FROM position_list2
                    WHERE position =?''', (pos,))
        return cursor.fetchall()

class Worker(Object):

    def __init__(self, name='Стьопа', id=0,position='dvornik'):
        self.name = name
        self.position = position
        self.id = id

    def add(self):
        #обчислення унікального індексу для нового робітника
        cursor.execute('''SELECT id FROM common_info_list1''')
        info = cursor.fetchall()
        index = info[-1][0]+1

        #безпосередньо заповлення таблички common_info_list1
        cursor.execute("""INSERT INTO common_info_list1
                        VALUES(?,?,?)""", (index, self.name, self.find_position(self.position)[0][0]))
        db.commit()

    def change(self):
        #вибір даних для заміни
        if self.name!="same":
            cursor.execute("""UPDATE common_info_list1 set
                            Name=? WHERE ID=?""",(self.name,self.id))
        if self.position!="same":
            cursor.execute("""UPDATE common_info_list1 set
                        positionID=? WHERE ID=?""",(self.find_position(self.position)[0][0],self.id))
        db.commit()

    def delete(self):
        cursor.execute('''DELETE FROM common_info_list1 WHERE ID=?''',(self.id,))
        db.commit()

class Position(Object):

    def __init__(self, position_name,new_name='',salary=0,plan=10):
        self.position_name = position_name
        self.salary = salary
        self.plan = plan
        self.new_name=new_name

    def add(self):
        #обчислення унікального індексу для нової посади
        cursor.execute('''SELECT positionID FROM position_list2''')
        info = cursor.fetchall()
        index = info[-1][0]+1

        #безпосередньо заповлення таблички position_list2
        cursor.execute("""INSERT INTO position_list2
                        VALUES(?,?,?,?)""", (index, self.position_name, self.salary,self.plan))
        db.commit()

    def change(self):
        #заміна даних в таблиці position_list2
        if self.new_name!='same':
            cursor.execute("""UPDATE position_list2 set
                        position = ? WHERE position = ?""",(self.new_name,self.position_name))
        if self.salary!='same':
            cursor.execute("""UPDATE position_list2 set
                        salary = ? WHERE position = ?""",(self.salary, self.position_name))
        if self.plan!='same':
            cursor.execute("""UPDATE position_list2 set
                        plan = ? WHERE position = ?""",(self.plan, self.position_name))
        db.commit()

    def delete(self):
        cursor.execute('''DELETE FROM position_list2 WHERE position = ?''',(self.position_name,))
        db.commit()

class Report(Object):
    #дані про відвідування вибрані випадковим чином
    def __init__(self, id,start='',end=''):
        self.id = id
        self.lst=[-1,-1,-1,-1,0,0,2,4,5,6,6,7,7,8,8,8,9,9,9,10,10]
        self.start=start
        self.end = end
    def add(self):
        for j in range(31):
            cursor.execute("""INSERT INTO report VALUES(?,?,?)""", (self.id,str(j+1)+'.05.2022',random.choice(self.lst)))
            db.commit()

    def change(self):
        for j in range(31):
            cursor.execute("""UPDATE report SET Result=? WHERE ID=? AND Date=?""", (random.choice(self.lst),self.id,str(j+1)+'.05.2022'))
            db.commit()

    def delete(self):
        cursor.execute('''DELETE FROM report WHERE ID = ?''',(self.id,))
        db.commit()

    def show_salary(self):
        cursor.execute('''SELECT Result FROM report WHERE ID=?''',(self.id,))
        res=cursor.fetchall()
        cursor.execute('''SELECT Name,positionID FROM common_info_list1 WHERE ID=?''',(self.id,))
        pos_id=cursor.fetchall()
        cursor.execute('''SELECT salary FROM position_list2 WHERE positionID=?''', (pos_id[0][1],))
        salary0=cursor.fetchall()[0][0]
        sick_fine=0
        days=int(self.end.split('.')[0])-int(self.start.split('.')[0])
        salary=salary0*days/31
        for i in range(days):
            r=res[i+int(self.start.split('.')[0])][0]
            if r<0:
                sick_fine+=0.2*salary/31
        print(TRANSACTION.format(f'Робітник {pos_id[0][0]} за період {self.start}-{self.end} отримав %.2f $'%(salary-sick_fine)))
    def show_all(self):
        line=''
        cursor.execute('''SELECT ID FROM common_info_list1''')
        id_lst = cursor.fetchall()
        for el in id_lst:
            cursor.execute('''SELECT Result FROM report WHERE ID=?''', (el[0],))
            res = cursor.fetchall()
            cursor.execute('''SELECT Name,positionID FROM common_info_list1 WHERE ID=?''',(el[0],))
            pos_id=cursor.fetchall()
            cursor.execute('''SELECT salary FROM position_list2 WHERE positionID=?''', (pos_id[0][1],))
            salary=cursor.fetchall()[0][0]
            sick_fine=0
            for i in range(31):
                r=res[i][0]
                if r<0:
                    sick_fine+=0.2*salary/31
            line+=f'{pos_id[0][0]} за місяць отримав %.2f $;<br>'%(salary-sick_fine)
        print(TRANSACTION.format(line))


db=sqlite3.connect('workers.db')
cursor=db.cursor()
#########################################
#########################################


form = cgi.FieldStorage()
if 'entry1' in form:
    entry1=form['entry1'].value
    info=entry1.split(',')
    W = Worker(name=info[0], position=info[1])
    W.add()
if 'entry2' in form:
    entry3 = form['entry2'].value
    info=entry3.split(',')
    W = Worker(id=info[0],name=info[1],position=info[2])
    W.change()
if 'entry3' in form:
    entry3 = form['entry3'].value
    info = int(entry3)
    W = Worker(id=info)
    W.delete()
if 'entry4' in form:
    entry4=form['entry4'].value
    info=entry4.split(',')
    P = Position(position_name=info[0],salary=int(info[1]),plan=int(info[2]))
    P.add()
if 'entry5' in form:
    entry5 = form['entry5'].value
    info=entry5.split(',')
    P = Position(position_name=info[0],new_name=info[1],salary=info[2],plan=info[3])
    P.change()
if 'entry6' in form:
    entry6 = form['entry6'].value
    info = entry6
    P = Position(position_name=info)
    P.delete()
if 'entry7' in form:
    entry7=form['entry7'].value
    info=int(entry7)
    R = Report(id=info)
    R.add()
if 'entry8' in form:
    entry8 = form['entry8'].value
    info = int(entry8)
    R = Report(id=info)
    R.change()
if 'entry9' in form:
    entry9 = form['entry9'].value
    info = int(entry9)
    R = Report(id=info)
    R.delete()
if 'entry10' in form:
    entry10 = form['entry10'].value
    info=entry10.split(',')
    info1=info[1].split('-')
    R = Report(id=info[0],start=info1[0],end=info1[1])
    R.show_salary()

print(OUTPUT_PAGE)
try:
    R=Report(100)
    R.show_all()
except:
    print("not enough information in database to show all statistics")
#########################################
#########################################
db.close()