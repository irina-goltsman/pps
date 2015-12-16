#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>
#include <QVector>
#include <QTimer>

// Интерфейс, через который задаём различные алгоритмы движения лифта
class RankerInterface
{
public:
    virtual void Rank(int current_floor, QVector<int> *ranked_floors,
                      int new_floor) = 0;
};

// Просто последовательно выполняет все задания. Если запросы были 1, 10, 2,
// то он сначала поедет на 1, потом на 10, а только потом на 2ой.
class ConcreteStupidRanker: public RankerInterface
{
public:
    void Rank(int current_floor, QVector<int> *ranked_floors,
              int new_floor);
};

class QElevator: public QObject
{
    Q_OBJECT
public:
    explicit QElevator(RankerInterface *ranker_ = new ConcreteStupidRanker());
    ~QElevator();

signals:
    void NewFloorReached(int floor);

public slots:
    void HandleSmokeEvent(bool is_smoked);
    void HandleWeightEvent(bool is_overloaded);
    void HandleAddFloorTask(int floor);
    void HandleDispatcherCall();
    void HandleCloseDoors();
    void HandleOpenDoors();
    void HandleSwitchOnOff(bool is_on);

    // Этого метода нет ни в одной диаграмме - он нужен для реализации в QT:
    void slotOneFloorMoved();

private:
    bool lighting_status;
    bool is_on;
    int current_floor;
    bool is_blocked;
    // Упорядоченный список этажей для остановки (заданий для остановки)
    QVector<int> ranked_floors;
    RankerInterface *ranker;

    // Этого атрибута нет ни в одной диаграмме - он нужен именно для реализации в QT:
    QTimer *timer;

    // Инициализация всех соединений
    void initConnections();
    // Разрыв всех соединений
    void destroyConnections();
    void onMovedFinished();
    void moveTo();
};

#endif // ELEVATOR_H
