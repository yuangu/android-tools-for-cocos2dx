#include "getpath.h"
#include <QDir>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include<QUrl>
#include <QDesktopServices>

GetPath::GetPath(Ui::MainWindow* ui )
{
    uiPtr = ui;
    QObject::connect(ui->selectFileButton, SIGNAL(clicked()), this, SLOT(getPathByTextLine()));
    QObject::connect(ui->label,SIGNAL(linkActivated(QString)),this,SLOT(openUrl(QString)));
}

void GetPath::getPathByTextLine()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);

    uiPtr->pathShowLine->setText(dir);


    fileList(dir);
}

void GetPath::fileList(QString path)
{
    QDir* dir = new QDir(path);

    QStringList filters;
       filters << "*.cpp" << "*.cxx" << "*.cc";


    QFileInfo file;
    QString prePath =   uiPtr -> prePathShowLine ->text();
    prePath.append("/");

    foreach (file, dir->entryInfoList(filters)) {
        uiPtr -> pathShowTextView->append(prePath + file.fileName() + "    \\");
    }

}




void GetPath::openUrl(QString url)
{
    QUrl qurl;
    qurl.setUrl(url);
    QDesktopServices::openUrl(qurl);
}
