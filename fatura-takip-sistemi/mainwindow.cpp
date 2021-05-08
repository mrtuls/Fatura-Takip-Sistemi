#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i=0;i<32;i++ ) {

        if (i==0)
            ui->e_gun->addItem("");
        else
                ui->e_gun->addItem(QString::number(i));
    }

    for (int i=0;i<32;i++ ) {
        if (i==0)
            ui->s_gun->addItem("");
        else

                ui->s_gun->addItem(QString::number(i));}

    for (int i=0;i<32;i++ ) {
        if (i==0)
            ui->d_gun->addItem("");
        else

                ui->d_gun->addItem(QString::number(i));}

    for (int i=0;i<32;i++ ) {
        if (i==0)
            ui->t_gun->addItem("");
        else

                ui->t_gun->addItem(QString::number(i));}

    ui->e_ay->addItems({"","Ocak","Şubat","Mart","Nisan","Mayıs","Haziran","Temmuz","Ağustos","Eylül","Ekim","Kasım","Aralık"});
    ui->s_ay->addItems({"","Ocak","Şubat","Mart","Nisan","Mayıs","Haziran","Temmuz","Ağustos","Eylül","Ekim","Kasım","Aralık"});
    ui->d_ay->addItems({"","Ocak","Şubat","Mart","Nisan","Mayıs","Haziran","Temmuz","Ağustos","Eylül","Ekim","Kasım","Aralık"});
    ui->t_ay->addItems({"","Ocak","Şubat","Mart","Nisan","Mayıs","Haziran","Temmuz","Ağustos","Eylül","Ekim","Kasım","Aralık"});

    for (int i=2019;i<2051;i++ ) {
        if (i==2019)
            ui->e_yil->addItem("");
        else
                ui->e_yil->addItem(QString::number(i));}

    for (int i=2019;i<2051;i++ ) {
        if (i==2019)
            ui->s_yil->addItem("");
        else

                ui->s_yil->addItem(QString::number(i));}

    for (int i=2019;i<2051;i++ ) {
        if (i==2019)
            ui->d_yil->addItem("");
        else

                ui->d_yil->addItem(QString::number(i));}

    for (int i=2019;i<2051;i++ ) {
        if (i==2019)
            ui->t_yil->addItem("");
        else

                ui->t_yil->addItem(QString::number(i));}

    ui->e_odeme->addItems({"","Evet","Hayır"});
    ui->s_odeme->addItems({"","Evet","Hayır"});
    ui->d_odeme->addItems({"","Evet","Hayır"});
    ui->t_odeme->addItems({"","Evet","Hayır"});

    ui->aylik_bilanco->setReadOnly(true);




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_temizle_buton_clicked()
{
    ui->e_tutar->clear();
    ui->s_tutar->clear();
    ui->d_tutar->clear();
    ui->t_tutar->clear();
    ui->aylik_gelir->clear();
    ui->aylik_bilanco->clear();
//    ui->e_gun->clear();
//    ui->s_gun->clear();
//    ui->d_gun->clear();
//    ui->t_gun->clear();
//    ui->e_ay->clear();
//    ui->s_ay->clear();
//    ui->d_ay->clear();
//    ui->t_ay->clear();
//    ui->e_yil->clear();
//    ui->s_yil->clear();
//    ui->d_yil->clear();
//    ui->t_yil->clear();
//    ui->e_odeme->clear();
//    ui->s_odeme->clear();
//    ui->d_odeme->clear();
//    ui->t_odeme->clear();

    ui->statusbar->showMessage("Temizlendi",2000);


}



void MainWindow::on_tamam_buton_clicked()
{
    float e_tutar_girisi = ui->e_tutar->text().toFloat();
    float s_tutar_girisi = ui->s_tutar->text().toFloat();
    float d_tutar_girisi = ui->d_tutar->text().toFloat();
    float t_tutar_girisi = ui->t_tutar->text().toFloat();
    float aylik_gelir_girisi = ui->aylik_gelir->text().toFloat();

    float bilanco = aylik_gelir_girisi-(e_tutar_girisi+s_tutar_girisi+d_tutar_girisi+t_tutar_girisi);

    ui->aylik_bilanco->setText(QString::number(bilanco));

    ui->statusbar->showMessage("Hesaplandı",2000);

    if (ui->e_odeme->currentIndex()==1){

        ui->e_tutar->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->e_odeme->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->e_ay->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->e_gun->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->e_yil->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->label->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
    }
    else if (ui->e_odeme->currentIndex()==2){

        ui->e_tutar->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->e_odeme->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->e_ay->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->e_gun->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->e_yil->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->label->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
    }

    if (ui->s_odeme->currentIndex()==1){

        ui->s_tutar->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->s_odeme->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->s_ay->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->s_gun->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->s_yil->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->label_2->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
    }
    else if (ui->s_odeme->currentIndex()==2){

        ui->s_tutar->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->s_odeme->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->s_ay->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->s_gun->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->s_yil->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->label_2->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
    }

    if (ui->d_odeme->currentIndex()==1){

        ui->d_tutar->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->d_odeme->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->d_ay->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->d_gun->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->d_yil->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->label_3->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
    }
    else if (ui->d_odeme->currentIndex()==2){

        ui->d_tutar->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->d_odeme->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->d_ay->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->d_gun->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->d_yil->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->label_3->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
    }

    if (ui->t_odeme->currentIndex()==1){

        ui->t_tutar->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->t_odeme->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->t_ay->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->t_gun->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->t_yil->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
        ui->label_4->setStyleSheet("background-color:rgb(0,128,0);color:rgb(255,255,255)");
    }
    else if (ui->t_odeme->currentIndex()==2){

        ui->t_tutar->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->t_odeme->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->t_ay->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->t_gun->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->t_yil->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
        ui->label_4->setStyleSheet("background-color:rgb(255,0,0);color:rgb(255,255,255)");
    }

    QFile file("D:/qt/fatura-takip-sistemi/data.txt");

    if (!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"title","dosya açılmadı");
    }

    QTextStream out (&file);
    QString text = ui->e_tutar->text();
    QString text1 = ui->s_tutar->text();
    QString text2 = ui->d_tutar->text();
    QString text3 = ui->t_tutar->text();
    QString text4 = ui->aylik_gelir->text();
    QString text5 = ui->aylik_bilanco->text();
    out<<"Elektrik "<< text<<"\n" <<"Su "<< text1<<"\n"<<"Dogal Gaz "<< text2<<"\n"<<"Telefon "<< text3<<"\n"<<"Aylik Gelir "<< text4<<"\n"<<"Aylik Bilanco "<< text5<<"\n"<<"\n";
    file.flush();
    file.close();


}
