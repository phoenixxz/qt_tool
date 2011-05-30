#ifndef DIALOG_H
 #define DIALOG_H

 #include <QDialog>

 class QAction;
 class QDialogButtonBox;
 class QGroupBox;
 class QLabel;
 class QLineEdit;
 class QMenu;
 class QMenuBar;
 class QPushButton;
 class QTextEdit;
 class QTextBrowser;
 class QComboBox;

 class Dialog : public QDialog
 {
     Q_OBJECT

 public:
     Dialog();

 private:
     void createMenu();
     void createHorizontalGroupBox();
     void createGridGroupBox();
     void createFormGroupBox();

     enum { NumGridRows = 3, NumButtons = 4 };

     QTextBrowser *textBrowser,*textBrowser1;
     QMenuBar *menuBar;
     QGroupBox *horizontalGroupBox;
     QGroupBox *gridGroupBox,*gridGroupBox1;
     QGroupBox *formGroupBox;
     QTextEdit *smallEditor;
     QTextEdit *bigEditor;
     QLabel *labels[NumGridRows];
     QLineEdit *lineEdits[NumGridRows];
     QPushButton *buttons[NumButtons];
     QDialogButtonBox *buttonBox;
     /************************/
     QLineEdit *numPacket,*netRecv,*numRecvLineEdit,*numSendLineEdit,*rateLineEdit;
     QPushButton *comSend;
     QLabel *packLabel;
     QLabel *netrecvLabel,*numSendLabel,*numRecvLabel,*rateLabel,*tempLabel;
     QComboBox *paudComboBox;

     QMenu *fileMenu;
     QAction *exitAction;
 };

 #endif
