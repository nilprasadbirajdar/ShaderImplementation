#include "stdafx.h"
#include "OpenGLWindow.h"
#include "Visualizer.h"

Visualizer::Visualizer(QWindow* parent) : QMainWindow(nullptr)
{
    setupUi();
    connect(mPushButton, &QPushButton::clicked, this, &Visualizer::clipLine);
    connect(mPushButton2, &QPushButton::clicked, this, &Visualizer::drawLine);
    connect(mPushButton3, &QPushButton::clicked, this, &Visualizer::drawCurveUsingHermite);
    connect(mPushButton4, &QPushButton::clicked, this, &Visualizer::drawCurveUsingBezier);
    connect(mPushButton5, &QPushButton::clicked, this, &Visualizer::colorPicker);
}
    
Visualizer::~Visualizer()
{

}
void Visualizer::drawCurveUsingBezier()
{
    mVertices.clear();
    mColors.clear();
    mColorss.clear();
    mVerticess.clear();

    xCoordinate = mLineEdit13->text().toFloat();
    yCoordinate = mLineEdit14->text().toFloat();
    zCoordinate = mLineEdit15->text().toFloat();

    x1Coordinate = mLineEdit16->text().toFloat();
    y1Coordinate = mLineEdit17->text().toFloat();
    z1Coordinate = mLineEdit18->text().toFloat();

    x2Coordinate = mLineEdit19->text().toFloat();
    y2Coordinate = mLineEdit20->text().toFloat();
    z2Coordinate = mLineEdit21->text().toFloat();

    x3Coordinate = mLineEdit22->text().toFloat();
    y3Coordinate = mLineEdit23->text().toFloat();
    z3Coordinate = mLineEdit24->text().toFloat();

    Point3D p0 = Point3D(xCoordinate, yCoordinate, zCoordinate);
    Point3D p1 = Point3D(x1Coordinate, y1Coordinate, z1Coordinate);
    Point3D p2 = Point3D(x2Coordinate, y2Coordinate, z2Coordinate);
    Point3D p3 = Point3D(x3Coordinate, y3Coordinate, z3Coordinate);

    Bezier bezier(p0, p1, p2, p3);
    bezier.drawCurve(p0, p1, p2, p3, mVerticess, mColorss);

    for (int i = 0; i < mVerticess.size(); i += 3)
    {
        mVertices << mVerticess[i] << mVerticess[i + 1] << mVerticess[i + 2];
    }
    for (int i = 0; i < mColorss.size(); i += 3)
    {
        mColors << mColorss[i] << mColorss[i + 1] << mColorss[i + 2];
    }
    int flag = 1;
    mRenderer->updateData(mVertices, mColors, flag);
    mColorss.clear();
    mVerticess.clear();
    mVertices.clear();
    mColors.clear();
}

void Visualizer::drawCurveUsingHermite()
{
    mVertices.clear();
    mColors.clear();
    mColorss.clear();
    mVerticess.clear();

    xCoordinate = mLineEdit13->text().toFloat();
    yCoordinate = mLineEdit14->text().toFloat();
    zCoordinate = mLineEdit15->text().toFloat();

    x1Coordinate = mLineEdit16->text().toFloat();
    y1Coordinate = mLineEdit17->text().toFloat();
    z1Coordinate = mLineEdit18->text().toFloat();

    x2Coordinate = mLineEdit19->text().toFloat();
    y2Coordinate = mLineEdit20->text().toFloat();
    z2Coordinate = mLineEdit21->text().toFloat();

    x3Coordinate = mLineEdit22->text().toFloat();
    y3Coordinate = mLineEdit23->text().toFloat();
    z3Coordinate = mLineEdit24->text().toFloat();

    Point3D p0 = Point3D(xCoordinate, yCoordinate, zCoordinate);
    Point3D p1 = Point3D(x1Coordinate, y1Coordinate, z1Coordinate);
    Point3D p2 = Point3D(x2Coordinate, y2Coordinate, z2Coordinate);
    Point3D p3 = Point3D(x3Coordinate, y3Coordinate, z3Coordinate);

    Hermite hermite(p0, p1, p2, p3);
    hermite.drawCurve(p0, p1, p2, p3, mVerticess, mColorss);

    for (int i = 0; i < mVerticess.size(); i += 3)
    {
        mVertices << mVerticess[i] << mVerticess[i + 1] << mVerticess[i + 2];
    }
    for (int i = 0; i < mColorss.size(); i += 3)
    {
        mColors << mColorss[i] << mColorss[i + 1] << mColorss[i + 2];
    }

    int flag = 1;
    mRenderer->updateData(mVertices, mColors, flag);
    mColorss.clear();
    mVerticess.clear();
    mVertices.clear();
    mColors.clear();

}

