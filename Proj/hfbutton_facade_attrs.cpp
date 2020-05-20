#include "hfbutton_facade_attrs.h"
#include <QDebug>
#include <QString>
#include <QXmlStreamReader>
HFButtonFacadeAttrs::HFButtonFacadeAttrs()
{
    qDebug() << "welcom to btn";
}

void HFButtonFacadeAttrs::BtnInfoParse(void){
    while(!m_xmlReader.atEnd()){
        QXmlStreamReader::TokenType token = m_xmlReader.readNext();
//        m_xmlReader.readNext();
        if(token == QXmlStreamReader::StartElement){
            qDebug() << "button:"<<m_xmlReader.name()<<endl;
           if(m_xmlReader.name() == "Normal"){
                GetNormalAttrs();
           }
           if(m_xmlReader.name() == "Press"){
               GetPressedAttrs();
           }
           if(m_xmlReader.name() == "Disabled"){
               GetDisabledAttrs();
           }
           if(m_xmlReader.name() == "Button"){
               qDebug() <<"exit" << endl;
               break;
           }

        }

    }

}


//获取按键正常状态的属性
const tHFButtonFacadeState* HFButtonFacadeAttrs::GetNormalAttrs()
{
    SetAttrs(stateNormal);
}

const tHFButtonFacadeState* HFButtonFacadeAttrs::GetPressedAttrs()
{
   SetAttrs(statePressd);
}

const tHFButtonFacadeState* HFButtonFacadeAttrs::GetDisabledAttrs()
{
     SetAttrs(stateDisabled);
}


void HFButtonFacadeAttrs::SetAttrs(tHFButtonFacadeState &state)
{
    bool ok0;
    attributes = m_xmlReader.attributes();
    if(attributes.hasAttribute("background")){
        QString backcolor = attributes.value("background").toString() ;
        //需要增加一个对 十六进制还是十进制的判断
        if(backcolor.startsWith("0x") || backcolor.startsWith("0X")){
            state.m_backgroundColor = backcolor.toInt(&ok0,16);
        }else{
            state.m_backgroundColor = backcolor.toInt(&ok0,10);
        }
    }
        if(attributes.hasAttribute("left")){
            QString left = attributes.value("left").toString();
            state.m_leftMargin = left.toInt(&ok0,10);
        }
        if(attributes.hasAttribute("top")){
            QString top = attributes.value("top").toString();
            state.m_topMargin = top.toInt(&ok0,10);
        }

        if(attributes.hasAttribute("right")){
            QString right = attributes.value("right").toString();
            state.m_rightMargin = right.toInt(&ok0,10);
        }
        if(attributes.hasAttribute("bottom")){
            QString bottom = attributes.value("bottom").toString();
            state.m_bottomMargin = bottom.toInt(&ok0,10);
        }
        if(attributes.hasAttribute("text_color")){
            QString text_color = attributes.value("text_color").toString();
            if(text_color.startsWith("0x")|| text_color.startsWith("0X")){
                state.m_textColor = text_color.toInt(&ok0,16);
            }else{
                state.m_textColor = text_color.toInt(&ok0,10);
            }
            state.m_imgFilename =m_xmlReader.readElementText();


            while(m_xmlReader.tokenType() !=QXmlStreamReader::EndElement){
                 m_xmlReader.readNext();

            }
            qDebug() << "end"<<m_xmlReader.name()<<endl;
        }



        debugTest(state);


}


void HFButtonFacadeAttrs::debugTest(tHFButtonFacadeState &state)
{
    qDebug() << "tcolor:"<<state.m_textColor << ";";
    qDebug()<<"top:"<< state.m_topMargin << ";";
    qDebug()<<"left:" <<state.m_leftMargin <<";";
    qDebug()<<"imgname:"<<state.m_imgFilename <<";";
    qDebug()<<"right" << state.m_rightMargin <<";";
    qDebug()<<"bottom" << state.m_bottomMargin << ";";
    qDebug()<<"bckcolor:"<<state.m_backgroundColor <<endl;
}




HFButtonFacadeAttrs::~HFButtonFacadeAttrs()
{

}
