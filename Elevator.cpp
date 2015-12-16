#include <Elevator.h>

ConcreteStupidRanker::Rank(int current_floor,
                           QVector<int> *ranked_floors, int new_floor)
{
    ranked_floors->append(new_floor);
}

QElevator::QElevator(RankerInterface ranker_ = ConcreteStupidRanker()): ranker(ranker_)
{
    timer = new QTimer(this);
}

~QElevator()
{
    delete timer;
}


void QElevator::HandleSmokeEvent(bool is_smoked)
{
    is_blocked = is_smoked;
}

void QElevator::HandleWeightEvent(bool is_overloaded)
{
}

void QElevator::HandleAddFloorTask(int floor)
{
    ranker.Rank(current_floor, ranked_floors, floor);
    if (ranked_floors.size() == 1 && !is_blocked) {
        // Значит до этого лифт находился в состоянии сна и сейчас нужно начать движение
        moveTo(floor);
    }
}

void QElevator::HandleDispatcherCall()
{
}

void QElevator::HandleCloseDoors()
{
}

void QElevator::HandleOpenDoors()
{
}

void QElevator::HandleSwitchOnOff(bool is_on)
{
    if (is_on && !this->is_on) {
        // То нужно включить лифт:
        initConnections();
        this->is_on = true;
    }

    if (!is_on && this->is_on) {
        // То нужно выключить лифт:
        destroyConnections();
        this->is_on = false;
    }
}

void QElevator::slotOneFloorMoved()
{
    int one_step = ranked_floors.at(0) - current_floor > 0 ? 1 : -1;
    current_floor += one_step;
    emit NewFloorReached(current_floor);
    if (current_floor == ranked_floors.at(0)) {
        // Значит задание только что было выполнено
        onMovedFinished();
    } else {
        // Значит ещё не добрались до нужного этажа.
        QTimer::singleShot(500, this, SLOT(slotOneFloorMoved()));
    }
}


void QElevator::initConnections()
{
    // TODO: связать сигналы со слотами всех устройст
}

// Разрыв всех соединений
void QElevator::destroyConnections()
{
    // TODO: разрушить установленные соединения
}

void QElevator::onMovedFinished()
{
    ranked_floors.pop_front();
}

void QElevator::moveTo(int floor)
{
    // Тут на самом деле происходит движение и при этом отправляется сигнал
    // о перемещении на очередной этаж, но для простоты нашего MVP:
    QTimer::singleShot(500, this, SLOT(slotOneFloorMoved()));
}
