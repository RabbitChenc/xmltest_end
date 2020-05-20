#include "hfview_facade_attrs.h"
#include <QFile>
#include <QDebug>
#include <QXmlStreamReader>


PtrHungry PtrHungry::s_PtrHungry;
HFviewFacadeAttrs::HFviewFacadeAttrs()
{
    qDebug() << "view con start " <<endl;

}
HFviewFacadeAttrs::~HFviewFacadeAttrs()
{
    if(btnAttrs!=nullptr){
        delete btnAttrs;
        btnAttrs = nullptr;
    }
    qDebug() << "view decon end~~ " <<endl;
}

int HFviewFacadeAttrs::readXml()
{
    QFile qtFile(fileNAme);
    if(!qtFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
         qDebug()<< "Open failed." << endl;
         return -1;
    }

     PtrHungry &hungry = PtrHungry::getInstance();
     QXmlStreamReader &m_xmlReader = hungry.xmlReader;
     m_xmlReader.setDevice(&qtFile);

     while(!m_xmlReader.atEnd()){
          QXmlStreamReader::TokenType token = m_xmlReader.readNext();
          if(token == QXmlStreamReader::StartElement){
             qDebug() << m_xmlReader.name()<<endl;

             if(m_xmlReader.name() == "Button"){
                 btnAttrs = new HFButtonFacadeAttrs;

                 btnAttrs->BtnInfoParse();

             }
          }
      }

     qDebug()<< "xml file deal.fini" << endl;
     if(m_xmlReader.hasError()){
        qDebug() << "error in file " <<endl;
     }
     qtFile.close();
}


