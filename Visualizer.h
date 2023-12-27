#pragma once
#include "Bezier.h"
#include "Hermite.h"
#include "Shape.h"
#include "SimpleDDA.h"
#include "SutherlandCohen.h"
#include "Visualizer.h"
//#include "ui_SymmetricDDAandSutherLandCohen.h"

#include <vector>
#include <QtWidgets/QMainWindow>

using namespace std;

class OpenGLWindow;


class Visualizer : public QMainWindow
{
    Q_OBJECT

public:
    Visualizer(QWindow* parent = nullptr);
    ~Visualizer();

private:
    void setupUi();

public slots:
    void clipLine();
    void drawLine();
    void drawCurveUsingHermite();
    void drawCurveUsingBezier();
    void colorPicker();

public:
    vector<float>      mVerticess;
    vector<float>      mColorss;
    QVector<GLfloat>   mVertices;
    QVector<GLfloat>   mColors;

private:
    //Ui::SymmetricDDAandSutherLandCohenClass ui;
    QWidget* mCentralWidget;
    QTabWidget* mtabWidget;
    QWidget* tab1;
    OpenGLWindow* mRenderer;
    QPushButton* mPushButton;
    QPushButton* mPushButton2;
    QPushButton* mPushButton3;
    QPushButton* mPushButton4;
    QPushButton* mPushButton5;


    QLineEdit* mLineEdit;
    QLineEdit* mLineEdit2;
    QLineEdit* mLineEdit3;
    QLineEdit* mLineEdit4;
    QLineEdit* mLineEdit5;
    QLineEdit* mLineEdit6;
    QLineEdit* mLineEdit7;
    QLineEdit* mLineEdit8;
    QLineEdit* mLineEdit9;
    QLineEdit* mLineEdit10;
    QLineEdit* mLineEdit11;
    QLineEdit* mLineEdit12;

    QLineEdit* mLineEdit13;
    QLineEdit* mLineEdit14;
    QLineEdit* mLineEdit15;
    QLineEdit* mLineEdit16;
    QLineEdit* mLineEdit17;
    QLineEdit* mLineEdit18;
    QLineEdit* mLineEdit19;
    QLineEdit* mLineEdit20;
    QLineEdit* mLineEdit21;
    QLineEdit* mLineEdit22;
    QLineEdit* mLineEdit23;
    QLineEdit* mLineEdit24;


    QLabel* mLabel;
    QLabel* mLabel2;
    QLabel* mLabel3;
    QLabel* mLabel4;
    QLabel* mLabel5;
    QLabel* mLabel6;
    QLabel* mLabel7;
    QLabel* mLabel8;
    QLabel* mLabel9;
    QLabel* mLabel10;
    QLabel* mLabel11;
    QLabel* mLabel12;
    QLabel* mLabel13;
    QLabel* mLabel14;

    QLabel* mLabel15;
    QLabel* mLabel16;
    QLabel* mLabel17;
    QLabel* mLabel18;
    QLabel* mLabel19;
    QLabel* mLabel20;
    QLabel* mLabel21;
    QLabel* mLabel22;
    QLabel* mLabel23;
    QLabel* mLabel24;
    QLabel* mLabel25;
    QLabel* mLabel26;

    QTabWidget* tabWidget;

    float xCoordinate;
    float yCoordinate;
    float zCoordinate;
    float x1Coordinate;
    float y1Coordinate;
    float z1Coordinate;
    float x2Coordinate;
    float y2Coordinate;
    float z2Coordinate;
    float x3Coordinate;
    float y3Coordinate;
    float z3Coordinate;

    float xMin;
    float yMin;
    float xMax;
    float yMax;

    SimpleDDA simpleDDAObj;

};

