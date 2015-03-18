/**
  *作者:麻菜
  *日期:2013年6月20日
  *功能:自定义颜色选择对象,从QColorDialog类中提取重新封装.仅保留通过鼠标pick提取颜色的控件
  *说明:开源,免费,使用时请保持开源精神.
  *联系:12319597@qq.com
  *博客:www.newdebug.com
**/
#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <QFrame>

class YviColorPicker : public QFrame
{
    Q_OBJECT
public:
    explicit YviColorPicker(QWidget *parent = 0);
    
signals:
    void newColor(int h, int s);

public slots:
    void setColor(int h, int s);

protected:
    QSize sizeHint() const;
    void paintEvent(QPaintEvent*);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *);

private:
    int m_hue;
    int m_sat;

    QPoint colPt();
    int huePt(const QPoint &pt);
    int satPt(const QPoint &pt);
    void setCol(const QPoint &pt);

    QPixmap m_pix;
};

#endif // COLORPICKER_H
