/**
  *作者:麻菜
  *日期:2013年6月20日
  *功能:自定义颜色选择对象,从QColorDialog类中提取重新封装.仅保留通过鼠标pick提取颜色的控件
  *说明:开源,免费,使用时请保持开源精神.
  *联系:12319597@qq.com
  *博客:www.newdebug.com
**/
#ifndef COLORSHOWLABEL_H
#define COLORSHOWLABEL_H

#include <QFrame>

class YviColorShowLabel : public QFrame
{
    Q_OBJECT
public:
    explicit YviColorShowLabel(QWidget *parent = 0);
    
    void setColor(QColor c) { m_color = c; }

signals:
    void colorDropped(QRgb);

protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    QColor  m_color;
    bool    m_mousePressed;
    QPoint  m_pressPos;
};

#endif // COLORSHOWLABEL_H
