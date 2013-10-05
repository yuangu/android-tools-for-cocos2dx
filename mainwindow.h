#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class GetPath;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    GetPath* m_path;
};

#endif // MAINWINDOW_H
