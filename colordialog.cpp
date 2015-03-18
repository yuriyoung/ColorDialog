/**
  *作者:麻菜
  *日期:2013年6月20日
  *功能:自定义颜色选择对象,从QColorDialog类中提取重新封装.仅保留通过鼠标pick提取颜色的控件
  *说明:开源,免费,使用时请保持开源精神.
  *联系:12319597@qq.com
  *博客:www.newdebug.com
**/
#include "colorpicker.h"
#include "colorshower.h"
#include "colordialog.h"

#include <QGridLayout>
#include <QHBoxLayout>

YviColorDialog::YviColorDialog(QWidget *parent) :
    QDialog(parent)
{
    setSizeGripEnabled(false);
    setFixedSize(300,200);
    setWindowTitle(YviColorDialog::tr("Select Color"));

    QGridLayout *gridLayout = new QGridLayout;
    m_colorPicker = new YviColorPicker(this);
    m_colorShower = new YviColorShower(this);
    m_colorLuminancePicker = new YviColorLuminancePicker(this);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(m_colorPicker);
    hLayout->addWidget(m_colorShower);
    hLayout->addWidget(m_colorLuminancePicker);
    gridLayout->addLayout(hLayout, 0, 0);
    this->setLayout(gridLayout);

    QObject::connect(m_colorPicker, SIGNAL(newColor(int,int)), m_colorLuminancePicker, SLOT(setCol(int,int)));
    QObject::connect(m_colorLuminancePicker, SIGNAL(newHsv(int,int,int)), this, SLOT(newHsv(int,int,int)));
//    QObject::connect(m_colorShower, SIGNAL(currentColorChanged(QColor)), this, SIGNAL(currentColorChanged(QColor)));
}

YviColorDialog::~YviColorDialog()
{
}

void YviColorDialog::newHsv(int h, int s, int v)
{
    m_colorShower->setHsv(h, s, v);
    //m_colorPicker->setColor(h, s);
    //m_colorLuminancePicker->setCol(h, s, v);
}
