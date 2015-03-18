/**
  *作者:麻菜
  *日期:2013年6月20日
  *功能:自定义颜色选择对象,从QColorDialog类中提取重新封装.仅保留通过鼠标pick提取颜色的控件
  *说明:开源,免费,使用时请保持开源精神.
  *联系:12319597@qq.com
  *博客:www.newdebug.com
**/
#include "colorshowlabel.h"
#include "colorshower.h"
#include <QGridLayout>

YviColorShower::YviColorShower(YviColorDialog *parent) :
    QWidget(parent)
{
    m_colorDialog = parent;
    m_curCol = qRgb(255, 255, 255);
    m_curQColor = Qt::white;

//    QGridLayout *gridlayout = new QGridLayout(this);
//    gridlayout->setMargin(gridlayout->spacing());
    m_colorLabel = new YviColorShowLabel(this);
    m_colorLabel->setFixedSize(30,20);

//    gridlayout->addWidget(m_colorLabel, 0, 0, 1, 1);

//    connect(m_colorLabel, SIGNAL(colorDropped(QRgb)), this, SIGNAL(newCol(QRgb)));
    //    connect(m_colorLabel, SIGNAL(colorDropped(QRgb)), this, SLOT(setRgb(QRgb)));
}

void YviColorShower::setHsv(int h, int s, int v)
{
    if (h < -1 || (uint)s > 255 || (uint)v > 255)
        return;

    m_hue = h; m_val = v; m_sat = s;
    QColor c;
    c.setHsv(m_hue, m_sat, m_val);
    m_curCol = c.rgb();

    showCurrentColor();
    //updateQColor();
}

void YviColorShower::showCurrentColor()
{
    m_colorLabel->setColor(currentColor());
    m_colorLabel->repaint();
}

void YviColorShower::updateQColor()
{
    QColor oldQColor(m_curQColor);
    m_curQColor.setRgba(qRgba(qRed(m_curCol), qGreen(m_curCol), qBlue(m_curCol), currentAlpha()));
    if (m_curQColor != oldQColor)
        emit currentColorChanged(m_curQColor);
}

int YviColorShower::currentAlpha() const
{
     return m_alphaEd->value();
}
