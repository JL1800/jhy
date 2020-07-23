///张法桐
//王振11
//王瑶
//王瑶test
#include "wavewidget.h"
#include <QPainter>
#include <QTimer>
#include <QTime>
#include <QColor>
WaveWidget::WaveWidget(QWidget *parent) : QWidget(parent)
{
     this->resize(600,150);
    pix=new QPixmap(this->width(),this->height());
    pix->fill(Qt::black);
     //创建和启动定时器
     QTimer *timer=new QTimer(this);
     connect(timer,&QTimer::timeout,
             this,&WaveWidget::refreshPixmap);
     timer->start(10);
}


int data1[]={
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2008, 2016, 2016, 2016, 2024, 2032, 2048,
            2064, 2064, 2064, 2072, 2080, 2080, 2080, 2088, 2096, 2104,
            2112, 2112, 2112, 2112, 2112, 2112, 2104, 2096, 2088,
            2080, 2080, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2032,
            2032, 2016, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 1992, 1984, 1976,
            1968, 1960, 1952, 1944, 1936, 1944, 1952, 2016, 2080, 2136,
            2192, 2256, 2320, 2376, 2432, 2488, 2544, 2568, 2592, 2536,
            2480, 2424, 2368, 2304, 2240, 2184, 2128, 2072, 2016, 1968,
            1920, 1928, 1936, 1944, 1952, 1960, 1968, 1984, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2008, 2016, 2024, 2032, 2032,
            2032, 2048, 2064, 2064, 2064, 2072, 2080, 2088, 2096, 2104,
            2112, 2112, 2112, 2120, 2128, 2136, 2144, 2152, 2160, 2160,
            2160, 2160, 2160, 2168, 2176, 2176, 2176, 2184, 2192,
            2192, 2192, 2192, 2200, 2208, 2208, 2208, 2208, 2208, 2208,
            2208, 2200, 2192, 2192, 2192, 2184, 2176, 2176, 2176, 2168,
            2160, 2160, 2160, 2144, 2128, 2128, 2128, 2128, 2128, 2112,
            2096, 2088, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2024,
            2016, 2016, 2016, 2008, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000
};
//更新数据
void WaveWidget::refreshPixmap()
{
    static int X=0;
    static int Y=0;
 //   static int direct=0;
    //1.将图画到pixmap上
    //1.1 定义QPainter
    QPainter painter(pix);
    painter.setPen(QPen(QColor(0,255,0),2));
    //1.2 擦除当前列
    painter.save();
    painter.setPen(Qt::black);
    painter.drawLine(X,0,X,pix->height());
    painter.drawLine(X+1,0,X+1,pix->height());
    painter.drawLine(X+2,0,X+2,pix->height());
    painter.drawLine(X+3,0,X+3,pix->height());
    painter.drawLine(X+4,0,X+4,pix->height());
    painter.drawLine(X+5,0,X+5,pix->height());
    painter.drawLine(X+6,0,X+6,pix->height());
    painter.restore();
    //1.3更新参数
     X=X+2;
    if(X>pix->width())
      {
          X=2;
      }
    QPoint lineStart;
    QPoint lineEnd;
    //设置起始、结束点x坐标
    lineStart.setX(X-2);
    lineEnd.setX(X);

    //设置起始、结束点y坐标
   lineStart.setY(round((double)pix->height()/2 -(((double)data1[Y] - 2048)/600 * pix->height()/2)));
   // lineStart.setY(round((double)pix->height()/2 -(((double)data1[Y] ));
   // 更新参数循环取数
     Y += 10;
      if (Y >= sizeof(data1)/sizeof(int))
      {
          Y = 0;}
    //设置结束坐标点
    lineEnd.setY(round((double)pix->height()/2 -(((double)data1[Y] - 2048)/600 * pix->height()/2)));

   //1.4 绘制直线
     painter.drawLine(lineStart,lineEnd);
// // 清除历史波形
  //  painter.drawPoint(pointX,pointY);

 //2.更新数据
    this->update();
}
void WaveWidget::paintEvent(QPaintEvent *event)
{
    QPainter  painter(this);
    painter.drawPixmap(0,0,pix->width(),pix->height(),*pix);

}
//显示时间
TimeWidget::TimeWidget(QWidget *parent) : QLCDNumber(parent)
{
    this->Timer =new QTimer;
    this->setDigitCount(8);
    this->setStyleSheet("color:blue");
  QTime TIME=QTime::currentTime() ;//Static静态成员函数
  QString str=TIME.toString("hh:mm:ss");
  this->display(str);
//  //初始化时间
//  this->updateTime();
  //创建信号槽连接
  //建立信号连接
  connect(this->Timer,&QTimer::timeout,
          this,&TimeWidget::updateTime);
 Timer->start(1000);//每隔1s，定时器溢出
}

void TimeWidget::updateTime()
{
    QTime t=QTime::currentTime();//获得时间
    QString str=t.toString("hh:mm:ss");
    this->display(str);
}
