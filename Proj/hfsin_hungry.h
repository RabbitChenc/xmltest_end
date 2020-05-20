#ifndef PTRHUNGRY_H
#define PTRHUNGRY_H
#include <QXmlStreamReader>
//创建一个单例模式 全局维护一个唯一的变量
//俄汉模式 适用多线程模式
class PtrHungry
{

public:
    static PtrHungry& getInstance(void){return s_PtrHungry;}; //静态成员函数 用来访问 静态成员变量 实例
    void print(void)const;

private:
    PtrHungry(){};//私有构造
    PtrHungry(const PtrHungry&){};
    static PtrHungry s_PtrHungry;
public:
    QXmlStreamReader xmlReader;
};



#endif // PTRHUNGRY_H
