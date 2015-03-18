/**
  *作者:麻菜
  *日期:2013年6月20日
  *功能:自定义颜色选择对象,从QColorDialog类中提取重新封装.仅保留通过鼠标pick提取颜色的控件
  *说明:开源,免费,使用时请保持开源精神.
  *联系:12319597@qq.com
  *博客:www.newdebug.com
**/
#include <QtGui/QApplication>
#include "colordialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    YviColorDialog w;
    w.show();
    
    return a.exec();
}
