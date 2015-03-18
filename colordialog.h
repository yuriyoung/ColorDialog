/**
  *作者:麻菜
  *日期:2013年6月20日
  *功能:自定义颜色选择对象,从QColorDialog类中提取重新封装.仅保留通过鼠标pick提取颜色的控件
  *说明:开源,免费,使用时请保持开源精神.
  *联系:12319597@qq.com
  *博客:www.newdebug.com
**/

#ifndef MYCOLORDIALOG_H
#define MYCOLORDIALOG_H

#include "colorluminancepicker.h"
#include <QDialog>

class YviColorPicker;
class YviColorShower;

class YviColorDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit YviColorDialog(QWidget *parent = 0);
    ~YviColorDialog();
signals:
    void currentColorChanged(const QColor &color);

private slots:
        void newHsv(int h, int s, int v);

private:
    YviColorPicker             *m_colorPicker;
    YviColorShower             *m_colorShower;
    YviColorLuminancePicker    *m_colorLuminancePicker;
};

#endif // MYCOLORDIALOG_H
