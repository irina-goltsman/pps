#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>
#include <QVector>

// Интерфейс, через который задаём различные алгоритмы движения лифта
class RankerInterface
{
public:
    virtual void Rank(int current_floor, int direction, QVector<int> *ranked_floors,
                      int new_floor);
};

// Просто последовательно выполняет все задания. Если запросы были 1, 10, 2,
// то он сначала поедет на 1, потом на 10, а только потом на 2ой.
class ConcreteStupidRanker: public RankerInterface
{
public:
    void Rank(int current_floor, int direction, QVector<int> *ranked_floors,
              int new_floor);
};

class QElevator: public QObject
{
    Q_OBJECT
public:
    explicit QElevator();
    ~QElevator();

public slots:
    void HandleSmokeEvent(bool checked);
    void HandleWeightEvent(bool checked);
    void HandleAddFloorTask(int floor);
    void HandleDispatcherCall();
    void HandleCloseDoors();
    void HandleOpenDoors();
    void HandleSwitchOnOff(bool is_on);

private:
    bool lighting_status;
    bool is_on;
    short current_floor;
    bool is_blocked;
    // Упорядоченный список этажей для остановки (заданий для остановки)
    QVector<int> ranked_floors;

    // Инициализация всех соединений
    void initConnections();
    // Разрыв всех соединений
    void destroyConnections();
};

#endif // ELEVATOR_H
