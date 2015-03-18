/**
  *作者:麻菜
  *日期:2013年6月20日
  *功能:自定义颜色选择对象,从QColorDialog类中提取重新封装.仅保留通过鼠标pick提取颜色的控件
  *说明:开源,免费,使用时请保持开源精神.
  *联系:12319597@qq.com
  *博客:www.newdebug.com
**/
#ifndef COLORLUMINANCEPICKER_H
#define COLORLUMINANCEPICKER_H

#include <QWidget>

class YviColorLuminancePicker : public QWidget
{
    Q_OBJECT
public:
    explicit YviColorLuminancePicker(QWidget *parent = 0);
    
signals:
    void newHsv(int h, int s, int v);

public slots:
    void setCol(int h, int s, int v);
    void setCol(int h, int s);

protected:
    void paintEvent(QPaintEvent*);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);

private:
    enum { foff = 3, coff = 4 }; //frame and contents offset
    int val;
    int hue;
    int sat;

    int y2val(int y);
    int val2y(int v);
    void setVal(int v);

    QPixmap *pix;
};

#endif // COLORLUMINANCEPICKER_H
