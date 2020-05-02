#ifndef BOARD_H
#define BOARD_H
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>
#include <QVector>
#include <QMessageBox>
#include <QSize>

class Board : public QWidget
{
    Q_OBJECT
public:
    Board(QWidget *parent = 0);
signals:

private slots:
    void buttonClicked(int);
private:
    QVector<QPushButton*> buttons;
    QVector<QVector<int>> grid;
    QVector<QVector<int>> weightGrid;
    QVector<QVector<bool>> open3;
    QVector<QVector<int>> patterns;
    bool playerTurn = true;
    void createButtons(QGridLayout*);
    void createPatterns();
    void createGrid();
    void updateGrid(int, int);
    void resetWeightGrid();
    bool checkValidMove(int);
    bool checkButtonFill(int);
    bool checkFive();
    bool checkFiveHori();
    bool checkFiveVert();
    bool checkFiveDiag1();
    bool checkFiveDiag2();
    bool checkDoubleThrees(int);
    bool checkDoubleThreesHori(int, int, int);
    bool checkDoubleThreesVert(int, int, int);
    bool checkDoubleThreesDiag1(int, int, int);
    bool checkDoubleThreesDiag2(int, int, int);
    void changeBackground(int, int, QString);
    int computerAI();
    void weighHori();
    void weighVert();
    void weighDiag1();
    void weighDiag2();
    int pickMaxWeight();
};

#endif // BOARD_H
