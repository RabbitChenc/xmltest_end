#ifndef HFBUTTON_FACADE_ATTRS_H
#define HFBUTTON_FACADE_ATTRS_H
#include <QXmlStreamAttribute>
#include "hfsin_hungry.h"
typedef struct {
    int m_leftMargin;
    int m_topMargin;
    int m_rightMargin;
    int m_bottomMargin;
    int m_backgroundColor;
    int m_textColor;
    QString m_imgFilename;
} tHFButtonFacadeState;



class HFButtonFacadeAttrs
{
public:
    HFButtonFacadeAttrs();
    virtual ~HFButtonFacadeAttrs();


    const tHFButtonFacadeState * GetNormalAttrs();
    const tHFButtonFacadeState * GetPressedAttrs();
    const tHFButtonFacadeState * GetDisabledAttrs();

    void SetAttrs(tHFButtonFacadeState& state);
    void debugTest(tHFButtonFacadeState& state);
    void BtnInfoParse(void);

protected:
    tHFButtonFacadeState stateNormal;
    tHFButtonFacadeState statePressd;
    tHFButtonFacadeState stateDisabled;

public:
    PtrHungry &hungry = PtrHungry::getInstance();
    QXmlStreamReader &m_xmlReader = hungry.xmlReader;

private:

    QXmlStreamAttributes attributes;
};

#endif
