#ifndef GETPATH_H
#define GETPATH_H

#include <QWidget>
#include <QMainWindow>
#include"mainwindow.h"


class GetPath:public QWidget
{
    Q_OBJECT
public :
    GetPath(Ui::MainWindow* );

 public slots:
    void getPathByTextLine();

    void fileList(QString Path);
    void openUrl(QString url);
   private:
    Ui::MainWindow* uiPtr;
};

#endif // GETPATH_H
