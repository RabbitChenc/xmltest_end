#ifndef HFVIEW_FACADE_ATTRS_H
#define HFVIEW_FACADE_ATTRS_H
#include <QXmlStreamReader>
#include <QString>
#include "hfbutton_facade_attrs.h"
#include "hfsin_hungry.h"
class HFviewFacadeAttrs
{
public:
    HFviewFacadeAttrs();
    ~HFviewFacadeAttrs();

public:
    int readXml();
    QString fileNAme;
private:

    QXmlStreamReader m_xmlReader;
    HFButtonFacadeAttrs *btnAttrs;

};

#endif // HFVIEW_FACADE_ATTRS_H