//Slot for Implimentation of Symmetric DDA
void Visualizer::drawLine()
{
    mVertices.clear();
    mColors.clear();
    mColorss.clear();
    mVerticess.clear();

    xCoordinate = mLineEdit9->text().toFloat();
    yCoordinate = mLineEdit10->text().toFloat();

    x1Coordinate = mLineEdit11->text().toFloat();
    y1Coordinate = mLineEdit12->text().toFloat();

    Point3D pt1(xCoordinate, yCoordinate);
    Point3D pt2(x1Coordinate, y1Coordinate);

    Line line(pt1, pt2);

    mVertices << pt1.x() << pt1.y();
    mVertices << pt2.x() << pt2.y();

    mColors << 0.0f << 1.0f << 0.0f;
    mColors << 0.0f << 1.0f << 0.0f;

    simpleDDAObj.drawGrid(mVerticess, mColorss);
    simpleDDAObj.drawLineBySimpleDDA(line, mVerticess);

    for (int i = 0; i < mVerticess.size(); i += 2)
    {
        mVertices << mVerticess[i] << mVerticess[i + 1];
    }
    for (int i = 0; i < mColorss.size(); i += 3)
    {
        mColors << mColorss[i] << mColorss[i + 1] << mColorss[i + 2];
    }

    mRenderer->updateData(mVertices, mColors);
    mVertices.clear();
    mColors.clear();
    mColorss.clear();
    mVerticess.clear();

}

//Slot for Implimentation of sutherland cohen line clipping
void Visualizer::clipLine()
{
    mVertices.clear();
    mColors.clear();
    mColorss.clear();
    mVerticess.clear();

    xCoordinate = mLineEdit->text().toFloat();
    yCoordinate = mLineEdit2->text().toFloat();

    x1Coordinate = mLineEdit7->text().toFloat();
    y1Coordinate = mLineEdit8->text().toFloat();

    xMin = mLineEdit3->text().toFloat();
    yMin = mLineEdit4->text().toFloat();

    xMax = mLineEdit5->text().toFloat();
    yMax = mLineEdit6->text().toFloat();

    Point3D pt1(xCoordinate, yCoordinate);
    Point3D pt2(x1Coordinate, y1Coordinate);

    Point3D pt3(xMin, yMin);
    Point3D pt4(xMax, yMax);

    Shape rectangle(pt3, pt4);

    for (int i = 0; i < rectangle.lines().size(); i++)
    {

        mVertices << rectangle.lines()[i].start().x() << rectangle.lines()[i].start().y();
        mVertices << rectangle.lines()[i].end().x() << rectangle.lines()[i].end().y();

        mColors << 1.0f << 1.0f << 0.0f;
        mColors << 1.0f << 1.0f << 0.0f;

    }

    Line line(pt1, pt2);
    Line diagonalLine(pt3, pt4);

    SutherlandCohen sutherlandCohen(line, diagonalLine, mVerticess, mColorss);

    for (int i = 0; i < mVerticess.size(); i += 2)
    {
        mVertices << mVerticess[i] << mVerticess[i + 1];
    }
    for (int i = 0; i < mColorss.size(); i += 3)
    {
        mColors << mColorss[i] << mColorss[i + 1] << mColorss[i + 2];
    }
    mRenderer->updateData(mVertices, mColors);

    mColorss.clear();
    mVerticess.clear();
    mVertices.clear();
    mColors.clear();
}

void Visualizer::colorPicker() {
    QColorDialog colorDialog(this);
    QColor selectedColor = colorDialog.getColor();
    if (selectedColor.isValid())
    {
        int red = selectedColor.red();
        int green = selectedColor.green();
        int blue = selectedColor.blue();
        int alpha = selectedColor.alpha();
        QString color = QString("%1, %2, %3, %4").arg(red).arg(green).arg(blue).arg(alpha);
        mRenderer->writeStringToFile(color, "fragmentShader.glsl");
    }
}

