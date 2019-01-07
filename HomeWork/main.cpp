#include <QTextStream>
#include <QFile>
#include <QList>
#include <QString>
#include <QDebug>

using namespace std;
// Создание потоков для чтения и вывода
QTextStream out(stdout);
QTextStream in(stdin);

// структура
typedef struct {
    QString varName;
    QString varType;
    int varId;
} T_variable;

// Функция парсинга строки в структуру
T_variable parse(QString &str, QString type)
{
    T_variable item;
    item.varType = type;
    item.varName = str.mid(0,str.indexOf(' '));
    item.varId = str.mid(str.indexOf('=')+2,str.length()-3).toInt();
    return item;
}

// Функциия поиска значения в списке
bool find_value(QList<T_variable> &values, QString name)
{
    // проходит по списку значений
    for(int i=0; i<values.size();i++)
    {
        //если находит совпадение по name, то выводит type и id  и возвращает true
        if (values[i].varName==name)
        {
            out<<"Varaible '"<<name<<"' have type '"<<values[i].varType<<"' and number '"<<values[i].varId<<"'"<<endl;
            return true;
        }
    }
    //вернет false, если не найдет значение
    return false;
}

int main()
{
 // Файл ini
 QFile file("C:/Users/AntoXa/Desktop/QtTask/HomeWork/dl_gsw.ini");
 // Поменяте имя *AntoXa* на имя своего пользвателя на компьютере
 QString line, type, command;
 QList<T_variable> values;

 //Чтение значений из файла в список структур
 if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
 {
     while(!file.atEnd())
     {
         // Чтение строкии из файла
         line=file.readLine();
         // Удаление символа конца строки
         line.remove(QRegExp("[\\n\\t\\r]"));
         if (line.length())
         {
             //Если строка начинается с [, значит это тип следующих строк
            if (line.startsWith('[')) type = line.mid(1,line.length()-2);
            // Иначе это сама строка со значениями
            else values.append(parse(line, type));
         }
     }
     file.close();
 }

 while(true)
 {
     // Чтение строки с консоли
     out<<"Please enter name to search, or 0 to exit:"<<endl;
     in>>command;
     // Если строка=="0" то выходиим
     if (command=="0") break;
     // Иначе вызываем функцию поиска значения в списке
     else if(!find_value(values, command)) out<<"Can't find Varaible '"<<command<<"' in file 'dl_gsw.ini'"<<endl;
 }
 out<<"Good bay!"<<endl;
 system("pause");
 return 0;
}
