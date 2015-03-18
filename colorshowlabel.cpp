/**
  *作者:麻菜
  *日期:2013年6月20日
  *功能:自定义颜色选择对象,从QColorDialog类中提取重新封装.仅保留通过鼠标pick提取颜色的控件
  *说明:开源,免费,使用时请保持开源精神.
  *联系:12319597@qq.com
  *博客:www.newdebug.com
**/
#include "colorshowlabel.h"
#include <QApplication>
#include <QPainter>
#include <QMimeData>
#include <QDrag>
#include <QMouseEvent>

YviColorShowLabel::YviColorShowLabel(QWidget *parent) :
    QFrame(parent)
{
    this->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    this->setAcceptDrops(true);
    m_mousePressed = false;
}

void YviColorShowLabel::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    drawFrame(&p);
    p.fillRect(contentsRect()&e->rect(), m_color);
}

void YviColorShowLabel::mousePressEvent(QMouseEvent *e)
{
    m_mousePressed = true;
    m_pressPos = e->pos();
}

void YviColorShowLabel::mouseMoveEvent(QMouseEvent *e)
{
    if (!m_mousePressed)
        return;
    if ((m_pressPos - e->pos()).manhattanLength() > QApplication::startDragDistance())
    {
        QMimeData *mime = new QMimeData;
        mime->setColorData(m_color);
        QPixmap pix(30, 20);
        pix.fill(m_color);
        QPainter p(&pix);
        p.drawRect(0, 0, pix.width() - 1, pix.height() - 1);
        p.end();
        QDrag *drg = new QDrag(this);
        drg->setMimeData(mime);
        drg->setPixmap(pix);
        m_mousePressed = false;
        drg->start();
    }
}

void YviColorShowLabel::mouseReleaseEvent(QMouseEvent *)
{
    if (!m_mousePressed)
        return;
    m_mousePressed = false;
}