//Implimentation of UI
void Visualizer::setupUi()
{
    mCentralWidget = new QWidget(this);
    mCentralWidget->setObjectName("centralwidget");

   mLabel = new QLabel(this);
    mLabel->setObjectName("label");
    mLabel->setText("X coordinate");
    mLabel->setGeometry(QRect(1035, 180, 85, 20));

    mLineEdit = new QLineEdit(this);
    mLineEdit->setObjectName("lineEdit");
    mLineEdit->setGeometry(QRect(1030, 205, 85, 20));

    mLabel2 = new QLabel(this);
    mLabel2->setObjectName("label_2");
    mLabel2->setText("Y coordinate");
    mLabel2->setGeometry(QRect(1125, 180, 85, 20));

    mLineEdit2 = new QLineEdit(this);
    mLineEdit2->setObjectName("lineEdit_2");
    mLineEdit2->setGeometry(QRect(1120, 205, 85, 20));

    mLabel3 = new QLabel(this);
    mLabel3->setObjectName("label");
    mLabel3->setText("          xMin");
    mLabel3->setGeometry(QRect(1030, 235, 85, 20));

    mLineEdit3 = new QLineEdit(this);
    mLineEdit3->setObjectName("lineEdit_3");
    mLineEdit3->setGeometry(QRect(1030, 260, 85, 20));

    mLabel4 = new QLabel(this);
    mLabel4->setObjectName("label");
    mLabel4->setText("      yMin");
    mLabel4->setGeometry(QRect(1120, 235, 85, 20));

    mLineEdit4 = new QLineEdit(this);
    mLineEdit4->setObjectName("lineEdit_4");
    mLineEdit4->setGeometry(QRect(1120, 260, 85, 20));

    mLabel5 = new QLabel(this);
    mLabel5->setObjectName("label");
    mLabel5->setText("          xMax");
    mLabel5->setGeometry(QRect(1210, 235, 85, 20));

    mLineEdit5 = new QLineEdit(this);
    mLineEdit5->setObjectName("lineEdit_5");
    mLineEdit5->setGeometry(QRect(1210, 260, 85, 20));

    mLabel6 = new QLabel(this);
    mLabel6->setObjectName("label");
    mLabel6->setText("      yMax");
    mLabel6->setGeometry(QRect(1300, 235, 85, 20));

    mLineEdit6 = new QLineEdit(this);
    mLineEdit6->setObjectName("lineEdit_6");
    mLineEdit6->setGeometry(QRect(1300, 260, 85, 20));

    mPushButton = new QPushButton(this);
    mPushButton->setObjectName("pushButton");
    mPushButton->setText("Clip Line");
    mPushButton->setGeometry(QRect(1420, 220, 85, 50));

    mLabel7 = new QLabel(this);
    mLabel7->setObjectName("label");
    mLabel7->setText("X1 Coordinate");
    mLabel7->setGeometry(QRect(1210, 180, 85, 20));

    mLineEdit7 = new QLineEdit(this);
    mLineEdit7->setObjectName("lineEdit_7");
    mLineEdit7->setGeometry(QRect(1210, 205, 85, 20));

    mLabel8 = new QLabel(this);
    mLabel8->setObjectName("label");
    mLabel8->setText("Y1 Coordinate");
    mLabel8->setGeometry(QRect(1300, 180, 85, 20));

    mLineEdit8 = new QLineEdit(this);
    mLineEdit8->setObjectName("lineEdit_6");
    mLineEdit8->setGeometry(QRect(1300, 205, 85, 20));

    mLabel9 = new QLabel(this);
    mLabel9->setObjectName("label");
    mLabel9->setText("X Coordinate");
    mLabel9->setGeometry(QRect(1210, 0, 85, 20));

    mLineEdit9 = new QLineEdit(this);
    mLineEdit9->setObjectName("lineEdit_6");
    mLineEdit9->setGeometry(QRect(1210, 25, 85, 20));

    mLabel10 = new QLabel(this);
    mLabel10->setObjectName("label");
    mLabel10->setText("Y Coordinate");
    mLabel10->setGeometry(QRect(1300, 0, 85, 20));

    mLineEdit10 = new QLineEdit(this);
    mLineEdit10->setObjectName("lineEdit_6");
    mLineEdit10->setGeometry(QRect(1300, 25, 85, 20));

    mLabel11 = new QLabel(this);
    mLabel11->setObjectName("label");
    mLabel11->setText("X1 Coordinate");
    mLabel11->setGeometry(QRect(1210, 55, 85, 20));

    mLineEdit11 = new QLineEdit(this);
    mLineEdit11->setObjectName("lineEdit_6");
    mLineEdit11->setGeometry(QRect(1210, 85, 85, 20));

    mLabel12 = new QLabel(this);
    mLabel12->setObjectName("label");
    mLabel12->setText("Y1 Coordinate");
    mLabel12->setGeometry(QRect(1300, 55, 85, 20));

    mLineEdit12 = new QLineEdit(this);
    mLineEdit12->setObjectName("lineEdit_6");
    mLineEdit12->setGeometry(QRect(1300, 85, 85, 20));

    mLabel13 = new QLabel(this);
    mLabel13->setObjectName("label");
    mLabel13->setText("Line cliping by Sutherland Cohen Algorithm");
    mLabel13->setGeometry(QRect(1100, 300, 285, 20));

    mLabel14 = new QLabel(this);
    mLabel14->setObjectName("label");
    mLabel14->setText("Line drawing by Simple DDA");
    mLabel14->setGeometry(QRect(1210, 110, 285, 20));

    mPushButton2 = new QPushButton(this);
    mPushButton2->setObjectName("pushButton");
    mPushButton2->setText("Draw Line");
    mPushButton2->setGeometry(QRect(1400, 40, 85, 50));

    mRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
    mRenderer->setGeometry(QRect(5, 5, 1000, 740));

    mLabel15 = new QLabel(this);
    mLabel15->setObjectName("label");
    mLabel15->setText("          x0");
    mLabel15->setGeometry(QRect(1200, 480, 85, 20));

    mLineEdit13 = new QLineEdit(this);
    mLineEdit13->setObjectName("lineEdit_6");
    mLineEdit13->setGeometry(QRect(1200, 500, 85, 20));

    mLabel16 = new QLabel(this);
    mLabel16->setObjectName("label");
    mLabel16->setText("          y0");
    mLabel16->setGeometry(QRect(1290, 480, 85, 20));

    mLineEdit14 = new QLineEdit(this);
    mLineEdit14->setObjectName("lineEdit_6");
    mLineEdit14->setGeometry(QRect(1290, 500, 85, 20));

    mLabel17 = new QLabel(this);
    mLabel17->setObjectName("label");
    mLabel17->setText("          z0");
    mLabel17->setGeometry(QRect(1380, 480, 85, 20));

    mLineEdit15 = new QLineEdit(this);
    mLineEdit15->setObjectName("lineEdit_6");
    mLineEdit15->setGeometry(QRect(1380, 500, 85, 20));

    mLabel18 = new QLabel(this);
    mLabel18->setObjectName("label");
    mLabel18->setText("          x1");
    mLabel18->setGeometry(QRect(1200, 530, 85, 20));

    mLineEdit16 = new QLineEdit(this);
    mLineEdit16->setObjectName("lineEdit_6");
    mLineEdit16->setGeometry(QRect(1200, 550, 85, 20));

    mLabel19 = new QLabel(this);
    mLabel19->setObjectName("label");
    mLabel19->setText("          y1");
    mLabel19->setGeometry(QRect(1290, 530, 85, 20));

    mLineEdit17 = new QLineEdit(this);
    mLineEdit17->setObjectName("lineEdit_6");
    mLineEdit17->setGeometry(QRect(1290, 550, 85, 20));

    mLabel20 = new QLabel(this);
    mLabel20->setObjectName("label");
    mLabel20->setText("          z1");
    mLabel20->setGeometry(QRect(1380, 530, 85, 20));

    mLineEdit18 = new QLineEdit(this);
    mLineEdit18->setObjectName("lineEdit_6");
    mLineEdit18->setGeometry(QRect(1380, 550, 85, 20));

    mLabel21 = new QLabel(this);
    mLabel21->setObjectName("label");
    mLabel21->setText("          x2");
    mLabel21->setGeometry(QRect(1200, 580, 85, 20));

    mLineEdit19 = new QLineEdit(this);
    mLineEdit19->setObjectName("lineEdit_6");
    mLineEdit19->setGeometry(QRect(1200, 600, 85, 20));

    mLabel22 = new QLabel(this);
    mLabel22->setObjectName("label");
    mLabel22->setText("          y2");
    mLabel22->setGeometry(QRect(1290, 580, 85, 20));

    mLineEdit20 = new QLineEdit(this);
    mLineEdit20->setObjectName("lineEdit_6");
    mLineEdit20->setGeometry(QRect(1290, 600, 85, 20));

    mLabel23 = new QLabel(this);
    mLabel23->setObjectName("label");
    mLabel23->setText("          z2");
    mLabel23->setGeometry(QRect(1380, 580, 85, 20));

    mLineEdit21 = new QLineEdit(this);
    mLineEdit21->setObjectName("lineEdit_6");
    mLineEdit21->setGeometry(QRect(1380, 600, 85, 20));

    mLabel24 = new QLabel(this);
    mLabel24->setObjectName("label");
    mLabel24->setText("          x3");
    mLabel24->setGeometry(QRect(1200, 630, 85, 20));

    mLineEdit22 = new QLineEdit(this);
    mLineEdit22->setObjectName("lineEdit_6");
    mLineEdit22->setGeometry(QRect(1200, 650, 85, 20));

    mLabel25 = new QLabel(this);
    mLabel25->setObjectName("label");
    mLabel25->setText("          y3");
    mLabel25->setGeometry(QRect(1290, 630, 85, 20));

    mLineEdit23 = new QLineEdit(this);
    mLineEdit23->setObjectName("lineEdit_6");
    mLineEdit23->setGeometry(QRect(1290, 650, 85, 20));

    mLabel26 = new QLabel(this);
    mLabel26->setObjectName("label");
    mLabel26->setText("          z3");
    mLabel26->setGeometry(QRect(1380, 630, 85, 20));

    mLineEdit24 = new QLineEdit(this);
    mLineEdit24->setObjectName("lineEdit_6");
    mLineEdit24->setGeometry(QRect(1380, 650, 85, 20));

    mPushButton3 = new QPushButton(this);
    mPushButton3->setObjectName("pushButton");
    mPushButton3->setText("Hermite curve");
    mPushButton3->setGeometry(QRect(1290, 690, 85, 25));

    mPushButton4 = new QPushButton(this);
    mPushButton4->setObjectName("pushButton");
    mPushButton4->setText("Bezier curve");
    mPushButton4->setGeometry(QRect(1290, 730, 85, 25));

    mPushButton5 = new QPushButton(this);
    mPushButton5->setObjectName("pushButton");
    mPushButton5->setText("color change");
    mPushButton5->setGeometry(QRect(1290, 350, 85, 25));

  


//pushButton_2 = new QPushButton(tab1);
//pushButton_2->setText("SimpleDDA");
//pushButton_2->setObjectName("pushButton_2");
//pushButton_2->setGeometry(QRect(10, 10, 81, 24));
//pushButton_3 = new QPushButton(tab1);
//pushButton_3->setText("Bresenhams");
//pushButton_3->setObjectName("pushButton_3");
//pushButton_3->setGeometry(QRect(120, 10, 91, 24));
/*tabWidget->addTab(tab1, "Lines");*/
//tab2 = new QWidget();
//tab2->setObjectName("tab_2");
//pushButton_4 = new QPushButton(tab2);
//pushButton_4->setObjectName("pushButton_4");
//pushButton_4->setText("Hermite");
//pushButton_4->setGeometry(QRect(10, 10, 81, 24));
//pushButton_5 = new QPushButton(tab2);
//pushButton_5->setObjectName("pushButton_5");
//pushButton_5->setGeometry(QRect(130, 10, 81, 24));
//pushButton_5->setText("Bezier");
//pushButton_6 = new QPushButton(tab2);
//pushButton_6->setObjectName("pushButton_6");
//pushButton_6->setGeometry(QRect(80, 40, 81, 24));
//pushButton_6->setText("BSpline");
//mtabWidget->addTab(tab2, "Splines");
 

    setWindowTitle(QCoreApplication::translate("CAGD Algorithm Implementation", "CAGD Algorithm Implementation", nullptr));
}