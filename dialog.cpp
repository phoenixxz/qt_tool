#include <QtGui>
#include "dialog.h"
Dialog::Dialog()
{

     createMenu();
     cntUdpRecv=QVariant(0);
     
     //createHorizontalGroupBox();
     createGridGroupBox();
     //createFormGroupBox();

     //bigEditor = new QTextEdit;
     //bigEditor->setPlainText(tr("This widget takes up all the remaining space "
                  //              "in the top-level layout."));

     buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                      | QDialogButtonBox::Cancel);

     connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
     connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
     //connect(comSend,SIGNAL(clicked()),this,SLOT(reject()));
     udpSocket=new QUdpSocket(this);
     udpSocket->bind(9999);
     connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));
     connect(comSend,SIGNAL(clicked()),this,SLOT(processTtySendButton()));

     //QVBoxLayout *mainLayout = new QVBoxLayout;
     QHBoxLayout *mainLayout = new QHBoxLayout;
     mainLayout->setMenuBar(menuBar);
     //mainLayout->addWidget(horizontalGroupBox);
     mainLayout->addWidget(gridGroupBox);

     /*mainLayout->addWidget(gridGroupBox1);*/
    // mainLayout->addWidget(formGroupBox);
    // mainLayout->addWidget(bigEditor);
     //mainLayout->addWidget(buttonBox);
     setLayout(mainLayout);
     setWindowTitle(tr("GW-TOOLS"));
 }

 void Dialog::createMenu()
 {
     menuBar = new QMenuBar;

     fileMenu = new QMenu(tr("&File"), this);
     updateMenu = new QMenu(tr("&Update"), this);
     chartMenu=new QMenu(tr("&Chart"), this);
     exitAction = fileMenu->addAction(tr("E&xit"));
     updateAction = updateMenu->addAction(tr("U&pdate"));
     chartAction = chartMenu->addAction(tr("C&hart"));
     menuBar->addMenu(fileMenu);
     menuBar->addMenu(updateMenu);
     menuBar->addMenu(chartMenu);

     connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
 }

 void Dialog::createHorizontalGroupBox()
 {
     horizontalGroupBox = new QGroupBox(tr("Horizontal layout"));
     QHBoxLayout *layout = new QHBoxLayout;

     for (int i = 0; i < NumButtons; ++i) {
         buttons[i] = new QPushButton(tr("Button %1").arg(i + 1));
         layout->addWidget(buttons[i]);
     }
     horizontalGroupBox->setLayout(layout);
 }

 void Dialog::createGridGroupBox()
 {
     /**************grdgroupbox 1*****************************************/
     gridGroupBox = new QGroupBox(tr("Grid layout"));
     QGridLayout *layout = new QGridLayout;
     textBrowser = new QTextBrowser;

#if 0
     for (int i = 0; i < NumGridRows; ++i) {
         labels[i] = new QLabel(tr("Line %1:").arg(i + 1));
         lineEdits[i] = new QLineEdit;
         layout->addWidget(labels[i], i + 1, 0);
         layout->addWidget(lineEdits[i], i + 1, 1);
     }
#endif

     smallEditor = new QTextEdit;
     smallEditor->setPlainText(tr("This widget takes up about two thirds of the "    "grid layout."));
     numPacket = new QLineEdit;
     numLostLineEdit=new QLineEdit;
     comSend = new QPushButton(tr("&send"),this);
     packLabel =new QLabel(tr("packSec"));
     netrecvLabel =new QLabel("Net receive");
     numLostLabel =new QLabel("numLost");
     numLostRateLabel =new QLabel("numLostRate");
     numLostRateLineEdit=new QLineEdit;

     paudComboBox= new QComboBox;
     paudComboBox->addItem(tr("115200"));
     paudComboBox->addItem(tr("9600"));
     paudComboBox->addItem(tr("196000"));

     layout->addWidget(paudComboBox, 0, 5);
     layout->addWidget(netrecvLabel, 5, 3);
     layout->addWidget(packLabel, 0, 4);
     layout->addWidget(comSend, 0, 6);
     layout->addWidget(numPacket, 0, 3);
     layout->addWidget(smallEditor, 1, 3, 3, 6);
     layout->addWidget(textBrowser, 6, 3, 3,6);
     layout->setColumnStretch(1, 10);
     layout->setColumnStretch(2, 20);

     /**************grdgroupbox 1*****************************************/

     /**************grdgroupbox 2*****************************************/
     gridGroupBox1 = new QGroupBox(tr("statistics"));
     QGridLayout *layout1 = new QGridLayout;
     textBrowser1 = new QTextBrowser;
     numSendLabel = new QLabel(tr("numSend"));;
     numSendLineEdit = new QLineEdit("",this);
     numRecvLabel = new QLabel(tr("numRecv"));;
     tempLabel = new QLabel(tr("...."));
     numRecvLineEdit = new QLineEdit("",this);
     rateLabel = new QLabel(tr("rate"),this);
     rateLineEdit =new QLineEdit("",this);
     
     //layout1->addWidget(numSendLineEdit, 3,8);
     //layout1->addWidget(numSendLabel, 0,9);
     layout->addWidget(numSendLabel, 0,13);
     layout->addWidget(numLostLabel, 2,13);
     layout->addWidget(numLostRateLabel, 3,13);
     layout->addWidget(numLostRateLineEdit, 3,18);
     layout->addWidget(numSendLineEdit, 0,18);
     layout->addWidget(numRecvLabel, 1,13);
     layout->addWidget(numRecvLineEdit, 1,18);
     layout->addWidget(numLostLineEdit, 2,18);
     layout1->addWidget(rateLabel, 2,9);
     layout1->addWidget(rateLineEdit, 2,10);
     layout1->setColumnStretch(1, 10);
     layout1->setColumnStretch(2, 20);
     layout1->setRowStretch(0, 20);
     layout1->setRowStretch(0, 20);
     gridGroupBox1->setLayout(layout1);
     gridGroupBox->setLayout(layout);
     /**************grdgroupbox 2*****************************************/

 }

void Dialog::createFormGroupBox()
{
     formGroupBox = new QGroupBox(tr("Form layout"));
     QFormLayout *layout = new QFormLayout;
     layout->addRow(new QLabel(tr("Line 1:")), new QLineEdit);
     layout->addRow(new QLabel(tr("Line 2, long text:")), new QComboBox);
     layout->addRow(new QLabel(tr("Line 3:")), new QSpinBox);
     formGroupBox->setLayout(layout);
}
void Dialog::processPendingDatagrams()
{
    cntUdpRecv = cntUdpRecv.toInt() + 1;
    numRecvLineEdit->setText(cntUdpRecv.toString());
    QByteArray datagram;
    do{
	datagram.resize(udpSocket->pendingDatagramSize());
	udpSocket->readDatagram(datagram.data(),datagram.size());
    }while(udpSocket->hasPendingDatagrams());
    //textBrowser->setText(datagram.data().toString());
    textBrowser->setText(datagram.data());
    //std::cout<<count<<"heeellll";
//    resize(100,200);
 //   show();
}
void Dialog::processTtySendButton()
{
    ttySend = new ThreadTtySend(numSendLineEdit);
    ttySend->start();
    //exit(0);
}
