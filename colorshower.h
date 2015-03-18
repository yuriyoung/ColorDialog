/**
  *作者:麻菜
  *日期:2013年6月20日
  *功能:自定义颜色选择对象,从QColorDialog类中提取重新封装.仅保留通过鼠标pick提取颜色的控件
  *说明:开源,免费,使用时请保持开源精神.
  *联系:12319597@qq.com
  *博客:www.newdebug.com
**/
#ifndef COLORSHOWER_H
#define COLORSHOWER_H
#include "colordialog.h"
#include <QWidget>
#include <QSpinBox>
#include <QLabel>

class YviColorShowLabel;

class QColSpinBox : public QSpinBox
{
public:
    QColSpinBox(QWidget *parent): QSpinBox(parent) { setRange(0, 255); }

    void setValue(int i)
    {
        bool block = signalsBlocked();
        blockSignals(true);
        QSpinBox::setValue(i);
        blockSignals(block);
    }
};

class YviColorShower : public QWidget
{
    Q_OBJECT
public:
    explicit YviColorShower(YviColorDialog *parent = 0);

    void setHsv(int h, int s, int v);
    int currentAlpha() const;
    void setCurrentAlpha(int a) { m_alphaEd->setValue(a);}
//    void showAlpha(bool b);
//    bool isAlphaVisible() const;

    QRgb currentColor() const { return m_curCol; }
    QColor currentQColor() const { return m_curQColor; }
    void updateQColor();

public slots:
//    void setRgb(QRgb rgb);

signals:
    void newCol(QRgb rgb);
    void currentColorChanged(const QColor &color);

private slots:

private:
    void showCurrentColor();
    int m_hue, m_sat, m_val;
    QRgb            m_curCol;
    QColor          m_curQColor;
    QColSpinBox     *m_alphaEd;
    QLabel          *m_alphaLab;
    YviColorShowLabel  *m_colorLabel;

    YviColorDialog   *m_colorDialog;

    friend class YviColorDialog;
};

#endif // COLORSHOWER_H
